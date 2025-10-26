#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    int count = 0;
    void* ctx = &count;
    ntn* tree1 = n_tree_new();
    printf("El arbol tree 1 por profundidad es: ");
    print_depth(tree1, print_int, ctx);
    printf("\n\nEl arbol tree 1 por anchura es: ");
    print_breath(tree1, print_int, ctx);
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

    int hight = tree_height(tree1);
    printf("\nLa altura de tree 1 es: %d\n", hight);
    //Ejercicio 1h

    int data = 10;
    void* value = &data;
    ntn* res = *search_node(&tree1, value, cmp_int);
    printf("\nEl sub arbol que tiene como raiz %d es: ", data);
    print_depth(res, print_int, ctx);
    printf("\n\n");
    //Ejercicio 2a

	int depth = node_depth(tree1, res, cmp_int);
	printf("La profundidad del nodo con valor %d en tree 1 es de: %d\n", data, depth);
	//Ejercicio 2b

    data = 11;
    printf("\nEl camino hacia la raiz de tree1 desde %d es ", data);
    print_path_to_root(tree1, value, cmp_int, print_path_int);
    printf("\n");
    //Ejercicio 2c

    count = 0;
    ntn* tree2 = n_tree_new_cargo();
    printf("\nEl arbol tree2 por profundidad es: \n");
    print_depth(tree2, print_persona, ctx);
    //Ejercicio 3a

    char* name = "Raimunda Gates";
    printf("\nEl camino hacia la raiz de tree2 desde %s es ", name);
    print_path_to_root(tree2, name, cmp_persona, print_path_persona);
    printf("\n");
    //Ejercicio 3b

    list* l = lista_por_nivel(tree2, 1);
    printf("\nLa lista de personas en el nivel 1 es: \n");
    list_print(l, print_persona);
    //Ejercicio 3d

    ntn* tree3 = n_tree_new2();
    //Ejercicio 4a

    count = 0;
    printf("\nEl arbol tree3 por profundidad es: \n");
    print_depth(tree3, print_int_depth, ctx);
    printf("\nEl arbol tree3 por anchura es: \n");
    print_breath(tree3, print_int_breath, ctx);
    printf("\n");
    //Ejercicio 4b

    data = 10;
    ntn* removed = remove_any_value(&tree3, value, cmp_int);
    printf("\nEl arbol tree3 luego de remover el nodo %d es: \n", data);
    print_breath(tree3, print_int_breath, ctx);
    printf("\n");
    //Ejercicio 4c

    max_n_degree(tree3, 3);
    printf("\nEl arbol tree3 luego de limitar su grado a 3 es: \n");
    print_breath(tree3, print_int_breath, ctx);
    printf("\n");
    //Ejercicio 4d

    ntn* copy = clone(tree3);
    int equal = are_equal_trees(tree3, copy, cmp_int);
    if(equal == 1) {
        printf("\nEl arbol tree3 y el arbol copy son iguales\n");
    } else {
        printf("\nEl arbol tree3 y el arbol copy no son iguales\n");
    }
    //Ejercicio 5

    int dataA = 45;
    int dataB = 35;
    void* elemA = &dataA;
    void* elemB = &dataB;
    printf("\nEl camino desde %d hasta %d en tree3 es: ", dataA, dataB);
    print_path_A_to_B(tree3, elemA, elemB, cmp_int, print_path_int);
    printf("\n");
    //Ejercicio 7

    int balanced = is_balanced(tree3);
    if(balanced == 1) {
        printf("\nEl arbol tree3 esta balanceado\n");
    } else {
        printf("\nEl arbol tree3 no esta balanceado\n");
    }
    //Ejercicio 8

    int symetric = is_symetric(tree3, cmp_int);
    if(symetric == 1) {
        printf("\nEl arbol tree3 es simetrico\n");
    } else {
        printf("\nEl arbol tree3 no es simetrico\n");
    }
    //Ejercicio 9

    destroy_tree(&tree1, 1);
    destroy_personas(tree2);
    destroy_tree(&tree2, 1);
    destroy_tree(&tree3, 1);
    destroy_tree(&removed, 1);
    destroy_tree(&copy, 1);
    //Destruye los arboles

    destroy_lista_personas(l);
    list_free(&l, 1);
    //Destruye las listas

    return 0;
}

