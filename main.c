#include <stdio.h>
#include <stdlib.h>

// this is my entry point, as defined in CMakeLists.txt
// it can be configured by passing -e,custom_entry_point
// to the linker, but it still needs a dummy main function.
void custom_entry_point() {
    printf("hello world\n");
    exit(0);
}

int main(void) { return 0; }
