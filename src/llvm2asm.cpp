#include "llvm_ir.h"
#include "asm_arm.h"
#include "temp.h"
#include "llvm2asm.h"

#include <queue>
#include <cassert>

using namespace std;
using namespace LLVMIR;
using namespace ASM;

static int stack_frame;
static bool alloc_frame = false;

static unordered_map<int, int> spOffsetMap;
static unordered_map<int, AS_relopkind> condMap;
static unordered_map<string, int> structLayout;

void structLayoutInit(vector<L_def *> &defs)
{
    for (const auto &def : defs)
    {
        switch (def->kind)
        {
        case L_DefKind::SRT:
        {
            int layout_size = 0;
            for (auto member : def->u.SRT->members)
            {
                switch (member.kind)
                {
                case TempType::STRUCT_TEMP:
                {
                    if (structLayout.find(member.structname) == structLayout.end())
                    {
                        printf("error in structLayoutInit\n!!");
                        assert(0);
                    }
                    layout_size += structLayout[member.structname];
                }
                break;
                case TempType::STRUCT_PTR:
                {
                    if (structLayout.find(member.structname) == structLayout.end())
                    {
                        printf("error in structLayoutInit\n!!");
                        assert(0);
                    }
                    layout_size += structLayout[member.structname] * member.len;
                }
                break;
                case TempType::INT_TEMP:
                {
                    layout_size += 4;
                }
                break;
                case TempType::INT_PTR:
                {
                    layout_size += 4 * member.len;
                }
                break;

                default:
                {
                    assert(0);
                }
                break;
                }
            }
            structLayout.emplace(def->u.SRT->name, layout_size);
            // Fixme: add here
        }
        case L_DefKind::GLOBAL:
        {
            break;
        }
        case L_DefKind::FUNC:
        {
            break;
        }
        }
    }
}

void set_stack(L_func &func)
{
    // Fixme: add here
    // 计算该函数需要的栈帧大小
    // 每一个alloca需要+4
    // GEP呢？
    stack_frame = 0;
    auto block = func.blocks.front();
    for (auto it = block->instrs.rbegin(); it != block->instrs.rend(); it++)
    {
        // 倒着处理alloca
        auto s = *it;
        if (s->type == L_StmKind::T_ALLOCA)
        {
            int vreg = s->u.ALLOCA->dst->u.TEMP->num;
            // printf("stack_frame = %d\n", stack_frame);
            spOffsetMap[vreg] = stack_frame;
            switch (s->u.ALLOCA->dst->u.TEMP->type)
            {
            case TempType::INT_TEMP:
            {
                assert(0);
                break;
            }
            case TempType::INT_PTR:
            {
                if (s->u.ALLOCA->dst->u.TEMP->len == 0)
                {
                    stack_frame += 4;
                }
                else
                {
                    stack_frame += s->u.ALLOCA->dst->u.TEMP->len * 4;
                }

                break;
            }
            case TempType::STRUCT_TEMP:
            {
                assert(0);
                break;
            }
            case TempType::STRUCT_PTR:
            {
                if (s->u.ALLOCA->dst->u.TEMP->len == 0)
                {
                    stack_frame += structLayout[s->u.ALLOCA->dst->u.TEMP->structname];
                }
                else
                {
                    stack_frame += structLayout[s->u.ALLOCA->dst->u.TEMP->structname] * s->u.ALLOCA->dst->u.TEMP->len;
                }
                break;
            }
            }
        }
    }
    stack_frame += (16 - stack_frame % 16) % 16;
}

void new_frame(list<AS_stm *> &as_list)
{
    // Fixme: add here
    if (stack_frame == 0)
        return;
    auto it = std::next(as_list.begin(), 2);

    auto sub_stm = AS_Binop(AS_binopkind::SUB_, AS_Reg_Sp(), AS_Reg_Imm(stack_frame), AS_Reg_Sp());
    as_list.insert(it, sub_stm);
}

