#ifdef STACK_H_EXPORT
#define STACK_API __declspec(dllexport)
#else
#define STACK_API __declspec(dllimport)
#endif

#include "vector.h"

typedef struct _stack stack;

stack* stack_new();
void push(stack* s, void* elem);
void* pop(stack* s);
void stack_free(stack** s, int dinamic);
int stack_length(stack* s);
void* top(stack* s);
int stack_is_empty(stack* s);