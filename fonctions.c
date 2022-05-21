#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

 /** Implémentation **\: LISTE DE ENTIERS**/

  /** Listes linaires chainées **/

    void Allouer_Leq (Pointeur_Leq *P)
    {
      *P = (struct Maillon_Leq *) malloc( sizeof( struct Maillon_Leq)) ;
      (*P)->Suiv = NULL;
    }
     void Aff_lettre_tete(Pointeur_Leq P, char Lettre, Pointeur_Li tete)
    {
      P->lettre = Lettre ;
      P->tete_equipes=tete;
    }

    void Aff_adr_Leq( Pointeur_Leq P,  Pointeur_Leq Q)
    {
      P->Suiv = Q ;
    }

    Pointeur_Leq Suivant_Leq(  Pointeur_Leq P)
    { return( P->Suiv ) ;  }

  void Allouer_Li (Pointeur_Li *P)
    {
      *P = (struct Maillon_Li *) malloc( sizeof( struct Maillon_Li)) ;
      (*P)->Suiv = NULL;
    }

  /*void Aff_val_Li(Pointeur_Li P,char Val[12])
    {

      strcpy(&(p->val,Val);

    }*/

  void Aff_adr_Li( Pointeur_Li P,  Pointeur_Li Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_Li Suivant_Li(  Pointeur_Li P)
    { return( P->Suiv ) ;  }

  /*char* Valeur_Li( Pointeur_Li P)
    { return( &(p->val) ; }*/

  void Liberer_Li ( Pointeur_Li P)
    { free (P);}

    void Allouer_Cal (Pointeur_Cal *P)
    {
      *P = (Pointeur_Cal)malloc(sizeof(struct Maillon_Cal)) ;
      (*P)->Suiv = NULL;
    }
    void Aff_val_Cal(Pointeur_Cal P , int bp, int bc)
    {
        P->bp=bp;
      P->bc=bc;

    }

    void Aff_adr_Cal( Pointeur_Cal P, Pointeur_Cal Q )
    {
      P->Suiv = Q ;
    }
    Pointeur_Cal Suivant_Cal(Pointeur_Cal P)
    {
        return P->Suiv;
    }
     void trier_listeEQ(Pointeur_Leq L)
    {char tmp1;
    Pointeur_Leq pp,qq;
    Pointeur_Li tmp2;
    pp=L;
    while (pp)
    {
        qq=Suivant_Leq(pp);
        while (qq)
        {
            if ((pp->lettre)>(qq->lettre))
            { /**la permutation entre pp et qq**/
                tmp1=(pp->lettre);
                tmp2=(pp->tete_equipes);

                pp->lettre=qq->lettre;
                pp->tete_equipes=qq->tete_equipes;

                qq->lettre=tmp1;
                qq->tete_equipes=tmp2;
            }
            qq=Suivant_Leq(qq);
        }
        pp=Suivant_Leq(pp);
    }}
   void trier_ListeLi(Pointeur_Li P)
{  ligne tmp12;
    Pointeur_Li p=P,q;
    while (p)
    {
        q=Suivant_Li(p);
        while (q)
        {
            if (strcmp((p->val.eq),(q->val.eq))==1)
            {
               tmp12=p->val;
                    p->val=q->val;
                    q->val=tmp12;
            }
            q=Suivant_Li(q);
        }
        p=Suivant_Li(p);
    }
}
/** la fin de tri **/


 void creer_ListeEQ (Pointeur_Leq *L , FILE* fic)
{
    Pointeur_Leq p=NULL,qq,pp,LL;
    Pointeur_Li M,m; char trouv;
    *L=NULL;
    while (!feof(fic))// tant que n'est pas la fin du fichier
    {
        p=*L;
        trouv=0;
        Allouer_Li(&M);
        fscanf(fic," %d %s %d %d %d %d %d %d %d %d ",&(M->val.rang),M->val.eq,&(M->val.npt),&(M->val.j),&(M->val.g),&(M->val.n),&(M->val.p),&(M->val.bp),&(M->val.bc),&(M->val.diff));
        /** fscanf pour lire la premiere ligne de fichier rang.text **/
        Aff_adr_Li(M,NULL);
        while (p!=NULL)
        {
            if (p->lettre==M->val.eq[0])// la comparaison entre la premiere lettre de la ligne avec les lettres de la liste verticale
            {
                trouv=1;
                break;//  car on a trouvé la lettre
            }
            p=Suivant_Leq(p);
        }
        if (trouv==1)
        {
            m=p->tete_equipes;
            Aff_lettre_tete(p,M->val.eq[0],M);
            Aff_adr_Li(M,m);
        }
        else
        {
            Allouer_Leq(&pp);
            if (*L==NULL)
                *L=pp;
            else
                Aff_adr_Leq(qq,pp);
            qq=pp;
            Aff_lettre_tete(pp,M->val.eq[0],M);
            Aff_adr_Leq(pp,NULL);
        }
    }
  trier_listeEQ(*L);
    LL=*L;
    while (LL)// LL different de nil
    {
        trier_ListeLi(LL->tete_equipes);
        LL=Suivant_Leq(LL);
    }
}
void creer_listeCal(Pointeur_Cal p2 ,Pointeur_Cal *tete) {
     equipe2 tab99[256];
      int k=0;
   int taille;
     taille=0;

    Allouer_Cal(&p2);
    Pointeur_Cal q2,calendrie;
     calendrie=p2;/**calenrdie est la tete du liste calendrier **/
//    p3=p2;
     *tete=p2;

     FILE *fichier=fopen("Equipes.txt","r");

     while (!feof(fichier))

{
   fscanf(fichier,"%s",tab99[k].equipe11);

  taille++;
   k++;
} taille=taille-1 ;
fclose(fichier);
printf("choisissez le mode de remplissage de match :\n 1- par saisie  \t 2- automatiquement\n");
int choix;
scanf("%d",&choix);
 if (choix==1){int a,b;

                for (int i=0 ;i<taille;i++){
            printf("%d-%s \n ",i+1,tab99[i].equipe11);}
             printf("veillez saisir les matchs sous la forme (indice_eq1 vs indice_eq2):\n");
            int i=0;int j=0;
          while (i<taille) {
                printf("saisir le %deme match\n",j+1);
          scanf("%d vs %d",&a,&b);
                strcpy(tab99[i].equipe11,tab99[a-1].equipe11);
                strcpy(tab99[i+1].equipe11,tab99[b-1].equipe11);
                j++;
                i=i+2;

          } }
if (choix==2){
//printf("%d  %d",taille,k);
 char temp6[12];
// srand(time(NULL));
for (int i=0 ;i<taille;i++){
        int j;

    j=rand()%taille;
    strcpy(temp6,tab99[i].equipe11);
    strcpy(tab99[i].equipe11,tab99[j].equipe11);
    strcpy(tab99[j].equipe11,temp6);
}}




        int y=0;
       strcpy(p2->eq1,tab99[y].equipe11);
        strcpy(p2->eq2,tab99[y+1].equipe11);
    Aff_adr_Cal(p2,NULL);
                y=2;
    for( int i=0;i<(taille/2)-1;i++){
      q2=p2;
      Allouer_Cal(&p2);
     strcpy(p2->eq1,tab99[y].equipe11);
        strcpy(p2->eq2,tab99[y+1].equipe11);
    y=y+2;
     Aff_adr_Cal(q2,p2);
     }
          Aff_adr_Cal(p2,NULL);}

void match_diffuser (Pointeur_Cal tete,Pointeur_Leq LLL,int *pv){
int pc;
calend tab15[256];
pc=*pv;

 Pointeur_Cal p6=tete;
 Pointeur_Leq pp6=LLL;
    Pointeur_Li ppp5;
  while (p6)
            {ppp5=pp6->tete_equipes;
                  if (p6->eq1[0]==pp6->lettre){ while (ppp5){
                        if (strcmp(p6->eq1,ppp5->val.eq)==0){
                               strcpy(tab15[pc].eq1,p6->eq1);
                            tab15[pc].smp=ppp5->val.npt;
                            tab15[pc].cer=ppp5->val.rang;
                             pc++;

                         p6=Suivant_Cal(p6);
                         pp6=LLL;
                        break;}
                        else ppp5=Suivant_Li(ppp5);}}
                        else pp6=Suivant_Leq(pp6);}


                              pp6=LLL;
                               p6=tete;


pc=0;

  while (p6){

            ppp5=pp6->tete_equipes;
                  if (p6->eq2[0]==pp6->lettre){ while (ppp5){



                     if (strcmp(p6->eq2,ppp5->val.eq)==0){
                          strcpy(tab15[pc].eq2,p6->eq2);
                          tab15[pc].smp=tab15[pc].smp+ppp5->val.npt;
                          pc++;
                           p6=Suivant_Cal(p6);


                            pp6=LLL;
                          break;

                     }
                     else ppp5=Suivant_Li(ppp5);

                        }}
                        else pp6=Suivant_Leq(pp6);}

int indice=0;
int pde;
int clas;
int taille;
indice=0;
*pv=pc;
taille=*pv*2;
 pde=tab15[0].smp;
  clas=tab15[0].cer;
for (int i=1;i<taille/2;i++){
        if  (tab15[i].smp>pde){
            indice=i;
            clas=tab15[i].cer;
            pde=tab15[i].smp;
        }
        if (tab15[i].smp==pde){
                if (tab15[i].cer<clas){
                    indice=i;
                     clas=tab15[i].cer;

                }

        }

}
printf("\n le match qui sera diffusé cette semaine est %s VS %s ",tab15[indice].eq1,tab15[indice].eq2);}
void resultat_match (Pointeur_Cal p3){
    printf("selectionez le mode de remplissage:\n 1- par saisie  \t 2- automatiquement\n");
     int choix;
     scanf("%d",&choix);

     if (choix==1){
            int bp;
            int bc;


            printf("veuillez entrer le le score de chaque match (le score doit etre de la forme x-y\n");
               while (p3!=NULL)
              {printf("%s vs %s\n",p3->eq1,p3->eq2);
                scanf("%d-%d",&bp,&bc);
                Aff_val_Cal(p3,bp,bc);
                p3=Suivant_Cal(p3);
                   }
       }
     if(choix==2) {
          while (p3!=NULL){
                int bp,bc;
              bp=rand()%6;
              bc=rand()%6;

                    Aff_val_Cal(p3,bp,bc);
                    p3=Suivant_Cal(p3);

}}}
void MAJ_listeEQ (Pointeur_Cal tete,Pointeur_Leq LLL,int taille){
    Pointeur_Cal p5;
    Pointeur_Leq pp5;
    Pointeur_Li ppp5;
    p5=tete;

     pp5=LLL;




             while (p5)
            {ppp5=pp5->tete_equipes;
                  if (p5->eq1[0]==pp5->lettre){ while (ppp5){




                     if (strcmp(p5->eq1,ppp5->val.eq)==0){
                        (ppp5->val.j)++;

                   (ppp5->val.bp)=(ppp5->val.bp)+(p5->bp);
                      (ppp5->val.bc)=(ppp5->val.bc)+(p5->bc);
                    ppp5->val.diff=(ppp5->val.bp)-(ppp5->val.bc);


                     if ((p5->bp) > (p5->bc)){
                        ppp5->val.npt= (ppp5->val.npt)+3;
                         (ppp5->val.g)++;}
                     if ((p5->bp) == (p5->bc)){
                        ppp5->val.npt= (ppp5->val.npt)+1;
                        (ppp5->val.n)++;}
                      if (p5->bp < p5->bc){
                        (ppp5->val.p)++;}


                        p5=Suivant_Cal(p5);
                            pp5=LLL;
                           break;
                   } else ppp5=Suivant_Li(ppp5);}

                   }else pp5=Suivant_Leq(pp5);}
     p5=tete;

     pp5=LLL;



             while (p5)
            {ppp5=pp5->tete_equipes;
                  if (p5->eq2[0]==pp5->lettre){ while (ppp5){



                     if (strcmp(p5->eq2,ppp5->val.eq)==0){
                        (ppp5->val.j)++;
                   (ppp5->val.bp)=(ppp5->val.bp)+(p5->bc);
                      (ppp5->val.bc)=(ppp5->val.bc)+(p5->bp);
                    ppp5->val.diff=(ppp5->val.bp)-(ppp5->val.bc);

                     if ((p5->bp) > (p5->bc)){


                          (ppp5->val.p)++; }

                      if ((p5->bp) == (p5->bc)){
                        ppp5->val.npt= (ppp5->val.npt)+1;
                        (ppp5->val.n)++;}
                        if (p5->bp < p5->bc){
                             ppp5->val.npt= (ppp5->val.npt)+3;
                             (ppp5->val.g)++;}
                            p5=Suivant_Cal(p5);
                               pp5=LLL;
                                 break;



                    } else ppp5=Suivant_Li(ppp5);}

                   }else pp5=Suivant_Leq(pp5);}




        int compteur=0;

        classement12 classement[taille-1];
        pp5=LLL;



            while(compteur<taille){

                  ppp5=pp5->tete_equipes;
                          while(ppp5){strcpy(classement[compteur].equipe,ppp5->val.eq);
                                classement[compteur].npt=ppp5->val.npt;
                                classement[compteur].diff=ppp5->val.diff;
                                classement[compteur].rang=ppp5->val.rang;
  compteur++;
                                       ppp5=Suivant_Li(ppp5);

                             }
                 pp5=Suivant_Leq(pp5);}


    classement12    temp8;
int cmd,cnd,cpd;
    do {       cnd=1,cmd=1,cpd=1;
        for (int i=0 ;i<(taille)-1 ;i++){
                if (classement[i].npt>classement[i+1].npt){
             temp8=classement[i];
          classement[i]=classement[i+1];
            classement[i+1]=temp8;
                   cnd=0;}
                if (classement[i].npt==classement[i+1].npt){
                        if   (classement[i].diff>classement[i+1].diff){
                            temp8=classement[i];
                             classement[i]=classement[i+1];
                              classement[i+1]=temp8;
                              cmd=0;}
                        if (classement[i].diff==classement[i+1].diff){
                            if (strcmp(classement[i+1].equipe,classement[i].equipe)>0) {
                                temp8=classement[i];
                                classement[i]=classement[i+1];
                                classement[i+1]=temp8;
                                cpd=0;}
                 } }

        } } while (cmd==0 || cnd==0 || cpd==0);

        int h=0;


                  pp5=LLL;

                  while(h<taille){
                         classement[h].rang=(taille-h);
                        ppp5=pp5->tete_equipes;
                   if (pp5->lettre==classement[h].equipe[0]){

                    while (ppp5) {
                        if (strcmp(classement[h].equipe,ppp5->val.eq)==0){
                            ppp5->val.rang=classement[h].rang;


                            h++;
                            pp5=LLL;

                            break;}

                        else ppp5=Suivant_Li(ppp5);
                     }
                    }
                    else   pp5=Suivant_Leq(pp5);



                 }
}
void affichage_resultat (Pointeur_Cal tete){
 while(tete)
    {
     printf(" %s %d-%d %s\n",tete->eq1,(tete->bp),(tete->bc),tete->eq2);
     tete=Suivant_Cal(tete);}}
     void affichage_match (Pointeur_Cal tete){  printf("les matchs de la prochaine journée:\n");

   while(tete)
    {
     printf(" %s vs %s\n",tete->eq1,tete->eq2);
     tete=Suivant_Cal(tete);}
     }
     void MAJ_rang (Pointeur_Leq LLL,FILE * fich,int taille){

           //  Pointeur_Cal p5=tete;
   Pointeur_Li ppp5;
    Pointeur_Leq pp5=LLL;
          int cpt=0;
                 while(cpt<taille){
                        while(pp5){ppp5=pp5->tete_equipes;
                        while (ppp5){

                            if (ppp5->val.rang==cpt+1){
                               fprintf(fich,"%d %s %d %d %d %d %d %d %d %d\n",ppp5->val.rang,ppp5->val.eq,ppp5->val.npt,ppp5->val.j,ppp5->val.g,ppp5->val.n,ppp5->val.p,ppp5->val.bp,ppp5->val.bc,ppp5->val.diff);
                             cpt++;
                            break;}
                            else ppp5=Suivant_Li(ppp5);
                        }pp5=Suivant_Leq(pp5);
                         }pp5=LLL;}}
void affichage_classement (FILE *fic){
    printf("le classement:");
     while (!feof(fic)){

    int a,b,c,d,e,f,g,h,i;
    char tab[256];
    fscanf(fic,"%d %s %d %d %d %d %d %d %d %d ",&a,tab,&b,&c,&d,&e,&f,&g,&h,&i);
printf("\n%d %s %d %d %d %d %d %d %d %d ",a,tab,b,c,d,e,f,g,h,i);
}}
