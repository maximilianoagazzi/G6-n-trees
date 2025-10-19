#include <stdlib.h>
#define VECTOR_H_EXPORT
#include "vector.h"

typedef struct vector {
    void** data; // Puntero a un array de punteros a void
    int size;    // Número actual de elementos en el vector
    int capacity; // Capacidad máxima del vector
} vector;

vector* vector_new()
{
    vector* v = (vector* )malloc(sizeof(vector));
    if (v == NULL) {
        return NULL;
    }
    v->capacity = 4; // Tamaño inicial por defecto
    v->size = 0;
    v->data = (void **)malloc(v->capacity * sizeof(void *));
    if (v->data == NULL) {
        free(v);
        return NULL;
    }
    return v;
}

vector* vector_new_with(int ini_size)
{
    vector *v = (vector *)malloc(sizeof(vector));
    if (v == NULL) {
        return NULL;
    }
    if (ini_size <= 0) {
        return NULL;
    }
    v->capacity = ini_size;
    v->size = 0;
    v->data = (void **)malloc(v->capacity * sizeof(void *));
    if (v->data == NULL) {
        free(v);
        return NULL;
    }
    return v;
}

void vector_free(vector* v)
{
    if (v != NULL) {
        free(v->data);
        free(v);
    }
    return;
}

int vector_size(vector* v)
{
    if (v != NULL) {
        return v->size;
    }
    return -1; // Indica error
}

int vector_isfull(vector* v)
{
    if (v != NULL) {
        if (v->size >= v->capacity) {
            return 1;
        } else {
            return 0;
        }
    }
    return -1; // Indica error
}

int vector_isempty(vector* v)
{
    if (v != NULL) {
        if(v->size == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    return -1; // Indica error
}

void* vector_get(vector* v, int index)
{
    if (v != NULL && index >= 0 && index < v->size) {
        return v->data[index];
    }
    return NULL; // Indica error
}

void* vector_set(vector* v, int index, void* value)
{
    if (v != NULL && index >= 0 && index < v->size) {
        void *old_value = v->data[index];
        v->data[index] = value;
        return old_value;
    }
    return NULL; // Indica error
}

int vector_add(vector* v, void* value)  //Agrega al final del vector
{
    if (v == NULL) {
        return -1; // Indica error
    }
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        void **new_data = (void **)realloc(v->data, v->capacity * sizeof(void *));
        if (new_data == NULL) {
            return -1; // Indica error
        }
        v->data = new_data;
    }
    v->data[v->size++] = value;
    return 0; // Éxito
}

int vector_insert(vector* v, int index, void* value)
{
    if (v == NULL || index < 0 || index > v->size) {
        return -1; // Indica error
    }
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        void **new_data = (void **)realloc(v->data, v->capacity * sizeof(void *));
        if (new_data == NULL) {
            return -1; // Indica error
        }
        v->data = new_data;
    }
    for (int i = v->size; i>index; i--) {
        v->data[i] = v->data[i-1];
    }
    v->data[index] = value;
    v->size++;
    return 0; // Éxito
}

void* vector_remove(vector* v, int index)
{
    if (v == NULL || index < 0 || index >= v->size) {
        return NULL; // Indica error
    }
    void *removed_value = v->data[index];
    for (int i = index; i<v->size-1; i++) {
        v->data[i] = v->data[i+1];
    }
    v->size--;
    return removed_value; // Retorna el valor removido
}

void vector_sort(vector *v, int (*ord)(void *, void *)) //Ordenar vector generico desde TDA vector
{
    char swapped = 1;
    int size = vector_size(v);
    void *aux;
    while ((size > 1) && (swapped != 0)) {
        swapped = 0;
        for (int i=1; i<size; i++) {
            if (ord(vector_get(v, i-1), vector_get(v, i)) > 0) {
                aux = vector_get(v, i-1);
                vector_set(v, i-1, vector_get(v, i));
                vector_set(v, i, aux);
                swapped = 1;
            }
        }
        size--;
    }
    return;
}

int vector_sequential_search(vector *v, void *val, int (*bsq)(void *, void *)) //Ejercicio 13
{
    int n = 0;
    while (n < vector_size(v) && bsq(vector_get(v, n), val) != 0) {
        n++;
    }
    if(n == vector_size(v)) {
        return -1; // No encontrado
    }
    return n+1;
}

int vector_binary_search(vector *v, void *val, int (*bsq)(void *, void *))
{
    int low = 0, high = vector_size(v) - 1;
    int mid = (low + high)/2;
    while ((low < high) && (bsq(vector_get(v, mid), val) != 0)) {
        if(bsq(vector_get(v, mid), val) > 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high)/2;
    }
    if (bsq(vector_get(v, mid), val) != 0) {
        return -1; // No encontrado
    }
    return mid+1;
}