/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>

unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    int bias = x >> (w - n - 1);
    return bias >> 1 | x << n;
}

int main()
{
    printf("%X\n", rotate_left(0x12345678, 4));
    printf("%X\n", rotate_left(0x12345678, 20));
    printf("%X\n", rotate_left(0x12345678, 0));
}