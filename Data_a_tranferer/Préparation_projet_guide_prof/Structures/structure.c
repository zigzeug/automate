# include <stdio.h>
# include <string.h>
# include <stdlib.h>


// Structure
struct Point
{
    /* data */
    double x,y;
};

// renommage de la structure 
typedef struct Point *ptr;



void affiche(ptr p)
{
    /* data */
    double x=p->x;
    double y=p->y;
    printf("(%f, %f)\n", x, y);
};

// Fonction principale
int main(){
    // Déclaration de variable
    ptr p1, p2;

    p1 =malloc(sizeof(ptr));
    p2 = malloc(sizeof(ptr));
    // Appel de structure // Avec la typedef on n'a plus besoin de saisir struc
    
    /* data */
    p1, p2;
    p1->x=90, p1->y=80;
    p2->x=-1, p2->y=-7;

    affiche(p1); 
    affiche(p2);

    return 0;

    
}
