#include<stdio.h>
int main()
{
    int a,b,i;
    b = 1;

    printf("Entrer votre multiplicateur\n");
    scanf("%d", &a);

    printf("MULTIPLICATION PAR %d\n", a);
    for(i = 0 ; i < 13 ; i++)
    {
        b = i*a;
        printf("%d x %d = %d\n", i,a,b);
    }

    return 0;
} 