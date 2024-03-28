#ifndef __VECTEUR__H__
#define __VECTEUR__H__
    #define SIZE 1000
    
    float* saisir_element(float* , int); 
    void affichage_element(float* , int);
    float* addition_vecteurs(float* , float* , int);
    float* soustraction_vecteurs(float* , float* , int);
    float  produit_scalaire(float* , float* , int);
    float puissance(float , int);
    //float racine_element(float, int);
    float norme_vecteur(float* , int);
    float distance_euclidienne(float* , float* , int);
#endif