void free_frame(list<AS_stm *> &as_list)
{
    // Fixme: add here
    if (stack_frame == 0)
        return;
    auto add_stm = AS_Binop(AS_binopkind::ADD_, AS_Reg_Sp(), AS_Reg_Imm(stack_frame), AS_Reg_Sp());
    for (auto it = as_list.begin(); it != as_list.end(); it++)
    {
        auto stm = *it;
        if (stm->type == AS_stmkind::RET)
        {
            // 现在it指向新插入的一行add
            it = as_list.insert(it, add_stm);
            // 连续挪动2行，指向ret后面一行
            it++;
        }
    }
}

void llvm2asmBinop(list<AS_stm *> &as_list, L_stm *binop_stm)
{
    AS_reg *left;
    AS_reg *right;
    AS_reg *dst;
    AS_binopkind op;

    switch (binop_stm->u.BINOP->op)
    {
    case L_binopKind::T_plus:
    {
        op = AS_binopkind::ADD_;
    }
    break;
    case L_binopKind::T_minus:
    {
        op = AS_binopkind::SUB_;
    }
    break;
    case L_binopKind::T_mul:
    {
        op = AS_binopkind::MUL_;
    }
    break;
    case L_binopKind::T_div:
    {
        op = AS_binopkind::SDIV_;
    }
    break;

    default:
        break;
    }

    switch (binop_stm->u.BINOP->op)
    {
    case L_binopKind::T_plus:
    case L_binopKind::T_minus:
    {
        // left必须是寄存器
        switch (binop_stm->u.BINOP->left->kind)
        {
        case OperandKind::ICONST:
        {
            // store from the const: str #1, ...
            // move the instant into x2: mov x2, #1
            int instant = binop_stm->u.BINOP->left->u.ICONST;
            AS_reg *src_mov = new AS_reg(-3, instant);
            AS_reg *dst_mov = new AS_reg(2, 0);
            as_list.push_back(AS_Mov(src_mov, dst_mov));
            left = dst_mov;
            break;
        }
        case OperandKind::TEMP:
        {
            // store from the reg directly: str x, ...
            int src_num = binop_stm->u.BINOP->left->u.TEMP->num;
            left = new AS_reg(src_num, 0);
            break;
        }
        case OperandKind::NAME:
        {
            assert(0);
        }
        }

        switch (binop_stm->u.BINOP->right->kind)
        {
        case OperandKind::ICONST:
        {
            // store from the const: str #1, ...
            // do not need to move the instant into reg, use #1 directly
            int instant = binop_stm->u.BINOP->right->u.ICONST;
            right = new AS_reg(-3, instant);
            break;
        }
        case OperandKind::TEMP:
        {
            // store from the reg: str x, ...
            int src_num = binop_stm->u.BINOP->right->u.TEMP->num;
            right = new AS_reg(src_num, 0);
            break;
        }
        case OperandKind::NAME:
        {
            assert(0);
        }
        }

        break;
    }

    case L_binopKind::T_mul:
    case L_binopKind::T_div:
    {
        // left必须是寄存器
        switch (binop_stm->u.BINOP->left->kind)
        {
        case OperandKind::ICONST:
        {
            // store from the const: str #1, ...
            // move the instant into x2: mov x2, #1
            int instant = binop_stm->u.BINOP->left->u.ICONST;
            AS_reg *src_mov = new AS_reg(-3, instant);
            AS_reg *dst_mov = new AS_reg(2, 0);
            as_list.push_back(AS_Mov(src_mov, dst_mov));
            left = dst_mov;
            break;
        }
        case OperandKind::TEMP:
        {
            // store from the reg directly: str x, ...
            int src_num = binop_stm->u.BINOP->left->u.TEMP->num;
            left = new AS_reg(src_num, 0);
            break;
        }
        case OperandKind::NAME:
        {
            assert(0);
        }
        }
        // right必须是寄存器
        switch (binop_stm->u.BINOP->right->kind)
        {
        case OperandKind::ICONST:
        {
            // store from the const: str #1, ...
            // move the instant into x2: mov x2, #1
            int instant = binop_stm->u.BINOP->right->u.ICONST;
            AS_reg *src_mov = new AS_reg(-3, instant);
            AS_reg *dst_mov = new AS_reg(3, 0);
            as_list.push_back(AS_Mov(src_mov, dst_mov));
            right = dst_mov;
            break;
        }
        case OperandKind::TEMP:
        {
            // store from the reg: str x, ...
            int src_num = binop_stm->u.BINOP->right->u.TEMP->num;
            right = new AS_reg(src_num, 0);
            break;
        }
        case OperandKind::NAME:
        {
            assert(0);
        }
        }

        break;
    }
    }
    assert(binop_stm->u.BINOP->dst->kind == OperandKind::TEMP);
    int src_num = binop_stm->u.BINOP->dst->u.TEMP->num;
    dst = new AS_reg(src_num, 0);

    as_list.push_back(AS_Binop(op, left, right, dst));
}

