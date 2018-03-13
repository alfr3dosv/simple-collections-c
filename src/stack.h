#include "collections.h"
#define STACK(NAME, TYPE) GENERATE_DYNAMIC_STACK(NAME, NAME##_node, TYPE)
#define GENERATE_DYNAMIC_STACK(STACK, NODE, TYPE) \
 \
typedef struct STACK { \
    	TYPE item; \
        struct NODE *head; \
        int size; \
} STACK; \
 \
typedef struct NODE { \
    	TYPE item; \
        struct NODE* previous; \
} NODE; \
 \
STACK* STACK##_new(void); \
 \
STACK* STACK##_new() { \
	STACK* stack = malloc(sizeof(STACK)); \
	stack->head = NULL; \
	stack->size = 0; \
	return stack; \
} \
 \
NODE* NODE##_new() { \
	NODE* node = malloc(sizeof(NODE)); \
	node->previous = NULL; \
	return node; \
} \
 \
bool STACK##_push(STACK *self, TYPE item) { \
	if(self && self->head) { \
		NODE* previous = self->head; \
		self->head = NODE##_new(); \
		self->head->previous = previous; \
		self->head->item = item; \
		self->size++; \
	} else if (self && !self->head) { \
		self->head = NODE##_new(); \
		self->head->item = item; \
		self->size = 1; \
	} \
	return false; \
} \
 \
TYPE STACK##_pop(STACK *self){ \
	if (self && self->head) { \
		TYPE item; \
		item = self->head->item; \
		NODE* previous = self->head->previous; \
		free(self->head); \
		self->head = previous; \
		self->size--; \
		if (self->size < 0) \
			self->size = 0; \
		return item;\
	} \
}