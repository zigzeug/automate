# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
        float abs;
        float ord;
} Point;

typedef struct{
    int num;
    char rue[200];
    char ville[200];
    int cpde;
} Adresse;

typedef enum{
    RUE, BOULEVARD, IMPASSE, CHEMIN, AVENUE
} Type_rue;

typedef struct{
    char nom[200];
    char prenom[200];
    int groupe;
    int num;
    Adresse add
};

int main(){
    Point x;

    scanf("%f", &x.abs);
    scanf("%f", &x.ord);

    printf("Les coordonnées du point sont (%f, %f)\n", x.abs, x.ord);

    return 0;
}
