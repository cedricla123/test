#include<stdio.h>
int main()
{
    int a,b,temp;
    // ce programme fait la permutation de a et b.
    printf("******Entrer deux chiffres*******\n");
    scanf("%d%d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    printf("a = %d b = %d\n", a,b);
    return 0;
}