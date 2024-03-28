#ifndef __CANDIDAT__H__
#define __CANDIDAT__H__
    #define N 30
    #define N4 10100
    #define FILE_CANDIDAT "../../fichiers/file2/donnees.csv"
    typedef struct candidat
    {
        char matricule[N];
        char nom[N];
        char dateNaissance[N];
        char ecole[N];
        char filiere[N];
        char examen[N];
    }candidat;

    void saisir_candidat(FILE* , candidat*);
    void lire_candidat(FILE* , candidat*);
    int obtenir_candidats(FILE* , candidat*);
    void enregistrer_candidats(FILE*, candidat*, int);
    void ajouter_candidat(candidat*);
    void modifier_candidat(void);
    void supprimer_candidat(char*);
    int rechercher_candidat(char*);
    int rechercher(candidat*, int, char*);
    void imprimer_Diplome(char*);
    void afficher_admis(void);
#endif