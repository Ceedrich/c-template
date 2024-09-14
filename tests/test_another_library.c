#include <assert.h>
#include "another_library.h"

int main() {
    assert(sub(2, 3) == -1);
    assert(sub(-1, 1) == -2);
    return 0;
}
