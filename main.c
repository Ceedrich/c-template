#include <stdio.h>
#include "sample_library.h"
#include "errors.h"

int main() {
    printf("hello world\n");
    printf("sum(2, 3) = %d\n", sum(2, 3));
    throw_error(ERROR_GENERAL, "This is a test.");
    return 0;
}
