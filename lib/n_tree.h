#ifndef N_TREE_H
#define N_TREE_H

typedef struct _ntn ntn;

typedef struct _ntlist {
    ntn* node;
    struct _ntlist* next;
} ntlist;

typedef struct _ntn {
    void* value;
    ntlist* child;
} ntn;

void print_depth(ntn* node, void print_elem(void* , void* ctx), void* ctx);
void print_breath(ntn* node, void print_elem(void* , void* ctx), void* ctx);
ntn* ntn_new(void* value);
ntlist* ntl_new(ntn* node);
int ntl_insert_head(ntlist** nodelist, ntlist* newnodelist);
int ntl_insert_last(ntlist* nodelist, ntlist* newnodelist);
int add_child(ntn* parent, ntn* new_child);
int cant_nodos(ntn* tree);
int tree_degree(ntn* tree);
int cant_child(ntn* tree);
int maxin(int a, int b);
int tree_hight(ntn* tree);
void destroy_tree(ntn** tree, int dinamic);
ntn** search_node(ntn** tree, void* value, int cmp(void* a, void* b));
int node_depth(ntn* root, ntn* node, int cmp(void* a, void* b));

#endif