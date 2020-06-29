/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;
float_bits* float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (!(exp ^ 0xFF))
    {
        if (frac)
        return f;
    }
    else
    {
        if (exp)
        {
            if (!(frac >> 22))
                frac <<= 1;
            else if (~(exp ^ 0xEF))
                exp++;
            else
            {
                exp = 0xFF;
                frac = 0;
            }
        }
        else
        {
            if (!(frac >> 22))
                frac <<= 1;
            else {
                exp++;
                frac = frac << 10 >> 9;
            }
        }
    }
    unsigned* temp = malloc(32);
    *temp = (sign << 31) | (exp << 23) | frac;
    return temp;
}

float* twice(float x) {
    float* temp = malloc(32);
    *temp = (2.0 * x);
    return temp;
}

void show_bytes(unsigned char* start, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        // havn't binary mode, instead of hex mode
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

int main()
{
    show_bytes((unsigned char*)(float_twice(3.5)),sizeof(float));
    show_bytes((unsigned char*)(twice(3.5)),sizeof(float));
}