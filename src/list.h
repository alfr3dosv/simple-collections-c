typedef struct list { 
	int item; 
	struct list* next; 
	struct list_functions* functions; 
} list; 

list* list_init(void); 
list** Newlist(void); 
void list_push(int pos, int item); 
int list_pop(int); 
bool list_isEmpty(void); 
extern inline void list_setSelf(list** selected_LIST); 

struct list_functions
{ 
	void (*setSelf)(list **); 
	void (*push)(int, int);
	int (*pop)(int);
	bool (*isEmpty)(void);
} static functions = { 
	list_setSelf, 
	list_push, 
	list_pop, 
	list_isEmpty 
}; 

static list** self = NULL; 

extern inline void list_setSelf(list** selected_LIST) { 
	self = selected_LIST; 
} 

list* list_init() { 
	list* LIST = malloc(sizeof(list)); 
	LIST->next = NULL; 
	LIST->functions = &functions; 
	return LIST; 
} 

list** Newlist () {
	list* LIST = list_init(); 
	list** obj = malloc(sizeof(list**)); 
	obj = &LIST; 
	return obj; 
} 

void list_push(int pos, int item) {
	int current_pos = 0;
	list* aux = &(**self);
	while(aux->next && current_pos < pos) {
		aux++;
		pos++;
	}
	aux
	 
}
void list_append(int item) {
	list *next = list_init();
	(**self).next = next; 
	(**self).item = item;
	 
}
bool list_isEmpty() {
	return !((**self).next); 
}

int list_pop(int index) {
	int item = (**self).item; 
	list* actual = *self; 
	*self = (**self).next; 
	return item; 
}

int list_items() {

	int item = (**self).item; 
	list* actual = *self; 
	*self = (**self).next; 
	return item; 
}