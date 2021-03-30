#include "2020640160_GRJA.h"

int main(){
    // inicio
    printf("Programa para realizar la codificacion/compresion de Huffman.\n\n");
    nodoL *lista;
    int sol;
    char path[255];
    lista = NULL;
    while (!lista){
        printf("\tindique el nombre del archivo a comprimir: ");
        scanf("%s", path);
        lista = rfile(lista, path); // esto debe de dar las letras y frecuencias
    }
    lista = MSort(lista); // esto debe de dar ordenamiento
    sol = listlen(lista);
    printf("\t\nlista de frecuencias:\n");
    verL(lista);
    // esto debe de dar suma de frecuencias
    nodoL *lista2;
    lista2 = CList(lista);
    while(lista2->siguiente != NULL){
        lista2 = lista2->siguiente;
    }
    // esto debe de dar asignación al arbol
    nodoL *arbol = lista2;
    //  esto debe de dar el arbol en lista postorder
    nodoL *llave = NULL;
    llave = postL(arbol, llave);
    printf("\t\nLlave:\n");
    verL(llave);
    // esto debe de dar el archivo llave
    keygen(llave);
    // esto debe de dar la lista de codigos
    nodoC *lcode;
    lcode = NULL;
    char codigos[sol];
    for(int i = 0; i<=strlen(codigos); i++)
        codigos[i] = '\0';
    lcode = coding(arbol, codigos, lcode, 0);
    printf("\t\n\nCaracteres codificados:\n");
    verC(lcode);
    // esto debe de dar el string binario
    char *final = NULL;
    final = strdup(frasecodi(lcode, path));
    // esto debe de dar el string binario completo
    while(strlen(final)%7){
        strcat(final, "0");
    }
    printf("\t\nBuffer: \"%s\"\n\n", final);
    // esto debe de dar el archivo binario
    int noele;
    noele = strlen(final)/7;
    binfile(final, noele);
    printf("\t\nCodificacion/compresion exitosa.\n\nRevisar los archivos generados.\nllave.txt y codificacion.bin\n\n");
    system("pause");
}
