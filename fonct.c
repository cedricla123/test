#include<stdio.h>
#include<math.h>
#define size 60 

double evaluationDuPolynome(double *T, int n, double x)
{
	double p;
	int i;

	p = T[0];

	for(i = 1 ; i < n+1 ; i++)
		p+= T[i]* pow(x,i); 
	return p;
}

int main(void)
{
	double tab[size];
	double i, x;
	int n ;
	int k;
	
	printf("degre:\n");
	scanf("%d", &n);

	printf("evalueur:\n");
	scanf("%lf", &x);

	printf("coefficients:\n");

	for(k = 0 ; k < n+1 ; k++)
		scanf("%lf", &tab[k]);

	printf("%.3lf\n", evaluationDuPolynome(tab, n, x));
	return 0;	
}