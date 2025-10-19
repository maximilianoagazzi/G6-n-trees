#ifdef VECTOR_H_EXPORT
#define VECTOR_API __declspec(dllexport)
#else
#define VECTOR_API __declspec(dllimport)
#endif

typedef struct vector vector;

VECTOR_API vector* vector_new(); // Crea el vector
VECTOR_API vector* vector_new_with(int ini_size); // Crea el vector con tamaño inicial
VECTOR_API void vector_free(vector* v); // Libera v.data y a v, no libera el contenido de cada v.data[i]
VECTOR_API int vector_size(vector* v); // Obtener el tamaño actual
VECTOR_API int vector_isfull(vector* v); // Devuelve 0 si no está lleno
VECTOR_API int vector_isempty(vector* v); // Devuelve 0 si no está vacío
VECTOR_API void* vector_get(vector* v, int index); // Obtener el elemento de una posición
VECTOR_API void* vector_set(vector* v, int index, void* value);// Reemplazar
VECTOR_API int vector_add(vector* v, void* value);// Agregar un elemento al final
VECTOR_API int vector_insert(vector* v, int index, void* value); // insertar un elemento
VECTOR_API void* vector_remove(vector* v, int index); // Remover un elemento
VECTOR_API void vector_sort(vector *v, int (*ord)(void *, void *)); // Ordenar el vector
VECTOR_API int vector_sequential_search(vector *v, void *val, int (*bsq)(void *, void *)); // Búsqueda secuencial en el vector
VECTOR_API int vector_binary_search(vector *v, void *val, int (*bsq)(void *, void *)); // Búsqueda binaria en el vector (debe estar ordenado)