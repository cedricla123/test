#include<stdio.h>
int main()
{
	int i;
	int tab[10];
	for(i = 0 ; i < 10 ; i++)
	{
		scanf("%d",&tab[i]);
	}
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d\n",tab[i]);
	}
	/*int temp = 0;
	for(i = 1 ; i < 10 ; i++)
	{
		for(int j = 0 ; j < 10 ; j++)
			if(tab[i] < tab[temp])
			{
				tab[i]*/
	
	return 0;
}
