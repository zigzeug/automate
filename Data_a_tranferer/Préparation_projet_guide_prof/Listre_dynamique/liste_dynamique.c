# include <stdio.h>
# include <string.h>
# include <stdlib.h>


// Liste chaînée d'entier

struct Noeud
{
    /* data */
    int val;
    struct Noeud *suivant;
    
};

typedef struct Noeud *Noeud;



// Fonction pour ajouter un élément en tête de liste
Noeud ajouterEnTete(Noeud tete, int valeur){
    Noeud nouveauNoeud = malloc(sizeof(Noeud));
    // Test si l'allocation a été bien faite
    if(nouveauNoeud == NULL){
        fprintf( stderr, "Echec de l'allocation de mémoire. \n");
        exit(1);
    }

    nouveauNoeud -> val = valeur;

    // Le nouveau noeud pointe vers l'ancienne tete de la liste
    nouveauNoeud -> suivant = tete;

    // Mettre à jour la tête de liste avec le nouveau noeud
    tete = nouveauNoeud;

    return tete;
}


// Fonction pour ajouter un élément à la fin de la liste
Noeud ajouterEnqueue(Noeud tete, int valeur){
    /*On se place à la tête de la fonction ajouterEntete*/
    Noeud nouveauNoeud = malloc(sizeof(Noeud));
    nouveauNoeud -> val = valeur;
    nouveauNoeud -> suivant = NULL;

    /*teste si la tete est vide on retourne le nouveau*/
    if(nouveauNoeud==NULL){
        tete=nouveauNoeud;
        return tete;
    }
    /* La liste n'est pas vide je dois avoir le dernier élément de la liste*/
    Noeud p = tete;

    Noeud dernier=malloc(sizeof(Noeud)); /*dernier élément de la liste*/
    while(p!=NULL){
        dernier = p;
        p= p-> suivant;
    }
    dernier -> suivant = nouveauNoeud;
    //dernier -> val;

    return tete;
}

// Méthode affiche une liste
void affiche_liste(Noeud tete){
    for(Noeud p=tete; p!= NULL; p=p->suivant){
        printf("%d ", p->val); 
    }
    printf("\n");
}


// Fonction pour caser une liste chaînée
Noeud casserListechainee(Noeud tete, int valeur){
    /*On se place à la tete de la liste chaînée*/
    /*teste si la tete est vide on retourne le nouveau*/
    if(tete==NULL){
        printf("Liste vide");
        return tete;
    }
    /*si un seul élément dans la liste*/
    if (tete->val==valeur){
        printf("NULL");
        return tete->suivant;
    }

    /*On est sûr que la 1er valeur n'est pas l'élément recherché */
    Noeud p = tete;
    Noeud avant=tete;
    while(p!=NULL && p-> val!=valeur){
        avant=p;
        p = p-> suivant;
    }
    /*on n'a pas trouvé*/
    if (p==NULL){
        printf("Valeur introuvable");
        return tete;
    }
    /*on a trouvé la valeur*/

    avant->suivant=p->suivant;
    return tete;

}

// Fonction principale

int main(){
    Noeud tete=NULL;
    Noeud queue=NULL;

    tete = ajouterEnTete(tete, 5);
    tete=ajouterEnTete(tete, 8);
    tete=ajouterEnTete(tete, 4);
    tete=ajouterEnTete(tete, 6);
    tete = ajouterEnTete(tete, 9);
    tete=ajouterEnTete(tete, 7);
    tete=ajouterEnTete(tete, 0);
    tete=ajouterEnTete(tete, 1);
    affiche_liste(tete);


    // Ajout en queue de liste
    //queue = ajouterEnqueue(tete, 2);
    //queue = ajouterEnqueue(tete, 3);
    //affiche_liste(queue);

    //Casser une valeur dans la liste
    /*test 1 :C'est la première valeur*/
    //tete=casserListechainee(tete, 5); OK


    /*Test 2 : Liste à 1 valeur mais c'est pas cette qu'il faut casser*/
    //tete=casserListechainee(tete, 3); OK

    /*Test 3 : Liste vide*/
    //tete = casserListechainee(tete, 18); OK

    // test 4 : Liste longue
    tete = casserListechainee(tete, 9);
    affiche_liste(tete);

    return 0;
}

