#include <stdio.h>
#include <stdlib.h>

int main(){
    char caractere = '7';  // Par exemple, '7' est un caractère numérique
    int entier = caractere - '0';


    char chaine[] = "42";  // Une chaîne de caractères représentant un entier
    int entierS = atoi(chaine);


    printf(" c = %d \n" ,entierS);


    return 0;
   
}