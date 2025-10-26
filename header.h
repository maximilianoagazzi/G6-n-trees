#ifndef HEADER_H
#define HEADER_H
#include "lib/n_tree.h"
#include "include/list.h"
#include "include/stack.h"
#include "include/queue.h"

typedef struct {
    char* cargo;
    char* nombre;
} persona;

void* copy_elem(void* elem);
void print_int(void* data, void* ctx);
int cmp_int(void* a, void* b);
ntn* n_tree_new();
int same_degree(ntn* tree);
void print_path_to_root(ntn* root, void* value, int cmp(void* , void* ), void print(void* ));
void path(ntn* root, void* value, stack* s, int cmp(void* , void* ));
void inverted_stack(stack* s);
void print_stack(stack* s, void print(void* ));
void print_path_int(void* elem);
persona* persona_new(char* carg0, char* nombre);
ntn* n_tree_new_cargo();
void print_persona(void* data, void* ctx);
void destroy_personas(ntn* root);
int cmp_persona(void* a, void* b);
void print_path_persona(void* elem);
void* copy_elem_persona(void* elem);
list* lista_por_nivel(ntn* tree, int nivel);
void list_print(list* l, void print(void* data, void* ctx));
void destroy_lista_personas(list* l);
ntn* n_tree_new2();
void print_int_depth(void* data, void* ctx);
void print_int_breath(void* data, void* ctx);
ntn* remove_any_value(ntn** tree, void* value, int cmp(void* , void* ));
ntn* remove_head(ntn** tree);

#endif