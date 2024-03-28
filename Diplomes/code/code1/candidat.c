#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outil.h"
#include "note.h"
#include "candidat.h"

void saisir_candidat(FILE* F, candidat* cd)
{
    fprintf(F , "%s;%s;%s;%s;%s;%s\n" , cd->matricule,cd->nom,cd->dateNaissance,cd->ecole,cd->filiere,cd->examen);
}
void lire_candidat(FILE* F, candidat* cd)
{
    fscanf(F , "%s;%s;%s;%s;%s;%s\n" , cd->matricule,cd->nom,cd->dateNaissance,cd->ecole,cd->filiere,cd->examen);
}
int obtenir_candidats(FILE* F, candidat* TAB)
{
    int nombreCandidat = 0;
    while(!feof(F))
    {
        lire_candidat(F,&TAB[nombreCandidat]);
        nombreCandidat++;
    }
    return nombreCandidat;
}
void enregistrer_candidats(FILE* F , candidat* TAB , int nombreCandidats)
{
    int i;
    for(i=0 ; i<nombreCandidats ; i++)
        saisir_candidat(F,TAB);
}
void ajouter_candidat(candidat* cd)
{
    int i;
    note nt;
    FILE* F=fopen(FILE_CANDIDAT , "a");
    if(F==NULL)
    {
        F=fopen(FILE_CANDIDAT, "w");
        if(F==NULL)
        {
            printf("Erreur d'ouverture du fichier %s \n", "donnees.csv");
            exit(-1);
        }
    }
    printf("Entrez le matricule du candidat : ");
    scanf("%s", cd->matricule);
    printf("Entrer le nom du candidat : ");
    scanf("%s", cd->nom);
    printf("Entrez la date de naissance du candidat(jour/mois/annee) du candidat : ");
    scanf("%s", cd->dateNaissance);
    printf("Entrez l'etablissement du candidat : ");
    scanf("%s", cd->ecole);
    fprintf(F , "%s;%s;%s;%s;%s;%s\n" , cd->matricule,cd->nom,cd->dateNaissance,cd->ecole,"INFORMATIQUE","LICENCE1");
    ajouter_Note(&nt);
    fclose(F);
}
void modifier_candidat(void)
{
    candidat* TAB=(candidat*)malloc(sizeof(candidat)*N4); 
    int trouver=0, nombreCandidat=0;
    char matricule[N];
    FILE* F=fopen(FILE_CANDIDAT , "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s\n", "donnees.csv");
        exit(-1);
    }
    nombreCandidat = obtenir_candidats(F, TAB);
    nombreCandidat-=1;
    fclose(F);

    printf("Entrez le matricule du candidat a rechercher : ");
    scanf("%s", matricule);
    trouver = rechercher(TAB , nombreCandidat , matricule);
    if(trouver!=0)
    {    
        printf("Entrez le matricule de l'etudiant %s : ", TAB[trouver].nom);
        scanf("%s", TAB[trouver].matricule);
        printf("Entrez le nom de l'etudiant identifier par %s : ", TAB[trouver].matricule);
        scanf("%s", TAB[trouver].nom);
        printf("Entrez la date de naissance de l'etudiant identifier par %s : ", TAB[trouver].matricule);
        scanf("%s", TAB[trouver].dateNaissance);
        printf("Entrez l'ecole de l'etudiant idenfier par %s : ", TAB[trouver].matricule);
        scanf("%s", TAB[trouver].ecole);
        modifier_note(trouver+2);
    }
    else
        printf("Le matricule saisie n'exite pas dans le fichier candidat .\n");
    F=fopen(FILE_CANDIDAT , "w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "donnees.csv");
        exit(-1);
    }
    enregistrer_candidats(F, TAB, nombreCandidat);
    fclose(F);
    free(TAB);
}
void supprimer_candidat(char matricule[N])
{
    int i;
    candidat* TAB=(candidat*)malloc(sizeof(candidat)*N4); 
    FILE* F=fopen(FILE_CANDIDAT ,"r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "Donnees.csv");
        exit(-1);
    }
    int nombreCandidats = obtenir_candidats(F, TAB);
    nombreCandidats-=1;
    fclose(F);
    int trouver = rechercher(TAB , nombreCandidats , matricule);
    if(trouver!=0)
    {
        F=fopen(FILE_CANDIDAT , "w");
        if(F==NULL)
        {
            printf("Erreur d'ouverture du fichier %s \n", "donnees.csv");
            exit(-1);
        }
        for(i=0 ; i<nombreCandidats ; i++)
            if(i!=trouver)
                saisir_candidat(F , &TAB[i]);
            supprimer_note(trouver+2);
        fclose(F);
    }
    else    
        printf("Le matricule saisie n'exite pas dans la base de donnees.\n");
    free(TAB);
}
int rechercher_candidat(char matricule[N])
{
    candidat* TAB=(candidat*)malloc(sizeof(candidat)*N4); 
    FILE* F=fopen(FILE_CANDIDAT , "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "donnees.csv");
        exit(-1);
    }
    int nombrecandidats = obtenir_candidats(F,TAB);
    nombrecandidats-=1;
    fclose(F);
    int trouver = rechercher(TAB , nombrecandidats , matricule);
    if(trouver != 0)
        printf(F , "%s : %s : %s : %s : %s : %s\n" , TAB[trouver].matricule,TAB[trouver].nom,TAB[trouver].dateNaissance,TAB[trouver].ecole,TAB[trouver].filiere,TAB[trouver].examen);
    else
        printf("Etudiant non exitant \n ");
    free(TAB);
}
int rechercher(candidat* TAB , int n , char matricule[N])
{
    int i,trouver=0,p=0;
    for(i=0 ; (i<n)&&(!trouver) ; i++)
    {
        p=strcmp(TAB[i].matricule , matricule);
        if(p==0)
            trouver = i;
        else
            trouver = 0;
    }
    return trouver;
}
void imprimer_Diplome(char matricule[N])
{
    candidat* TAB1=(candidat*)malloc(sizeof(candidat)*N4); 
    note* TAB2 = (note*)malloc(sizeof(note)*N3);
    FILE* F=fopen(FILE_CANDIDAT , "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "donnees.csv");
        exit(-1);
    } 
    int nombreCandidat = obtenir_candidats(F , TAB1);
    nombreCandidat-=1;
    fclose(F);
    int trouver = rechercher(TAB1 , nombreCandidat , matricule);
    printf("\nExamen : %10s   ~  Filiere : %10s\n\n", TAB1[trouver].examen , TAB1[trouver].filiere);
    printf("Nom : %10s  ~  \tDate et lieu de naissance : %10s\n\n", TAB1[trouver].nom , TAB1[trouver].dateNaissance);
    printf("Etablissement : %10s\n\n", TAB1[trouver].ecole);
    LINES;
    printf("|         MATIERES            |            NOTES           |          COEFFICIENT       |          NOTECOEFF         |\n");    
    float somme=0;
    int i;
    F=fopen(FILE_NOTE , "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "note.csv");
        exit(-1);
    }
    int nombreNotes = obtenir_note(F,TAB2);
    nombreNotes-=1;
    fclose(F);
    for(i=0 ; i<N2 ; i++)
    {
        LIGNE;
        printf("|%29s|%28.1f|%28.1f|%28.1f|\n", TAB2[0].matiere[i],TAB2[trouver].poids[i],TAB2[1].coefficient[i],produit_noteCoef(trouver));
        somme+=produit_noteCoef(trouver);
    }
    LIGNE;
    float nombre1 = somme_note(trouver);
    float nombre2=0;
    for(i=0 ; i<N2 ; i++)  
        nombre2+=TAB2[1].coefficient[i];
    printf("|            TOTAL            |%28.1f|%28.1f|%28.1f|\n",nombre1,nombre2,somme);
    LINES;
    float auxiliaire = moyenne_candidat(somme,nombre2);
    printf("MOYENNE : %2.1f  ~  MENTION : %10s  ~ ", auxiliaire, mention(auxiliaire));
    printf("\tDECISION : ");
    decision(auxiliaire);
    printf("\n\n");
    free(TAB1);
    free(TAB2);
}
void afficher_admis(void)
{
    candidat* TAB1=(candidat*)malloc(sizeof(candidat)*N4); 
    note* TAB2 = (note*)malloc(sizeof(note)*N3);
    FILE* F=fopen(FILE_CANDIDAT , "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier %s \n", "donnees.csv");
        exit(-1);
    } 
    int nombreCandidat = obtenir_candidats(F , TAB1);
    nombreCandidat-=1;
}
