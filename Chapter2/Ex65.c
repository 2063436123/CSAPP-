/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>

int odd_ones(unsigned x) {
    x = x ^ x >> 16;
    x = x ^ x >> 8;
    x = x ^ x >> 4;
    x = x ^ x >> 2;
    x = x ^ x >> 1;
    return x & 1;
}

int main() {
    unsigned x1 = 0xFF00FF00;
	unsigned x2 = 0xFF01FF00;
	printf("%d\t%d\n", odd_ones(x1), odd_ones(x2));
	return 0;
}