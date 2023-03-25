#include<stdio.h>
int main(void)

{
	int tab[500];
	int i,n;

	scanf("%d", &n);

	printf("*****entrer les elements du tableau****\n");

	for(i = 0 ; i < n ; i++)
	{
		scanf("%d", &tab[i]);
	}
	int val , k;
	printf("entrer une valeur\n");
	scanf("%d", &val);

	k = -1;

	for(i = 0 ; i < n ; i++)
		if(val == tab[i])
			k = i;
	if(k =! -1)
		printf("valeur existe et est en position :%d\n", i);
	else
		printf("valeur introuvable\n");

	return 0;
}