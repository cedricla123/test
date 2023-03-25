#include<stdio.h>

typedef struct eleves
{
	char matricule[10];
	char nom[40];
	char sexe[2];
	char naissance[15];

}eleves;

typedef struct matiere
{
	char nom[10];
	int coef;
}matiere;

typedef struct notes
{
	float math;
	float physique;
	float svt;
	float chimie;
	float anglais;
}notes;

int main(void)

{
	int k,n,i;
	eleves classe[10000];
	matiere prof[10000];
	notes tab[10000];


	printf("entrer un nombre :\n");
	scanf("%d", & n);

	printf("*****enregistrement des eleves*****\n");

	for(i = 1 ; i <= n ; i++)
	
	{
		printf("entrer le nom du %de eleve :\n", i);
		scanf("%s", classe[i].nom);

		printf("entrer le matricule du %de eleve :\n", i);
		scanf("%s", classe[i].matricule);

		printf("entrer le sexe du %de eleve : \n", i);
		scanf("%s", classe[i].sexe);

		printf("entrer la date de naissance du %de eleve :\n", i);
		scanf("%s", classe[i].naissance);
	}

	printf("*****enregistrement des notes des eleves*****\n");

	for(i = 1 ; i <= n ; i++)
	{
		printf("note de physique du %de eleve:\n", i);
		scanf("%f", &tab[i].physique);

		printf("note de math du %de eleve:\n", i);
		scanf("%f", &tab[i].math);

		printf("note de svt du %de eleve :\n", i);
		scanf("%f",&tab[i].svt);

		printf("note de chimie du %de eleve :\n", i);
		scanf("%f", &tab[i].chimie);

		printf("note de anglais du %de eleve:\n", i);
		scanf("%f" , &tab[i].anglais);
	}

	printf("matricule\t");
	printf("noms\t");
	printf("sexe\t");
	printf("date de naissance\t");
	printf("phys\t");
	printf("maths\t");
	printf("svt\t");
	printf("chimie\t");
	printf("anglais\n");


	for(i = 1 ; i <= n ; i++)

	{
		printf("%s\t", classe[i].matricule);
		printf("%s\t", classe[i].nom);
		printf("%s\t", classe[i].sexe);
		printf("%s\t", classe[i].naissance);
		printf("%f\t", tab[i].physique);
		printf("%f\t", tab[i].math);
		printf("%f\t", tab[i].svt);
		printf("%f\t", tab[i].chimie);
		printf("%f\n", tab[i].anglais);
	}

	//TAF2
	printff("*****TRAITEMENT DES ELEVES*****");

	for(i = 0 ; i < n)
	return 0;
}
