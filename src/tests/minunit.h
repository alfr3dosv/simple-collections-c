#ifndef MINUNIT_H
#define MINUNIT_H
#include <string.h>
char buf[1000];
#define mu_assert(test)  do { if (!(test)) {  sprintf(buf, "[TEST: %s] failed at line [%d] of file %s", #test, __LINE__, __FILE__); return buf ; } } while (0);
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0);
#define mu_run_suite(test) do { char *message = test(); \
                                if (message) return message; } while (0);
#endif