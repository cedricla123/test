#include<stdio.h>
int main()
{
    int n,N=5,i,p = 0;
    do
    {
        printf("Entrez un nombre compris entre 0 et 9\n");
        scanf("%d",&n);
    }while(!(n<10&&n>-1));

    for(i = 0 ; i < N ; i++)
    {
        p = n*i+(i+1);
        printf("%dx%d+%d=%d\n",n,i,i+1,p);
    }
    return 0;
}