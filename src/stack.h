#define STACK(NAME, TYPE) GENERATE_DYNAMIC_STACK(NAME, TYPE)

#define GENERATE_DYNAMIC_STACK(STACK_NAME, TYPE) typedef struct STACK_NAME {\
	TYPE item;\
	struct STACK_NAME* previous;\
	struct STACK_NAME##_functions* functions;\
} STACK_NAME;\
STACK_NAME* STACK_NAME##_init(void);\
STACK_NAME* STACK_NAME##_init() {\
	STACK_NAME* stack = malloc(sizeof(STACK_NAME));\
	stack->previous = NULL;\
	return stack;\
}\
void STACK_NAME##_push(STACK_NAME **self, TYPE item) {\
	STACK_NAME *previous = &(**self);\
	*self = STACK_NAME##_init();\
	(**self).previous = previous;\
	(**self).item = item;\
}\
\
TYPE STACK_NAME##_pop(STACK_NAME **self){ \
	TYPE item = (**self).item;\
	STACK_NAME* actual = *self;\
	*self = (**self).previous;\
	return item;\
}