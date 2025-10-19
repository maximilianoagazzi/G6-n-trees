#ifdef NODE_H_EXPORT
#define NODE_API __declspec(dllexport)
#else
#define NODE_API __declspec(dllimport)
#endif

typedef struct _node node;

NODE_API node* new_node();
NODE_API node* new_node_with(void* data);
NODE_API void* destroy_node(node* n);
NODE_API void* get_data(node* h);
NODE_API node** get_next_node(node* h);
NODE_API node** get_prev_node(node* h);
NODE_API void set_data(node* h, void* data);
NODE_API void set_next_node(node* h, node* next);
NODE_API void set_prev_node(node* h, node* prev);