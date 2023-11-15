# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// Déclaration des constantes


// Déclaration de variables globales



// 1- Saisir information
int **saisir(int * nb_etat,int *nb_symbol){
    // Déclaration de variable
    int  nb_arcs;
    int etat_suivant, symbol_associe;

    // Les saisis
    printf("Veillez saisir le nombre d'états : ");
    scanf("%d", nb_etat);

    printf("Veillez saisir le nombre de symboles :");
    scanf("%d", nb_symbol);

   
  int size=*nb_etat;

    // Allocation de mémoire
    int **m;
    m=malloc(size*sizeof(int *));
       
        for(int i=0; i< *nb_etat; i++){
        size=*nb_symbol;
       
              m[i] = malloc(size*sizeof(int));
             
              for(int j =0; j< *nb_symbol; j++){
                  m[i][j]=-1;
                 
                       
        }
         
    }
    // compléter ici la saisie des arcs
    for(int i=0; i< *nb_etat; i++){
        /*Récupération du nombre d'arc*/
        printf("Pour l'état : %d\n", i);
        printf("Veillez saisir le nombre d'arcs qui partent de cet état : \n");
        scanf("%d", &nb_arcs);

        /*Inventaire des états cibles par application de chaque symboles = transition*/
        for(int j=0; j< nb_arcs; j++){
            printf("Pour cet arc : a%d\n", j);
            printf("Quel est l'état suiant ? : \n");
            scanf("%d", &etat_suivant);

            /*Récupération du symbole aosscié*/
            printf("Quel est le symbole associé ? : \n");
            scanf("%d", &symbol_associe);

            /*Remplissage de la matrice = etat cible*/
            m[i][symbol_associe]=etat_suivant;
        }
    }

   
   
    return m;

}

// affichage, IL FAUT LUI PASSER LES PARAMETRES la matrice, nbLigne, nbColone
// 2- Affichage de l'automate
void affichage(int ** m_automate,  int nb_etat,int nb_symbol){
   
    // Déclaration de variable
    int  nb_arcs, etat_suivant;
   

    // Appel de fonction
   

    // Instruction
    for(int i=0; i< nb_etat; i++){
        for(int j=0; j< nb_symbol; j++){
            printf("q%d ---> a%d : q%d\n", i, j, m_automate[i][j] );
        }
        printf("\n********************************");
    }

}



// II- Fonction principale
int main(){
    // Déclaration de varaibles
   int **matrice_test;
   int nb_etats,nb_symbol;
    matrice_test = saisir(&nb_etats,&nb_symbol);
    
//printf("DJO%d %d",nb_etats,nb_symbol);
   affichage(matrice_test, nb_etats,nb_symbol);
   // matrice_test = saisir();

    return 0;
   
}