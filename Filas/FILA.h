#ifndef _FILA_H_
#define _FILA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
    char *titulo;
    int pags;
    char *edit;
    struct _nodo *siguiente;
}nodo;

nodo *AsignarMemoria(char *d, int e, char *f){

    char a[sizeof(d)];
    char b[sizeof(f)];

    strcpy(a, d);
    strcpy(b, f);

    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    strcpy(nuevo->titulo, a);
    nuevo->pags = e;
    strcpy(nuevo->edit, b);
    nuevo->siguiente = NULL;
    return nuevo;

}

nodo *insertar(nodo *inicio, char *d, int e, char *f){

    nodo *nuevo;
    nodo *aux;
    nuevo = AsignarMemoria(d, e, f);
    if (inicio == NULL){
        inicio = nuevo;
    }
    else{
        aux = inicio;
        while (aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    
    return inicio;
}

nodo *quitar(nodo *inicio){

    nodo *aux;
    aux = inicio;
    if (inicio != NULL){
        inicio = inicio->siguiente;
        free(aux);
    }
    return inicio;
}

void mostrar(nodo *inicio){

    if (inicio == NULL){
        printf("\nSin libros registrados..\n");
    }
    else{
        while (inicio != NULL){
            printf("\nTitulo:\t%s",inicio->titulo);
            printf("\nNum. de paginas:\t%d",inicio->pags);
            printf("\nEditorial:\t%s\n\n",inicio->edit);
            inicio = inicio->siguiente;
        }
        
    }
}

void tamano(nodo *inicio){

    int i = 0;
    while (inicio != NULL){
        i++;
        inicio = inicio->siguiente;
    }
    printf("\nNumero de libros:\t%d\n'n", i);

}

/*
void volcar(nodo *top, char *ptr){

    if (top == NULL){
        printf("\nLa pila esta vacia...\n");
    }
    else if(ptr == NULL){
        printf("\nNombre del archivo son especificar...\n");
    }
    else{
        FILE *t1 = fopen(ptr, "w");
        while (top != NULL){
            fprintf(t1, "%d\n", top->dato);
            top = top->siguiente;
        }
        fclose(t1);
    }
}

void importar(nodo *top, char *ptr){

nodo *nuevo;
int aux;

    if(ptr == NULL){
        printf("\nNombre del archivo son especificar...\n");
    }
    else{
        FILE *t1 = fopen(ptr, "r");

        if (t1 == NULL){
        printf("\nError al abrir el aarchivo...\n");
        }
        else{
            while (feof(t1) == 0){
                printf("Code check");
                fscanf(t1, "%d", &aux);
                printf("%d", aux);
            }
        
        fclose(t1);
        }
         
    }
}
*/
#endif