#ifndef __DIPLOME__H__
#define __DIPLOME__H__
#define N 30
#define LIGNE printf("+-----------------------------+----------------------------+----------------------------+----------------------------+\n")
#define LINES printf("----------------------------------------------------------------------------------------------------------------------\n")
#define DIESE printf("#################################################\n")

    typedef struct candidat
    {
        char  nomCandidat[N];
        char  dateNaissance[N];
        char  identifiant[N];
        char  etablissement[N];
        char  filiere[N];
        char  examen[N];
        char matiere[N][N];
        float note[N];
        float coef[N];
    }candidat;

    void  saisir_candidat(candidat*);
    void  saisie_note(candidat*,int);
    float sommes(float* , int);
    float produit_note(float , float);
    float moyenne_candidat(float note , float coef);
    void  decision(float);
    char* mention(float);
#endif