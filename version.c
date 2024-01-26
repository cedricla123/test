#include <stdio.h>

// Fonction pour vérifier si une matrice est un carré magique
int estCarreMagique(int matrice[][100], int tailleMatrice) {
    // Calculer la somme magique attendue
    int sommeMagiqueAttendue = (tailleMatrice * (tailleMatrice * tailleMatrice + 1)) / 2;

    // Vérifier la somme des lignes et des colonnes
    for (int i = 0; i < tailleMatrice; i++) {
        int sommeLigne = 0;
        int sommeColonne = 0;

        for (int j = 0; j < tailleMatrice; j++) {
            sommeLigne += matrice[i][j];
            sommeColonne += matrice[j][i];
        }

        // Si la somme de la ligne ou de la colonne n'est pas égale à la somme magique attendue, la matrice n'est pas un carré magique
        if (sommeLigne != sommeMagiqueAttendue || sommeColonne != sommeMagiqueAttendue) {
            return 0; // Faux
        }
    }

    // Vérifier la somme de la diagonale principale
    int sommeDiagonalePrincipale = 0;
    for (int i = 0; i < tailleMatrice; i++) {
        sommeDiagonalePrincipale += matrice[i][i];
    }

    // Si la somme de la diagonale principale n'est pas égale à la somme magique attendue, la matrice n'est pas un carré magique
    if (sommeDiagonalePrincipale != sommeMagiqueAttendue) {
        return 0; // Faux
    }

    // Vérifier la somme de la diagonale secondaire
    int sommeDiagonaleSecondaire = 0;
    for (int i = 0; i < tailleMatrice; i++) {
        sommeDiagonaleSecondaire += matrice[i][tailleMatrice - 1 - i];
    }

    // Si la somme de la diagonale secondaire n'est pas égale à la somme magique attendue, la matrice n'est pas un carré magique
    if (sommeDiagonaleSecondaire != sommeMagiqueAttendue) {
        return 0; // Faux
    }

    // Si toutes les vérifications passent, la matrice est un carré magique
    return 1; // Vrai
}

int main() {
    int tailleMatrice;

    // Demander à l'utilisateur de saisir la taille de la matrice
    printf("Entrez la taille de la matrice carree : ");
    scanf("%d", &tailleMatrice);

    // Déclarer et demander à l'utilisateur de saisir la matrice
    int matrice[100][100];
    printf("Entrez les elements de la matrice carree :\n");
    for (int i = 0; i < tailleMatrice; i++) {
        for (int j = 0; j < tailleMatrice; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    // Appeler la fonction estCarreMagique et afficher le résultat
    if (estCarreMagique(matrice, tailleMatrice)) {
        printf("La matrice est un carre magique.\n");
    } else {
        printf("La matrice n'est pas un carre magique.\n");
    }

    return 0;
}
