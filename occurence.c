#include<stdio.h>
int main()
{
    int TABLE[10];
    int i, occ;

    printf("Entrer les element de votre tableau\n");
    for(i = 0 ; i < 10 ; i++)
        scanf("%d", &TABLE[i]);

    printf("Entrer l'element que vous voulez compter le nombre d'occurence\n");
    scanf("%d", &occ);

    int j = 0;
    for(i = 0 ; i < 10 ; i++)
    {
        if(occ == TABLE[i])
            j += 1;
    }
    printf("Le nombre d'occurence est %d\n", j);
    return 0;
}