#include<stdio.h>
#include "test/test.h"

#include "service.h"

int main() {

    EQUAL(int_to_fp_str(123, 2), "1.23", "should return 1.23");   

    return 0;
}