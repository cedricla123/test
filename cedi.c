#include<stdio.h>
int main()
{
    int a = 12, b = 10 , c, d,e, x1,x2;
    c = a&b;
    e = a|b;
    d = a^b;
    x1 = a << 2;
    x2 = b >> 2;

    printf("c = %d  d = %d  e = %d  x1 = %d  x2 = %d\n", c, d , e,x1, x2);
    return 0;
}