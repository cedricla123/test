#include <stdio.h>
#include "vecteur.h"

float* saisir_element(float* vecteur , int nombreElement)
{
    int i;
    for(i=0 ; i<nombreElement ; i++)
    {
        printf("Entrer l'element numero %d : ", i+1);
        scanf("%f", &vecteur[i]);
    }
    return vecteur;
}

void affichage_element(float* vecteur , int nombreElement)
{
    int i=0;
    for(i=0 ; i<nombreElement-1 ; i++)
        printf("%.1f ; ", vecteur[i]);
    printf("%.1f\n", vecteur[i]);
}

float* addition_vecteurs(float* vecteur1 , float* vecteur2 , int nombreElement)
{
    float somme[nombreElement];
    int i;
    for(i=0 ; i<nombreElement ;i++)
        somme[i] = vecteur1[i]+vecteur2[i];
    return somme;
}

float* soustraction_vecteurs(float* vecteur1 , float* vecteur2 , int nombreElement)
{
    float difference[nombreElement];
    int i;
    for(i=0 ; i<nombreElement ;i++)
        difference[i] = vecteur1[i]-vecteur2[i];
    return difference;
}

float produit_scalaire(float* vecteur1 , float* vecteur2 , int nombreElement)
{
    int i;
    float produitScalaire = 0;
    for(i=0 ; i<nombreElement ; i++)
        produitScalaire += vecteur1[i]*vecteur2[i];
    return produitScalaire;
}

float puissance(float nombre , int exposant)
{
    int i;
    float puissance = 1;
    for(i=1 ; i<=exposant ; i++)
        puissance*=nombre;
    return puissance;
}

/*float racine_element(float nombre , int racine)
{
    
}*/

float norme_vecteur(float* vecteur , int nombreElement)
{
    int i;
    float norme=0;
    for(i=0 ; i<nombreElement ; i++)
        norme+=puissance(vecteur[i] , nombreElement);
    return norme;
}

float distance_euclidienne(float* vecteur1 , float* vecteur2 , int nombreElement)
{
    float disatnceEuclidiene=0;
    disatnceEuclidiene = norme_vecteur(vecteur1 , nombreElement)-norme_vecteur(vecteur2 , nombreElement);
    return disatnceEuclidiene;
}