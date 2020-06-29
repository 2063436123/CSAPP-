#include <string>
#include <stdio.h>
int main()
{
    printf("%.18f %.18f %.18f %d \n", 0.1, 0.2, 0.3, 0.1 + 0.2 == 0.3);
    printf("%.8X %.8X %.8X\n", 0x00AA1390,0x00AA45B0, (0x00AA1390 || 0x00AA45B0));
    printf("%5f", 234.0);
}