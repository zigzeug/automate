# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(){
    int tab[10]={0};

    printf("&tab[0] =%p \n", &tab[0]);
    printf("&tab[1] =%p \n", &tab[1]);
    printf("&tab[2] =%p \n", &tab[2]);



    // Vérification de l'allocation de mémoire toujours à faire 
    int* p;
    p=malloc(4);
    //test
    if(p==NULL){
    printf("Allocation échouée !");
    exit(1); // On quitte le programme
    };


    return 0;
}