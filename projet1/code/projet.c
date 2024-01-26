#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"projet.h"

void saisir(void)
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
    for(i=0; i<n ; i++)
    {
        fprintf(F,"%s ; ",e[i].CNI);
        fprintf(F,"%s ; ",e[i].nom);
        fprintf(F,"%s ; ",e[i].prenom);
        fprintf(F,"%d ; ",e[i].age);
        fprintf(F,"%s ; ",e[i].filiere);
        fprintf(F,"%d ; ",e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fprintf(F," ; %.1f",e[i].cotisation[j]);
        fprintf(F, "\n");
    }
    fclose(F);
}
void ajouter(void)
{
    int j;
    etud e;
    FILE* F; 
    F = ouverture3("../files/etudiants.txt");
    add(&e);
    fprintf(F,"%s ; ",e.CNI);
    fprintf(F,"%s ; ",e.nom);
    fprintf(F,"%s ; ",e.prenom);
    fprintf(F,"%d ; ",e.age);
    fprintf(F,"%s ; ",e.filiere);
    fprintf(F,"%d",e.niveau);
    for(j=0 ; j<5 ; j++)
        fprintf(F," ; %.1f",e.cotisation[j]);
    fprintf(F, "\n");
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

void modifier(void)
{
    int i=0,j,n;
    etud e[SIZE];
    char matricule[N];
    FILE *F;
    F = ouverture1("../files/etudiants.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
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
    for(i=0; i<n ; i++)
    {
        fprintf(F,"%s ; ",e[i].CNI);
        fprintf(F,"%s ; ",e[i].nom);
        fprintf(F,"%s ; ",e[i].prenom);
        fprintf(F,"%d ; ",e[i].age);
        fprintf(F,"%s ; ",e[i].filiere);
        fprintf(F,"%d",e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fprintf(F," ; %.1f",e[i].cotisation[j]);
        fprintf(F, "\n");
    }
    fclose(F);
}

void supprimer(char matricule[10])
{
    int i = 0,j,n,trouver = -1;
    etud e[SIZE];
    FILE *F;
   
    F = ouverture1("../files/etudiants.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
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
    i = 0;
    if(trouver != -1)
    {
        F = ouverture2("../files/etudiants.txt");
        while(i < n)
        {
            if(i != trouver)
            {
                fprintf(F,"%s ; ",e[i].CNI);
                fprintf(F,"%s ; ",e[i].nom);
                fprintf(F,"%s ; ",e[i].prenom);
                fprintf(F,"%d ; ",e[i].age);
                fprintf(F,"%s ; ",e[i].filiere);
                fprintf(F,"%d",e[i].niveau);
                for(j=0 ; j<5 ; j++)
                    fprintf(F," ; %.1f",e[i].cotisation[j]);
                fprintf(F, "\n");
            }
            i++;
        }
    }
    else
        printf("Le matricule saisie n'exite pas dans la liste des etudiants!!\n");
    fclose(F);
}
float somme(float* TA, int n)
{
    float som=0;
    int i;
    for(i=0 ; i<n ; i++)
        som += TA[i];
    return som;
}

void affichage(void)
{
    float som = 0;
    etud e[SIZE];
    int i = 0,j,n;

    FILE *F;
   
    F = ouverture1("../files/etudiants.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
    FIN;
    printf("|NUMERO      |CNI         |NOMS        |PRENOMS     |AGES        |FILIERES    |NIVEAU      |COTISATIONS |\n");
    for(i=0 ; i<n-1 ; i++)
    {
        LINES;
        printf("|%12d|%12s|%12s|%12s|%12d|%12s|%12d|%12.1f|\n",i+1,e[i].CNI,e[i].nom,e[i].prenom,e[i].age,e[i].filiere,e[i].niveau,somme(e[i].cotisation,5));
    }
    LINES;
    printf("|%12d|%12s|%12s|%12s|%12d|%12s|%12d|%12.1f|\n",i+1,e[i].CNI,e[i].nom,e[i].prenom,e[i].age,e[i].filiere,e[i].niveau,somme(e[i].cotisation,5));
    FIN;
}
void solvable(void)
{
    etud e[SIZE];
    int i = 0,j,n;
    FILE *F;
    F=ouverture1("../files/etudiants.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
    int k=0;
    for(i=0 ; i<n ; i++)
    {
        if(etat(&e[i]))
        {
            printf("%10d|%10s|%10s|%10s|%10d|%10s|%10d|",k+1,e[i].CNI,e[i].nom,e[i].prenom,e[i].age,e[i].filiere,e[i].niveau);
            for(j=0 ; j<5 ; j++)
                printf("%9.1f", e[i].cotisation[j]);
            printf("%9.1f\n", somme(e[i].cotisation,5));
            k++;
        }
    }
    F = ouverture2("../files/etat.txt");
    for(i=0 ; i<n ;i++)
    {
        if(etat(&e[i]))
        {    
            fprintf(F, "%s ; %s ; %s ; %d ; %s ; %d",e[i].CNI,e[i].nom,e[i].prenom,e[i].age,e[i].filiere,e[i].niveau);
            for(j=0 ; j<5 ; j++)
                fprintf(F, " ; %.1f", e[i].cotisation[j]);
            fprintf(F," ; %.1f",somme(e[i].cotisation , 5));
            fprintf(F,"\n");
        }
        
    }
    fclose(F);
}
int etat(etud* e)
{
    int i=0;
    while((e->cotisation[i]!=0)&&(i<5))
        i++;
    if(i<5)
        return 0;
    else
        return 1;
}
void insolvable(void)
{
    int  n,i = 0,j;
    etud e[SIZE];
    FILE *F;
    F=ouverture1("../files/etudiants.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
    for(i=0 ; i<n ; i++)
    {
        if(!etat(&e[i]))
        {
            printf("%10d|%10s|%10s|%10s|%10d|%10s|%10d|",i+1,e[i].CNI,e[i].nom,e[i].prenom,e[i].age,e[i].filiere,e[i].niveau);
            for(j=0 ; j<5 ; j++)
                printf("%9.1f", e[i].cotisation[j]);
            printf("%9.1f\n", somme(e[i].cotisation,5));
        }
    }
    F = ouverture2("../files/mauvais.txt");
    for(i=0 ; i<n ;i++)
    {
        if(!etat(&e[i]))
        {    
            fprintf(F, "%s ; %s ; %s ; %d ; %s ; %d",e[i].CNI,e[i].nom,e[i].prenom,e[i].age,e[i].filiere,e[i].niveau);
            for(j=0 ; j<5 ; j++)
                fprintf(F, " ; %.1f", e[i].cotisation[j]);
            fprintf(F," ; %.1f",somme(e[i].cotisation , 5));
            fprintf(F,"\n");
        }
        
    }
    fclose(F);
}
float statistique(void)
{
    etud e[SIZE];
    float insol=0,n;
    int i=0,j;
    FILE* F;
    F = ouverture1("../files/etudiants.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
    int nombre = 0;
    for(i=0 ; i < n ; i++)
        if(!etat(&e[i]))
            nombre++;
    insol = ((float)nombre/n)*100;
    return insol;
}
void suprimer(void)
{
    etud e[SIZE];
    int i=0,j,n;
    FILE* F;
    F = ouverture1("../files/etudiants.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
    for(i=0 ; i<n ; i++)
    {
        if(somme(e[i].cotisation,5))
        {
            fprintf(F,"%s ; ",e[i].CNI);
            fprintf(F,"%s ; ",e[i].nom);
            fprintf(F,"%s ; ",e[i].prenom);
            fprintf(F,"%d ; ",e[i].age);
            fprintf(F,"%s ; ",e[i].filiere);
            fprintf(F,"%d",e[i].niveau);
            for(j=0 ; j<5 ; j++)
                fprintf(F," ; %.1f",e[i].cotisation[j]);
            fprintf(F, "\n");
        }
    }
    F = ouverture1("../files/etat.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
    for(i=0 ; i<n ; i++)
    {
        if(somme(e[i].cotisation,5))
        {
            fprintf(F,"%s ; ",e[i].CNI);
            fprintf(F,"%s ; ",e[i].nom);
            fprintf(F,"%s ; ",e[i].prenom);
            fprintf(F,"%d ; ",e[i].age);
            fprintf(F,"%s ; ",e[i].filiere);
            fprintf(F,"%d",e[i].niveau);
            for(j=0 ; j<5 ; j++)
                fprintf(F," ; %.1f",e[i].cotisation[j]);
            fprintf(F, "\n");
        }
    }
    F = ouverture1("../files/mauvais.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    fclose(F);
    n = i-1;
    for(i=0 ; i<n ; i++)
    {
        if(somme(e[i].cotisation,5))
        {
            fprintf(F,"%s ; ",e[i].CNI);
            fprintf(F,"%s ; ",e[i].nom);
            fprintf(F,"%s ; ",e[i].prenom);
            fprintf(F,"%d ; ",e[i].age);
            fprintf(F,"%s ; ",e[i].filiere);
            fprintf(F,"%d",e[i].niveau);
            for(j=0 ; j<5 ; j++)
                fprintf(F," ; %.1f",e[i].cotisation[j]);
            fprintf(F, "\n");
        }
    }
}
void recherche(char matricule[10])
{
    etud e[SIZE];
    int i=0,j,n,trouver=-1;
    FILE* F;
    F = ouverture1("../files/etudiants.txt");
    while(!feof(F))
    {
        fscanf(F, "%s ; %s ; %s ; %d ; %s ; %d", e[i].CNI,e[i].nom,e[i].prenom,&e[i].age,e[i].filiere,&e[i].niveau);
        for(j=0 ; j<5 ; j++)
            fscanf(F, " ; %f",&e[i].cotisation[j]);
        i++;
    }
    n=i-1;
    fclose(F);
    int p;
    i = 0;
    while((i < n) && (trouver == -1))
    {
        p = strcmp(e[i].CNI , matricule);
        if(p ==0)
           trouver = i; 
        else
           i++; 
    }
    if(trouver != -1)
    {
        printf("%10d|%10s|%10s|%10s|%10d|%10s|%10d|",i+1,e[i].CNI,e[i].nom,e[i].prenom,e[i].age,e[i].filiere,e[i].niveau);
        for(j=0 ; j<5 ; j++)
            printf("%9.1f", e[i].cotisation[j]);
        printf("|%9.1f",somme(e[i].cotisation , 5));
        printf("\n");
    }
    else
        printf("Le matricule saisie n'exite pas dans la liste des etudiants!!\n");
}