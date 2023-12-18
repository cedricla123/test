#include<stdio.h>

int main()
{
    int i , j, temp;
    int tab[19]={12,13,0,17,20,11,12,90,40,23,21,78,45,34,221,67,49,876,345};

    i = 0; 
    j = 0;

    printf("Elements desordonner du tableau\n");
    printf("\n");
    for(i = 0 ; i < 19 ; i++)
    {
        printf("%d\n",tab[i]);
    }
    for(i = 0 ; i < 19 ; i++)
    {
        for(j = 0 ; j <= i ; j++)
        {
            if(tab[i]<tab[j])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
    printf("\n");

    printf("TABLEAU TRIER \n");
    printf("\n");
    for(i = 0 ; i < 19 ; i++)
    {
        printf("%d\n", tab[i]);
    }
    return 0 ;
}