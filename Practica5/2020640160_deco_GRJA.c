#include "2020640160_deco_GRJA.h"

int main(){
    char codes[255];
    char pathbin[255], pathkey[255];
    nodoL *lista = NULL;
    nodoL *arbol = NULL;
    
    printf("\n\t\tDecodificacion de huffman");
    printf("\n\tFavor de introducir los nombres de los archivos.");
    printf("\n\tcodigo (archivo binario): ");
    scanf("%s", pathbin);
    fflush(stdin);
    printf("\n\tllave (archivo txt): ");
    scanf("%s", pathkey);
    fflush(stdin);

    lista = recolist(lista, pathkey);
    arbol = recotree(lista);
    decode(arbol, pathbin);
    printf("\n***Revise el archivo frase.txt***");
}
