#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <stdio.h>
   typedef struct equipe1 equipe2;
    struct equipe1
{
char  equipe11[12];


  };
typedef struct equipes {
    char eq1[12];/**contient le nom de la premiere equipe (recevante)**/
    char eq2[12];/**contient le nom de la 2eme equipe(visitante)**/
    int smp;/**contient la somme des points des deux equipes**/
    int cer;/**contient le rang de la premiere equipe **/

}calend;
   typedef struct classement2{
        int rang;
        char equipe[12];
        int npt;
        int diff;

        }classement12;

  typedef struct Maillon_Li * Pointeur_Li ;
    typedef struct rang{
    char eq[12]; /**le nom de l'équipe**/
    int p;
    int j;
    int g;
    int n;
    int npt;
    int diff;
    int bp;
    int bc;
    int rang;
    } ligne;
  struct Maillon_Li
    {

      ligne val;
      Pointeur_Li Suiv ;
    } ;


  typedef struct Maillon_Leq * Pointeur_Leq ;

  struct Maillon_Leq
    {
      Pointeur_Li tete_equipes;
      char  lettre ;
      Pointeur_Leq Suiv ;
    };

    void Allouer_Leq (Pointeur_Leq *P);
    void Aff_lettre_tete(Pointeur_Leq P, char Lettre, Pointeur_Li tete);
    void Aff_adr_Leq( Pointeur_Leq P,  Pointeur_Leq Q);
    Pointeur_Leq Suivant_Leq(  Pointeur_Leq P);
    void Allouer_Li (Pointeur_Li *P);
    void Aff_adr_Li( Pointeur_Li P,  Pointeur_Li Q);
    Pointeur_Li Suivant_Li(  Pointeur_Li P);
    void Liberer_Li ( Pointeur_Li P);

typedef struct Maillon_Cal * Pointeur_Cal;
  struct Maillon_Cal
    {
      char eq1[12];
      char eq2[12];
      int bp;/** le nombre de but marqués par l'equipe recevante**/
      int bc;/** le nombre de but marqués par l'equipe visiteuse **/

      Pointeur_Cal Suiv ;
    } ;
    void Allouer_Cal (Pointeur_Cal *P);
    void Aff_val_Cal(Pointeur_Cal P, int bp, int bc);
    void Aff_adr_Cal( Pointeur_Cal P, Pointeur_Cal Q );
    Pointeur_Cal Suivant_Cal(Pointeur_Cal P);
    void trier_ListeEQ(Pointeur_Leq L);
void trier_ListeLi(Pointeur_Li P);
    void creer_ListeEQ(Pointeur_Leq* L, FILE* fic);
 void creer_listeCal(Pointeur_Cal p2 ,Pointeur_Cal *tete);
 void match_diffuser (Pointeur_Cal tete,Pointeur_Leq LLL,int *pv);
 void resultat_match (Pointeur_Cal p3);
 void MAJ_listeEQ (Pointeur_Cal tete,Pointeur_Leq LLL,int taille);
 void affichage_resultat (Pointeur_Cal tete);
 void affichage_match (Pointeur_Cal tete);
 void MAJ_rang (Pointeur_Leq LLL,FILE * fich,int taille);
void affichage_classement (FILE *fic);

#endif // FONCTIONS_H_INCLUDED



