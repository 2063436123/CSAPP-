/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>
int lower_one_mask(int n)
{
    int w = sizeof(int) << 3;
    int bias = 1 << (w - 1);
    bias = bias >> (w - n);
    bias <<= 1; // 不能与上一行写在一起成为w-n-1，防止n==w时出现>>-1这种意外
    return ~bias;
}
int main()
{
    printf("%X\n", lower_one_mask(6));
    printf("%X\n", lower_one_mask(1));
    printf("%X\n", lower_one_mask(32));
}