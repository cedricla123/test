#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"

int main(void)
{
    int choix;
    float* vecteur = (float*)malloc(sizeof(float)*SIZE);
    float* vecteur1 = (float*)malloc(sizeof(float)*SIZE);
    float* vecteur2 = (float*)malloc(sizeof(float)*SIZE);
    system("clear");
    do
    {
        printf("1- SAISIR LES CORDONNEES D'UN VECTEUR\n");
        printf("2- AFFICHAGE DES CORDONNEES D'UN VECTEUR\n");
        printf("3- ADDITION DE DEUX VECTEURS\n");
        printf("4- SOUSTRACTION DE DEUX VECTEURS\n");
        printf("5- PRODUIT SCALAIRE DE DEUX VECTEURS\n");
        printf("6- NORME D'UN VECTEUR\n");
        printf("7- DISTANCE EUCLIDIENNE DE DEUX VECTEURS\n");
        printf("0- QUITTER LE PROGRAMME\n\n\n");

        printf("Entrer une option : ");
        scanf("%d", &choix);

        switch(choix)
        {
            case 1:
                int nombreElement;
                system("clear");
                do
                {
                    printf("Entrer la taille  de votre vecteur : ");
                    scanf("%d", &nombreElement);
                }while(!(nombreElement >=2));
                vecteur = saisir_element(vecteur , nombreElement);
                break;
            case 2:
                system("clear");
                affichage_element(vecteur , nombreElement);
                break;
            case 3:
                printf("Entrer les cordonnees du deuxiemes vecteurs\n");
                vecteur1 = saisir_element(vecteur1 , nombreElement);
                vecteur2 = addition_vecteurs(vecteur , vecteur1 , nombreElement);
                affichage_element(vecteur2, nombreElement);
                break;
            case 4:
                vecteur2 = soustraction_vecteurs(vecteur , vecteur1 , nombreElement);
                affichage_element(vecteur2 , nombreElement);
                break;
            case 5:
                float produit=0;
                produit=produit_scalaire(vecteur , vecteur1 , nombreElement);
                printf("Le produit scalaire des deux vecteurs est %.1f \n", produit);
                break;
            case 6:
                do
                {
                    printf("Entrer la taille  de votre vecteur : ");
                    scanf("%d", &nombreElement);
                }while(!(nombreElement >=2));
                vecteur = saisir_element(vecteur , nombreElement);
                float norme=0;
                norme=norme_vecteur(vecteur , nombreElement);
                printf("La norme du vecteur est %.1f\n", norme);
                break;
            case 7:
                float distance=0;
                do
                {
                    printf("Entrer la taille  de votre vecteur : ");
                    scanf("%d", &nombreElement);
                }while(!(nombreElement >=2));
                vecteur1 = saisir_element(vecteur1 , nombreElement);
                vecteur2 = saisir_element(vecteur2 , nombreElement);
                distance = distance_euclidienne(vecteur1 , vecteur2 , nombreElement);
                break;
            case 0:
                system("clear");
                printf("MERCI D'UTILISER NOS SERVICES \n");
                break;
            default:
                printf("entrer une valeur valide :)\n");
                break;
        }
    } while(choix!=0);
    
    free(vecteur);
    free(vecteur1);
    free(vecteur2);
}