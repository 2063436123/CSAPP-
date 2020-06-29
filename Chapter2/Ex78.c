/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    int w = sizeof(int) << 3;
    int msb = x >> (w - 1); // x < 0:FFFFFFFF , otherwise 00000000
    printf("%.8X %.8X %.8X\n", msb, msb & (x + (1 << k) - 1), ~msb & x);
    int bias = (1 << k) - 1;
    return (((msb & ((x + bias))) + (~msb & x))) >> k;
}

int main()
{
    printf("%d\n", divide_power2(1024, 2));
    printf("%d\n", divide_power2(5, 2));
    printf("%d\n", divide_power2(-1024, 2));
    printf("%d\n", divide_power2(-5, 2));
}