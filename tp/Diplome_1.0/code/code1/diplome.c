#include<stdio.h>
#include "diplome.h"

void saisir_candidat(candidat* cd)
{
    printf("Entrez le nom du candidat : ");
    scanf("%s", cd->nomCandidat);
    printf("Entrez la date et lieu de naissance du candidat : ");
    scanf("%s", cd->dateNaissance);
    printf("Entrez l'identifiant unique du candidat : ");
    scanf("%s", cd->identifiant);
    printf("Entrez la filiere du candidat : ");
    scanf("%s", cd->filiere);
    printf("Quel examen presente le candidat : ");
    scanf("%s", cd->examen);
    printf("Entrez l'etablissement du candidat : ");
    scanf("%s", cd->etablissement);
}
void saisie_note(candidat* cd, int nombreMatiere)
{
    int i;
    for(i=0 ; i<nombreMatiere ; i++)
    {
        printf("Entrez le nom de la matiere %d : ", i+1);
        scanf("%s", cd->matiere[i]);
    }
    for(i=0 ; i<nombreMatiere ; i++)
    {
        do
        {    
            printf("Entrez la note de l'etudiant a la matiere %s : ", cd->matiere[i]);
            scanf("%f", &cd->note[i]);
        }while(!(cd->note[i]>-1 && cd->note[i]<21));
    }
    for(i=0 ; i<nombreMatiere ; i++)
    {
        do
        {
            printf("Entrez le coef de la note de l'etudiant a la matiere %s : ", cd->matiere[i]);
            scanf("%f", &cd->coef[i]);
        }while(!(cd->coef[i]>-1&&cd->coef[i]<7));
    }
}
float produit_note(float note, float coef)
{
    return note*coef;
}
float sommes(float* tableau , int nombreElement)
{
    int i;
    float somme=0;
    for(i=0 ; i<nombreElement ; i++)
        somme+=tableau[i];
    return somme;
}
float moyenne_candidat(float note , float coef)
{
    return note/coef;
}
void decision(float moyenne)
{
    if(moyenne < 10)
        printf(" ECHEC\n");
    else 
        printf(" ADMIS\n");
}
char* mention(float moyenne)
{
    if(moyenne < 10)
        return "INSSUFISANT";
    else if(moyenne < 12)
        return "PASSABLE";
    else if(moyenne < 15)
        return "ASSEZ-BIEN";
    else if(moyenne < 18)
        return "BIEN";
    else
        return "TRES-BIEN";   
}