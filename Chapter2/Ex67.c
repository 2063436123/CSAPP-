/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>
#define BITS 32

int bad_int_size_is()
{
    int set_msb = 1 << (BITS - 1);
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int main()
{
    printf("%d\n", bad_int_size_is());
}