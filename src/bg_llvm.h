#ifndef __BG_LLVM
#define __BG_LLVM

#include <unordered_map>
#include <unordered_set>

#include "graph.hpp"
#include "llvm_ir.h"
#include "temp.h"

GRAPH::Graph<LLVMIR::L_block*>& Create_bg(std::list<LLVMIR::L_block*>& bl);
GRAPH::Graph<LLVMIR::L_block*>& Bg_graph();
std::unordered_map<Temp_label*, LLVMIR::L_block*>& Bg_block_env();
void SingleSourceGraph(GRAPH::Node<LLVMIR::L_block*>* r,
                       GRAPH::Graph<LLVMIR::L_block*>& bg, LLVMIR::L_func* fun,
                       std::unordered_set<LLVMIR::L_block*>& node_deprecated);
void Show_graph(FILE* out, GRAPH::Graph<LLVMIR::L_block*>& bg);
#endif