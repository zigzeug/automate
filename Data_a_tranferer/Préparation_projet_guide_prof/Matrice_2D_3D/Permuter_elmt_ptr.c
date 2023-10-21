# include <stdio.h>
# include <string.h>
# include <stdlib.h>

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

// Diapo 2 :
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

int main(){
    int a=5, b=0;
    printf("Avant la permutation 1");
    printf("a=%d et b=%d\n", a, b);
    permute_1(a, b);
    printf("Après la pertumation 1");
    printf("a=%d et b=%d\n", a, b);
    printf("Après le permutation 2");
    permute_2(a, b);
    printf("a=%s et b=%d\n", a, b);
    return 0;
}
