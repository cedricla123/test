#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include "travaux_dirige.h"

int main(void)
{
    int x, choix;
    float y;
    unsigned int f;
    printf("\n\t[*******TD1 DE INF111*******]\n");
    printf("1  : exercice1\n");
    printf("2  : exercice2\n");
    printf("3  : exercice3\n");
    printf("4  : exercice4\n");
    printf("5  : exercice5\n");
    printf("6  : exercice6\n");
    printf("7  : exercice7\n");
    printf("8  : exercice8\n");
    printf("9  : exercice9\n");
    printf("10 : exercice10\n");
    printf("11 : exercice11\n");
    printf("12 : exercice12\n");
    printf("13 : exercice13\n");
    printf("14 : exercice14\n");
    printf("15 : exercice15\n");
    printf("16 : exercice16\n");
    printf("17 : exercice17\n");
    printf("0  : QUITTER\n");
    printf("\n");

    do
    {
        printf("Vous voulez examiner quel exercice :)\n");
        scanf("%d",&choix);
        switch(choix)
        {
            case 1 :
                exercice1();
                printf("\n");
                break;
            case 2 :
                printf("EXERCICE 2: PRODUIT D'ENTIER PAR LES BIT\n");
                int a, b;
                printf("Entrer deux entiers\n");
                scanf("%d%d", &a,&b);
                printf("le resultat de %d x %d = %d\n", a , b , ProduitBit(a,b));
                printf("\n");
                break;    
            case 3 :
                printf("entrer un votre rayon\n");
                scanf("%d", &x);
                cercle_donnees(x);
                printf("\n");
                break;
            case 4 :
                do
                {
                    printf("Entrer votre moyenne\n");
                    scanf("%f", &y);
                }while(!(y > 0));
                affichage_mention(y);
                printf("\n");
                break;
            case 5 :
                do 
                {
                    printf("entrer un nombre\n");
                    scanf("%u", &f);
                }while(!(f > 0));
                factoriel(f);
                printf("\n");
                break;
            case 6 :
                int x1,x2;
                printf("Entrer deux entier\n");
                scanf("%d%d",&x1,&x2);
                pgcd(x1,x2);
                
                break;
            case 7 :
                printf("Fait sur papier :)\n");
                break;
            case 8 :
                lecture_inverse();
                break;
            case 9 :
                produit_tableau();
                printf("\n");
                break;
            case 10 :
                somme_matrice();
                break;
            case 11 :
                produit_matrice();
                break;
            case 12 :
                printf("premiere partie du code\n");
                exercice11();
                printf("\n");
                
                printf("Deuxieme partie du code\n");
                NombrePremier();
                printf("\n");
                break;
            case 13 :
                printf("Multible de 2 : \n");
                int Y = 1000;
                int tab[1000];
                init_table(tab , Y);
                multible(tab, Y, 2);
                printf("AFFICHAGE DE TOUS LES NOMBRES PREMIERS DE 2 \n");
                for(int i = 0 ; i < Y ; i++)
                {
                    if(tab[i] == 0)
                        printf("[%d] : %d \n", i,tab[i]);
                }
                printf("\n");


                printf("AFFICHAGE DE TOUS LES NOMBRES PREMIERS DE 0 a 1000\n");
                liste_premier(tab , Y);
                for(int i = 0 ; i < Y ; i++)
                {
                    if(tab[i] == 1)
                        printf("[%3d] \n", i);
                }
                printf("\n");

                break;
            case 14 :
                int** mat;
                mat = (int**)malloc(sizeof(int*)*N);
                for(int i = 0 ; i < N ; i++)
                    mat[i] = (int*)malloc(sizeof(int)*N);
                printf("REMPLISSER LES ELEMENTS DE VOTRE MATRICE\n");
                for(int i = 0 ; i < N ; i++)
                {
                    for(int j = 0 ; j < N ; j++)
                        scanf("%d", &mat[i][j]);
                }
                int cte, i , carreMagique = 1;

                cte = somme_colonne(mat , N , 0);
                i = 1;
                while(i < N && carreMagique)
                {
                    if(cte != somme_colonne(mat, N , i))
                        carreMagique = 0;

                    i++;
                }

                i = 0;
                while(i < N && carreMagique)
                {
                    if(cte != somme_ligne(mat , N , i))
                        carreMagique = 0;

                    i++;
                }
                if(carreMagique)
                    printf("Cette matrice est un carre magique\n");
                else
                    printf("cette matrice n'est pas un carre magique\n");
                break;
            case 15 :
                    printf("En cour d'inplementation\n");
                break;
            case 16 :
                {
                    int tableau[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
                    int taille = sizeof(tableau) / sizeof(int);
                    int valeur = 11;
                    int index = recherche_dichotomique(tableau, taille, valeur);
                    if (index == -1) {
                        printf("La valeur %d n'a pas été trouvée.\n", valeur);
                    } else {
                        printf("La valeur %d a été trouvée à l'index %d.\n", valeur, index);
                    }
                }
            break;
            case 17 :
                printf("en cour d'implementation service limite :( \n");
            break;
            case 0 :
                printf("Merci d'avoir utiliser nos servives :)\n");
            default :
                printf("Option invalide :(\n");
                break;
        }
    }while(!(choix >= 0));
    
    return 0;
}