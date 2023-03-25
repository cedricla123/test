#include<stdio.h>

int main(void)

{
	int vecteur[100];
	int val, n, i;

	printf("entrer le nombre d'elements\n");
	scanf("%d",& n);

	printf("ENTRER LES ELEMENTSDU TABLEAU\n");

	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&vecteur[i]);
	}

	printf("ENTRER L'ELEMENT A RECHERCHER!!!!\n");
	scanf("%d",&val);
	 i = 1;

	 while(val =! vecteur[i] && i < n)
	 	i = i+1;

	 if(vecteur[i] == val)
	 	printf("l'element se trouve en : %d \n", i);
	 else
	 	printf("element non present!!!\n");

	return 0;
}