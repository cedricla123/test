#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Entrer la taille : ");
    scanf("%d", &n);

    int PA[n][n];
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
            if(j == 0 || i == j)
                PA[i][j] = 1;
            else
                PA[i][j] = 0;
    }
    for(i = 1 ; i < n ; i++)
        for(j = 1 ; j < n ; j++)
            PA[i][j] = PA[i-1][j-1]+PA[i-1][j]; 
    
    printf("TRIANGLE DE PASCAL\n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j <= i ; j++)
            printf("%2d ", PA[i][j]);
            printf("\n");
        
    }
    return 0 ;
}