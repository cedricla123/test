#include<stdio.h>
int main()
{
    int i,j,N;
    printf("entrer une taille : ");
    scanf("%d",&N);
    int ta[N][N];

    //initialisation de la matrice.
    
    for(i=0;i<N;i++)
    {
        for(j = 0;j < N;j++)
        {
            if(j == 0 || i ==j)
                ta[i][j] = 1;
            else
                ta[i][j] = 0;
        }
    }
    
    //calcul des elements de la matrice.
    
    for(i = 1 ; i < N ; i++)
    {
        for(j = 1 ; j <= i ; j++)
            ta[i][j] = ta[i-1][j-1]+ta[i-1][j];
    }

    //affichage des elements du triangle.
    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j <= i ; j++)
            printf("%3d ",ta[i][j]);
        printf("\n");
    }
    return 0;

} 