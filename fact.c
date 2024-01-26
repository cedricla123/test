#include<stdio.h>
float fact(int n)
{
   int i,j=1;
   if(n==0)
        return 1;
   else
   {
        for(i=1 ; i<n ; i++)
        {
            j*=i;   
        }
        return  j;
   }
}
int combinaison(int p , int n)
{
    if(n > p)
        return fact(n)/(fact(n-p)*fact(p));
}
int main()
{
    int n,i,j; 
    printf("Entrer la taille de votre matrice : ");
    scanf("%d", &n);
    for(i=1 ; i<n ; i++)
    {
        for(j=0 ; j<i ; j++)
        {
            printf("%3d", combinaison(j , i));
        }
        printf("\n");
    }
    return 0;
}