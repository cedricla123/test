#ifndef PROJET_H
#define PROJET_H
#define SIZE 2000
#define N 10
#define LINES printf("+------------+------------+------------+------------+------------+------------+------------+------------+\n")
#define FIN printf("+-------------------------------------------------------------------------------------------------------+\n")
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
    void saisir(void);
    void ajouter(void);
    void add(etud* );
    void modifier(void);
    FILE *ouverture1(const char* );
    FILE *ouverture2(const char* );
    FILE *ouverture3(const char* );
    void supprimer(char matricule[10]);
    float somme(float*  , int );
    int etat(etud* );
    void affichage(void);
    void solvable(void);
    void insolvable(void);
    float statistique(void);
    void suprimer(void);
    void recherche(char matricule[10]);
#endif
