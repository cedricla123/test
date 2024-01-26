#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
#define N 10

typedef struct etudiant
{
    char matricule[N];
    char nom[N];
    char prenom[N];
    int age;
    char filiere[N];
    int niveau;
    int cotisation;
}etudiant;
int main()
{
    etudiant etudiant[SIZE];
    int i,j,nombreEtudiant;

    system("clear");
    do
    {
        printf("Entrez le nombre d'etudiant\t\t : ");
        scanf("%d", &nombreEtudiant);
    }while(!(nombreEtudiant > 0) && (nombreEtudiant <=100));

    for(i=0 ; i<nombreEtudiant ; i++)
    {
        printf("Entrez le numero de CNI de l'etudiant %d\t\t : ", i+1);
        scanf("%s", etudiant[i].matricule);
        printf("Entrez le nom de l'etudiant %d\t\t : ", i+1);
        scanf("%s", etudiant[i].nom);
        printf("Entrez le prenom de l'etudiant %d\t\t : ", i+1);
        scanf("%s", etudiant[i].prenom);
        printf("Entrez l'age de l'etudiant %d\t\t : ", i+1);
        scanf("%d", &etudiant[i].age);
        printf("Entrez la filiere de l'etudiant %d\t\t : ", i+1);
        scanf("%s", etudiant[i].filiere);
        do
        {
            printf("Entrez comme entier le niveau de l'etudiant %d\t\t : ", i+1);
            scanf("%d", &etudiant[i].niveau);
        }while(!(etudiant[i].niveau > 0) && (etudiant[i].cotisation <=8));
        printf("Entrez la somme de la cotisation de l'etudiant %d\t\t : ", i+1);
        scanf("%d", &etudiant[i].cotisation);
    }
    printf("\n\n");
    i=0;
    char matricule[N];
    printf("\nEntrez le matricule de l'etudiant a modifier ses informations\t\t : ");
    scanf("%s", matricule);
    int Aux , position , trouver = 0;
    while(i < nombreEtudiant && !trouver)
    {
        Aux = strcmp(etudiant[i].matricule , matricule);
        if(Aux == 0)
        {   
            trouver = 1;
            position = i;
        }
        else
            i++;
    }
    if(trouver)
    {
        printf("Entrez le numero de CNI de l'etudiant ayant pour matricule %s\t\t : ", matricule);
        scanf("%s", etudiant[position].matricule);
        printf("Entrez le nom de l'etudiant ayant pour matricule %s\t\t : ", matricule);
        scanf("%s", etudiant[position].nom);
        printf("Entrez le prenom de l'etudiant ayant pour matricule %s\t\t : ", matricule);
        scanf("%s", etudiant[position].prenom);
        printf("Entrez l'age de l'etudiant ayant pour matricule %s\t\t : ", matricule);
        scanf("%d", &etudiant[position].age);
        printf("Entrez la filiere de l'etudiant ayant pour matricule %s\t\t : ", matricule);
        scanf("%s", etudiant[position].filiere);
        do
        {
            printf("Entrez le comme entier le niveau de l'etudiant ayant pour matricule %s\t\t : ", matricule);
            scanf("%d", &etudiant[position].niveau);
        }while(!(etudiant[position].niveau > 0) && (etudiant[position].cotisation <=8));
        printf("Entrez la somme de la cotisation de l'etudiant ayant pour matricule %s\t\t : ", matricule);
        scanf("%d", &etudiant[position].cotisation);
        
    }
    else
        printf("L'etudiant n'exite pas :( \n");
    printf("\n\n");
    printf("Entrez le matricule de l'etudiant a supprimer\t\t : ");
    scanf("%s", matricule);
    i=0;
    Aux=0;
    trouver = 0;
    position = 0;
    while(i < nombreEtudiant && !trouver)
    {
        Aux = strcmp(etudiant[i].matricule , matricule);
        if(Aux == 0)
        {   
            trouver = 1;
            position = i;
        }
        else
            i++;
    }
    int k,compteur = 0;
    if(trouver)
    {
        for(i=0 ; i<nombreEtudiant ; i++)
        {
            if(i != position)
            {
                for(k=0 ; k<nombreEtudiant-1 ; k++)
                    etudiant[k] = etudiant[k];
                compteur++;
            }
        }
        printf("L'etudiant %s a ete supprimer avec succes\n", etudiant[position].nom);
    }
    else
    {
        printf("Etudiant introuvable verifier le matricule entrer.\n");
        compteur = nombreEtudiant+1;
    }
    printf("\n\n");
    nombreEtudiant=compteur;
    for(i=0 ; i<nombreEtudiant-1 ; i++)
        printf("%10s %10s %10d\n", etudiant[i].matricule, etudiant[i].nom, etudiant[i].cotisation);
    printf("\n\n");
    int sommeCotisation = 0;
    for(i=0 ; i<nombreEtudiant ; i++)
        sommeCotisation += etudiant[i].cotisation;
    printf("\t SOMME TOTAL DES COTISATIONS : %d\n", sommeCotisation);
    printf("\n\n");
    i=0;
    Aux=0;
    trouver = 0;
    position = 0;
    printf("Entrez le matricule de l'etudiant rechercher\t\t : ");
    scanf("%s", matricule);
    while(i < nombreEtudiant && !trouver)
    {
        Aux = strcmp(etudiant[i].matricule , matricule);
        if(Aux == 0)
        {   
            trouver = 1;
            position = i;
        }
        else
            i++;
    }
    if(trouver)
    {    
        printf("%10s %10s %10s %10d ", etudiant[position].matricule,etudiant[position].nom,etudiant[position].prenom,etudiant[position].age);
        printf("%10s %10d %10d\n", etudiant[position].filiere, etudiant[position].niveau,etudiant[position].cotisation);
    }   
    else
        printf("Etudiant introuvable \n");
    return 0;
}