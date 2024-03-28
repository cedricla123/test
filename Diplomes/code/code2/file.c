#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"

void nom_candidat(void)
{
    int i,j;
    char nom[8];
    FILE* F=fopen("../../fichiers/file1/candidat.data" , "w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(-1);
    }
    for(i=0 ; i<N ;i++)
    {    
        for(j=0 ; j<8 ; j++)
            nom[j]=(char)(rand()%26+65);
        fprintf(F, "%s\n", nom);
    }
    fclose(F);
}

void date_naissance(void)
{
    int    i,jour,mois,annee;
    int x;
    FILE* F=fopen("../../fichiers/file1/dateNaissance.data" , "w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier \n");
        exit(-1);
    }
    for(i=0 ; i<N ; i++)
    {
        x=(int)rand();
        jour = (int)(x%28+1);
        mois = (int)(x%12+1);
        annee = (int)(x%35+1990);
        fprintf(F,"%d/%d/%d\n", jour,mois,annee);
    }
    fclose(F);
}
void matricule(void)
{
    char matricule[10];
    int i,j;
    FILE* F=fopen("../../fichiers/file1/matricule.data" , "w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier : %s\n", "matricule.data");
        exit(-1);
    }
    for(i=0 ; i<N ; i++)
    {
        for(j=0 ; j<10 ; j++)
        {
            if(j==2||j==3)
                matricule[j]=(char)(rand()%26+65);
            else
                matricule[j]=(int)(rand()%9+48);
        }
        fprintf(F,"%s\n", matricule);
    }
    fclose(F);
}
void note(void)
{
    int i=0,j;
    float note[12];
    FILE* F = fopen("../../fichiers/file1/note.data" , "w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "note.data");
        exit(-1);
    }
    for(i ; i<N ; i++)
    {
        for(j=0 ; j<11 ; j++)
        {
            note[j]=(float)(rand()%21);
            fprintf(F, "%.1f ; ",note[j]);
        }
        note[j]=(float)(rand()%21);
        fprintf(F, "%.1f",note[j]);
        fprintf(F , "\n");
    }
    fclose(F);
}
void etablissement(void)
{
    int i;
    FILE* F =fopen("../../fichiers/file1/etablissement.data" , "w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s ", "etablissement.data");
        exit(-1);
    }    
    for(i=0 ; i<N ; i++)
    {
        switch (rand()%4)
        {
            case 0:
                fprintf(F, "UniversiteDeYaounde1\n");
                break;
            case 1:
                fprintf(F , "UniversiteDeyaounde2\n");
                break;
            case 2:
                fprintf(F, "UniversiteDeDouala\n");
                break;
            case 3:
                fprintf(F, "UniversiteDeDschang\n");
                break;
        }
    }
    fclose(F);
}