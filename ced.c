#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//RESOLUTION DES EQUATIONS DE SECOND DEGREE.
int main()
{
    float a,b,c;
    float X1 = 0;
    float X2 = 0;
    float X0 = 0;


    printf("\n*******RESOLUTION DES EQUATION DE SECOND DEGREE******\n");
    
    printf("Entrer les coefficients de votre equation : ");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    //Calcul du determinant.

    float D = 0;
    D =b*b - 4*a*c;

    //Conditions de delta.

    if(D != 0)
    {
        if(D < 0)
        {
            printf("S = {}\n");
        }
        else
        {
            X1 = (-b - sqrt(D))/2*a;
            X2 = (-b + sqrt(D))/2*a;

            printf("S = {%.2f, %.2f}\n", X1, X2);
        }
    }
    else
    {
        X0 = (-b)/2*a;

        printf("S = {%.2f}\n", X0);
    }
    return 0;
}