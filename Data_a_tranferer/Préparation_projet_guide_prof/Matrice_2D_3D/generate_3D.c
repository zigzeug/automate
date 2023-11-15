# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// Déclaration des constantes


// Déclaration de variables globales


/*La fonction qui génère la matrice 3D*/
int ***generate_3D(int d1, int d2, int d3){
    // Déclaration de variables
    int ***m;

    // Contruction de la matrice
    m = malloc(d1*sizeof(int**));
    for (int i=0; i<d1; i++){
        m[i]=malloc(d2*sizeof(int*));
        for(int j=0; j<d2; j++){
            m[i][j]=malloc(d3*sizeof(int));
            for(int k=0; k<d3; k++){
                m[i][j][k]=-1;
            }
        }  
    }
    return m;
}

/*La fonction qui affiche la matrice*/
void affiche(int *** m,  int d1, int d2, int d3){
   
    // Déclaration de variable


    // Instruction
    printf("{");
    for(int i=0; i< d1; i++){
        printf("{");
        for(int j=0; j< d2; j++){
            printf("{");
            for(int k=0; k<d3; k++){
                printf("%d,", k);
            }
            printf("}");
        }
        printf("}");
        printf("\n");
    };
    printf("}");

}

/*La fonction principale*/
int main(){
    // Déclaration de variables
    int d1=3, d2=2, d3=3;
    int ***matrice_test;

    // Appel de fonction
    matrice_test = generate_3D( d1, d2, d3);
    affiche(matrice_test, d1, d2, d3);


    //Return
    return 0;


}