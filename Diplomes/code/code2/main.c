#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"
int main (void)
{
    srand(time(NULL));
    int choix;
    system("clear");
    printf("1- GENERER NOMS DES CANDIDATS\n");
    printf("2- GENERER DATES DE NAISSANCE DES CANDIDATS\n");
    printf("3- GENERER MATRICULES DES CANDIDATS\n");
    printf("4- GENERER LES NOTES DES CANDIDATS\n");
    printf("5- GENERER LES ETABLISSEMENTS\n");
    printf("0- OUBLIER LA GENERATION\n");
    printf("\n\n");
    printf("Entrez une option : ");
    scanf("%d",&choix);
    if(choix==1)
        nom_candidat();
    else if(choix==2)   
        date_naissance();
    else if(choix==3)
        matricule();
    else if(choix==4)
        note();
    else if(choix==5)
        etablissement();
    else if(choix==0)
        printf("Merci d'utiliser nos services :)\n");
    return 0;
}