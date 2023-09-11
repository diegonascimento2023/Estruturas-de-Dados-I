#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char** frutas = (char**) malloc(sizeof(char*)*4);
    int count;
    for(count=0; count<4; count++){
        frutas[count]=(char*) malloc(sizeof(char)*10);
    }

    strcpy(frutas[0], "maca");
    strcpy(frutas[1], "abacate");
    strcpy(frutas[2], "uva");
    strcpy(frutas[3], "laranja");
    
for(count=0; count<4; count++){
    printf("%s", frutas[count]);
}

return 0;
}