/**
 * Author: Louis
 * Description: nothing
 * Copyright (C) 2020
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 **/
#include <stdio.h>
#include <limits.h>

int int_shifts_are_arithmetic()
{
    return !(-1 >> 8 ^ -1);
    /* Use unsigned take place logic_shifts 
    unsigned x = -1;
    return !(x >> 8 ^ -1); */
}

int main()
{
    printf("%d\n", int_shifts_are_arithmetic());
}