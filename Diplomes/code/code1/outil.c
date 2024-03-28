#include<stdio.h>
#include <stdlib.h>
#include "note.h"
#include "candidat.h"
#include "outil.h"

float moyenne_candidat(float note , float coef)
{
    return note/coef;
}
void decision(float moyenne)
{
    if(moyenne < 10)
        printf(" ECHEC\n");
    else 
        printf(" ADMIS\n");
}
char* mention(float moyenne)
{
    if(moyenne < 10)
        return "INSSUFISANT";
    else if(moyenne < 12)
        return "PASSABLE";
    else if(moyenne < 15)
        return "ASSEZ-BIEN";
    else if(moyenne < 18)
        return "BIEN";
    else
        return "TRES-BIEN";   
}