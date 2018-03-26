#include <stdlib.h>
#define STACK(TYPE, NAME, FUNCTION_PREFIX) GENERATE_DYNAMIC_STACK(NAME, NAME##NODE, TYPE, FUNCTION_PREFIX)
#define GENERATE_DYNAMIC_STACK(STACK, NODE, TYPE, FN) \
 \
typedef struct STACK { \
    	TYPE item; \
        struct NODE *head; \
        void (*delete_node)(void* item); \
        int size; \
} STACK; \
 \
typedef struct NODE { \
    	TYPE item; \
        struct NODE* previous; \
} NODE; \
 \
STACK* FN##_new(void); \
 \
STACK* FN##_new() { \
	STACK* stack = malloc(sizeof(STACK)); \
	stack->head = NULL; \
	stack->size = 0; \
	stack->delete_node = free; \
	return stack; \
} \
 \
NODE* FN##_node_new() { \
	NODE* node = malloc(sizeof(NODE)); \
	node->previous = NULL; \
	return node; \
} \
 \
bool FN##_push(STACK *self, TYPE item) { \
	if(self && self->head) { \
		NODE* previous = self->head; \
		self->head = FN##_node_new(); \
		if (self->head) { \
			self->head->previous = previous; \
			self->head->item = item; \
			self->size++; \
			return true; \
		} \
		else { \
			self->head = previous; \
		} \
	} else if (self && !self->head) { \
		self->head = FN##_node_new(); \
		if (self->head) { \
			self->head->item = item; \
			self->size = 1; \
			return true; \
		} \
	} \
	return false; \
} \
 \
TYPE FN##_pop(STACK *self){ \
	if (self && self->head) { \
		TYPE item; \
		item = self->head->item; \
		NODE* previous = self->head->previous; \
		self->delete_node(self->head); \
		self->head = previous; \
		self->size--; \
		if (self->size < 0) \
			self->size = 0; \
		return item;\
	} \
} \
TYPE FN##_peek(STACK *self){ \
	if (self && self->head) { \
		TYPE item; \
		item = self->head->item; \
		return item;\
	} \
}