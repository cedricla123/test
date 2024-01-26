#include <stdio.h>
#include <stdlib.h>
#define CARRE(a) a*a
int main()
{
    int i,j,tailleMatrice,sommEtenduMatrice, SommLigne,Sommcolonne,SommDiagonale1,SommDiagonale2;
    printf("Entrez la taille de la matrice : ");
    scanf("%d", &tailleMatrice);
    int matrice[tailleMatrice][tailleMatrice];
    for(i=0 ; i<tailleMatrice ; i++)
    {   
        for(j=0 ; j<tailleMatrice ; j++)
        {
            printf("Entrez l'element de la ligne %d et de la colonne %d : ",i+1,j+1);
            scanf("%d", &matrice[i][j]);
        }
    }
    int verifier = 0;
    sommEtenduMatrice = (tailleMatrice +(CARRE(tailleMatrice)+1))/2;

    //Calcul de la somme des lignes et verification de la compatibiliter.

    for(i=0 ; i<tailleMatrice ; i++)
    {
        SommLigne = 0;
        for(j=0 ; j<tailleMatrice ; j++)
        {
            SommLigne += matrice[i][j];
        }
        if((SommLigne != sommEtenduMatrice) && !verifier)
            verifier = 0;
        else
            verifier = 1;
    }

    //calcul de la somme des colonnes et verification de la compatibiliter.

    for(j=0 ; j<tailleMatrice ; j++)
    {
        Sommcolonne = 0;
        for(i=0 ; i<tailleMatrice ; i++)
        {
            Sommcolonne += matrice[i][j];
        }
        if((Sommcolonne != sommEtenduMatrice) && !verifier)
            verifier = 0;
        else
            verifier = 1;
    }
    
    //Calcul de la somme de la premiere diagonal et verification.
    
    SommDiagonale1 = 0;
    for(i=0 ; i<tailleMatrice ; i++)
    {
        for(j=0 ; j<tailleMatrice ; j++)
        {
            if(i == j)
                SommDiagonale1 += matrice[i][j];
        }
    }
    if((SommDiagonale1 != sommEtenduMatrice) && !verifier)
        verifier = 0;
    else
        verifier = 1;

    //Calcul de la somme de la deuxieme diagonal et verification.
    
    SommDiagonale2 = 0;
    for(i=tailleMatrice-1 ; i>=0 ; i--)
    {
        for(j=0 ; j<tailleMatrice ; j++)
        {
            if(i == j)
                SommDiagonale2 += matrice[i][j];
        }
    }
    if((SommDiagonale2 != sommEtenduMatrice) && !verifier)
        verifier = 0;
    else
        verifier = 1;

    //conclusion sur la nature de la marice.
    if(verifier)
    {
        system("clear");
        printf("votre matrice : \n");
        for(i=0 ; i<tailleMatrice ; i++)
        {
            for(j=0 ; j<tailleMatrice ; j++)
                printf("%3d", matrice[i][j]);
            printf("\n");
        }
        printf("\tEST UN CARRE MAGIQUE\n");
    }
    else
    {
        system("clear");
        printf("votre matrice : \n");
        for(i=0 ; i<tailleMatrice ; i++)
        {
            for(j=0 ; j<tailleMatrice ; j++)
                printf("%3d ", matrice[i][j]);
            printf("\n");
        }
        printf("N'EST PAS UN CARRE MAGIQUE\n");
    }
    return 0;
}