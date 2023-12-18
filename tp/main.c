#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
#define SPACE fprintf(F, "+----------+------------+------------+------------+----------+\n")

typedef struct etudiant
{
    char nom[10];
    char matricule[10];
    int age;
    float moy;
}etud;
int main()
{
    int nom;
    etud TA[SIZE];
    int i,j,num;
    FILE *F;
    F = fopen("./files/donnee.data", "r");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(-1);
    }
    i = 0;
    while(!feof(F))
    {
        fscanf(F,"%s ; %s ; %d ; %f\n",TA[i].matricule,TA[i].nom,&TA[i].age,&TA[i].moy);
        i++;
    } 
    fclose(F);
    nom = i;
    int max;
    for(i = 0 ; i < nom-1 ; i++)
    {
        max = i;
        for(j = i+1; j < nom ; j++)
        {
            if(TA[j].age > TA[max].age)
                max = j;
        }
        num = TA[i].age;
        TA[i].age = TA[max].age;
        TA[max].age = num;
    }

    F = fopen("./files/result.data","w");
    if(F == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(-1);
    }
    fprintf(F, "\n*************TABLEAU RECAPITULATIF DES ETUDIANTS**************\n");
    fprintf(F, "+------------------------------------------------------------+\n");
    fprintf(F, "|NUM       |MATRICULE   |NOM         |AGE         |MOYENNE   |\n");
    SPACE;
    fclose(F);

    F = fopen("./files/result.data", "a");
    if(F==NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(-1);
    }
    for(i = 0 ; i < nom-1 ; i++)
    {
        fprintf(F, "|%10d|%12s|%12s|%12d|%10.2f|\n",i+1,TA[i].matricule, TA[i].nom, TA[i].age,TA[i].moy);
        SPACE;
    }
    fprintf(F, "|%10d|%12s|%12s|%12d|%10.2f|\n",i+1,TA[nom-1].matricule, TA[nom-1].nom, TA[nom-1].age,TA[nom-1].moy);
    fprintf(F, "+------------------------------------------------------------+\n");
    fprintf(F, "\n");
    fclose(F);
    return 0;
}