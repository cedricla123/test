#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"projet.h"

void saisir()
{
    etud e[SIZE];
    int i,j;
    FILE *F;
    int n;
    do
    {
        printf("Entrez le nombre d'etudiant : ");
        scanf("%d",&n);
    }while(!(n > 0));
    F = ouverture2("../files/etudiants.txt");
    for(i=0 ; i<n ; i++)
    {
        printf("Entrer le numero de CNI de l'etudiant %d : ",i+1);
        scanf("%s", e[i].CNI);
        printf("%s\n", e[i].CNI);
        printf("Entrez le nom de l'etudiant %d : ", i+1);
        scanf("%s", e[i].nom);
        printf("Entrez le prenom de l'etudiant %d : ", i+1);
        scanf("%s", e[i].prenom);
        printf("Entrez l'age de l'etudiant %d : ", i+1);
        scanf("%d", &e[i].age);
        printf("Entrez la filiere de l'etudiant %d : ", i+1);
        scanf("%s", e[i].filiere);
        do
        {
            printf("Entrez le niveau(nombre entier)de l'etudiant %d : ", i+1);
            scanf("%d", &e[i].niveau);
        }while(!(e[i].niveau > 0 && e[i].niveau < 9));
        printf("Entrez les cotisations de l'etudiant %d\n", i+1);
        j = 0;
        while(j < 5)
        {
            do
            {
                printf("Entrez la cotisation %d : ", j+1);
                scanf("%f", &e[i].cotisation[j]);
            }while(!(e[i].cotisation[j] >= 0));
            j++;
        }
    }
    fprintf(F, "----------------------------------------------------------------------------------------------------------------\n");
    fprintf(F, "|CNI         |NOM         |PRENOM      |AGE         |FILIERE     |NIVEAU      |COTISATIONS                     |\n");
    for(i=0; i<n-1 ; i++)
    {
        LINES;
        fprintf(F,"%s ; ",e[i].CNI);
        fprintf(F,"%s ; ",e[i].nom);
        fprintf(F,"%s ; ",e[i].prenom);
        fprintf(F,"%d ; ",e[i].age);
        fprintf(F,"%s ; ",e[i].filiere);
        fprintf(F,"%d ; ",e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fprintf(F,"%f ; ",e[i].cotisation[j]);
        fprintf(F, "\n");
    }
    LINES;
    fprintf(F,"%s ; ",e[n-1].CNI);
    fprintf(F,"%s ; ",e[n-1].nom);
    fprintf(F,"%s ; ",e[n-1].prenom);
    fprintf(F,"%d ; ",e[n-1].age);
    fprintf(F,"%s ; ",e[n-1].filiere);
    fprintf(F,"%d ; ",e[n-1].niveau);
    for(j=0 ; j<5 ; j++)
        fprintf(F,"%f ; |",e[n-1].cotisation[j]);
    fprintf(F, "\n");
    fprintf(F, "--------------------------------------------------------------------------------------------------------\n");
    fclose(F);
}
void ajouter()
{
    int j;
    etud e;
    FILE* F; 
    F = ouverture3("../files/etudiants.txt");
    e.age = 18;
    add(&e);
    LINES;
    fprintf(F,"%s ; ",e.CNI);
    fprintf(F,"%s ; ",e.nom);
    fprintf(F,"%s ; ",e.prenom);
    fprintf(F,"%d ; ",e.age);
    fprintf(F,"%s ; ",e.filiere);
    fprintf(F,"%d ; ",e.niveau);
    for(j=0 ; j<4 ; j++)
        fprintf(F,"%f ; ",e.cotisation[j]);
    fprintf(F,"%f ; ",e.cotisation[4]);
    fprintf(F, "\n");
    fprintf(F, "--------------------------------------------------------------------------------------------------------\n");
    fclose(F);
}
FILE *ouverture1(const char* Name)
{
    FILE *F= fopen(Name,"r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(-1);
    }
    return F;
}
FILE *ouverture2(const char* name)
{
    FILE *F = fopen(name,"w");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(-1);
    }
    return F;
}
FILE *ouverture3(const char* name)
{
    FILE* F = fopen(name,"a");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(-1);
    }
    return F;
}
void add(etud* e)
{
    int j;
    printf("Entrer le numero de CNI de l'etudiant  : ");
    scanf("%s", e->CNI);
    printf("Entrez le nom de l'etudiant  : ");
    scanf("%s", e->nom);
    printf("Entrez le prenom de l'etudiant  : ");
    scanf("%s", e->prenom);
    printf("Entrez l'age de l'etudiant : ");
    scanf("%d", &e->age);
    printf("Entrez la filiere de l'etudiant : ");
    scanf("%s", e->filiere);
    do
    {
        printf("Entrez le niveau(nombre entier)de l'etudiant  : ");
        scanf("%d", &e->niveau);
    }while(!(e->niveau > 0 && e->niveau < 9));
    printf("Entrez les cotisations de l'etudiant \n");
    j = 0;
    while(j < 5)
    {
        do
        {
            printf("Entrez la cotisation %d : ",j+1);
            scanf("%f", &e->cotisation[j]);
        }while(!(e->cotisation[j] >= 0));
        j++;
    }
}

