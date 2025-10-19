#ifdef LIST_H_EXPORT
#define LIST_API __declspec(dllexport)
#else
#define LIST_API __declspec(dllimport)
#endif

#include "node.h"

typedef struct _list list;

LIST_API list* list_create();
LIST_API void list_insert_first(list *l, void* elem);
LIST_API void list_insert_current(list *l, void* elem);
LIST_API void list_append(list* l, void* elem);
LIST_API void list_free(list** l, int dinamic);
LIST_API int list_length(list* l);
LIST_API void* list_get(list* l);
LIST_API void* list_first(list* l);
LIST_API void* list_next(list* l);
LIST_API void* list_last(list* l);
LIST_API void* list_remove(list *l);
LIST_API int list_find(list* l, void* elem, int cmp(void*, void*));
LIST_API int list_is_empty(list* l);