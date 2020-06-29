/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>
int any_odd_one(unsigned x)
{
    return (x & 0x55555555) != 0;
}
int main()
{
    printf("%d\n", any_odd_one(3));
    printf("%d\n", any_odd_one(0));
    printf("%d\n", any_odd_one(8));
}