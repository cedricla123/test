#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"projet.h"
int main(void)
{
    int choix;
    char matricule[10];
    printf("\nEnsemble nous allons faire une etude :)\n\n");
    do
    {
        printf("1: SAISISSEZ LES DONNEES DES CANDIDATS\n");
        printf("2: AJOUTER UN CANDIDAT\n");
        printf("3: MODIFIER LES DONNEES D'UN CANDIDAT\n");
        printf("4: SUPPRIMER DU FICHIER UN CANDIDAT\n");
        printf("5: AFFICHER LA LISTE DES CANDIDATS \n");
        printf("6: AFFICHER LA LISTE DES CANDIDATS SOLVABLES\n");
        printf("7: AFFICHER LA LISTE DES CANDIDATS INSOLVABLES\n");
        printf("8: POURCENTAGE DES INSOLVABLES\n");
        printf("9: SUPPRIMER LES CANDIDATS N'AYANT RIEN COTISE\n");
        printf("10: RECHERCHER LES DONNEES D'UN CANDIDAT\n");
        printf("0: QUITTER LE PROGRAMME\n");
        printf("\n\n\n");
        printf("Entrez un choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
            case 1:
                system("clear");
                saisir();
                break;
            case 2:
                system("clear");
                ajouter();
                break;
            case 3:
                system("clear");
                modifier();
                break;
            case 4:
                system("clear");
                printf("Entrer un matricule : ");
                scanf("%s", matricule);
                supprimer(matricule);
            case 5:
                system("clear");
                affichage();
                break;
            case 6:
                system("clear");
                printf("**********Liste des solvables**********\n");
                solvable();
                break;
            case 7:
                system("clear");
                insolvable();
                break;
            case 8:
                system("clear");
                printf("les insolvables sont de %.1f pourcent.\n", statistique());
                break;
            case 9:
                printf("Votre demande a bien ete pris en compte :)\n");
                suprimer();
                break;
            case 10:
                system("clear");
                printf("Entrer le matricule\n");
                scanf("%s", matricule);
                recherche(matricule);
                break;
            case 0:
                printf("Merci d'avoir utiliser nos services :)\n");
                break;
            default :
                printf("choix invalide :(\n");
                break;
        }
    }while(choix != 0);
    return 0;
}