void* copy_elem(void* elem)  //Auxiliar
{
    void* copy = malloc(sizeof(int));
    *(int*)copy = *(int*)elem;
    return copy;
}

void print_int(void* data, void* ctx)  //Auxiliar
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
    //Crear los hijos del primer hijo

    data = 3;
    ntn* grandson5 = ntn_new(copy_elem(value));
    data = 11;
    ntn* grandson6 = ntn_new(copy_elem(value));
    add_child(child3, grandson5);
    add_child(child3, grandson6);
    //Crear los hijos del tercer hijo

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

void print_path_to_root(ntn* root, void* value, int cmp(void* , void* ), void print(void* ))  //Ejercicio 2c
{
    if(root == NULL) return;

    stack* s = stack_new();
    if(s != NULL) {
        path(root, value, s, cmp);
        inverted_stack(s);
        print_stack(s, print);
        stack_free(&s, 0);
    }
}

void path(ntn* root, void* value, stack* s, int cmp(void* , void* ))  //Ejercicio 2c
{
    if(root != NULL) {
        if(cmp(root->value, value) == 0) {
            push(s, root->value);
        } else {
            ntlist* l = root->child;
            while(l != NULL && stack_is_empty(s) == 1) {
                path(l->node, value, s, cmp);
                l = l->next;
            }
            if(stack_is_empty(s) != 1) {
                push(s, root->value);
            }
        }
    }
}

void inverted_stack(stack* s)  //Ejercicio 2c
{
    if(s == NULL) return;

    queue* q = queue_new();
    if(q != NULL) {
        while(!stack_is_empty(s)) {
            enqueue(q, pop(s));
        }

        while(!queue_is_empty(q)) {
            push(s, dequeue(q));
        }
    }
    queue_free(&q, 0);
}

void print_stack(stack* s, void print(void* ))  //Ejercicio 2c
{
    if(s == NULL) return;

    stack* aux = stack_new();
    if(aux != NULL) {
        void* elem;
        while(stack_is_empty(s) != 1) {
            elem = pop(s);
            print(elem);
            push(aux, elem);
        }
        while(stack_is_empty(aux) != 1) {
            push(s, pop(aux));
        }
        stack_free(&aux, 0);
    }
}

void print_path_int(void* elem)  //Ejercicio 2c
{
    if(elem == NULL) return;

    printf("-->%d ", *(int*)elem);
}

ntn* n_tree_new_cargo()  //Ejercicio 3a
{
    persona* gerente = persona_new("Gerente", "Ariel Perez");
    ntn* root = ntn_new(gerente);
    //Crear al gerente

    persona* jefe1 = persona_new("Director de administracion", "Antonio Emerson");
    ntn* j1 = ntn_new(jefe1);
    persona* jefe2 = persona_new("Director de produccion", "Josefa Lake");
    ntn* j2 = ntn_new(jefe2);
    persona* jefe3 = persona_new("Director comercial", "Arturo Palmer");
    ntn* j3 = ntn_new(jefe3);
    add_child(root, j1);
    add_child(root, j2);
    add_child(root, j3);
    //Crear los directores

    persona* empleado1 = persona_new("Empleado", "Andrea Heras");
    ntn* e1 = ntn_new(empleado1);
    persona* empleado2 = persona_new("Empleado", "Clotilde Schwarzkopf");
    ntn* e2 = ntn_new(empleado2);
    add_child(j1, e1);
    add_child(j1, e2);
    //Crear los empleados del director de administracion

    persona* empleado3 = persona_new("Empleado", "Raimunda Gates");
    ntn* e3 = ntn_new(empleado3);
    add_child(j2, e3);
    //Crear el empleado del director de produccion

    persona* empleado4 = persona_new("Empleado", "Estibaliz Bacon");
    ntn* e4 = ntn_new(empleado4);
    persona* empleado5 = persona_new("Empleado", "Luis Hidalgo");
    ntn* e5 = ntn_new(empleado5);
    add_child(j3, e4);
    add_child(j3, e5);
    //Crear los empleados del director comercial

    return root;
}

