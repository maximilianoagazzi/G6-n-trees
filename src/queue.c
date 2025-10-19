#include <stdio.h>
#include <stdlib.h>
#define QUEUE_H_EXPORT
#include "queue.h"

typedef struct _queue {
    node* front; //Puntero al frente de la cola
    node* rear; //Puntero al final de la cola
    int size;  //Cantidad de elementos de la cola
} queue;

queue* queue_new()  //Crea la cola
{
    queue* q = (queue* )malloc(sizeof(queue));
    if(q == NULL) {
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(queue* q, void* elem)  //Agrega un elemento al final de la cola
{
    if(q != NULL) {
        node* n = new_node_with(elem);
        if (n == NULL) {
            return;
        }
        if (q->rear == NULL) { //Si la cola esta vacia
            q->front = n;
            q->rear = n;
            q->size++;
        } else {
            set_next_node(q->rear, n);
            q->rear = n;
            q->size++;
        }
    }
}

void* dequeue(queue* q)  //Saca el elemento del frente de la cola
{
    if(q != NULL && q->front != NULL) {
        void* data = get_data(q->front);
        node* temp = q->front;
        q->front = *(get_next_node(q->front));
        if(q->front == NULL) { //Si la cola queda vacia
            q->rear = NULL;
        }
        destroy_node(temp);
        q->size--;
        return data;
    }
    return NULL;
}

void queue_free(queue** q, int dinamic) //Destruye la cola y hay que indicarle si los datos son dinamicos o no
{
    void* data;
    if(*q != NULL) {
        while((*q)->front != NULL) {
            data = dequeue(*q);
            if(dinamic == 1) {
                free(data);
            }
        }
        free(*q);
        *q = NULL;
    }
}

int queue_length(queue* q) //devueleve la cantidad de elementos de la cola
{
    if(q != NULL) {
        return q->size;
    }
    return -1;
}

void* peak(queue* q)  //Devuelve el primer elemento de la cola
{
    if(q != NULL && q->size > 0) {
        return get_data(q->front);
    }
    return NULL;
}

int queue_is_empty(queue* q)  //Devuelve 1 si la cola no tiene elementos, 0 si no y -1 si hubo un error
{
    if(q != NULL) {
        if (q->size == 0) {
            return 1;
        }
        return 0;
    }
    return -1;
}