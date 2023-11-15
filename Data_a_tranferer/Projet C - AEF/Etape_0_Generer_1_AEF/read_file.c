#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour stocker une ligne et son numéro
typedef struct
{
    int numeroLigne;
    char contenu[256]; // Vous pouvez ajuster la taille en fonction de vos besoins
} LigneAvecNumero;

int main()
{
    FILE *fichier;                        // Déclaration d'un pointeur de type FILE
    fichier = fopen("automate.txt", "r"); // Ouvre le fichier en lecture

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1; // Quitte le programme avec une erreur
    }

    int numeroLigne = 0;
    LigneAvecNumero lignes[100]; // Tableau de structures pour stocker les lignes (ajustez la taille au besoin)

    char ligne[256]; // Un tableau pour stocker une ligne du fichier

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        // Copie la ligne dans la structure et enregistre le numéro de ligne
        lignes[numeroLigne].numeroLigne = numeroLigne;
        strncpy(lignes[numeroLigne].contenu, ligne, sizeof(lignes[numeroLigne - 1].contenu));

        numeroLigne++;
    }

    // Ferme le fichier
    fclose(fichier);

    // Maintenant, vous avez les lignes stockées dans le tableau 'lignes'
    // Vous pouvez accéder aux lignes avec leurs numéros comme suit :
    for (int i = 0; i < numeroLigne - 1; i++)
    {
        printf("Ligne %d : %s", lignes[i].numeroLigne, lignes[i].contenu);
    }

    return 0;
}