void llvm2asmLoad(list<AS_stm *> &as_list, L_stm *load_stm)
{
    // Fixme: add here
    AS_reg *dst;
    AS_reg *ptr;

    assert(load_stm->u.LOAD->dst->kind == OperandKind::TEMP);
    dst = AS_Reg_Operand(load_stm->u.LOAD->dst);
    auto ptr_oper = load_stm->u.LOAD->ptr;

    if (ptr_oper->kind == OperandKind::NAME)
    {
        // 直接从全局变量int load
        ptr = new AS_reg(3, 0);
        as_list.push_back(AS_Adr(new AS_label(ptr_oper->u.NAME->name->name), ptr));
    }
    else
    {
        // 全局变量，但是已经计算过偏移了
        if (spOffsetMap.find(ptr_oper->u.TEMP->num) == spOffsetMap.end())
        {
            ptr = new AS_reg(ptr_oper->u.TEMP->num, 0);
        }
        // 栈上的局部变量
        else
        {
            int offset = spOffsetMap[ptr_oper->u.TEMP->num];
            ptr = AS_Reg_OnStack(offset);
        }
    }

    as_list.push_back(AS_Ldr(dst, ptr));
}

void llvm2asmStore(list<AS_stm *> &as_list, L_stm *store_stm)
{
    // Fixme: add here
    AS_reg *src;
    AS_reg *ptr;

    // assert(store_stm->u.STORE->src->kind == OperandKind::TEMP);
    if (store_stm->u.STORE->src->kind == OperandKind::ICONST)
    {
        src = new AS_reg(2, 0);
        as_list.push_back(AS_Mov(AS_Reg_Operand(store_stm->u.STORE->src), src));
    }
    else
    {
        src = AS_Reg_Operand(store_stm->u.STORE->src);
    }

    auto ptr_oper = store_stm->u.STORE->ptr;

    if (ptr_oper->kind == OperandKind::NAME)
    {
        // 直接对全局变量int store
        ptr = new AS_reg(3, 0);
        as_list.push_back(AS_Adr(new AS_label(ptr_oper->u.NAME->name->name), ptr));
    }
    else
    {
        // 全局变量，但是已经计算过偏移了
        if (spOffsetMap.find(ptr_oper->u.TEMP->num) == spOffsetMap.end())
        {
            ptr = new AS_reg(ptr_oper->u.TEMP->num, 0);
        }
        // 栈上的局部变量
        else
        {
            int offset = spOffsetMap[ptr_oper->u.TEMP->num];
            ptr = AS_Reg_OnStack(offset);
        }
    }

    as_list.push_back(AS_Str(src, ptr));
}

