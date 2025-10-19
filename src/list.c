#include <stdio.h>
#include <stdlib.h>
#define LIST_H_EXPORT
#include "list.h"

typedef struct _list {
    node* head;
    node* current;
    int size;
} list;

list* list_create()
{
    list* l = (list* )malloc(sizeof(list));
    if (l == NULL) {
        return NULL;
    }
    l->head = NULL;
    l->current = NULL;
    l->size = 0;
    return l;
}

void list_insert_first(list *l, void* elem) //Inserta al principio
{
    if(l != NULL) {
        node* n = new_node_with(elem);
        if (n != NULL) {
            set_next_node(n, l->head);
            l->head = n;
            l->current = n;
            l->size++;
        }
    }
}

void list_insert_current(list *l, void* elem) //Inserta antes del nodo actual
{
    if(l != NULL && l->current != NULL) {
        node** aux = &(l->head);
        while(*aux != NULL && *aux != l->current) {
            aux = get_next_node(*aux);
        }
        if(*aux == l->current) {
            node* n = new_node_with(elem);
            if(n != NULL) {
                set_next_node(n, l->current);
                *aux = n;
                l->current = n;
                l->size++;
            }
        }
    }
}

void list_append(list* l, void* elem) //Inseta al final
{
    if(l != NULL) {
        node** h = &(l->head);
        node* n = new_node_with(elem);
        if (n != NULL) {
            while (*h != NULL) {
                h = get_next_node(*h);
            }
            *h = n;
            l->current = n;
            l->size++;
        }
    }
}

void list_free(list** l, int dinamic) //Destruye la lista y hay que indicarle si los datos son dinamicos o no
{
    void* data;
    if(*l != NULL) {
        while ((*l)->head != NULL) {
            node* temp = (*l)->head;
            (*l)->head = *(get_next_node((*l)->head));
            data = get_data(temp);
            destroy_node(temp);
            if(dinamic == 1 && data != NULL) {
                free(data);
            }
        }
        free(*l);
        *l = NULL;
    }
}

int list_length(list* l) //Devuelve la cantidad de nodos en la lista
{
    if(l != NULL) {
        return l->size;
    }
    return -1;
}

void* list_get(list* l) //Devuelve el elemento guardado en el nodo actual
{
    if(l != NULL && l->current != NULL) {
        return get_data(l->current);
    }
    return NULL;
}

void* list_first(list* l)  //Devuelve el elemento guardado en la cabeza de la lista
{
    if(l != NULL && l->head != NULL) {
        l->current = l->head;
        return get_data(l->head);
    }
    return NULL;
}

void* list_next(list* l)  //Devuelve el siguiente elemento al actual
{
    if(l != NULL && l->current != NULL) {
        node* next = *get_next_node(l->current);
        if (next != NULL) {
            l->current = next;
            return get_data(next);
        }
    }
    return NULL;
}

void* list_last(list* l)  //Devueleve el ultimo elemento de la fila
{
    void* data = NULL;
    if(l != NULL) {
        node* temp = l->head;
        while (temp != NULL && *get_next_node(temp) != NULL) {
            temp = *get_next_node(temp);
        }
        if (temp != NULL) {
            l->current = temp;
            data = get_data(temp);
        }
    }
    return data;
}

void* list_remove(list *l) //Elimina el nodo actual y devuelve su dato
{
    void* data = NULL;
    if(l != NULL && l->current != NULL) {
        node** aux = &(l->head);
        while(*aux != NULL && *aux != l->current) {
            aux = get_next_node(*aux);
        }
        if(*aux == l->current) {
            node* temp = *aux;
            data = get_data(temp);
            *aux = *get_next_node(temp);
            destroy_node(temp);
            l->current = *aux;
            l->size--;
        }
    }
    return data;
}

int list_find(list* l, void* elem, int cmp(void*, void*)) //Busca elem en la lista y si lo encuentra mueve el actual a ese nodo y devuelve 1
{
    if(l != NULL) {
        node* aux = l->head;
        while(aux != NULL) {
            if(cmp(elem, get_data(aux)) == 0) {
                l->current = aux;
                return 1;
            }
            aux = *get_next_node(aux);
        }
        return 0;
    }
    return -1; //Error
}

int list_is_empty(list* l) //Devuelve 1 si la lista no tiene elementos, 0 si no y -1 si hubo un error
{
    if(l != NULL) {
        if(l->size == 0) {
            return 1;
        }
        return 0;
    }
    return -1;
}