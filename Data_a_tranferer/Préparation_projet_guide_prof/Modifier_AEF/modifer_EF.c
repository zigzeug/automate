# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// Déclaration des constantes


// Déclaration de variables globales


// Protypage
/*Saisir information de modification (juste prendre le nombre d'états à modifier ainsi que les symboles)*/
int saisir_modif(int *nb_etat_modif, int *nb_symbol_modif, int *choix){

    // Déclaration de variables
    int nb_arcs, symbol_a_remplacer;
    int new_etat_suivant, new_symbo_associe;
    char reponse_symbole;

    /*Les saisies*/
    printf("Veillez saisir le nombre d'états à modifier: ");
    scanf("%d", nb_etat_modif);

    printf("Veillez saisir le nombre de symboles à modifier :");
    scanf("%d", nb_symbol_modif);

    /*Bilan*/
    printf("La modification de %d états et de %d symboles sera faite\n", nb_etat_modif, nb_symbol_modif);

    // Déclaration d'un tableau : nb_etat_modif, nb_symbol_modif, et choix de la méthode de modification
    int *tab_bilan_modif[]={nb_etat_modif, nb_symbol_modif, choix};


    return tab_bilan_modif;
}


int AEF_modif(int *tab, int nb_etat_modif, int nb_symbol_modif ){
    // Initialisation de la matrice en sortie
    int size = *nb_etat_modif;
    int **matrice= malloc(size*sizeof(int *));

    return matrice;

}
/*Enregistrement de tous les états à modifier dans un tableau*/
int enregistrement_etat_a_modifier(){
    for(int i=0; i<*nb_etat_modif; i++){
        printf("Saisir les numéros des états à modifier : \n");
        while(i<=nb_etat_modif-1){
                scanf("%d", etat_a_modif);
                *(tab_etat_modif[i+1])=etat_a_modif;
                printf("Ensuite,");
            }
            printf("Enfin");
            scanf("%d", etat_a_modif);
            *(tab_etat_modif[i+1])=etat_a_modif;  
        }
}


/*Choix 1 : Modification un par un*/
int choix_modif_un_par_un(){
        if(choix == 1){
        /*Bouclage sur tous les états*/
        for(int i=0; i< *nb_etat_modif; i++){
            /*Récupération du nombre d'arc à modifier*/
            printf("Pour l'état : %d\n", i);
            printf("Veillez saisir le nombre d'arcs qui partent de cet état : \n");
            scanf("%d", &nb_arcs);

            /*Sur chaque arc : modification de l'état cible*/
            for(int j=0; j< nb_arcs; j++){
                printf("Pour cet arc : a%d\n", j);
                printf("Quel est le nouvel état suiant ? : \n");
                scanf("%d", &new_etat_suivant);

                /*Sur cet arc le symbole est modifié ou pas ? */
                printf("Souhaitez-vous modifier le symbole  existant ? : oui [y] / non [n]");
                scanf("%c", &reponse_symbole);
                if (reponse_symbole=='y'){
                    printf("Par quel symbole voulez-vous le remplacer ? : \n");
                    scanf("%d", &new_symbo_associe);
                    matrice_result[i][new_symbo_associe] = new_etat_suivant;
                }
                else{
                    matrice_result[i][j] = new_etat_suivant;
                }
            }
        }
    }
}
    /*Choix 2 : Modification d'un coup*/


int choix_modif_tout_un_fois(){
        if(choix == 2){
                for(int i=0; i< *nb_etat_modif; i++){
            
            /*Récupération du nombre d'arc à modifier*/
            printf("Pour l'état : %d\n", i);
            printf("Veillez saisir le nombre d'arcs qui partent de cet état : \n");
            scanf("%d", &nb_arcs);

            /*Sur chaque arc : modification de l'état cible*/
            for(int j=0; j< nb_arcs; j++){
                printf("Pour cet arc : a%d\n", j);
                printf("Quel est le nouvel état suiant ? : \n");
                scanf("%d", &new_etat_suivant);

                /*Sur chaque arc modification du symbole ou pas*/
                printf("Souhaitez-vous modifier le symbole  ? : oui [y] / non [n]");
                scanf("%c", &reponse_symbole);
                if (reponse_symbole==y){
                    printf("Par quel symbole voulez-vous le remplacer ? : \n");
                    scanf("%d", &new_symbo_associe);
                }
                else{
                    new_symbo_associe = m[][];
                }
            }
        }
    }

}

    


int man(){
    // Déclaration de varaibles
    int nb_etat_modif, nb_symbol_modif, choix;
    /*Tableau bilan des modifications à apporter*/
    int *tab_bilan[3]={0};
    int **matrice_result;

    // Appel de fonction
    tab_bilan = saisir_modif(&nb_etat_modif, &nb_symbol_modif, &choix);

    affichage(matrice_result);

}