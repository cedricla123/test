#include <stdio.h>

int somme_positif(int nombre)
{
    int i = nombre,somme=0;
    while(i >= 0)
    {
        somme+=i;
        i--;
    }
    return somme;
}

int somme_impaire(int nombre)
{
    int i = nombre , somme=0;
    while(i>=0)
    {
        if(i%2!=0)
            somme+=i;
        i--;
    }
    return somme;
}

int somme_carree(int nombre)
{
    int i=nombre , somme=0;
    while(i>=0)
    {
        somme+= i*i;
        i--;
    }
    return somme;
}

void diviseur_nombre(int nombre)
{
    int i=1;
    while(i<nombre)
    {
        if(nombre%i == 0)
            printf("%d ; ", i);
        i++;
    }
    printf("%d}\n", nombre);
}

void multible_nombre(int nombre)
{
    int i=0;
    for(i=0 ; i<nombre ;i++)
        printf("%d ; ", nombre*i);
    printf("%d}\n",nombre*i);
}
int main(void)
{
    int nombre;
    do
    {
        printf("Entrer un nombre positif : ");
        scanf("%d", &nombre);
    }while(!(nombre>=0));

    printf("La somme des entiers positifs inferieurs ou egaux a %d est %d\n", nombre , somme_positif(nombre));
    printf("La somme des entiers positifs impaire inferieurs ou egaux a %d est %d\n", nombre,somme_impaire(nombre));
    printf("La somme des carrees des nombre inferieurs ou egaux a %d est %d \n", nombre , somme_carree(nombre));
    printf("l'ensemble des diviseurs de %d est  D={", nombre);
    diviseur_nombre(nombre);
    printf("L'ensemble des multiple des n premiers nombre de %d est D={", nombre);
    multible_nombre(nombre);
    return 0;
}