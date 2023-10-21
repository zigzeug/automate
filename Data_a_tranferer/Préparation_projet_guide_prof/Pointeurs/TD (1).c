# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// Déclaration des constantes


// Déclaration de variables globales



// 1- Saisir information
int **saisir(){
    // Déclaration de variable
    int nb_etat, nb_symbol, nb_arcs;
    int etat_suivant, symbol_associe;

    // Les saisis
    printf("Veillez saisir le nombre d'états : ");
    scanf("%d\n", &nb_etat);

    printf("Veillez saisir le nombre de symboles :");
    scanf("%d\n", &nb_symbol);

    // Bilan 
    printf("Vous avez saisi : %d, %d,\n", nb_etat, nb_symbol);


    // Allocation de mémoire
    int **m =malloc(nb_etat*sizeof(int*));

    for(int i=0; i< nb_etat; i++){
        m[i] = malloc(nb_symbol*sizeof(int));
        for(int j =0; j< nb_symbol; j++){
            m[i][j]=-1;
        }
    }

    // Construction de la matrice
    for(int i=0; i< nb_etat; i++){
        /*Nombre des arcs*/
        printf("Pour l'état : %d\n,", i);
        printf("Vaillez saisir le nombre d'arcs qui parte de cet état\n");
        scanf("%d\n", &nb_arcs);
        for(int j=0; j< nb_arcs; j++ ){
            printf("Pour cet arc :  arc%d\n", j);
            printf("Quel est l'état suivant ? : \n");

            scanf("%d\n", &etat_suivant);
            printf("Quel est le symbole associé ? : \n");
            scanf("%d\n", &symbol_associe);
            m[i][symbol_associe]= etat_suivant;
        }

    }
    return m;

}

// 2- Affichage de l'automate
void affichage(){
    
    // Déclaration de variable
    int nb_etat, nb_symbol, nb_arcs, etat_suivant;
    int **m_automate;

    // Appel de fonction
    m_automate = saisir();

    // Instruction
    for(int i=0; i< nb_etat; i++){
        for(int j=0; j< nb_symbol; j++){
            printf("q%d ---> a%d : q%d\n", i, j, m_automate[i][j] );
        }
    }

}



// II- Fonction principale
int main(){
    // Déclaration de varaibles
   int **matrice_test;
     
    // Appel de fonctions :
    matrice_test = saisir();

    //affichage();
    matrice_test = saisir();



    return 0;
    
}