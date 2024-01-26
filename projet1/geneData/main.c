#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CNI 11
#define MAX_TAILLE 15
#define MAX_CODE 5
#define MAX_COTI 5

typedef struct etudiants
{
    char CNI[MAX_CNI];
    char nom[MAX_TAILLE];
    char prenom[MAX_TAILLE];
    int age;
    char filiere[MAX_CODE];
    int niveau;
    float cotisation[MAX_COTI];
}etud;
void gene_cni(char*);
void gene_abc(char*);
void gene_filiere(char*);
void aleaEtudiant(etud*);
void ecrire(FILE *,etud*);


int main(int argc, char *argv[])
{
    FILE* file;
    int n;
    etud etudiant;
    printf("%d\n",argc);
    if(argc == 3)
    {
        srand((unsigned int)time(NULL));
        n = atoi(argv[1]);
        file = fopen(argv[2],"w");
        for(int i = 0; i < n; i++)
        {
            aleaEtudiant(&etudiant);
            ecrire(file,&etudiant);
        }
    }
    else
        printf("manque d'argument : (nombreElements,nomFichier)\n");
    return 0;
}

void gene_cni(char* cni)
{
    cni[MAX_CNI - 1] = '\0';
    for(int i = 0; i < MAX_CNI - 1; i++)
        cni[i] = (char)(48 + rand()%10);
}
void gene_abc(char* mot)
{
    int i;
    int taille = 4 + rand()%11;
    mot[taille] = '\0';
    for(i = 0; i < taille ;i++)
        mot[i] = (char)(97 + rand()%26);
    
}
void gene_filiere(char* code_filiere)
{
    int i;

    for( i = 0; i < MAX_CODE - 1; i++)
        code_filiere[i] = (char)(65 + rand()%26);
    code_filiere[MAX_CODE] = '\0';
}

void aleaEtudiant(etud* etudiant)
{
    gene_cni(etudiant->CNI);
    gene_abc(etudiant->nom);
    gene_abc(etudiant->prenom);
    etudiant->age = 16 + rand()%15;
    gene_filiere(etudiant->filiere);
    etudiant->niveau = 1 + rand()%5;
    for(int i = 0; i < MAX_COTI; i++)
        etudiant->cotisation[i] = rand()%100001;
}
void ecrire(FILE * file,etud* etudiant)
{
    fprintf(file,"%s ;",etudiant->CNI);
    fprintf(file," %s ;",etudiant->nom);
    fprintf(file," %s ;",etudiant->prenom);
    fprintf(file," %d ;",etudiant->age);
    fprintf(file," %s ;",etudiant->filiere);
    fprintf(file," %d ",etudiant->niveau);
    for(int i = 0; i < MAX_COTI; i++)
        fprintf(file,"; %.2f ",etudiant->cotisation[i]);
    fprintf(file,"\n");
}