#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 1000

int main(void)
{
    srand(time(NULL));
    int i, j,n,temp;
    float T[Max];
    do
    {   
        printf("Entrer la taille de votre tableau (<1000)\n");
        scanf("%d", &n);
    }while(!(n < 1000 && n > 0));
   
    for(i = 0 ; i < n ; i++)
    {
        T[i] = rand()%201;
    }
    printf("\nTableau non trier\n");

    for(i = 0 ; i < n ; i++)
    {
        printf("%.1f\n",T[i]);
    }
    i = 0;
    j = 0;

    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j <= i ; j++)
        {
            if(T[i]<T[j])
            {
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
    printf("\nTableau trier\n");
    
    for(i = 0 ; i < n ; i++)
    {
        printf("%.1f\n",T[i]);
    }
    
    return 0;
    
}