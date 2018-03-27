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
    return 0;
}

static char* test_itereable() {
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
    mu_assert(ints_remove(i, 0) ==  7);
    mu_assert(ints_remove(i, 0) ==  9);
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
    return 0;
}

char * linked_list_tests() {
    mu_run_test(test_new);
    mu_run_test(test_insert);
    mu_run_test(test_itereable);
    mu_run_test(test_remove);
    mu_run_test(test_get);
    return 0;
 }