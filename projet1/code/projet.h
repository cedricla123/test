#ifndef PROJET_H
#define PROJET_H
#define SIZE 200
#define N 10
#define LINES fprintf(F, "+-----------+-----------+-----------+-----------+-----------+-----------+-------------------------------+\n")
    typedef struct etudiant
    {
        char CNI[N];
        char nom[N];
        char prenom[N];
        int age;
        char filiere[N];
        int niveau;
        float cotisation[5];
    }etud;
    void saisir();
    void ajouter();
    void add(etud* );
    void modifier();
    FILE *ouverture1(const char* );
    FILE *ouverture2(const char* );
    FILE *ouverture3(const char* );
#endif
