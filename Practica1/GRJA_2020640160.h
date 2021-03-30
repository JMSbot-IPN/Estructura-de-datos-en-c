#ifndef _PILA_H_
#define _PILA_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    char dato;
    struct _nodo *siguiente;
}nodo;

nodo *AsignarMemoria(char d){

    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->dato = d;
    nuevo->siguiente = NULL;
    return nuevo;

}

nodo *push(nodo *top, char d){

    nodo *nuevo;
    nuevo = AsignarMemoria(d);
    if (top != NULL){
        nuevo->siguiente = top;
    }
    
    return nuevo;
}

nodo *pop(nodo *top){

    nodo *aux;
    aux = top;
    if (top != NULL){
        top = top->siguiente;
        free(aux);
    }
    return top;
}

char popch(nodo *top){

    nodo *aux;
    aux = top;
    if(top != NULL){
        aux->siguiente;
        return aux->dato;
    }
    return 'e';
}

#endif