#ifndef _PILA_H_
#define _PILA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
    char *dato;
    int primnum;
    int segnum;
    struct _nodo *siguiente;
}nodo;

nodo *AsignarMemoria(char *a, int b, int c){

    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->dato = strdup(a);
    nuevo->primnum = b;
    nuevo->segnum = c;
    nuevo->siguiente = NULL;
    return nuevo;

}

nodo *Q(nodo *inicio, char *a, int b, int c){

    nodo *nuevo;
    nodo *aux;
    nuevo = AsignarMemoria(a, b, c);
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

nodo *dQ(nodo *inicio){

    nodo *aux;
    aux = inicio;
    if (inicio != NULL){
        inicio = inicio->siguiente;
        free(aux);
    }
    return inicio;
}

void ver(nodo *inicio){

    while (inicio != NULL){
        printf("%s\t%d\t%d\n", inicio->dato, inicio->primnum, inicio->segnum);
        inicio = inicio->siguiente;
    }
    printf("\n");

}

nodo *reQ(nodo *recep, nodo *obje){

    nodo *nuevo;
    nodo *aux;
    char *a = NULL;
    int b, c;
    
    a = strdup(recep->dato);
    b = recep->primnum;
    c = recep->segnum;

    nuevo = AsignarMemoria(a, b, c);
    if (obje == NULL){
        obje = nuevo;
    }
    else{
        aux = obje;
        while (aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    return obje;

}

#endif