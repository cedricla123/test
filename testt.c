#include<stdio.h>
#include<stdlib.h>
typedef struct element
{
	float nombre;
	element *suiv;
}element;

typedef struct list 
{
	element *premier;
}liste;
liste* initialisation()
{
	liste*liste = malloc(sizeof(*liste));
	element *element = malloc(sizeof(element));

	if(liste == NULL || element == NULL)
		exit(EXIT_FAILLURE);

	element -> nombre = 0;
	element -> suivant = NULL;
	liste -> premier = element ;
	return liste; 
}
void insertion(liste *liste , float nb)
{
	element *nouveau = malloc(sizeof(*nouveau));
	if(liste == NULL || nouveau == NULL)
		exit(EXIT_FAILLURE);

	nouveau -> nombre = nb;
	nouveau -> suiv = liste -> premier;
	liste -> premier = nouveau;
} 
void suppression()
{
	if(liste == NULL)
		exit(EXIT_FAILLURE);
	if(liste -> premier != NULL)
	{
		element *eltsup = liste -> premier;
		liste -> premier = liste -> premier -> suiv;
	}
	free(eltsup);
}

void affilist(liste *liste)
{
	if(liste == NULL)
		exit(EXIT_FAILLURE);
	element *present = liste -> premier;
	
	while(premier != NULL)
	{
		printf("%f ->", present -> nombre);
		present = present -> suiv;
	}
	printf("NULL\n");
	
}
int main()
{
	
	return 0;
} 