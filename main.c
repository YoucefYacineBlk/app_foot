#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"




int main(int argc, char *argv[]){
int choix;
int pv=0;
  Pointeur_Cal p2,tete;
  Pointeur_Leq L=NULL;
   Pointeur_Leq LLL;
    Pointeur_Cal p5=tete;
     int taille;
    printf("bienvenu dans notre petite console sur le deroulement du championat de football\n");
printf("commencez par bien vouloir remplir le calendrier de la journée\n");
 creer_listeCal(p2,&tete);/**on cree la liste calendrier**/
 printf("\n");
  FILE *fic=fopen("rang.txt","r");

    creer_ListeEQ(&L,fic);/**on cree la liste EQ**/
    fclose(fic);
    LLL=L;

 match_diffuser(tete,LLL,&pv);
 taille=pv*2;
 printf("\n");
/** ************************************************** **/
    printf("choisissez ce que vous desirez faire:\n1-consultation des matchs de la journées\n2-le match qui sera diffusé sur notre chaine\n3-saisir les resultatde la journée\n4-consulter le classement\n5-resume de la journée\n6-quiter la console");
 printf("\n");
 scanf("%d",&choix);
if (choix==5){
    /** le début du programme : les instructions principales **/

  affichage_match(tete);/**on affiche les match de la journée**/


match_diffuser(tete,LLL,&pv);/**on ecrit le match a diffuser**/
printf("\n");
resultat_match(tete);/**on recupere les resultats des matchs par saisie ou automatiquement**/



affichage_resultat(tete);/**affichage des resultats**/
MAJ_listeEQ(tete,LLL,taille);/**mise a jour de la liste EQ en fonction des nouveaux resultat**/


                      FILE *fich=fopen("rang.txt","w");

MAJ_rang (LLL,fich,taille);/**mise a jour du fichier rang apres la mise a jour de la liste EQ**/
             fclose(fich);
      FILE *fic1=fopen("rang.txt","r");
      affichage_classement(fic1);/**affichage du classement**/
      fclose(fic1);

    }
    if (choix==1){
             affichage_match(tete);
             printf("si vous voulez saisir les resultats ecrivez 3 sinon ecrivez 6\n");
             scanf("%d",&choix);}
    if (choix==2) {
             match_diffuser(tete,LLL,&pv);
    printf("\n");
             printf("si vous voulez saisir les resultats ecrivez 3 sinon ecrivez 6\n");
             scanf("%d",&choix);
           }


    if (choix==3){

        resultat_match(tete);
        affichage_resultat(tete);
      MAJ_listeEQ(tete,LLL,taille);

       FILE *fich=fopen("rang.txt","w");

MAJ_rang (LLL,fich,taille);/**mise a jour du fichier rang apres la mise a jour de la liste EQ**/
             fclose(fich);
              FILE *fic1=fopen("rang.txt","r");
      affichage_classement(fic1);/**affichage du classement**/
      fclose(fic1);
    }
    if(choix==4){

              FILE *fic1=fopen("rang.txt","r");
      affichage_classement(fic1);/**affichage du classement**/
      fclose(fic1);

    }
if (choix==6){
    printf("A BIENTOT");
}
return 0;

}