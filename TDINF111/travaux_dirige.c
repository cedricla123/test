#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include "travaux_dirige.h"

void exercice1(void)
{
    unsigned int n;
    unsigned int i;

    printf("Entrer votre element\n");
    scanf("%u", &n);
    
    // 1ere question.

    n = n&0;

    // 2eme Question

    printf("%u\n", n);
    n = n | 0xffffffff;

    //3eme question

    printf("%u\n", n);
    i = 3;
    n = (n & 0) |(1<<i); 
    printf("%u\n", n);

    //4eme Question.

    i = 0;
    n = (n | 0xffffffff) ^ (1<<i);
    printf("%u\n", n);

    //5eme Question.
    
    n = 8; 
    i = 3;
    n = n | (1<<i);
    printf("%u\n", n);

    //6eme Question.

    n = 8;
    i = 3;
    n = (n | (1<<i)) ^ (1<<i);
    printf("%u\n", n);

    //7eme Question.
    n = 7;
    i = 3;
    n = n ^ (1<<i);
    printf("%u\n", n);

    //8eme Question.
    n = n & 0;
    for(int j = 0 ; j < i ; j++)
        n = n|(1<<j);
    printf("%u\n", n);

    //9eme Question.
    n = n | 0xffffffff;
    for(int j = 0 ; j < i ; j++)
        n = n^(1<<j);
    printf("%u\n", n);

    //10eme Question;

    for(int j = 0 ; j <= i ; j++)
        n = n |(1<<j);
    printf("%u\n", n);

    //11eme Question.
    for(int j = 0 ; j <= i ; j++)
        n = (n |(1<<j)) ^ (1<<j);
    printf("%u\n", n);

    //12eme Question.
}

void cercle_donnees(int R)
{
     printf("\n\tExercice 3 : CALCUL DU PERIMETRE D'UN CERCLE \n");

    float P, S;

    P = 2*R*Pi;
    S = R*R*Pi;
    printf("Le perimetre de votre cercle est P = %.2fm\n", P);
    printf("La surface de votre cercle est S = %.2fm(carree)\n", S);

}

void affichage_mention(float M)
{
    printf("\n\tExercice 4 : AFFICHAGE DE LA MOYENNE\n");
   
    if(M < 10)
    {
        if(M < 7)
            printf("MENTION : FAIBLE\n");
        else
            printf("MENTION : MEDIOCRE\n");
    }
    else if(M <= 20)
    {
        if(M < 12)
            printf("MENTION : PASASABLE\n");
        else if(M < 15)
            printf("MENTION : ASSEZ BIEN\n");
        else if(M < 18)
            printf("MENTION : BIEN\n");
        else
            printf("MENTION TRES BIEN\n");
    }
    else
        printf("Moyenne invalide veuillez entrer une moyenne valide\n");
}

void factoriel(int n)
{
    printf("\n\tEXERXICE 5 : CALCUL DU FACTORIEL\n");
    
    unsigned int f, i;
    
    f = 1;
    
    printf("\n\tboucle for\n");

    for(i = 1 ; i <= n ; i++)
        f *= i;
    printf("le factoriel de votre nombre est n! = %u\n", f);
    
    printf("\n\tboucle while\n");

    i = 1;
    f = 1;
    while(i <= n)
    {    
        f *= i;
        i++;
    }

    printf("le factoriel de votre nombre est n! = %u\n", f);
}

void pgcd(int a , int b)
{
    printf("\n\tEXERCICE 6 : CALCUL DU PGCD\n\n");

    int temp, r0 , r1;
    r0 = a;
    r1 = b;

    while(b != 0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }

    printf("le pgcd(%d,%d) = %d\n",r0 , r1 ,a);
    printf("\n");

}

void lecture_inverse(void)
{
    int TAB[10];
    printf("\n\tEXERCICE 8 : lecture et affichage de dix entier dans l'ordre inverse\n");

    printf("Entrer les valeurs de votre tableau\n");
    for(int i = 0 ; i < 10 ; i++)
    {
        scanf("%d",&TAB[i]);
    }
    printf("Element afficher de facon inverse\n");
    for(int cpt = 9 ; cpt >= 0 ; cpt--)
        printf("[%d]  ", TAB[cpt]);

    printf("\n");
}

void produit_tableau(void)
{
    printf("\n\tEXERCICE 9 : produit des valeurs de deux tableaux.\n");
    int t1[MAX], t2[MAX], t3[MAX];
    int i;

    for(i = 0 ; i < MAX ; i++)
    {
        t1[i] = 0;
        t2[i] = 0;
        t3[i] = 0;
    }

    printf("\nentrer les valeurs du tableau t1\n");
    for(i = 0 ; i < MAX ; i++)
    {
      scanf("%d", &t1[i]);
    }

    printf("entrer les valeurs du tableau t2\n");
    for(i = 0 ; i < MAX ; i++)
    {
      scanf("%d", &t2[i]);
    }

    printf("\n\tPRODUIT DES DEUX TABLEAUX\n");
    for(i = 0 ; i < MAX ; i++)
    {
      t3[i] = t1[i]*t2[i];
    }

    for(i = 0 ; i < MAX ; i++)
    {
      printf("%d |", t3[i]);
    }
    printf("\n");

}

