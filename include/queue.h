#ifdef QUEUE_H_EXPORT
#define QUEUE_API __declspec(dllexport)
#else
#define QUEUE_API __declspec(dllimport)
#endif

#include "node.h"

typedef struct _queue queue;

queue* queue_new();
void enqueue(queue* q, void* elem);
void* dequeue(queue* q);
void queue_free(queue** q, int dinamic);
int queue_length(queue* q);
void* peak(queue* q);
int queue_is_empty(queue* q);