/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>

int fits_bits(int x, int n) {
    int w = sizeof(int) << 3;
    return (x << (w-n) >> (w-n)) == x;
}

int main() {
    printf("%d\n", fits_bits(0xFF,7));
    printf("%d\n", fits_bits(0xFF,8));
    printf("%d\n", fits_bits(0xFF,9));
}