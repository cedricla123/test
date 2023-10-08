#include<stdio.h>
#include<stdlib.h>

typedef struct Element
{
	int nombre;
	Element *suivant;
}Element;

typedef struct Liste
{
	Element *premier;
}Liste;

//declaration des fonctions.

void affiche(Liste*);
void suppression(Liste*);
Liste *initialisation();
void insertion(Liste*, int );

int main()
{
	Liste *maliste = initialisation();
	insertion(maliste , 4);
	insertion(maliste, 100);
	insertion(maliste, 300);

	return 0;
}

//definition des fonctions.

void insertion(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(*nouveau));
	Liste *liste = malloc(sizeof(*liste));
	if(liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;
	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
}

Liste *initialisation()
{
	Liste *liste = malloc(sizeof(*liste));
	Element *element = malloc(sizeof(*element));
	if(liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}
	element->nombre = 0;
	element->suivant = NULL;
	element->premier = element;
	return liste;
}

void suppression(Liste *liste)
{
	if(liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if(liste->premier != NULL)
	{
		element*asupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(asupprimer);
	}
}

void affiche(Liste *liste)
{
	if(liste == NULL)
	{
		exit(EXIT_FAILURE)
	}

	element *actuel = liste->premier;
	while(actuel != NULL)
	{
		printf("%d -> ", actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("NULL\n");
}
