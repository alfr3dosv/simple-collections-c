#define LINKED_LIST(TYPE, NAME, FUNCTION_PREFIX) GENERATE_DYNAMIC_LINKED_LIST(NAME, NAME##Node, TYPE, FUNCTION_PREFIX)
#define GENERATE_DYNAMIC_LINKED_LIST(LIST, NODE, TYPE, FN) \
typedef struct LIST { \
    TYPE value; \
    struct NODE* head; \
    struct NODE* last; \
    int size; \
} LIST; \
typedef struct NODE { \
    TYPE value; \
    struct NODE* next; \
    struct NODE* previous; \
} NODE; \
 \
LIST* FN##_new(void); \
bool FN##_insert_node(LIST *self, NODE *, NODE *); \
NODE* FN##_insert(LIST* self, int index, TYPE value); \
TYPE FN##_get(LIST* self, int index); \
NODE* FN##_append(LIST* self, TYPE value); \
bool FN##_remove_node(LIST* self, NODE* node); \
TYPE FN##_remove(LIST* self, int index); \
void (* FN##_free)(void *node) = free; \
void (* FN##_free_node)(void *node) = free; \
 \
LIST* FN##_new() { \
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
NODE* FN##_insert(LIST *self, int position, TYPE value) { \
    if (self->size < position) \
        return NULL; \
    NODE *aux = self->head; \
    int i = 1; \
    while(i < position && aux->next != NULL) { \
        aux = aux->next; \
        i++; \
    } \
    if (i >= position) { \
        NODE *new_node = NODE##_new(); \
        if (new_node) { \
            new_node->value = value; \
            FN##_insert_node(self, aux, new_node); \
        } \
        return new_node; \
    } \
} \
bool FN##_insert_node(LIST *self, NODE* node_before, NODE *node) { \
    if (self && node) { \
        if ((self->head == node_before && node_before == NULL) || \
            node_before == NULL) \
        { \
            self->head = node; \
            self->last = node; \
        } \
        else { \
            if (node_before->next) { \
                node->next = node_before->next; \
                node_before->next->previous = node; \
            } \
            else { \
                self->last = node; \
            } \
            node->previous = node_before; \
            node_before->next = node; \
        } \
        self->size++; \
        return true; \
    } \
    return false; \
} \
 \
NODE* FN##_append(LIST *self, TYPE value) { \
    NODE* new_node = NULL; \
    if (self && !self->head) { \
        new_node = NODE##_new(); \
        if (new_node) { \
            self->last = new_node; \
            self->head = new_node; \
            self->head->value = value; \
            self->size++; \
        } \
    } else if (self && self->last) { \
        new_node = NODE##_new(); \
        if (new_node) { \
            self->last->next = new_node; \
            new_node->previous = self->last; \
            new_node->value = value; \
            self->last = new_node; \
            self->size++; \
        } \
    } \
    return new_node; \
} \
\
TYPE FN##_get(LIST* self, int index) { \
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
TYPE FN##_remove(LIST* self, int position) { \
    TYPE value; \
    if (self->size < position) \
        return value; \
    NODE *aux = self->head; \
    int i = 0; \
    while(i < position && aux->next != NULL) { \
        aux = aux->next; \
        i++; \
    } \
    if (i >= position) { \
        value = aux->value; \
        FN##_remove_node(self, aux); \
        return value; \
    } \
} \
bool FN##_remove_node(LIST* self, NODE* node) { \
    if (!node) \
        return false; \
    if (self->head == node) { \
        if (node->next) { \
            self->head = node->next; \
            self->head->previous = NULL; \
            self->last = node->next; \
        } \
    } \
    else { \
        if (node->previous) \
            node->previous->next = node->next; \
        if (node->next) \
            node->next->previous = node->previous; \
        if (node == self->last && self->last != NULL) \
            self->last = node->previous; \
        FN##_free_node(node); \
    } \
    self->size--; \
} \
\
TYPE FN##_pop(LIST* self) { \
    TYPE value; \
    if (self->last) { \
        value = self->last->value; \
        FN##_remove_node(self, self->last); \
        return value; \
    } \
    return value; \
}

#define foreach_node(X, LIST) for(X = LIST->head; X != NULL; X = X->next)