void somme_matrice(void)
{
    printf("\n\tEXERCICE 11 : somme de deux matrice\n");

    int  C1[N][N] , C2[N][N] , C3[N][N];
    int i, j;
    
    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            C1[i][j] = 0;
            C2[i][j] = 0;
            C3[i][j] = 0;
        }
    }

    printf("\nEnregistrement des valeurs de la matrice C1\n");
    for(i = 0; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            scanf("%d", &C1[i][j]);
        }
    }
    printf("\nEnregistrement des valeurs de la matrice C2\n");
    for(i = 0; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            scanf("%d", &C2[i][j]);
        }
    }
    
    printf("\nSOMMES DES DEUX MATRICES\n");
     for(i = 0; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            
            C3[i][j] = C1[i][j]+C2[i][j];
        }
    }

    for(i = 0; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            printf("%d |", C3[i][j]);
        }
    }
    printf("\n");
}

void produit_matrice(void)
{
    printf("\n\tEXERCICE 10 : produit de deux matrice\n");

    int  C1[N][N] , C2[N][N] , C3[N][N];
    int i, j;
    
    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            C1[i][j] = 0;
            C2[i][j] = 0;
            C3[i][j] = 0;
        }
    }

    printf("\nEnregistrement des valeurs de la matrice C1\n");
    for(i = 0; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            scanf("%d", &C1[i][j]);
        }
    }
    printf("\nEnregistrement des valeurs de la matrice C2\n");
    for(i = 0; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            scanf("%d", &C2[i][j]);
        }
    }
    
    printf("\nPRODUIT DE DEUX MATRICES\n");
     for(i = 0; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            
            C3[i][j] = C1[i][j]*C2[i][j];
        }
    }

    for(i = 0; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            printf("%d |", C3[i][j]);
        }
    }
    printf("\n");

}

void exercice11(void)
{
    printf("EXERCICE 12 : Algorithme premier\n");
    int n,d,q,r;

    do
    {
        printf("Entrer un entier\n");
        scanf("%d",&n);
    }while(!(n > 1));

    d = 2;
    q = n/d;
    r = n - q*d;

    while((r != 0) && (d < n-1))
    {
        if(d == 2)
            d += 1;
        else
            d += 2;

        q = n/d;
        r = n - q*d;

    }

    if((r == 0) && (n != 2))
        printf("%d n'est pas premier\n", n);
    else
        printf("%d est  premier\n", n);

}

void NombrePremier(void)
{
    int n, i = 2, racine;
    printf("Entrez un entier naturel\n");
    scanf("%d",&n);
    if (n == 1 || n == 0)
    {
        printf("Ce n'est pas un nombre premier\n");
    }
    else
    {
        racine = sqrt(n);
        while (i <= racine && n % i != 0)
        {
            ++i;
        }
        if (i - 1 == racine)
        {
            printf("%d  nombre est premier\n", n);
        }
        else
        {
            printf("%d n'est pas un nombre premier\n",n);
        }
    }
}
int ProduitBit(int a, int b)
{

    int resultat = 0;
    while(b != 0)
    {
        if(b&1)
            resultat += a;
        
        a <<= 1;
        b >>=1;
    }
    return resultat;
}

void init_table(int* tab , int n)
{
   int i;
  
   for(i = 0 ; i < n ; i++)
    tab[i] = 1;
}

void multible(int* tab, int n, int i)
{
    int j;
    for(j = 0 ; j < n ; j += i)
        tab[j] = 0;
}

void liste_premier(int* tab, int n)
{
    init_table(tab , n);
    
    tab[0] = 0;
    tab[1] = 0;
    for(int i = 2 ; i < n ; i++)
    {
        if(tab[i] == 1)
        {
            multible(tab , n , i);
            tab[i] = 1;
        }
    }
}

int somme_ligne(int** mat, int n, int i)
{
    int som = 0, j;
    for(j = 0 ; j < n ; j++)
        som += mat[i][j];

    return som;
}

int somme_colonne(int** mat, int n, int j)
{
    int som2 = 0, i;
    for(i = 0 ; i < n ; i++)
        som2 += mat[i][j];

    return som2;
}

void trie_change(int* tab, int n)
{
    int i,aux;
    bool inversion;
    do
    {
        inversion = 1;
        for(int i = 0 ; i < n ; i++)
        {
            if(tab[i]>tab[i+1])
            {
                aux = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = aux;
                inversion = 0;
            }
        }
    }while(inversion = 0);
}
int recherche_dichotomique(int tableau[], int taille, int valeur) 
{
    int gauche = 0, droite = taille - 1, milieu;
    while (gauche <= droite) {
        milieu = (gauche + droite) / 2;
        if (tableau[milieu] == valeur) {
            return milieu;
        } else if (tableau[milieu] > valeur) {
            droite = milieu - 1;
        } else {
            gauche = milieu + 1;
        }
    }
    return -1;
}
void trie_table(int* TAB, int N)
{
    
}

