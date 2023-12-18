#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000
int main(void)
{
    srand(time(NULL));

    float Tab[MAX];
    int i,j;
    float e;
    bool trouver;

    do
    {
        printf("entrer la taille de votre tableau (<1000)\n");
        scanf("%d", &j);
    }while(!(j < 1000 && j > 0));
    
    for(i = 0 ; i < j ; i++)
    {
        Tab[i] = rand()%1001;
    }
    printf("Tableau d'elements donc vous pouvez chercher votre element\n");
    for(i = 0 ; i < j ; i++)
    {
        printf("[%f]\n", Tab[i]);
    }
    trouver = 0;
    
    printf("entrer l'element a rechercher\n"); 
    scanf("%f", &e);

    i = 0;
    while((!trouver) && (i < j))
    {
        if(Tab[i] == e)
            trouver = 1;
        else
            i++;
    }

    if(trouver)
        printf("L'element rechercher est E = %f, et ce trouve a la case %d\n", e , i+1);
    else
        printf("Element introuvable\n");
    
    return 0;
}
