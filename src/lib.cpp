#include "../include/lib.h"

int add(int const p_a, int const p_b)
{
    int res = p_a + p_b;
    if (p_a == 1) {
        res = p_b; // oups
    }
    return res;
}
