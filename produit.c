#include<stdio.h>
int main()
{
    int a, b;
    int resultat = 0;

    printf("Entrer deux entiers\n");
    scanf("%d%d", &a,&b);

    while(b != 0)
    {
        if(b&1)
            resultat += a;
        
        a <<= 1;
        b >>=1;
    }
    printf("le resultat est %d\n", resultat);
    return 0;
}