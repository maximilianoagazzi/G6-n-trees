#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    ntn* tree1 = n_tree_new();
    printf("El arbol tree 1 por profundidad es: ");
    print_depth(tree1, print_int);
    printf("\n\nEl arbol tree 1 por anchura es: ");
    print_breath(tree1, print_int);
    printf("\n\n");
    //Ejercicios 1 a-b-c-d

    int cant = cant_nodos(tree1);
    printf("La cantidad de nodos de tree 1 es: %d\n", cant);
    //Ejercicio 1e

    int degree = tree_degree(tree1);
    printf("\nEl grado de tree 1 es: %d\n", degree);
    //Ejercicio 1f

    int same = same_degree(tree1);
    if(same == 1) {
        printf("\nEl arbol tree 1 tiene el mismo grado en todos sus nodos\n");
    } else {
        printf("\nEl arbol tree 1 no tiene el mismo grado en todos sus nodos\n");
    }
    //Ejercicio 1g

    int hight = tree_hight(tree1);
    printf("\nLa altura de tree 1 es: %d\n", hight);
    //Ejercicio 1h

    int data = 10;
    void* value = &data;
    ntn* res = search_value(tree1, value, cmp_int);
    printf("\nEl sub arbol que tiene como raiz %d es: ", data);
    print_depth(res, print_int);
    printf("\n\n");
    //Ejercicio 2a

	int depth = node_depth(tree1, res, cmp_int);
	printf("La profundidad del nodo con valor %d en tree 1 es de: %d\n", data, depth);
	//Ejercicio 2b

    destroy_tree(&tree1, 1);
    //Destruye el arbol
    return 0;
}

void* copy_elem(void* elem)  //Auxiliar
{
    void* copy = malloc(sizeof(int));
    *(int*)copy = *(int*)elem;
    return copy;
}

void print_int(void* data)  //Auxiliar
{
    printf("%d  ", *(int*)data);
}

int cmp_int(void* a, void* b)  //Auxiliar
{
    int na = *(int*)a;
    int nb = *(int*)b;
    return na - nb;
}

ntn* n_tree_new()  //Arbol de prueba 1
{
    int data = 5;
    void* value = &data;
    ntn* root = ntn_new(copy_elem(value));
    //crear la raiz

    data = 10;
    ntn* child1 = ntn_new(copy_elem(value));
    data = 8;
    ntn* child2 = ntn_new(copy_elem(value));
    data = 7;
    ntn* child3 = ntn_new(copy_elem(value));
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    //crear hijos de la raiz

    data = 4;
    ntn* grandson1 = ntn_new(copy_elem(value));
    data = 9;
    ntn* grandson2 = ntn_new(copy_elem(value));
    data = 2;
    ntn* grandson3 = ntn_new(copy_elem(value));
    data = 15;
    ntn* grandson4 = ntn_new(copy_elem(value));
    add_child(child1, grandson1);
    add_child(child1, grandson2);
    add_child(child1, grandson3);
    add_child(child1, grandson4);
    //Crear los nietos del primer hijo

    data = 3;
    ntn* grandson5 = ntn_new(copy_elem(value));
    data = 11;
    ntn* grandson6 = ntn_new(copy_elem(value));
    add_child(child3, grandson5);
    add_child(child3, grandson6);
    //Crear los nietos del tercer hijo

    data = 20;
    ntn* ggson1 = ntn_new(copy_elem(value));
    add_child(grandson1, ggson1);
    
    return root;
}

int same_degree(ntn* tree)  //Ejercicio 1g
{
    if(tree == NULL) return 1;

    int s = 1;
    if(tree->child != NULL) {
        int degree = tree_degree(tree);
        ntlist* child = tree->child;
        while(child != NULL && s == 1) {
            if(child->node->child != NULL && degree != tree_degree(child->node)) {
                s = 0;
            }
            if (same_degree(child->node) == 0) {
                s = 0;
            }
            child = child->next;
        }
    }

    return s;
}

