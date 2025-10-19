#ifndef HEADER_H
#define HEADER_H
#include "lib/n_tree.h"

void* copy_elem(void* elem);
void print_int(void* data);
int cmp_int(void* a, void* b);
ntn* n_tree_new();
int same_degree(ntn* tree);

#endif