void llvm2asmCmp(list<AS_stm *> &as_list, L_stm *cmp_stm)
{
    // Fixme: add here
    unordered_map<L_relopKind, AS_relopkind> map = {
        {L_relopKind::T_eq, AS_relopkind::EQ_},
        {L_relopKind::T_ne, AS_relopkind::NE_},
        {L_relopKind::T_ge, AS_relopkind::GE_},
        {L_relopKind::T_gt, AS_relopkind::GT_},
        {L_relopKind::T_le, AS_relopkind::LE_},
        {L_relopKind::T_lt, AS_relopkind::LT_}};
    condMap[cmp_stm->u.CMP->dst->u.TEMP->num] = map[(cmp_stm->u.CMP->op)];
    AS_reg *left;
    // 左操作数必须是寄存器
    if (cmp_stm->u.CMP->left->kind == OperandKind::ICONST)
    {
        left = new AS_reg(3, 0);
        as_list.push_back(AS_Mov(AS_Reg_Operand(cmp_stm->u.CMP->left), left));
    }
    else
    {
        left = AS_Reg_Operand(cmp_stm->u.CMP->left);
    }
    AS_reg *right = AS_Reg_Operand(cmp_stm->u.CMP->right);
    as_list.push_back(AS_Cmp(left, right));
}

void llvm2asmCJmp(list<AS_stm *> &as_list, L_stm *cjmp_stm)
{
    // Fixme: add here

    as_list.push_back(AS_BCond(condMap[cjmp_stm->u.CJUMP->dst->u.TEMP->num], new AS_label(cjmp_stm->u.CJUMP->true_label->name)));
    as_list.push_back(AS_B(new AS_label(cjmp_stm->u.CJUMP->false_label->name)));
}

void llvm2asmRet(list<AS_stm *> &as_list, L_stm *ret_stm)
{
    // Fixme: add here
    as_list.push_back(AS_Mov(AS_Reg_Operand(ret_stm->u.RET->ret), new AS_reg(0, 0)));
    as_list.push_back(AS_Ret());
}

void llvm2asmGep(list<AS_stm *> &as_list, L_stm *gep_stm)
{
    // Fixme: add here
    AS_reg *dst = AS_Reg_Operand(gep_stm->u.GEP->new_ptr);
    auto x3 = new AS_reg(3, 0);
    AS_reg *index = AS_Reg_Operand(gep_stm->u.GEP->index);
    auto base_ptr = gep_stm->u.GEP->base_ptr;
    if (base_ptr->kind == OperandKind::NAME)
    {
        // 对全局变量GEP，会把中间结果都记录下来
        if (base_ptr->u.NAME->type == TempType::INT_PTR)
        {
            // int数组get element_ptr
            assert(gep_stm->u.GEP->index->kind == OperandKind::ICONST);
            index->offset *= 4;
        }
        else if (base_ptr->u.NAME->type == TempType::STRUCT_TEMP)
        {
            // 获取结构体的某个成员变量，目前规定一个结构体内部只能都是int的成员变量
            index->offset *= 4;
        }
        else if (base_ptr->u.NAME->type == TempType::STRUCT_PTR)
        {
            // 结构体数组 get element_ptr,偏置要乘上结构体大小
            assert(gep_stm->u.GEP->index->kind == OperandKind::ICONST);
            index->offset *= structLayout[base_ptr->u.NAME->structname];
        }
        else
        {
            assert(0);
        }
        as_list.push_back(AS_Adr(new AS_label(gep_stm->u.GEP->base_ptr->u.NAME->name->name), x3));
        as_list.push_back(AS_Binop(AS_binopkind::ADD_, x3, index, x3));
        as_list.push_back(AS_Mov(x3, dst));
    }
    else
    {
        if (base_ptr->u.TEMP->type == TempType::INT_PTR)
        {
            // int数组get element_ptr
            assert(gep_stm->u.GEP->index->kind == OperandKind::ICONST);
            index->offset *= 4;
        }
        else if (base_ptr->u.TEMP->type == TempType::STRUCT_TEMP)
        {
            // 获取结构体的某个成员变量，目前规定一个结构体内部只能都是int的成员变量
            index->offset *= 4;
        }
        else if (base_ptr->u.TEMP->type == TempType::STRUCT_PTR && base_ptr->u.TEMP->len == 0)
        {
            // 获取结构体的某个成员变量，目前规定一个结构体内部只能都是int的成员变量
            index->offset *= 4;
        }
        else if (base_ptr->u.TEMP->type == TempType::STRUCT_PTR)
        {
            // 结构体数组 get element_ptr,偏置要乘上结构体大小
            assert(gep_stm->u.GEP->index->kind == OperandKind::ICONST);
            index->offset *= structLayout[base_ptr->u.TEMP->structname];
        }
        else
        {
            assert(0);
        }
        // 全局变量进一步GEP
        if (spOffsetMap.find(base_ptr->u.TEMP->num) == spOffsetMap.end())
        {
            // TODO：这个地方应该加多少？
            as_list.push_back(AS_Binop(AS_binopkind::ADD_, AS_Reg_Operand(base_ptr), index, x3));
            as_list.push_back(AS_Mov(x3, dst));
        }
        // 栈上的GEP，在spOffsetMap中记录
        else
        {
            int origin_offset = spOffsetMap[base_ptr->u.TEMP->num];
            int new_offset = origin_offset + index->offset;
            spOffsetMap[gep_stm->u.GEP->new_ptr->u.TEMP->num] = new_offset;
        }
    }
}