void modifier()
{
    int i,j;
    etud e[SIZE];
    char matricule[N];
    int n;
    FILE *F;
    F = ouverture1("../files/etudiants.txt");
    for(i=0 ; i<n ; i++)
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d ; ", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, "%f ; ",&e[i].cotisation[j]);
    }
    fclose(F);
    n = i;
    printf("Entrez le numero de CNI de l'etudiant a modifier ces informations : ");
    scanf("%s", matricule);
    int trouver = -1;
    int p;
    i = 0;
    while((i < n) && (trouver == -1))
    {
        p = strcmp(e[i].CNI , matricule);
        if(p == 0)
           trouver = i; 
        else
           i++; 
    }
    if(trouver!= -1)
    {
        printf("Modifier les informations de l'etudiant %s\n",e[i].nom);
        printf("Entrer le numero de CNI de l'etudiant %d : ",i+1);
        scanf("%s", e[i].CNI);
        printf("Entrez le nom de l'etudiant %d : ", i+1);
        scanf("%s", e[i].nom);
        printf("Entrez le prenom de l'etudiant %d : ", i+1);
        scanf("%s", e[i].prenom);
        printf("Entrez l'age de l'etudiant %d : ", i+1);
        scanf("%d", &e[i].age);
        printf("Entrez la filiere de l'etudiant %d : ", i+1);
        scanf("%s", e[i].filiere);
        do
        {
            printf("Entrez le niveau(nombre entier)de l'etudiant %d : ", i+1);
            scanf("%d", &e[i].niveau);
        }while(!(e[i].niveau > 0 && e[i].niveau < 9));
        printf("Entrez les cotisations de l'etudiant %d\n", i+1);
        j = 0;
        while(j < 5)
        {
            do
            {
                printf("Entrez la cotisation %d : ", j+1);
                scanf("%f", &e[i].cotisation[j]);
            }while(!(e[i].cotisation[j] >= 0));
            j++;
        }
        
    }
    else
        printf("Etudiant n'existe pas!!\n");
    F = ouverture2("../files/etudiants.txt");
    fprintf(F, "----------------------------------------------------------------------------------------------------------------\n");
    fprintf(F, "|CNI         |NOM         |PRENOM      |AGE         |FILIERE     |NIVEAU      |COTISATIONS                     |\n");
    for(i=0; i<n-1 ; i++)
    {
        LINES;
        fprintf(F,"%s ; ",e[i].CNI);
        fprintf(F,"%11s ; ",e[i].nom);
        fprintf(F,"%11s ; ",e[i].prenom);
        fprintf(F,"%11d ; ",e[i].age);
        fprintf(F,"%11s ; ",e[i].filiere);
        fprintf(F,"%11d ; ",e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fprintf(F,"%f ; ",e[i].cotisation[j]);
        fprintf(F, "\n");
    }
    LINES;
    fprintf(F,"%s ; ",e[n-1].CNI);
    fprintf(F,"%11s ; ",e[n-1].nom);
    fprintf(F,"%11s ; ",e[n-1].prenom);
    fprintf(F,"%11d ; ",e[n-1].age);
    fprintf(F,"%11s ; ",e[n-1].filiere);
    fprintf(F,"%12d ; ",e[n-1].niveau);
    for(j=0 ; j<4 ; j++)
        fprintf(F,"%f ; ",e[n-1].cotisation[j]);
    fprintf(F,"%f ; ",e[n-1].cotisation[4]);
    fprintf(F, "\n");
    fprintf(F, "----------------------------------------------------------------------------------------------------------------\n");
    fclose(F);
}