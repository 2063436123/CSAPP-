/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    int w = sizeof(int) << 3;
    // 先运算再移位可以生成FFFF 和 0000 而非 0001 和 0000
    int a = (x ^ y) >> (w - 1);       // x，y同号为0
    int b = (x ^ (x + y)) >> (w - 1); // x,y异号为1
    int c = x >> (w - 1);             // 负溢出为FFFF
    return (a & (x + y)) + (~a & ((~b & (x + y)) + ( b & ((c & INT_MIN) + (~c & INT_MAX)))));
}

int main()
{
    printf("%d\n", saturating_add(123456, -54321));
    printf("%d\n", saturating_add(2147483647, 1));
    printf("%d\n", saturating_add(-2147483648, -1));
}