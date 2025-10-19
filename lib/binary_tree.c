#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

btn* new_btn(void* data)  //Crea un nodo
{
    btn* n = (btn* )malloc(sizeof(btn));
    if(n != NULL) {
        n->data = data;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void pre_order(btn* n, void (*dod)(void* data, void* ctx), void* ctx)  //Recorre en pre orden
{
    if(n != NULL) {
        dod(n->data, ctx);
        pre_order(n->left, dod, ctx);
        pre_order(n->right, dod, ctx);
    }
}

void post_order(btn* n, void (*dod)(void* data, void* ctx), void* ctx)  //Recorre en post orden
{
    if(n != NULL) {
        post_order(n->left, dod, ctx);
        post_order(n->right, dod, ctx);
        dod(n->data, ctx);
    }
}

void in_order(btn* n, void (*dod)(void* data, void* ctx), void* ctx)  //Recorre en in orden
{
    if(n != NULL) {
        in_order(n->left, dod, ctx);
        dod(n->data, ctx);
        in_order(n->right, dod, ctx);
    }
}

btn** find_BST(btn** node, void* data, int (*cmp)(void* a, void* b))  //Encuentra el nodo con el valor, devuelve donde incertar el valor si no lo encuentra (ABB)
{
    while(*node != NULL && cmp((*node)->data, data) != 0) {
        if(cmp(data, (*node)->data) < 0)
            node = &(*node)->left;
        else
            node = &(*node)->right;
    }
    return node;
}

int add_BST(btn** root, btn* new_node, int (*cmp)(void* a, void* b))  //agrega un nodo con un valor si ese valor no se encuentra (ABB) 
{
    int res = 0;
    if(new_node != NULL) {
        btn** found = find_BST(root, new_node->data, cmp);
        if(*found == NULL) {
            *found = new_node;
            res = 1;
        }
    }
    return res;
}

btn* rmv_BST(btn** node, void* data, int (*cmp)(void* a, void* b))  //Remueve en nodo con un valor (ABB)
{
    btn* res = NULL;
    btn** found = find_BST(node, data, cmp);
    if(*found != NULL) {
        res = *found;
        add_BST(&(*found)->right, (*found)->left, cmp);
        *found = res->right;
        res->left = NULL;
        res->right = NULL;
    }
    return res;
}

void destroy_btree(btn** root, char dinamic)  //Elimina el nodo y sus hijos
{
    if(*root == NULL) return;

    destroy_btree(&((*root)->left), dinamic);
    destroy_btree(&((*root)->right), dinamic);

    if(dinamic == 1) {
        free((*root)->data);
    }
    free(*root);
    *root = NULL;
}

int cant_btn(btn* root)  //Retorna la cantidad de nodos de una arbol
{
    return cant_btn_aux(root, 0);
}

int cant_btn_aux(btn* root, int cant)  //Auxiliar
{
    if(root == NULL) return cant;

    return 1 + cant_btn_aux(root->left, cant) + cant_btn_aux(root->right, cant);
}

int is_leaf(btn* node) //Devuelve 1 si el nodo es una hoja y 0 si no
{
    if(node == NULL) return -1;

    int r = 0;
    if(node->left == NULL && node->right == NULL) {
        r = 1;
    }
    return r;
}

int depth_btn(btn* root, btn* node, int cmp(void* a, void* b))  //Devuelve la profundidad de un nodo con respecto a una raiz si ese nodo esta en el arbol
{
    if(root == NULL || node == NULL) return -1;

    int p = 0;
    if(cmp(root->data, node->data) != 0) {
        int left_depth = depth_btn(root->left, node, cmp);
        int right_depth = depth_btn(root->right, node, cmp);

        if(left_depth >= 0) {
            p = 1 + left_depth;
        } else if (right_depth >= 0) {
            p = 1 + right_depth;
        } else {
            p = -1;
        }
    }

    return p;
}

int height_btn(btn* root) //Devuelve la altura de un arbol
{
    int r = -1;
    if(root != NULL) {
        r = 1 + maxi(height_btn(root->left), height_btn(root->right));
    }
    return r;
}

int maxi(int a, int b) //Auxiliar
{
    int r;
    if(a >= b) {
        r = a;
    } else {
        r = b;
    }
    return r;
}