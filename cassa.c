#include<stdio.h>
int main()

{
    int N=15,i,j;
    for(i=0;i<N ;i++)
    {
        for(j=0;j< N + i+ 1; j++)
        {
            if(j < N - i)
                printf(" ");
            else if(j%2 == 0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}