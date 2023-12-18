 #include<stdio.h>
 int main()
 {
    int i,j;
    int n=10;
    for(i = 1 ; i < n ; i++)
    {
        for(j = 0 ; j < i ; j++)
            printf("*");
        printf("\n");
    }
    return 0;
 }