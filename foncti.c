#include<stdio.h>

int main(void)
{
	int i,j,s;
	int n,m;
	
	i = 1;
	j = 1;
	s = 0;
	

	printf("entrer un nombre\n");
	scanf("%d", &n);

	printf("entrer un autre\n");
	scanf("%d", &m);

	for(i = 1 ; i <= n ; i++)
		s += 1;

	for(j = 1 ; j <= m ; j++)
		s += 1;
	
	printf("%d\n", s);

	return 0;  
}