persona* persona_new(char* cargo, char* nombre)  //Ejercicio 3a
{
    persona* p = (persona*)malloc(sizeof(persona));

    if(p != NULL) {
        p->cargo = (char*)malloc(sizeof(char)*(strlen(cargo) + 1));
        strcpy(p->cargo, cargo);

        p->nombre = (char*)malloc(sizeof(char)*(strlen(nombre) + 1));
        strcpy(p->nombre, nombre);
    }

    return p;
}

void print_persona(void* data, void* ctx) //Ejercicio 3a
{
    if(data == NULL) return;

    persona* p = (persona*)data;
    int depth = 0;
    if(ctx != NULL) {
        depth = *(int*)ctx;
    }

    for(int i=0; i<depth; i++) {
        printf("  ");
    }
    printf("Cargo: %s, Nombre: %s\n", p->cargo, p->nombre);
}

void destroy_personas(ntn* root) //Ejercicio 3a
{
    if(root == NULL) return;

    persona* p = (persona*)root->value;
    if(p != NULL) {
        free(p->cargo);
        free(p->nombre);
        p->cargo == NULL;
        p->nombre == NULL;
    }

    ntlist* child = root->child;
    while(child != NULL) {
        destroy_personas(child->node);
        child = child->next;
    }
}

int cmp_persona(void* a, void* b)  //Ejercicio 3b
{
    persona* pa = (persona*)a;
    char* pb = (char*)b;

    return strcmp(pa->nombre, pb);
}

void print_path_persona(void* elem)  //Ejercicio 3b
{
    if(elem == NULL) return;

    persona* p = (persona*)elem;
    printf("-->%s ", p->nombre);
}

list* lista_por_nivel(ntn* tree, int nivel)  //Ejercicio 3d
{
    if(tree == NULL || nivel < 0) return NULL;
    
    list* l = list_create();
    if(l != NULL) {
        queue* q = queue_new();
        enqueue(q, tree);
        int current_level = 0;
        while(!queue_is_empty(q) && current_level <= nivel) {
            int level_size = queue_length(q);
            for(int i=0; i<level_size; i++) {
                ntn* node = (ntn*)dequeue(q);
                if(current_level == nivel) {
                    list_append(l, copy_elem_persona(node->value));
                }

                ntlist* aux = node->child;
                while(aux != NULL) {
                    enqueue(q, aux->node);
                    aux = aux->next;
                }
            }
            current_level++;
        }
        queue_free(&q, 0);
    }

    return l;
}

void* copy_elem_persona(void* elem)  //Ejercicio 3d
{
    if(elem == NULL) return NULL;

    persona* p = (persona*)elem;
    return (void*)persona_new(p->cargo, p->nombre); 
}

void list_print(list* l, void print(void* data, void* ctx)) //Ejercicio 3d
{
    if(l == NULL) return;

    list_first(l);
    for(int i=0; i<list_length(l); i++) {
        void* data = list_get(l);
        print(data, NULL);
        list_next(l);
    }
}

void destroy_lista_personas(list* l)  //Ejercicio 3d
{
    if(l == NULL) return;

    list_first(l);
    for(int i=0; i<list_length(l); i++) {
        persona* p = (persona*)list_get(l);
        free(p->cargo);
        free(p->nombre);
        p->cargo == NULL;
        p->nombre == NULL;
        list_next(l);
    }
}

