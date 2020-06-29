/**
* Author: Louis
* Description: nothing
* Copyright (C) 2020
* Everyone is permitted to copy and distribute verbatim copies
* of this license document, but changing it is not allowed.
**/
#include <stdio.h>
#include <limits.h>
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum) {
    int left_shift = (3 - bytenum) << 3; // 让指定的字节成为最高字节
    int right_shift = 3 << 3; // 右移24位后，最低字节为指定字节，左侧为填充的全0或全1
    return (int) word << left_shift >> right_shift;
}

int main() {
    packed_t word = 0x8008FF00;
	printf("%d\n", xbyte(word, 0));
    printf("%d\n", xbyte(word, 1));
    printf("%d\n", xbyte(word, 2));
    printf("%d\n", xbyte(word, 3));
}