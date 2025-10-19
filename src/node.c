#include <stdio.h>
#include <stdlib.h>
#define NODE_H_EXPORT
#include "node.h"

typedef struct _node {
    void* data;  //Puntero a un dato, de tipo void para ser generico
    struct _node* next;  //Puntero al siguiente elemento
    struct _node* prev;  //Puntero al elemento previo (nodo generalizado, si se va a usar exclusivamente para SLL's conviene elminar prev)
} node;

node* new_node() {
    node* r = (node* )malloc(sizeof(node));
    if( r != NULL) {
        r->data = NULL;
        r->next = NULL;
        r->prev = NULL;
    }
    return r;
}

node* new_node_with(void* data) {
    node* r = (node* )malloc(sizeof(node));
    if( r != NULL) {
        r->data = data;
        r->next = NULL;
        r->prev = NULL;
    }
    return r;
}

void* destroy_node(node* n) {
    void* data = NULL;
    if( n != NULL) {
    data = n->data;
    n->data = NULL;
    n->next = NULL;
    n->prev = NULL;
    free(n);
    }
    return data;
}

void* get_data(node* h) {
    return (h != NULL) ? h->data : NULL;
}

node** get_next_node(node* h) {
    return (h != NULL) ? &(h->next) : NULL;
}

node** get_prev_node(node* h) {
    return (h != NULL) ? &(h->prev) : NULL;
}

void set_data(node* h, void* data) {
    if(h != NULL) {
        h->data = data;
    }
}

void set_next_node(node* h, node* next) {
    if(h != NULL) {
        h->next = next;
    }
}

void set_prev_node(node* h, node* prev) {
    if(h != NULL) {
        h->prev = prev;
    }
}