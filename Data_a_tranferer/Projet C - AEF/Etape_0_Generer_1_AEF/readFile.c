#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure pour stocker une ligne et son numéro
typedef struct
{
    int numeroLigne;
    char contenu[50]; // Vous pouvez ajuster la taille en fonction de vos besoins
} LigneAvecNumero;



int **readFile()
{
    FILE *fichier;                        // Déclaration d'un pointeur de type FILE
    fichier = fopen("automate.txt", "r"); // Ouvre le fichier en lecture

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier.\n");
        return NULL; // Retourne NULL si le fichier n'a pas pu être ouvert
    }
    // Maintenant, on peut lire le fichier

    // On lit les lignes jusqu'a ce qu'on atteigne la fin du fichier
    // On utilise fgets() pour lire une ligne du fichier
    // On utilise strncpy() pour copier la ligne dans la structure
    // On utilise atoi() pour convertir la chaine en entier

    int numeroLigne = 0;
    LigneAvecNumero lignes[50]; // Tableau de structures pour stocker les lignes (ajustez la taille au besoin)

    char ligne[50]; // Un tableau pour stocker une ligne du fichier

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        // Copie la ligne dans la structure et enregistre le numéro de ligne
        lignes[numeroLigne].numeroLigne = numeroLigne;
        strncpy(lignes[numeroLigne].contenu, ligne, sizeof(lignes[numeroLigne].contenu)); // Copie la ligne dans la structure

        numeroLigne++;
    }

    // Ferme le fichier
    fclose(fichier);

    //on recupere les dimensions de la matrice qui sont sur la premiere ligne
    int nbLigne = lignes[0].contenu[0] - '0';
    int nbColonne = lignes[0].contenu[2] - '0'; 
    //test
    printf("nbLigne = %d, nbColonne = %d\n", nbLigne, nbColonne);

    // Maintenant, on a les lignes stockées dans le tableau 'lignes'
    // On cree la matrice et on la remplit avec les valeurs de la matrice
    // On commence a la ligne 1 car la premiere ligne contient les dimensions de la matrice

    int **m = malloc(numeroLigne * sizeof(int *));

    for (int i = 1; i < nbLigne; i++)
    {
        printf("%s", lignes[i].contenu);
        m[i] = malloc(nbColonne * sizeof(int));
        //strcpy(m[i], lignes[i].contenu);
        for (int j = 1; j <= nbColonne; j++)
        //for (int j = 0; j <= strlen(lignes[i].contenu); j++)
      
        {
           printf("%d", lignes[i].contenu[j]-'0');
            //if (lignes[i].contenu[j]){
                //test
                //printf("%d", lignes[i].contenu[j]); 
                m[i][j] = lignes[i].contenu[j+1]-'0';

            //}else{
                //m[lignes[i].numeroLigne][lignes[i].contenu[j]] = -1;
            //}
        }
    }

    return m; 
}




 void affichage_2(int **m){
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                printf(" m[i][j] %d", m[i][j]);
                printf("\n");
            }
        }
    }




int main()
{ 
    //readFile();
    int **m = readFile();
    affichage_2(m);

    return 0;
}


