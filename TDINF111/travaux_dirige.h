#ifndef TD_H
#define TD_H
#define Pi 3.14
#define MAX 10
#define N 8
#define SIZE 10

    int ProduitBit(int a, int b);
    void exercice1(void);
    void cercle_donnees(int R);
    void affichage_mention(float M);
    void factoriel(int n);
    void pgcd(int a , int b);
    void lecture_inverse(void);
    void produit_tableau(void);
    void somme_matrice(void);
    void produit_matrice(void);
    void exercice11(void);
    void NombrePremier(void);
    void init_table(int* tab , int n);
    void multible(int* tab, int n, int i);
    void liste_premier(int* tab, int n);
    int somme_colonne(int** mat, int n, int j);
    int somme_ligne(int** mat, int n, int i);
    void trie_change(int* tab, int n);
    int recherche_dichotomique(int tableau[], int taille, int valeur);

#endif