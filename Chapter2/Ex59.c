#include <stdio.h>
int main() {
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    // shift operators take precedence over bit operators
    printf("%X\n",(x&0xFF) | (y&-1 << 8) );
}