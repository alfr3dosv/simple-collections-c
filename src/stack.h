#define STACK_TYPE(TYPE) GENERATE_DYNAMIC_STACK(Stack##TYPE, TYPE)

#define GENERATE_DYNAMIC_STACK(STACK_NAME, TYPE) typedef struct STACK_NAME { \
	TYPE item; \
	struct STACK_NAME* before; \
	struct STACK_NAME##_functions* functions; \
} STACK_NAME; \
\
STACK_NAME* STACK_NAME##_init(void); \
STACK_NAME** NewSTACK_NAME(void); \
void STACK_NAME##_push(TYPE item); \
TYPE STACK_NAME##_pop(void); \
bool STACK_NAME##_isEmpty(void); \
extern inline void STACK_NAME##_setSelf(STACK_NAME** selected_stack); \
\
struct STACK_NAME##_functions \
{ \
	void (*setSelf)(STACK_NAME **); \
	void (*push)(TYPE);\
	TYPE (*pop)(void);\
} static functions = { \
	STACK_NAME##_setSelf, \
	STACK_NAME##_push, \
	STACK_NAME##_pop \
}; \
\
static STACK_NAME** self = NULL; \
\
extern inline void STACK_NAME##_setSelf(STACK_NAME** selected_stack) { \
	self = selected_stack; \
} \
\
STACK_NAME* STACK_NAME##_init() { \
	STACK_NAME* stack = malloc(sizeof(STACK_NAME)); \
	stack->before = NULL; \
	stack->functions = &functions; \
	return stack; \
} \
\
STACK_NAME** NewSTACK_NAME () {\
	STACK_NAME* stack = STACK_NAME##_init(); \
	STACK_NAME** obj = malloc(sizeof(STACK_NAME**)); \
	obj = &stack; \
	return obj; \
} \
\
void STACK_NAME##_push(TYPE item) {\
 \
 	\
	STACK_NAME *before = &(**self); \
	*self = STACK_NAME##_init(); \
	(**self).before = before; \
	(**self).item = item;\
	\
}\
TYPE STACK_NAME##_pop() {\
	TYPE item = (**self).item; \
	STACK_NAME* actual = *self; \
	*self = (**self).before; \
	return item; \
}