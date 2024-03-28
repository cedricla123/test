#ifndef __NOTE__H__
#define __NOTE__H__
    #define SIZE 30
    #define N1   10
    #define N2   12 
    #define N3   10100
    #define FILE_NOTE "../../fichiers/file2/note.csv"
    typedef struct note
    {
        char  matiere[N2][N1];
        float coefficient[N2];
        float poids[N2];
    }note;
    void saisir_note(FILE* , note*);
    void lire_note(FILE* , note*);
    int obtenir_note(FILE* , note*);
    void enregistrer_note(FILE*, note*,int);
    void ajouter_Note(note*);
    void modifier_note(int);
    void supprimer_note(int);
    float somme_note(int);
    float produit_noteCoef(int);

#endif