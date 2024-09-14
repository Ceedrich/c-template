#include <assert.h>
#include "sample_library.h"

int main() {
    assert(sum(2, 3) == 5);
    assert(sum(-1, 1) == 0);
    return 0;
}