ntn* n_tree_new2()  //Ejercicio 4a
{
    int data = 10;
    void* value = &data;
    ntn* root = ntn_new(copy_elem(value));
    //crear la raiz

    for(int i=0; i<5; i++) {
        data = 20 + i;
        ntn* child = ntn_new(copy_elem(value));
        add_child(root, child);
    }
    ntlist* aux = root->child;
    //crear hijos de la raiz

    ntn* child1 = aux->node;
    for(int i=0; i<3; i++) {
        data = 30 + i;
        ntn* grandson123 = ntn_new(copy_elem(value));
        add_child(child1, grandson123);
    }
    aux = aux->next;
    //Crear los hijos del primer hijo

    ntn* child2 = aux->node;
    data = 33;
    ntn* grandson4 = ntn_new(copy_elem(value));
    add_child(child2, grandson4);
    aux = aux->next;
    //Crear los hijos del segundo hijo

    ntn* child3 = aux->node;
    data = 34;
    ntn* grandson5 = ntn_new(copy_elem(value));
    add_child(child3, grandson5);
    aux = aux->next;
    //Crear los hijos del tercer hijo

    ntn* child5 = aux->next->node;
    data = 35;
    ntn* grandson6 = ntn_new(copy_elem(value));
    add_child(child5, grandson6);
    //Crear los hijos del quinto hijo

    for(int i=0; i<7; i++) {
        data = 40 + i;
        ntn* ggson = ntn_new(copy_elem(value));
        add_child(grandson5, ggson);
    }
    //Crear los hijos del nieto del tercer hijo

    return root;
}

void print_int_depth(void* data, void* ctx)  //Ejercicio 4b
{
    if(data == NULL) return;

    int n = *(int* )data;
    int depth = 0;
    if(ctx != NULL) {
        depth = *(int*)ctx;
    }

    for(int i=0; i<depth; i++) {
        printf("   ");
    }
    printf("%d\n", n);
}

void print_int_breath(void* data, void* ctx)  //Ejercicio 4b
{
    if(data == NULL) return;

    static int last_level = -1;
    int n = *(int* )data;
    int depth = *(int*)ctx;

    if(depth != last_level) {
        printf("\nNivel %d:  ", depth+1);
        last_level = depth;
    }
    printf("%d  ", n);
}

ntn* remove_any_value(ntn** tree, void* value, int cmp(void* , void* ))  //Ejercicio 4c
{
    if(*tree == NULL) return NULL;

    ntn* r = NULL;
    if(cmp((*tree)->value, value) == 0) {
        r = remove_head(tree);
    } else {
        ntlist* child = (*tree)->child;
        while(child != NULL && r == NULL) {
            r = remove_any_value(&(child->node), value, cmp);
            if(r == NULL)
                child = child->next;
        }
    }

    return r;
}

ntn* remove_head(ntn** tree)  //Ejercicio 4c
{
    if(*tree == NULL) return NULL;

    ntn* r = NULL;
    ntn* new_head = NULL;
    ntlist* aux = NULL;
    ntlist* insert = NULL;

    r = *tree;
    if((*tree)->child != NULL) {
        new_head = (*tree)->child->node;
        aux = (*tree)->child->next;
 
        r->child = NULL;
        free((*tree)->child);
        *tree = new_head;

        insert = new_head->child;
        if(insert == NULL)
            new_head->child = aux;
        else {
            while(insert->next != NULL)
                insert = insert->next;
            insert->next = aux;
        }
    } else {
        *tree = NULL;
    }

    return r;
}

void max_n_degree(ntn* tree, int n)  //Ejercicio 4d
{
    if(tree == NULL || n < 1) return;

    ntlist* child = tree->child;
    ntlist* removed = max_cant_list_n(child, n);

    while(removed != NULL) {
        if(child == NULL)
            child = tree->child; 
        
        ntlist* aux = removed->next;
        removed->next = NULL;  
        insert_append(&(child->node->child), removed);
        removed = aux;
        child = child->next;
    }

    child = tree->child;
    while(child != NULL) {
        max_n_degree(child->node, n);
        child = child->next;
    }
}

ntlist* max_cant_list_n(ntlist* l, int n)  //Ejercicio 4d
{
    if(l == NULL || n < 1) return NULL;

    ntlist* r = NULL;

    int count = 1;
    while(l != NULL && count < n) {
        count++;
        l = l->next;
    }
    if(l != NULL && count == n) {
        r = l->next;
        l->next = NULL;
    }

    return r;
}

void insert_append(ntlist** l, ntlist* n)  //Ejercicio 4d
{
    if(n == NULL) return;

    if(*l != NULL) {
        while((*l)->next != NULL) {
            l = &((*l)->next);
        }
        (*l)->next = n;
    } else {
        *l = n;
    }
}

ntn* clone(ntn* root)  //Ejercicio 5
{
    if(root == NULL) return NULL;
    
    ntn* clon = ntn_new(copy_elem(root->value));
    copy_list(root->child, &(clon->child));

    return clon;
}

