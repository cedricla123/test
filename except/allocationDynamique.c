#include <stdio.h>
#include <stdlib.h>
#define space printf("\n----------------------------------------------------------\n\n")

int main(void)
{
    int nombreNombre = 0, i;
    int *tabeauNombre = NULL;

    printf("Entrez le nombre d'element a enregistrer : ");
    scanf("%d", &nombreNombre);
    tabeauNombre = malloc(sizeof(int)*nombreNombre);
    if(tabeauNombre == NULL)
    {    
        printf("Impossible d'allouer de la memoire\n");
        exit(-1);
    }
    for(i=0 ; i<nombreNombre ; i++)
        tabeauNombre[i] = i+1;
    printf("Affichage des elements :)\n");
    for(i=0 ; i<nombreNombre-1 ; i++)
        printf("%d -> ", tabeauNombre[i]);
        printf("%d\n", tabeauNombre[i]);
    nombreNombre += 5;
    space;
    tabeauNombre = realloc(tabeauNombre , sizeof(int)*nombreNombre);
    if(tabeauNombre == NULL)
    {
        printf("Impossible d'allouer de l'espace\n");
        exit(-1);
    }
    for(i=0 ; i<nombreNombre ; i++)
        tabeauNombre[i] = i+1;
    printf("Affichage des elements avec ajout :)\n");
    for(i=0 ; i<nombreNombre-1 ; i++)
        printf("%d -> ", tabeauNombre[i]);
        printf("%d\n", tabeauNombre[i]);
    free(tabeauNombre);
    space;
    int *Tableaunombre = NULL;
    int nombreElement = 10;
    Tableaunombre = calloc(nombreElement , sizeof(int));
    for(i=0 ; i<nombreElement-1 ; i++)
        printf("%d -> ", Tableaunombre[i]);
        printf("%d\n", Tableaunombre[i]);
    free(Tableaunombre);
    return 0;
}