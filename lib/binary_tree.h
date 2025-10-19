#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct _btn {
    void* data;
    struct _btn* left;
    struct _btn* right;
} btn;

btn* new_btn(void* data);
int is_leaf(btn* node);
void pre_order(btn* n, void (*dod)(void* data, void* ctx), void* ctx);
void post_order(btn* n, void (*dod)(void* data, void* ctx), void* ctx);
void in_order(btn* n, void (*dod)(void* data, void* ctx), void* ctx);
btn** find_BST(btn** node, void* data, int (*cmp)(void* a, void* b));
int add_BST(btn** root, btn* new_node, int (*cmp)(void* a, void* b));
btn* rmv_BST(btn** node, void* data, int (*cmp)(void* a, void* b));
void destroy_btree(btn** root, char dinamic);
int cant_btn(btn* root);
int cant_btn_aux(btn* root, int cant);
int depth_btn(btn* root, btn* node, int cmp(void* a, void* b));
int maxi(int a, int b);
int height_btn(btn* root);

#endif