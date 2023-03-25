#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char d[89];
	FILE * k;
	k = fopen("toto.txt","r");

	if(k == NULL)
	{
		printf("erreur d'ouverture!!!\n");
		return -1;
	}
	
	fscanf(k,"%[a-z ]", d);
	fclose(k);
	printf("%s \n", d);
	
	return 0;
}