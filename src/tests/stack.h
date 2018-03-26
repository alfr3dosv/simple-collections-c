// test cases for collections/stack

#include <stdbool.h>
#include "collections/stack.h"
#include "minunit.h"

int tests_run = 0;

STACK(char, Stack, stack_char);

static char * test_stack_new() {
    Stack* stack = stack_char_new();
    mu_assert(stack);
    return 0;
}

static char * test_stack_push() {
    Stack* stack = stack_char_new();
    mu_assert(stack_char_push(stack, 'd') == true);
    return 0;
}


char * stack_tests() {
    mu_run_test(test_stack_new);
    mu_run_test(test_stack_push);
    return 0;
 }