void llvm2asmStm(list<AS_stm *> &as_list, L_stm &stm)
{

    if (!alloc_frame && stm.type != L_StmKind::T_LABEL)
    {
        new_frame(as_list);
        alloc_frame = true;
    }

    switch (stm.type)
    {
    case L_StmKind::T_BINOP:
    {
        llvm2asmBinop(as_list, &stm);
        break;
    }
    case L_StmKind::T_LOAD:
    {
        llvm2asmLoad(as_list, &stm);
        break;
    }
    case L_StmKind::T_STORE:
    {
        llvm2asmStore(as_list, &stm);
        break;
    }
    case L_StmKind::T_LABEL:
    {
        auto label = new AS_label(stm.u.LABEL->label->name);
        as_list.push_back(AS_Label(label));
        break;
    }
    case L_StmKind::T_JUMP:
    {
        auto label = new AS_label(stm.u.JUMP->jump->name);
        as_list.push_back(AS_B(label));
        break;
    }
    case L_StmKind::T_CMP:
    {
        llvm2asmCmp(as_list, &stm);
        break;
    }
    case L_StmKind::T_CJUMP:
    {
        llvm2asmCJmp(as_list, &stm);
        break;
    }
    case L_StmKind::T_MOVE:
    {
        // Do nothing
        break;
    }
    case L_StmKind::T_CALL:
    {
        // Do nothing
        break;
    }
    case L_StmKind::T_VOID_CALL:
    {
        // Do nothing
        break;
    }
    case L_StmKind::T_RETURN:
    {
        llvm2asmRet(as_list, &stm);
        alloc_frame = false;
        break;
    }
    case L_StmKind::T_ALLOCA:
    {
        // Do nothing
        break;
    }
    case L_StmKind::T_GEP:
    {
        llvm2asmGep(as_list, &stm);
        break;
    }
    case L_StmKind::T_PHI:
    {
        // Do nothing
        break;
    }
    case L_StmKind::T_NULL:
    {
        // Do nothing
        break;
    }
    }
}

