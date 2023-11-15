#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **saveAutomateOnFile(int nbLigne, int nbColonne)
{

    FILE *fichier;                       // Déclaration d'un pointeur de type FILE
    fichier = fopen("donnees.txt", "w"); // Ouvre le fichier en écriture ("w")
    /*
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1; // Quitte le programme avec une erreur
    }*/

    int qTrans;

    int **m = malloc(nbLigne * sizeof(int *));

    for (int i = 0; i < nbLigne; i++)
    {
        m[i] = malloc(nbColonne * sizeof(int));
        for (int j = 0; j < nbColonne; j++)
        {

            printf("Choisissez la transition q%d -----> a%d \n", i, j);
            scanf("%d", &qTrans);

            m[i][j] = qTrans;
        }
    }
    return m;
}

void affiche(int **m, int ligne, int colonne)
{

    FILE *fichier; // Déclaration d'un pointeur de type FILE
    fichier = fopen("donnees.txt", "a");

    fprintf(fichier, "   ");
    for (int i = 0; i < ligne; i++)
    {

        fprintf(fichier, "a%d ", i);
    }
    fprintf(fichier, "\n");

    for (int i = 0; i < ligne; i++)
    {
        fprintf(fichier, "q%d ", i);
        for (int j = 0; j < colonne; j++)
        {
            printf("q%d -----> a%d, q%d \n", i, j, m[i][j]);

            fprintf(fichier, "q%d ", m[i][j]);
        }
        fprintf(fichier, "\n");
    }
}

int main()
{

    int nbLigne, nbColonne;
    printf("Entrez le nbre d'etats : ");
    scanf("%d", &nbLigne);

    printf("Entrez le nbre de transitions : ");
    scanf("%d", &nbColonne);

    int **m = saveAutomateOnFile(nbLigne, nbColonne);
    affiche(m, nbLigne, nbColonne);
    printf("Les valeurs ont été enregistrées dans le fichier 'donnees.txt'.\n");

    return 0;
}
