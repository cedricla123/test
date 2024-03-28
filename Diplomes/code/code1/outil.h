#ifndef __OUTIL__H__
#define __OUTIL__H__
    #define LIGNE printf("+-----------------------------+----------------------------+----------------------------+----------------------------+\n")
    #define LINES printf("----------------------------------------------------------------------------------------------------------------------\n")
    #define DIESE printf("#################################################\n")

    float produit_note(float , float);
    float moyenne_candidat(float note , float coef);
    void  decision(float);
    char* mention(float);
    
#endif