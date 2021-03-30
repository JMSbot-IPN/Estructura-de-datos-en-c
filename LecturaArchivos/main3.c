#include <stdio.h>
#include <stdlib.h>

int main(){

    char c;
    char ca[10];
    int n1, n2, n3, i;
    FILE *t1 = fopen("resultado.bin","rb");
    if (t1 == NULL){
        
        printf("error al abrir el archivo");
        exit(0);
    }
    else{
        while (feof(t1) == 0){
            
            c = getc(t1);
            printf("%c", c);
        }
    }    
    fclose(t1);

return 0;}
/*
Referencias
1.-https://www.youtube.com/watch?v=PPK28h5TmHc
2.-https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Manejo_de_archivos
*/ 