void allocReg(list<AS_stm *> &as_list)
{

    unordered_map<int, int> vregStart;
    unordered_map<int, int> vregEnd;
    auto setDef = [&](AS_reg *reg, int lineNo)
    {
        int regNo = reg->reg;
        if (regNo < 100)
            return;
        if (vregStart.find(regNo) == vregStart.end())
        {
            vregStart.insert({regNo, lineNo});
        }
    };
    auto setUse = [&](AS_reg *reg, int lineNo)
    {
        int regNo = reg->reg;
        if (regNo < 100)
            return;
        vregEnd.insert({regNo, lineNo});
    };
    int lineNo = 0;
    for (const auto &stm : as_list)
    {
        switch (stm->type)
        {
        case AS_stmkind::BINOP:
            setDef(stm->u.BINOP->dst, lineNo);
            setUse(stm->u.BINOP->left, lineNo);
            setUse(stm->u.BINOP->right, lineNo);
            break;
        case AS_stmkind::MOV:
            setDef(stm->u.MOV->dst, lineNo);
            setUse(stm->u.MOV->src, lineNo);
            break;
        case AS_stmkind::LDR:
            setDef(stm->u.LDR->dst, lineNo);
            setUse(stm->u.LDR->ptr, lineNo);
            break;
        case AS_stmkind::STR:
            setUse(stm->u.STR->src, lineNo);
            setUse(stm->u.STR->ptr, lineNo);
            break;
        case AS_stmkind::CMP:
            setUse(stm->u.CMP->left, lineNo);
            setUse(stm->u.CMP->right, lineNo);
            break;
        case AS_stmkind::ADR:
            setDef(stm->u.ADR->reg, lineNo);
            break;
        default:
            break;
        }
        lineNo += 1;
    }

    // workaround for undef vreg
    for (const auto &iter : vregEnd)
    {
        auto pos = vregStart.find(iter.first);
        if (pos == vregStart.end())
        {
            vregStart.insert(iter);
        }
    }

    /* cout<<"Live interval:\n";
    for (auto iter: vregStart){
        cout<<iter.first<<": ["<<iter.second<<", "<<vregEnd[iter.first]<<"]\n";
    } */

    // -1 invalid for allocation, 0 unallocated, >100 registerNo
    // x9-x15 x20-x28 is available
    vector<int> allocateRegs{9, 10, 11, 12, 13, 14, 15, 20, 21, 22, 23, 24, 25, 26, 27, 28};
    vector<int> allocateTable;
    unordered_map<int, int> v2pMapping;
    allocateTable.resize(32);
    for (int i = 0; i < 32; ++i)
    {
        allocateTable[i] = -1;
    }
    for (auto ind : allocateRegs)
    {
        allocateTable[ind] = 0;
    }

    auto get_mapping = [&](int regNo, int lineNo)
    {
        auto pos = v2pMapping.find(regNo);
        if (pos != v2pMapping.end())
            return pos->second;

        // find available reg
        for (int i = 0; i < 32; ++i)
        {
            int allocNo = allocateTable[i];
            if ((allocNo == 0) || (allocNo > 0 && vregEnd[allocNo] < lineNo))
            {
                v2pMapping[regNo] = i;
                allocateTable[i] = regNo;
                // cout<<regNo<<" -> "<<i<<"\n";
                return i;
            }
        }
        // throw runtime_error("allocate register fail");
    };

    auto vreg_map = [&](AS_reg *reg, int lineNo)
    {
        int regNo = reg->reg;
        if (regNo < 100)
            return;
        reg->reg = get_mapping(regNo, lineNo);
    };

    lineNo = 0;
    for (const auto &stm : as_list)
    {
        switch (stm->type)
        {
        case AS_stmkind::BINOP:
            vreg_map(stm->u.BINOP->dst, lineNo);
            vreg_map(stm->u.BINOP->left, lineNo);
            vreg_map(stm->u.BINOP->right, lineNo);
            break;
        case AS_stmkind::MOV:
            vreg_map(stm->u.MOV->dst, lineNo);
            vreg_map(stm->u.MOV->src, lineNo);
            break;
        case AS_stmkind::LDR:
            vreg_map(stm->u.LDR->dst, lineNo);
            vreg_map(stm->u.LDR->ptr, lineNo);
            break;
        case AS_stmkind::STR:
            vreg_map(stm->u.STR->src, lineNo);
            vreg_map(stm->u.STR->ptr, lineNo);
            break;
        case AS_stmkind::CMP:
            vreg_map(stm->u.CMP->left, lineNo);
            vreg_map(stm->u.CMP->right, lineNo);
            break;
        case AS_stmkind::ADR:
            vreg_map(stm->u.ADR->reg, lineNo);
            break;
        default:
            break;
        }
        lineNo += 1;
    }

    /* cout<<"regAlloc:\n";
    for (const auto& iter:v2pMapping){
        cout<<"x"<<iter.first<<" -> x"<<iter.second<<"\n";
    } */
}

