# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(){
    char nom[100];

    printf("*Comment tu t'appelles ? ");
    
    scanf("%s", nom);
    
    printf("Bonjour %s", nom);
    return 0;
}