#include<stdio.h>
#include<stdio.h>

float racine(float x)
{
    float y;

    y = 0;
    while(y*y < x)
    {
        y = y+0.0001;
    }

    y = y-0.0001;

    return y;
}

int main()
{
    printf("%.2f\n",racine(1000000000));
    return 0;
}