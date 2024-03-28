#include <stdio.h>
#include <stdlib.h>
#include "outil.h"

int main()
{
    int choix, i , nombreElement;
    do
    {
        DIESE;
        printf("|\t  ELABORATION DES DIPLOMES  \t\t|\n");
        DIESE;
        printf("1-  AJOUTER UN CANDIDAT\n");
        printf("2-  AJOUTER LES NOTES DU CANDIDAT\n");
        printf("3-  IMPRIMER LE DIPLOME DU CANDIDAT\n");
        printf("0-  QUITTER LE PROGRAMME\n");
        printf("\n\n");
        printf("Entrez une option : ");
        scanf("%d", &choix);
        switch(choix)
        {
            case 1:
                system("clear");
                saisir_candidat(&cad);
                break;
            case 2:
                system("clear");
                do
                {
                    printf("Quel est le nombre de matieres (max = 12) : ");
                    scanf("%d", &nombreElement);
                } while (!(nombreElement<13 && nombreElement>0));
                saisie_note(&cad , nombreElement);
                break;
            case 3:
                system("clear");
                break;
            case 0 :
                printf("Merci d'utiliser nos services :)\n");
                break;
            default:
                printf("Option invalide\n");
            break;
        } 
    }while (choix!=0); 
}