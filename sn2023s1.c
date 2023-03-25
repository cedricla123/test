#include<stdio.h>

// question 1 partie 1

typedef struct etudiant

{	
	char matricule[10];
	
	char nom[50];

	int age;
}etudiant;

// question 1 partie 2

/*typedef struct classe

{
	etudiant tab[100];
}classe;*/

int main(void)


// question 2

{
	int n,i,jeun,agee , moy;

	etudiant tab[1000];

	printf("entrer un nombre!!:\n");
	scanf("%d" , &n);

	for(i = 0 ; i < n ; i++)
	
	{
			printf("nom :\n");
			scanf("%s", tab[i].nom);

			printf("matricule :\n");
			scanf("%s", tab[i].matricule);

			printf("age :\n");
			scanf("%d", & tab[i].age);
	}

	for(i = n-1 ; i >= 0 ; i--)
	
	{
		printf("matricule : %s\t", tab[i].matricule);
		
		printf("nom : %s\t", tab[i].nom);
		
		printf("age : %d\n", tab[i].age);
	}

	// question 3

	jeun = 0 ;

	for(i = 1 ; i < n ; i++)

	{
		if(tab[jeun].age > tab[i].age)
		
			jeun = i;
	}

	printf("nom jeune : %s\n", tab[jeun].nom);
	agee = 0;
	
	for(i = 1 ; i <= n ; i++)

	{
		if(tab[agee].age < tab[i].age)

			agee = i;
	}

	
	printf("nom agee : %s\n", tab[agee].nom);

	// question 4

	moy = 0;

	for(i = 0 ; i < n ; i ++)

		moy = moy + tab[i].age;

	moy = moy / n;

	printf("l'age moyen est : %d\n", moy);

	// question 5

	char matricule[10];

	printf("RECHERCHE DE MATRICULE\n");
	
	printf("votre matricule : \n");
	scanf("%s", matricule);
	
	for(i = 0 ; i < n ; i++)

		if(matricule == !tab[i].matricule)

			printf("matricule introuvable\n");
		else
			printf("matricule correct\n");		
	
	
	return 0;
}