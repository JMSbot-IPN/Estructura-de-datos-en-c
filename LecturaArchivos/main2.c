#include <stdio.h>
#include <stdlib.h>

int main(){
    char c;
    char ca[10];
    int n1, n2, n3, i;

    FILE *t1 = fopen("Archivo_E1_.txt","r");
    if (t1 == NULL){
        
        printf("error al abrir el archivo");
        exit(0);

    }
    else{
        while (feof(t1) == 0){
            
            c = getc(t1);
            printf("%c",c);

        }
    }
    
    fclose(t1);

    FILE *t2 = fopen("Archivo_E1_.txt","r");
    if (t2 == NULL){
        
        printf("error al abrir el archivo");
        exit(0);

    }
    else{

        FILE *t3 = fopen("resultado.bin","wb");

        while (feof(t2) == 0){
            
            fscanf(t2, "%s%d%d%d", &ca, &n1, &n2, &n3);
            fprintf(t3, "%d\n", n1+n2-n3);

        }

        for ( i = 0; i < 10; i++){
            
            fprintf(t3, "%d\n", i);

        }
        fclose(t3);
    }
    fclose(t2);

return 0;}
/*
Referencias
1.-https://www.youtube.com/watch?v=PPK28h5TmHc
2.-https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Manejo_de_archivos
*/ 