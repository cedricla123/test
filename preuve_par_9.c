#include<stdio.h>
#include<stdlib.h>
#define Max 100

int main()
{
    int x[Max];
    int y[Max];
    float q, preuv;
    int n1, n2, i;

    printf("Entrer le nombre de chiffre que compte votre dividante\n");
    scanf("%d", &n1);

    printf("Entrer le nombre de chiffre de votre diviseur\n");
    scanf("%d", &n2);

    printf("ENTRER UNE A UNE LES CHIFFRES DE VOTRE DIVIDANTE\n");
    for(i = 0 ; i < n1 ; i++)
    {
       scanf("%d", &x[i]);
    }

    printf("ENTRER UNE A UNE LES CHIFFRE DE VOTRE DIVISEUR\n");
    for(i = 0 ; i < n2 ; i++)
    {
       scanf("%d", &y[i]); 
    }
    return 0;
}