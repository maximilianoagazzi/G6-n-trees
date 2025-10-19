#include <stdio.h>
#include <stdlib.h>
#include "n_tree.h"
#include "../include/queue.h"

void print_depth(ntn* node, void print_elem(void* ))  //Imprime el arbol en profundidad
{
    if(node == NULL) return;

    ntlist* aux = node->child;
    print_elem(node->value);
    while(aux != NULL) {
        print_depth(aux->node, print_elem);
        aux = aux->next;
    }
}

void print_breath(ntn* node, void print_elem(void* ))  //Imprime el arbol en anchura
{
    if(node == NULL) return;

    queue* q = queue_new();
    enqueue(q, node);
    while(!queue_is_empty(q)) {
        node = (ntn* )dequeue(q);
        print_elem(node->value);
        ntlist* aux = node->child;
        while(aux != NULL) {
            enqueue(q, aux->node);
            aux = aux->next;
        }
    }
    queue_free(&q, 0);
}

ntn* ntn_new(void* value)  //Crea un nuevo nodo de arbol
{
    ntn* n = (ntn* )malloc(sizeof(ntn));
    if(n != NULL) {
        n->value = value;
        n->child = NULL;
    }
    return n;
}

ntlist* ntl_new(ntn* node)  //Crea un nuevo nodo de lista
{
    ntlist* ntl = (ntlist* )malloc(sizeof(ntlist));
    if(ntl != NULL) {
        ntl->node = node;
        ntl->next = NULL;
    }
    return ntl;
}

int ntl_insert_head(ntlist** nodelist, ntlist* newnodelist)  //Inserta al comienzo de la sublista
{
    if(newnodelist == NULL) return -1;

    newnodelist->next = *nodelist;
    *nodelist = newnodelist;

    return 1;
}

int ntl_insert_last(ntlist* nodelist, ntlist* newnodelist)  //Inserta al final de la sublista
{
    if(newnodelist == NULL) return -1;

    ntlist** aux = &nodelist;
    while(*aux != NULL) {
        aux = &((*aux)->next);
    }
    *aux = newnodelist;

    return 1;
}

int add_child(ntn* parent, ntn* new_child)  //Añade un hijo directo como ultimo al arbol
{
    if(parent == NULL) return -1;

    if(parent->child == NULL) {
        parent->child = ntl_new(new_child);
    } else {
        ntl_insert_last(parent->child, ntl_new(new_child));
    }

    return 1;
}

int cant_nodos(ntn* tree)  //Devuelve la cantidad de nodos de un arbol
{
    if(tree == NULL) return 0;

    int cant = 1;
    ntlist* child = tree->child;

    while(child != NULL) {
        cant += cant_nodos(child->node);
        child = child->next;
    } 

    return cant;
}

int tree_degree(ntn* tree)  //Devuelve el grado del arbol
{
    if(tree == NULL) return -1;

    int degree = cant_child(tree);

    ntlist* child = tree->child;
    while(child != NULL) {
        degree = maxin(degree, tree_degree(child->node));
        child = child->next;
    }

    return degree;
}

int cant_child(ntn* tree)  //Devuelve la cantidad de hijos directos
{
    if(tree == NULL) return -1;

    int cant = 0;
    ntlist* aux = tree->child;
    while(aux != NULL) {
        cant++;
        aux = aux->next;
    }

    return cant;
}

int maxin(int a, int b)  //Auxiliar
{
    int r = a;
    if(a < b)
        r = b;

    return r;
}

int tree_hight(ntn* tree)  //Devuelve la altura del arbol
{
    if(tree == NULL) return -1;

    int hight = 0;
    ntlist* child = tree->child;
    if(child != NULL) {
        int aux = hight;
        while(child != NULL) {
            aux = maxin(aux, tree_hight(child->node));
            child = child->next;
        }
        hight = 1 + aux;
    }

    return hight;
}

void destroy_tree(ntn** tree, int dinamic)  //Destruye el arbol
{
    if(*tree == NULL) return;

    ntlist* child = (*tree)->child;
    ntlist* aux;
    while(child != NULL) {
        destroy_tree(&(child->node), dinamic);
        aux = child->next;
        free(child);
        child = aux;
    }
    if(dinamic == 1 && (*tree)->value != NULL) {
        free((*tree)->value);
    }

    free(*tree);
    *tree = NULL;
}

ntn* search_value(ntn* tree, void* value, int cmp(void* a, void* b))  //Devuelve un nodo que tenga value
{
    if(tree == NULL) return NULL;

    ntn* r = NULL;
    if(cmp(value, tree->value) == 0) {
        r = tree;
    } else {
        ntlist* child = tree->child;
        while(child != NULL && r == NULL) {
            if(cmp(value, child->node->value) == 0) {
                r = child->node;
            } else {
                r = search_value(child->node, value, cmp);
            }
            child = child->next;
        }
    }

    return r;
}

int node_depth(ntn* root, ntn* node, int cmp(void* a, void* b))  //Devuelve la profundidad de node en root
{
    if(root == NULL || node == NULL) return -1;

	int r =  -1;
	if (cmp(root->value, node->value) == 0) {
        r = 0;
	}

	ntlist* child = root->child;
    while (child != NULL && r == -1) {
        int d = node_depth(child->node, node, cmp);
        if (d != -1) {
            r = d + 1;
		}
        child = child->next;
    }

    return r;
}