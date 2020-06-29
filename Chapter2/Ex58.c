#include <stdio.h>

int is_little_endian()
{
    int x = 1 << 4;

    unsigned char *pointer = (unsigned char *)&x;
    if (pointer[0] == 0)
        return 0;
    return 1;
}

int main()
{
    printf("%d\n", is_little_endian());
}