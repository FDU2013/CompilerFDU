#include "printASM.h"
#include "asm_arm.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace ASM;

void ASM::printAS_global(std::ostream &os, ASM::AS_global *global)
{
    os << global->label->name << ":" << endl;
    if (global->len == 4)
    {
        os << "\t.word\t" << global->init << endl;
    }
    else
    {
        os << "\t.zero\t" << global->len << endl;
    }
}

void ASM::printAS_decl(std::ostream &os, ASM::AS_decl *decl)
{
    os << ".global " << decl->name << endl;
}

void ASM::printAS_stm(std::ostream &os, AS_stm *stm)
{
    // Fixme: add here
    switch (stm->type)
    {

    case AS_stmkind::BINOP:
    {
        os << "\t";
        switch (stm->u.BINOP->op)
        {

        case AS_binopkind::ADD_:
        {
            os << "add\t";
        }
        break;
        case AS_binopkind::SUB_:
        {
            os << "sub\t";
        }
        break;
        case AS_binopkind::MUL_:
        {
            os << "mul\t";
        }
        break;
        case AS_binopkind::SDIV_:
        {
            os << "sdiv\t";
        }
        break;

        default:
        {
            assert(0);
        }
        break;
        }
        printAS_reg(os, stm->u.BINOP->dst);
        os << ", ";
        printAS_reg(os, stm->u.BINOP->left);
        os << ", ";
        printAS_reg(os, stm->u.BINOP->right);
        os << endl;
        break;
    }
    case AS_stmkind::MOV:
    {
        os << "\tmov\t";
        printAS_reg(os, stm->u.MOV->dst);
        os << ", ";
        printAS_reg(os, stm->u.MOV->src);
        os << endl;
        break;
    }
    case AS_stmkind::LDR:
    {
        os << "\tldr\t";
        printAS_reg(os, stm->u.LDR->dst);
        os << ", [";
        printAS_reg(os, stm->u.LDR->ptr);
        os << "]" << endl;
        break;
    }
    case AS_stmkind::STR:
    {
        os << "\tstr\t";
        printAS_reg(os, stm->u.STR->src);
        os << ", [";
        printAS_reg(os, stm->u.STR->ptr);
        os << "]" << endl;
        break;
    }
    case AS_stmkind::LABEL:
    {
        os << stm->u.LABEL->name << ":";
        os << endl;
        break;
    }
    case AS_stmkind::B:
    {
        os << "\tb\t";
        os << stm->u.B->jump->name;
        os << endl;
        break;
    }
    case AS_stmkind::BCOND:
    {
        switch (stm->u.BCOND->op)
        {
        case AS_relopkind::EQ_:
        {
            os << "\tb.eq\t";
        }
        break;
        case AS_relopkind::NE_:
        {
            os << "\tb.ne\t";
        }
        break;
        case AS_relopkind::LE_:
        {
            os << "\tb.le\t";
        }
        break;
        case AS_relopkind::LT_:
        {
            os << "\tb.lt\t";
        }
        break;
        case AS_relopkind::GE_:
        {
            os << "\tb.ge\t";
        }
        break;
        case AS_relopkind::GT_:
        {
            os << "\tb.gt\t";
        }
        break;

        default:
        {
            assert(0);
        }
        break;
        }
        os << stm->u.BCOND->jump->name;
        os << endl;
        break;
    }
    case AS_stmkind::BL:
    {
        // 一般用于调用子程序，我们这次不会用到
        assert(0);
        break;
    }
    case AS_stmkind::CMP:
    {
        os << "\tcmp\t";
        printAS_reg(os, stm->u.CMP->left);
        os << ", ";
        printAS_reg(os, stm->u.CMP->right);
        os << endl;
        break;
    }
    case AS_stmkind::RET:
    {
        os << "\tret\t" << endl;
        break;
    }
    case AS_stmkind::ADR:
    {
        os << "\tadr\t";
        printAS_reg(os, stm->u.ADR->reg);
        os << ", ";
        os << stm->u.ADR->label->name;
        os << endl;
        break;
    }
    default:
    {
        assert(0);
    }
    }
}

void ASM::printAS_reg(std::ostream &os, AS_reg *reg)
{
    if (reg->reg == -3)
    {
        os << "#" << reg->offset;
    }
    else if (reg->reg == -1 && reg->offset != -1)
    {
        os << "sp, #" << reg->offset;
    }
    else if (reg->reg == -1 && reg->offset == -1)
    {
        os << "sp";
    }
    else
    {
        os << "x" << reg->reg;
    }
}

void ASM::printAS_func(std::ostream &os, AS_func *func)
{
    for (const auto &stm : func->stms)
    {
        printAS_stm(os, stm);
    }
}

void ASM::printAS_prog(std::ostream &os, AS_prog *prog)
{

    os << ".section .data\n";
    for (const auto &global : prog->globals)
    {
        printAS_global(os, global);
    }

    os << ".section .text\n";

    for (const auto &decl : prog->decls)
    {
        printAS_decl(os, decl);
    }

    for (const auto &func : prog->funcs)
    {
        printAS_func(os, func);
    }
}