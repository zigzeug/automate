# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define nbLigne 3
# define nbColone 4

// Diapo 1 : 
    //conseil 1 = Représenter les données en mémoires
    // Cas 1
    //int a=12, b=90;
    //printf("a=%d et b=%d", a, b);

    //printf("n***********************************\n");

    // Cas 2
    /*int *pa, *pb, a=90;
    pa = &pa;

    printf("*pa=%d\n", *pa);
    a=-90;
    printf("*pa=%d\n", *pa);
    pb=pa;
    printf("*pb=%d", *pb);
    return 0;
    */
    // Donc représenter une donnée en mémoire c'est donc accéder à son adresse mémoire

// Diapo 2+3 :
    // Conseil 2 = permutation de valeurs sans et avec des pointeurs 

    void permute_1(int a, int b){
    int temp = a;
    a=b;
    b=temp;
 }
 
    void permute_2(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
 }

    // Ce qui suit est dans le main
    /*int a=5, b=0;
    printf("Avant la permutation 1");
    printf("a=%d et b=%d\n", a, b);
    permute_1(a, b);
    printf("Après la pertumation 1");
    printf("a=%d et b=%d\n", a, b);
    printf("Après le permutation 2");
    permute_2(&a, &b);
    printf("a=%s et b=%d\n", a, b);
    return 0;*/ 

    // Donc utiliser les pointeurs pour faire des modifications sur des valeurs

// Diapp 4

    /*int tab[]={1,2,3,4,5};
    int a=90;
    printf("%p\n", tab);
    printf("%p\n", &tab);
    printf("%p\n", a);
    printf("%p\n", &a);

    return 0;*/

    // Donc un tableau est un pointeur et l'afficher revient à pointer sur la première valeur



// Diapo 5

    void inc_1(int tab[], int size){
        for(int i=0; i<size; i++){
            tab[i]++;
        }
    }

    void inc_2(int *tab, int size){
        for(int i=0; i<size; i++){
            tab[i]++;
        }
    }

    void inc_3(int *tab, int size){
        for(int i=0; i<size; i++){
            *(tab+i)=*(tab+i)+1;
        }
    }

    void affiche(int tab[], int size){
        for (int i=0; i<size; i++){
            printf("tab[%d]=%d\n", i, tab[i]);
        }
    }

    /*int tab[]={11, 22, 23, 37, 44, 55};
    affiche(tab, 5);
    printf("************INC_1************\n");
    inc_1(tab, 5);
    affiche(tab, 5);
    printf("************INC_2************\n");
    inc_2(tab, 5);
    affiche(tab, 5);
    printf("************INC_3************\n");
    inc_3(tab, 5);
    affiche(tab, 5);*/

    //Donc un tableau est un pointeur et le passer en argument dans une fonction avec *tab permet de faire des opérations sur les valeurs des variables


// Diapo 6 :

    int *generate(int size){
        int *tab = malloc(size*sizeof(int));
        for (int i=0; i<size; i++){
            tab[i]=rand()%100;
        }
        return tab;
    }

    void affichage(int tab[], int size){
        for (int i=0; i<size; i++){
            printf("tab[%d]=%d\n", i, tab[i]);
        }
        
    }

    /*int size = 7;
    int *t=generate(size);
    affichage(t, size);*/

    // Donc pour déclarer un tableau on doit allouer de la mémoire avec malloc


// Diapo 7 : Génération d'une matrice avec une définition d'une constante


    int ** generate_1(){
        int **m;
        m = malloc(nbLigne*sizeof(int*));
        for (int i=0; i<nbLigne; i++){
            m[i]=malloc(nbColone*sizeof(int));
            for (int j=0; j<nbColone; j++){
                m[i][j] = rand()%15;
            }
        }
        return m;
    }

    void affichage_2(int **m){
        for (int i=0; i<nbLigne; i++){
            for (int j=0; j<nbColone; j++){
                printf("%d", m[i][j]);
                printf("\n");
            }
        }
    }
        
    /*int **m = generate_1();
    affichage_2(m);*/

    // Donc pour générer une matrice il faut alouer de la mémoire deux fois et c'est un pointeur de pointeur **m


// Diapo 7 : Génération d'une matrice 2D avec pour cellule le produit des indices ixj

    int ** generate_2D(int l, int c){
        int **m;
        m = malloc(l*sizeof(int *));
        for (int i = 0; i<l; i++){
            m[i]=malloc(c*sizeof(int));
            for (int j = 0; j<c; j++){
                m[i][j] = i*j;
            }
        }
        return m;
    }

    void affichage_2D(int **m, int l, int c){
        for (int i = 0; i<l; i++){
            for (int j = 0; j<c; j++){
                printf("%d", m[i][j]);
                printf("\n");
            }
        }
    }
    
    /*int ** matrice = generate_2D(4, 3);
    affichage_2D(matrice, 4, 3);*/

    // Donc contruire une matrice 2D revient simplement avec  créer un pointeur de pointeur et à faire deux fois une allocation de mémoire
    

int main(){

    return 0;

}
