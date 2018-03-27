#include "collections/linked_list.h"

LINKED_LIST(int, Integers, ints);

static char* test_new() {
    Integers* i = ints_new();
    mu_assert(i != NULL);
    return 0;
}

static char* test_insert() {
    Integers* i = ints_new();
    mu_assert(ints_insert(i, 0, 6) != NULL);
    mu_assert(ints_insert(i, 1, 7) != NULL);
    mu_assert(ints_insert(i, 1, 8) != NULL);
    mu_assert(ints_insert(i, 10, 9) == NULL);
    return 0;
}

static char* test_iterable() {
    Integers* list = ints_new();
    ints_insert(list, 0, 6);
    ints_insert(list, 1, 7);
    ints_insert(list, 2, 8);
    ints_insert(list, 3, 9);
    IntegersNode* iterator = list->head;
    int i = 0;
    while(iterator) {
        i++;
        iterator = iterator->next;
    }
    int j = 0;
    iterator = list->last;
    while(iterator) {
        j++;
        iterator = iterator->previous;
    }
    mu_assert(list->size == 4);
    mu_assert(i == 4);
    mu_assert(j == 4);
    return 0;
}

static char* test_remove() {
    Integers* i = ints_new();
    ints_insert(i, 0, 6);
    ints_insert(i, 1, 7);
    ints_insert(i, 2, 8);
    ints_insert(i, 3, 9);
    mu_assert(ints_remove(i, 0) ==  6);
    mu_assert(ints_remove(i, 1) ==  8);
    mu_assert(i->size == 2);
    mu_assert(ints_remove(i, 0) ==  7);
    mu_assert(ints_remove(i, 0) ==  9);
    mu_assert(i->size == 0);
    return 0;
}

static char* test_append() {
    Integers* list = ints_new();
    mu_assert(ints_append(list, 6) != NULL);
    mu_assert(ints_append(list, 7) != NULL);
    mu_assert(ints_append(list, 8) != NULL);
    mu_assert(ints_append(list, 9) != NULL);
    mu_assert(list->size == 4);
    mu_assert(ints_get(list, 3) == 9);
    return 0;
}

static char* test_pop() {
    Integers* list = ints_new();
    mu_assert(ints_append(list, 6) != NULL);
    mu_assert(ints_append(list, 7) != NULL);
    mu_assert(ints_append(list, 8) != NULL);
    mu_assert(ints_append(list, 9) != NULL);
    mu_assert(list->size == 4);
    mu_assert(ints_pop(list) == 9);
    mu_assert(list->size == 3);
    mu_assert(ints_pop(list) == 8);
    mu_assert(ints_pop(list) == 7);
    mu_assert(ints_pop(list) == 6);
    return 0;
}

static char* test_get() {
    Integers* i = ints_new();
    mu_assert(ints_insert(i, 0, 6) != NULL);
    mu_assert(ints_insert(i, 1, 7) != NULL);
    mu_assert(ints_insert(i, 1, 8) != NULL);
    mu_assert(ints_get(i, 0) ==  6);
    mu_assert(ints_get(i, 1) ==  8);
    mu_assert(ints_get(i, 2) ==  7);
    mu_assert(i->size == 3);
    return 0;
}

static char* test_iterable_after_remove() {
    Integers* list = ints_new();
    ints_append(list, 6);
    ints_append(list, 7);
    ints_append(list, 8);
    ints_append(list, 9);
    ints_pop(list) == 9;
    ints_pop(list) == 8;
    IntegersNode* iterator = list->head;
    int i = 0;
    while(iterator) {
        i++;
        iterator = iterator->next;
    }
    int j = 0;
    iterator = list->last;
    while(iterator) {
        j++;
        iterator = iterator->previous;
    }
    mu_assert(list->size == 2);
    mu_assert(i == 2);
    mu_assert(j == 2);
    return 0;
}

char * linked_list_tests() {
    mu_run_test(test_new);
    mu_run_test(test_insert);
    mu_run_test(test_iterable);
    mu_run_test(test_remove);
    mu_run_test(test_get);
    mu_run_test(test_append);
    mu_run_test(test_pop);
    mu_run_test(test_iterable_after_remove);
    return 0;
 }