AS_func *llvm2asmFunc(L_func &func)
{
    list<AS_stm *> stms;

    auto p = new AS_func(stms);
    auto func_label = new AS_label(func.name);
    p->stms.push_back(AS_Label(func_label));

    for (const auto &block : func.blocks)
    {
        for (const auto &instr : block->instrs)
        {
            llvm2asmStm(p->stms, *instr);
        }
    }
    free_frame(p->stms);
    allocReg(p->stms);

    return p;
}

void llvm2asmDecl(vector<AS_decl *> &decls, L_def &def)
{
    switch (def.kind)
    {
    case L_DefKind::GLOBAL:
    {
        return;
    }
    case L_DefKind::FUNC:
    {
        AS_decl *decl = new AS_decl(def.u.FUNC->name);
        decls.push_back(decl);
        break;
    }
    case L_DefKind::SRT:
    {
        return;
    }
    }
}

void llvm2asmGlobal(vector<AS_global *> &globals, L_def &def)
{
    switch (def.kind)
    {
    case L_DefKind::GLOBAL:
    {
        auto label = new AS_label(def.u.GLOBAL->name);
        int init = 0, len;
        if (def.u.GLOBAL->def.kind == TempType::INT_TEMP)
        {
            init = def.u.GLOBAL->init[0];
            len = 4;
        }
        else if (def.u.GLOBAL->def.kind == TempType::INT_PTR)
        {
            len = 4 * def.u.GLOBAL->def.len;
        }
        else if (def.u.GLOBAL->def.kind == TempType::STRUCT_TEMP)
        {
            len = structLayout[def.u.GLOBAL->def.structname];
        }
        else if (def.u.GLOBAL->def.kind == TempType::STRUCT_PTR)
        {
            len = structLayout[def.u.GLOBAL->def.structname] * def.u.GLOBAL->def.len;
        }
        else
        {
            assert(0);
        }
        globals.push_back(new AS_global(label, init, len));

        break;
    }
    case L_DefKind::FUNC:
    {
        return;
    }
    case L_DefKind::SRT:
    {
        return;
    }
    }
}

AS_prog *llvm2asm(L_prog &prog)
{
    std::vector<AS_global *> globals;
    std::vector<AS_decl *> decls;
    std::vector<AS_func *> func_list;

    auto as_prog = new AS_prog(globals, decls, func_list);

    structLayoutInit(prog.defs);

    // translate function definition
    // 处理仅声明的函数
    for (const auto &def : prog.defs)
    {
        llvm2asmDecl(as_prog->decls, *def);
    }
    // 处理仅定义的函数
    // 如果文件中出现一个函数声明+定义，这里会重复
    for (const auto &func : prog.funcs)
    {
        bool invector = false;
        for (auto old_decl : as_prog->decls)
        {
            if (old_decl->name == func->name)
            {
                invector = true;
                break;
            }
        }
        if (invector)
            continue;
        AS_decl *decl = new AS_decl(func->name);
        as_prog->decls.push_back(decl);
    }

    // translate global data
    for (const auto &def : prog.defs)
    {
        llvm2asmGlobal(as_prog->globals, *def);
    }

    // translate each llvm function
    for (const auto &func : prog.funcs)
    {
        set_stack(*func);
        as_prog->funcs.push_back(llvm2asmFunc(*func));
    }

    return as_prog;
}