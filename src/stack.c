#include <stdio.h>
#include <stdlib.h>
#define STACK_H_EXPORT
#include "stack.h"

typedef struct _stack {
    vector* body;  //Usa un vector de forma simplificada para usarlo de pila
} stack;

stack* stack_new()  //Crea la pila
{
    stack* s = (stack* )malloc(sizeof(stack));
    vector* v = vector_new();
    if(s == NULL || v == NULL) {
        free(s);
        return NULL;
    }
    s->body = v;
    return s;
}

void push(stack* s, void* elem)  //Añade un elemento
{
    if(s != NULL) {
        vector_add(s->body, elem);
    }
}

void* pop(stack* s)  //Saca el ultimo elemento
{
    if(s != NULL && vector_size(s->body) > 0) {
        return vector_remove(s->body, vector_size(s->body) - 1);
    }
    return NULL;
}

void stack_free(stack** s, int dinamic) //Destruye la pila y hay que indicarle si los datos son dinamicos o no
{
    void* data;
    if(*s != NULL) {
        while(vector_size((*s)->body) > 0) {
            data = pop(*s);
            if(dinamic == 1) {
                free(data);
            }
        }
        vector_free((*s)->body);
        free(*s);
        *s = NULL;
    }
}

int stack_length(stack* s)  //Devuelve la cantidad de elementos en la pila
{
    if(s != NULL) {
        return vector_size(s->body);
    }
    return -1;
}

void* top(stack* s)  //Devuelve el primer elemento de la pila
{
    if(s != NULL && vector_size(s->body) > 0) {
        return vector_get(s->body, vector_size(s->body) - 1);
    }
    return NULL;
}

int stack_is_empty(stack* s)  //Devuelve 1 si la pila no tiene elementos, 0 si no y -1 si hubo un error
{
    if(s != NULL) {
        if (vector_size(s->body) == 0) {
            return 1;
        }
        return 0;
    }
    return -1;
}