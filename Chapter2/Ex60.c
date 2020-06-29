#include <stdio.h>
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    int bias = i;
    unsigned char *ptr = (unsigned char *)&x;
    *(ptr + i) = b;
    return x;
}

int main()
{
    printf("%X\n", replace_byte(0x12345678, 2, 0xAB));
    printf("%X\n", replace_byte(0x12345678, 0, 0xAB));
}