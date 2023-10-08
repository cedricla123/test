#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p;
	FILE * file = fopen("toto.txt", "w");
	if(file == NULL)
	{
		printf("Erreur d'ouverture du fichier\n");
		exit(1);
	}
	fprintf(file, "123\n");
	fclose(file);
	return 0;
}