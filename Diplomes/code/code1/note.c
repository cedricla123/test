#include <stdio.h>
#include <stdlib.h>
#include "outil.h"
#include "note.h"

void saisir_note(FILE* F, note* note)
{
    int j;
    for(j=0 ; j<N2-1 ; j++)
        fprintf(F,"%.1f ; ", note->poids[j]);
    fprintf(F,"%.1f\n", note->poids[j]);
    
}

void lire_note(FILE* F, note* note)
{
    int j;
    for(j=0 ; j<N2-1 ; j++)
        fscanf(F,"%f ; ", &note->poids[j]);
    fscanf(F,"%f\n", &note->poids[j]);
      
}

int obtenir_note(FILE* F, note* TAB)
{
    int nombreNotes=2, i;
    for(i=0 ; i<N2-1 ; i++)
        fscanf(F,"%s ; ", TAB[0].matiere[i]);
    fscanf(F,"%s\n", TAB[0].matiere[i]);

    for(i=0 ; i<N2-1 ; i++)
    fscanf(F,"%f ; ", &TAB[1].coefficient[i]);
        fscanf(F,"%f\n", &TAB[1].coefficient[i]);
    while(!feof(F))
    {   
        lire_note(F, &TAB[nombreNotes]);
        nombreNotes++;
    }
    return nombreNotes;
}

void enregistrer_note(FILE* F, note* TAB , int nombreNote)
{
    int i;
    for(i=0 ; i<N2-1 ; i++)
            fprintf(F,"%s ; ", TAB[0].matiere[i]);
        fprintf(F,"%s\n", TAB[0].matiere[i]);

    for(i=0 ; i<N2-1 ; i++)
    fprintf(F,"%.1f ; ", TAB[1].coefficient[i]);
        fprintf(F,"%.1f\n", TAB[1].coefficient[i]);
        
    for(i=2 ; i<nombreNote ; i++)
        saisir_note(F, TAB);
}
void ajouter_Note(note* nt)
{
    int i=0;
    note nom[N2];
    FILE*F=fopen(FILE_NOTE , "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "note.csv");
        exit(-1);
    }
    while(i==0)
    {    
        for(int j=0 ; j<N2 ; i++)
            fscanf(F,"%s", nom[i].matiere[j]);
        i++;  
    }
    fclose(F); 
    for(i=0 ; i<N2 ; i++)
    {
        do
        {
            printf("Entrez la note de l'etudiant a la matiere de %s : ", nom[0].matiere[i]);
            scanf("%f", &nt->poids[i]);
        }while(!((nt->poids[i]>-1)&&(nt->poids[i]<21)));
    }
    F=fopen(FILE_NOTE , "a");
    if(F==NULL)
    {
        F=fopen(FILE_NOTE , "w");
        if(F==NULL)
        {
            printf("Erreur d'ouverture du fichier %s ", "note.csv");
            exit(-1);
        }
    }
    saisir_note(F, nt);
    fclose(F);
}

void modifier_note(int position)
{
    int i=0;
    note* TAB = (note*)malloc(sizeof(note)*N3);
    FILE* F =fopen(FILE_NOTE,"r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "note.csv");
        exit(-1);
    }
    int nombreNotes = obtenir_note(F, TAB);
    nombreNotes-=1;
    fclose(F);
    for(i=0 ; i<N2 ; i++)
    {
        do
        {
            printf("Entrez la note de l'etudiant a la matiere %s : ", TAB[0].matiere[i]);
            scanf("%f", &TAB[position].poids[i]);
        }while((!(TAB[position].poids[i]>-1))&&(TAB[position].poids[i]<21));
    }
    F=fopen(FILE_NOTE , "w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "notes.csv");
        exit(-1);
    }
    enregistrer_note(F , TAB , nombreNotes);
    fclose(F);
    free(TAB);
}

void supprimer_note(int position)
{
    int i;
    note* TAB = (note*)malloc(sizeof(note)*N3);
    note nt;
    FILE* F=fopen(FILE_NOTE , "a");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "note.csv");
        exit(-1);
    }
    int nombreNotes = obtenir_note(F, TAB);
    nombreNotes-=1;
    fclose(F);
    F=fopen(FILE_NOTE , "w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "note.csv");
        exit(-1);
    }
    for(i=0 ; i<nombreNotes ; i++)
    {
        if(i!=position)
        {
            for(i=0 ; i<N2-1 ; i++)
                fprintf(F,"%s ; ", TAB[0].matiere[i]);
            fprintf(F,"%s\n", TAB[0].matiere[i]);

            for(i=0 ; i<N2-1 ; i++)
                fprintf(F,"%f ; ", TAB[1].coefficient[i]);
            fprintf(F,"%f\n", TAB[1].coefficient[i]);
            saisir_note(F , &nt);
        }
    }
    fclose(F);
    free(TAB);
}

float somme_note(int trouver)
{
    int i;
    note* TAB = (note*)malloc(sizeof(note)*N3);
    FILE* F=fopen(FILE_NOTE , "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "Note.csv");
        exit(-1);
    }
    int nombreNote = obtenir_note(F, TAB);
    nombreNote-=1;
    float somme = 0;
    for(i=0 ; i<N2 ; i++)
        somme+=TAB[trouver].poids[i];
    free(TAB);
    fclose(F);
    return somme;
}

float produit_noteCoef(int position)
{
    int i;
    note* TAB = (note*)malloc(sizeof(note)*N3);
    FILE* F=fopen(FILE_NOTE , "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "Note.csv");
        exit(-1);
    }
    int nombreNote = obtenir_note(F, TAB);
    nombreNote-=1; 
    float produit=0;
    for(i=0 ; i<N2 ; i++)
        produit+=TAB[1].coefficient[i]*TAB[position].poids[i];
    free(TAB);
    fclose(F);
    return produit;
}
