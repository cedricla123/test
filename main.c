#include<stdio.h>
#include<stdlib.h>

void pyramide(int n)
{
    int i,j;

    for(i = 1 ; i < n ; i++)
    {
        for(j = n-1 ; j >= 0 ; j--)
        {
            printf("%c", (char)32);
        }
        

        for(j = 0 ; j < 2*(i+1); j++)
        {
            printf("%c", (char)46);
        }
        printf("\n");
    }
}

int main()
{
    pyramide(5);
    return 0;
}