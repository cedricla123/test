#include <stdio.h>
#include <stdlib.h>
#include "diplome.h"

int main()
{
    int choix, i , nombreElement;
    candidat     cad;
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
                printf("\nExamen : %10s   ~  Filiere : %10s\n\n", cad.examen , cad.filiere);
                printf("Nom : %10s  ~  \tDate et lieu de naissance : %10s\n\n", cad.nomCandidat , cad.dateNaissance);
                printf("Etablissement : %10s\n\n", cad.etablissement);
                LINES;
                printf("|         MATIERES            |            NOTES           |          COEFFICIENT       |          NOTECOEFF         |\n");    
                float somme=0;
                for(i=0 ; i<nombreElement ; i++)
                {
                    LIGNE;
                    printf("|%29s|%28.1f|%28.1f|%28.1f|\n", cad.matiere[i],cad.note[i],cad.coef[i],produit_note(cad.note[i],cad.coef[i]));
                    somme+=produit_note(cad.note[i],cad.coef[i]);
                }
                LIGNE;
                float nombre1 = sommes(cad.note , nombreElement);
                float nombre2 = sommes(cad.coef , nombreElement);
                printf("|            TOTAL            |%28.1f|%28.1f|%28.1f|\n",nombre1,nombre2,somme);
                LINES;
                float auxiliaire = moyenne_candidat(somme,nombre2);
                printf("MOYENNE : %2.1f  ~  MENTION : %10s  ~ ", auxiliaire, mention(auxiliaire));
                printf("\tDECISION : ");
                decision(auxiliaire);
                printf("\n\n");
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