/**
 *  Homework 2.55 - 2.57
 **/
#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        // havn't binary mode, instead of hex mode
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

template<typename T>
void shows(T x) {
    show_bytes((byte_pointer)&x, sizeof(x));
}

int main() {
    int ival = 12345;       //111001001100000000000000000000
    float fval = 12345;
    int *pval = &ival;
    short sval = 12345;
    long lval = 12345;
    double dval = 12345.0;  //10000000000111001100100001000000

    shows(ival);
    shows(fval);
    shows(pval);
    shows(sval);
    shows(lval);
    shows(dval);

    return 0;
}