#define LINKED_LIST(NAME, TYPE) GENERATE_DYNAMIC_LINKED_LIST(NAME, NAME##_node, TYPE)
#define GENERATE_DYNAMIC_LINKED_LIST(LIST, NODE, TYPE) \
typedef struct LIST { \
    TYPE value; \
    struct NODE* head; \
    int size; \
} LIST; \
 \
typedef struct NODE { \
    TYPE value; \
    struct NODE* next; \
    struct NODE* previous; \
} NODE; \
 \
LIST* LIST##_new(void); \
bool LIST##_insert_node(LIST *self, NODE *, NODE *); \
void LIST##_push(LIST* self, TYPE value, int index); \
TYPE LIST##_get(LIST* self, int index); \
void LIST##_append(LIST* self, TYPE value); \
void (* FN##_free)(void *node) = free; \
void (* FN##_free_node)(void *node) = free; \
 \
LIST* LIST##_new() { \
    LIST* list = malloc(sizeof(LIST)); \
    list->head = NULL; \
    list->size = 0; \
    return list; \
} \
 \
NODE* NODE##_new() { \
    NODE* node = malloc(sizeof(NODE)); \
    node->next = NULL; \
    node->previous = NULL; \
    return node; \
} \
 \
void LIST##_insert_at(int position, LIST *self, TYPE value) { \
    if (self->size < 0) \
        return; \
    NODE *aux = self->head; \
    int i = 0; \
    while(i < position && aux->next != NULL) { \
        aux = aux->next; \
        i++; \
    } \
    if (aux && i >= position) { \
        NODE *new_node = NODE##_new(); \
        if (new_node) { \
            new_node->value = value; \
            LIST##_insert_node(self, aux, new_node); \
        } \
    } \
} \
 \
void LIST##_append(LIST *self, TYPE value) { \
    if (self && !self->head) { \
        self->head = NODE##_new(); \
        self->head->value = value; \
        self->size++; \
    } else if (self && self->head) { \
        NODE *new_head = NODE##_new(); \
        if (new_head) { \
            self->head->previous = new_head; \
            new_head->next = self->head; \
            new_head->value = value; \
            self->head = new_head; \
            self->size++; \
        } \
    } \
} \
\
bool LIST##_insert_node(LIST *self, NODE* node_before, NODE *node) { \
    if (self && node_before && node) { \
        if (self->head == node_before) { \
            node->next = node_before; \
            node_before->previous = node; \
            self->head = node; \
        } else { \
            node_before->previous->next = node; \
            node_before->previous = node; \
            node->next = node_before; \
            node->previous = node_before; \
        } \
        self->size++; \
        return true; \
    } \
    return false; \
} \
\
TYPE LIST##_get(LIST* self, int index) { \
    NODE* aux = self->head; \
    int i = 0; \
    while(i < index && aux->next != NULL) { \
        i++; \
        aux = aux->next; \
    } \
    TYPE value; \
    if (aux && i == index) \
        value = aux->value; \
    return value; \
} \
 \
NODE* LIST##_remove(LIST* self, int index) { \
    NODE* node = self->head; \
    NODE* previous_node = NULL; \
    int i = 0; \
    while(i < index && node->next != NULL) { \
        i++; \
        previous_node = node; \
        node = node->next; \
    } \
    if (node == self->head) \
        self->head = node->next; \
    return node; \
} \
#define foreach_node(X, LIST) for(X = LIST->head; X != NULL; X = X->next)
