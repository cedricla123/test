#include<stdio.h>

int main(void)
{
	int tab[10];
	int i;


	for(i = 0 ; i < 10 ; i++)
		printf("%d\n", tab[i]);

	
	for(i = 0 ; i < 10 ; i++)
	{
		tab[i] = i*2 + 16;	
	}

	for(i = 0 ; i < 10 ; i++)
		printf("%d\n", tab[i]);
	
	return 0;
}