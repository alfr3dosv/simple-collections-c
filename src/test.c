#include <stdio.h>
#include "tests/stack.h"
#include "tests/linked_list.h"

char * run_tests() {
    return 0;
}

static char * all_tests() {
    mu_run_suite(stack_tests);
    mu_run_suite(linked_list_tests);
    return 0;
}

int main() {
    char* results = all_tests();
    if (results != 0) {
        printf("%s\n", results);
    } else {
        printf("\nALL TESTS PASSED\n");
        printf("Tests run: %d\n", tests_run);
    }
}