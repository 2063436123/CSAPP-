#include <stdio.h>
#include <limits.h>

int tsub_ok(int x, int y);

int main(int argc, char const *argv[])
{
    printf("%d\n", tsub_ok(123456, 54321));
    printf("%d\n", tsub_ok(2147483647, -1));
    printf("%d\n", tsub_ok(-147483648, INT_MIN));
    return 0;
}

int tsub_ok(int x, int y)
{
    int w = sizeof(int) << 8;
    y = -y;

    int first = y ^ INT_MIN;          // y 等于 INT_MIN 时，first为0, 若想不发生溢出，x 应该是个负数，
    int i = (x ^ y) >> (w - 1);       //+-:FFFFFFFF ++/--:00000000
    int j = ((x + y) ^ x) >> (w - 1); //overflow:FFFFFFFF otherwise:00000000
    //TODO: 为什么非零值做逻辑与运算会变成0？
    printf("%.8X %.8X %.8X\n",i,~j,(i || ~j));
    printf("%.8X %.8X %.8X %.8X \t %d %d\n", first, (i || ~j), !first, (x >> (w - 1)), first && (i || ~j) , !first && (x >> (w - 1)));
    return first &&
           (i || ~j) +
               !first &&
           (x >> (w - 1));
}