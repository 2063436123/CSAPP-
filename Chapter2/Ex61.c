/**
* Author:Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>
int is_obt(int x) {
    int bias = (sizeof(int)-1) << 3;
    // ! operator take precedence over other operators
    return !(~x) || !x || !(x&0xFF^0xFF) || ! (x&(0xFF<<bias)^(0xFF<<bias));
}
int main() {
    printf("%d\n", is_obt(-1));
    printf("%d\n", is_obt(0));
    printf("%d\n", is_obt(255));
    printf("%d\n", is_obt(43775)); //0..0 1010 1010 1111 1111
    printf("%d\n", is_obt(42240)); //0..0 1010 0101 0000 0000
    printf("%d\n", is_obt(234));
    printf("%d\n", is_obt(1));
    printf("%d\n", is_obt(-323432)); //1111 1111 1111 1011 0001 0000 1001 1000
}