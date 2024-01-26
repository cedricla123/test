#include <stdio.h>
int main()
{
    char coeur[100][100];
    int i,j,tailleCoeur;
    printf("Entrez la taille du coeur : ");
    scanf("%d", &tailleCoeur);
    for(i=0 ; i<tailleCoeur ; i++)
    {
        for(j=0 ; j<(tailleCoeur-i-1) ; j++)
        {
            if(j > tailleCoeur + i)
            {
                coeur[i][j] = ' ';
                printf("%c", coeur[i][j]);
            }
            else
            {
                coeur[i][j] = '*';
                printf("%c", coeur[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
