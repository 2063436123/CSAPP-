/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    return ~(-1 << k) & xsra;
}

int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    int shift_val = sizeof(int) << 3;
    // msb 类似 (x < 0) 1000 0000 或 (x>=0) 0000 0000; ~(msb - 1) 相应为 1..1 1000 0000, 0..0
    int msb = (1 << shift_val - 1 - k) & xsrl;
    int mask = ~(msb - 1);
    return xsrl | mask;
}

int main()
{
    printf("%u\n", srl(255, 4));  // 1111 1111 -> (logic) 0000 1111 || (arithmetic) 1111 1111
    printf("%d\n", sra(-128, 4)); // divide by 2^4=16
}