#ifndef __SSA
#define __SSA

#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "graph.hpp"
#include "llvm_ir.h"
#include "temp.h"

LLVMIR::L_prog* SSA(LLVMIR::L_prog* prog, FILE*, FILE*, FILE*, FILE*);
void combine_addr(LLVMIR::L_func* fun);
void mem2reg(LLVMIR::L_func* fun);

void Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg);
void tree_Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg);
void computeDF(GRAPH::Graph<LLVMIR::L_block*>& bg,
               GRAPH::Node<LLVMIR::L_block*>* r);
void Place_phi_fu(GRAPH::Graph<LLVMIR::L_block*>& bg, LLVMIR::L_func* fun);
void Rename(GRAPH::Graph<LLVMIR::L_block*>& bg);
void printf_domi(FILE*);
void printf_D_tree(FILE*);
void comput_reverse_graph(GRAPH::Graph<LLVMIR::L_block*>& bg);
void printf_DF(FILE*);
#endif