#include<stdio.h>
#include<string.h>
#define N 10
#define SIZE 100
#define space printf("\n")
typedef struct etudiant
{
    char matricule[N];
    char nom[N];
    int age;
}etudiant;
int main()
{
    int i,n;
    etudiant classe[SIZE];
    do
    {
        printf("Entrez le nombre d'etudiant que vous aimerez enregistrer : ");
        scanf("%d", &n);
    }while(!(n > 0));

    space;
    for(i = 0 ; i < n ; i++)
    {
       printf("Entrez le matricule de l'etudiant numero %d : ", i+1); 
       scanf("%s", classe[i].matricule);

       printf("Entrez le nom de l'etudiant numero %d : ", i+1); 
       scanf("%s", classe[i].nom);

       printf("Entrez l'age de l'etudiant %d :",i+1);
       scanf("%d", &classe[i].age);
    }
    space;

    printf("ETUDIANT ENREGISTRER\n");
    for(i = n-1 ; i >= 0 ; i--)
    {
        printf("MATRICULE: %10s |",classe[i].matricule);
        printf("NOM: %10s |",classe[i].nom);
        printf("AGE: %3d |", classe[i].age);
        space;
    }
    int min, max = 0, temp;
    min = 0;
    for(i = 1 ; i < n ; i++)
    {
        if(classe[min].age > classe[i].age)
        {
            min = i;
        }
        if(classe[max].age < classe[i].age)
        {
            max = i;
        }
        
    }
    printf("le plus jeune est : %s\n",classe[min].nom);
    printf("le plus vieu est : %s\n",classe[max].nom);

    temp = 0;
    for(i = 0 ; i < n ; i++)
        temp += classe[i].age;
    temp /= n;

    printf("l'age moyen est : %d\n", temp);
    
    char recherche[N];
    printf("Entrer le matricule a rechercher\n");
    scanf("%s",recherche);
    
    int trouver = -1; 
    i = 0;
    while((trouver == -1) && (i < n))
    {
        if(strcmp(classe[i].matricule , recherche) == 0)
            trouver = i;
        else
            i++;      
    }
    if(trouver != -1)
        printf("Le matricule saisie fait partie de la classe\n");
    else    
        printf("Ce matricule n'est pas dans cette classe\n");

    return 0;
}