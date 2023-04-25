#include <iostream>

#define SUCCESS_COLOR "\033[32m"
#define FAIL_COLOR "\033[31m"

#define success_print(test_name) \
    (std::cout          \
    << SUCCESS_COLOR    \
    << "OK - "          \
    << test_name        \
    << "\n")

#define fail_print(test_name) \
    (std::cout      \
    << FAIL_COLOR   \ 
    << "NOK - "     \
    << test_name    \
    << "\n")

#define EQUAL(x, y, test_name) \
    (((x) == (y)) ? \
    success_print(test_name) \
    : fail_print(test_name))

#define TRUE(x, test_name) \
    ((x) ? \
    success_print(test_name) \
    : fail_print(test_name))

#define FALSE(x, test_name) \
    ((!x) ? \
    success_print(test_name) \
    : fail_print(test_name))