void copy_list(ntlist* l, ntlist** newl)  //Ejercicio 5
{
    if(l == NULL) return;

    ntlist* aux = ntl_new(clone(l->node));
    copy_list(l->next, &(aux->next));
    *newl = aux;
}

int are_equal_trees(ntn* tree1,ntn* tree2, int cmp(void* , void* ))  //Ejercicio 5
{
    if(tree1 == NULL && tree2 == NULL) return 1;
    if(tree1 == NULL || tree2 == NULL) return 0;

    int equal = 0;
    if(cmp(tree1->value, tree2->value) == 0) {
        ntlist* child1 = tree1->child;
        ntlist* child2 = tree2->child;

        if(cant_child(tree1) == cant_child(tree2)) {
            equal = 1;
            while(child1 != NULL && equal == 1) {
                equal = are_equal_trees(child1->node, child2->node, cmp);
                child1 = child1->next;
                child2 = child2->next;
            }
        } 
    }

    return equal;
}

void print_path_A_to_B(ntn* root, void* A, void* B, int cmp(void* , void* ), void print(void* ))  //Ejercicio 7
{
    if(root == NULL) return;

    if(search_node(&root, A, cmp) == NULL || search_node(&root, B, cmp) == NULL) {
        printf("Alguno de los nodos no se encuentra en el arbol");
    } else {
        stack* s = stack_new();
        path_A_to_B(root, A, B, s, cmp_int);
        print_stack(s, print);
        stack_free(&s, 0);
    }
}

void path_A_to_B(ntn* root, void* A, void* B, stack* s, int cmp(void* , void* ))  //Ejercicio 7
{
    if(root == NULL) return;

    stack* auxA = stack_new();
    stack* auxB = stack_new();
    path(root, A, auxA, cmp);
    path(root, B, auxB, cmp);
    queue* q = queue_new();
    void* common = NULL;
    int inter = 0;

    while(!stack_is_empty(auxA)) {
        void* elemA = pop(auxA);
        void* elemB;
        if(inter == 0)
            elemB = pop(auxB);

        if(cmp(elemA, elemB) == 0) {
            common = elemA;
        } else {
            if(queue_is_empty(q) == 1) {
                enqueue(q, common);
                push(auxB, elemB);
                inter = 1;
            }
            enqueue(q, elemA);
        }
    }
    while(!stack_is_empty(auxB)) {
        push(s, pop(auxB));
    }
    inverted_stack(s);
    while(!queue_is_empty(q)) {
        push(s, dequeue(q));
    }

    stack_free(&auxA, 0);
    stack_free(&auxB, 0);
    queue_free(&q, 0);
}

int is_balanced(ntn* root)  //Ejercicio 8
{
    if(root == NULL) return 1;

    int balanced = 1;
    int min_h = 9999;
    int max_h = -1;

    ntlist* child = root->child;
    while(child != NULL) {
        int h = tree_height(child->node);
        if(h < min_h) min_h = h;
        if(h > max_h) max_h = h;

        child = child->next;
    }
    if((max_h - min_h) > 1) {
        balanced = 0;
    } else {
        child = root->child;
        while(child != NULL && balanced == 1) {
            balanced = is_balanced(child->node);
            child = child->next;
        } 
    }

    return balanced;
}

ntn* mirror(ntn* root)  //Ejercicio 9
{
    if(root == NULL) return NULL;
    
    ntn* clon = ntn_new(copy_elem(root->value));
    copy_mirror(root->child, &(clon->child));

    return clon;
}

void copy_mirror(ntlist* l, ntlist** newl)  //Ejercicio 9
{
    if(l == NULL) return;

    ntlist* aux = ntl_new(mirror(l->node));
    aux->next = *newl;
    *newl = aux;
    copy_mirror(l->next, newl);
}

int is_symetric(ntn* root, int cmp(void* , void* ))  //Ejercicio 9
{
    if(root == NULL) return 1;

    ntn* mirror_tree = mirror(root);
    int equal = are_equal_trees(root, mirror_tree, cmp);
    destroy_tree(&mirror_tree, 1);

    return equal;
}