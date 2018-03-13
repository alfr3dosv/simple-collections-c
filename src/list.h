#define LIST(NAME, TYPE) GENERATE_DYNAMIC_LIST(NAME, TYPE)
#define GENERATE_DYNAMIC_LIST(LIST_NAME, TYPE) typedef struct LIST_NAME { \
	TYPE item; \
	struct LIST_NAME* next; \
} LIST_NAME; \
\
LIST_NAME* LIST_NAME##_init(void); \
void LIST_NAME##_push(LIST_NAME** self, TYPE item, int index); \
TYPE LIST_NAME##_get(LIST_NAME** self, int index); \
void LIST_NAME##_append(LIST_NAME **self, TYPE item);\
\
LIST_NAME* LIST_NAME##_init() { \
	LIST_NAME* new_LIST_NAME = malloc(sizeof(LIST_NAME)); \
	new_LIST_NAME->next = NULL; \
	return new_LIST_NAME; \
} \
\
void LIST_NAME##_push(LIST_NAME** self, TYPE item, int index) {\
	LIST_NAME *next = LIST_NAME##_init();\
	LIST_NAME *aux = *self;\
	TYPE i = 0;\
	while(i < index, aux->next != NULL) {\
		aux = aux->next;\
	}\
	aux->next = next; \
	aux->item = item;\
}\
\
void LIST_NAME##_append(LIST_NAME **self, TYPE item) {\
	LIST_NAME *next = LIST_NAME##_init();\
	LIST_NAME *aux = *self;\
	while(aux->next != NULL) {\
		aux = aux->next;\
	}\
	aux->next = next;\
	aux->item = item;\
}\
\
TYPE LIST_NAME##_get(LIST_NAME** self, int index) {\
	LIST_NAME* aux_ptr = *self;\
	TYPE i = 0;\
	while(i < index && aux_ptr->next != NULL) {\
		i++;\
		aux_ptr = aux_ptr->next;\
	}\
	TYPE item = aux_ptr->item;  \
	return item; \
}\
LIST_NAME *LIST_NAME##_get_ptr(LIST_NAME** self, int index) {\
	LIST_NAME* aux_ptr = *self;\
	TYPE i = 0;\
	while(i < index && aux_ptr->next != NULL) {\
		i++;\
		aux_ptr = aux_ptr->next;\
	}\
	return aux_ptr; \
}\
\
LIST_NAME* LIST_NAME##_remove(LIST_NAME** self, int index) {\
	LIST_NAME* node = *self;\
	LIST_NAME* previous_node;\
	TYPE i = 0;\
	while(i < index && node->next != NULL) {\
		i++;\
		previous_node = node;\
		node = node->next;\
	}\
	if (node == *self) {\
		LIST_NAME* node_to_remove = *self;\
		*self = (**self).next;\
		return node_to_remove;\
	}\
	LIST_NAME* node_to_remove = node;\
	previous_node->next = node;\
\
	return node_to_remove;\
}\
\
TYPE LIST_NAME##_size(LIST_NAME** self) {\
	LIST_NAME* aux_ptr = *self;\
	TYPE size = 0;\
	while(aux_ptr->next != NULL) {\
		size++;\
		aux_ptr = aux_ptr->next;\
	}\
	return size; \
}

#define foreach_list(X, LIST) for(X = LIST; X->next != NULL; X = X->next)
