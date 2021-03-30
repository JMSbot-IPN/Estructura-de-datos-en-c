#ifndef _LISTA_H_
#define _LISTA_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int dato;
    struct _nodo *siguiente;
}nodo;

nodo *AsignarMemoria(int d){

    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->dato = d;
    nuevo->siguiente = NULL;
    return nuevo;

}

//Listar
nodo *listini(nodo *inicio, int d){

    nodo *nuevo;
    nuevo = AsignarMemoria(d);
    if (inicio != NULL){
        nuevo->siguiente = inicio;
    }
    
    return nuevo;
}

nodo *list(nodo *lista, int d){

    nodo *nuevo;
    nodo *aux;
    nuevo = AsignarMemoria(d);
    if(lista == NULL){
        lista = nuevo;
    }
    else{
        aux = lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }

    return lista;

}

nodo *listref(nodo *inicio, int k, int d){

    nodo *nuevo;
    nodo *aux;
    int l, i;
    l = listlen(inicio);

    if(k >= 1 && k <= l){
        if(k == 1){
            inicio = listini(inicio, d);
        }
        else{
            aux = inicio;
            nuevo = AsignarMemoria(d);
            for(i = 1; i < k-1; i++){
                aux = aux->siguiente;
            }
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
return inicio;
}

//de-listar
nodo *unlistini(nodo *inicio){

    nodo *aux;
    aux = inicio;
    if (inicio != NULL){
        inicio = inicio->siguiente;
        free(aux);
    }

    return inicio;
}

nodo *unlist(nodo *lista){
    
    nodo *aux;
    aux = lista;
    while(aux->siguiente->siguiente != NULL){
        aux = aux->siguiente;
    }
    aux->siguiente = NULL;

    return lista;
}

nodo *unlistref(nodo *lista, int k){

    nodo *aux;
    nodo *aux2;
    aux2 = NULL;
    int l, i;
    l = listlen(lista);

    if(k >= 1 && k <= l){
        if(k == 1){
            lista = unlist(lista);
        }
        else{
            aux = lista;
            for(i = 1; i < k-1; i++){
                aux = aux->siguiente;
            }
            aux2 = aux->siguiente->siguiente;
            aux->siguiente = aux2;
        }
    }
return lista;
}

//re-enlistar
nodo *relistini(nodo *inicio, int d){

    nodo *nuevo;
    nodo *aux;
    nuevo = AsignarMemoria(d);
    if (inicio != NULL){
        aux = inicio->siguiente;
        nuevo->siguiente = aux;
    }
    
    return nuevo;
}

nodo *relist(nodo *lista, int d){

    nodo *nuevo;
    nuevo = NULL;
    nodo *aux;
    nodo *aux2;
    nuevo = AsignarMemoria(d);
    if(lista == NULL){
        lista = nuevo;
    }
    else{
        aux = lista;
        while(aux->siguiente->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }

    return lista;
}

nodo *relistref(nodo *inicio, int k, int d){

    nodo *nuevo;
    nodo *aux;
    int l, i;
    l = listlen(inicio);

    if(k >= 1 && k <= l){
        if(k == 1){
            inicio = relistini(inicio, d);
        }
        else{
            aux = inicio;
            nuevo = AsignarMemoria(d);
            for(i = 1; i < k-1; i++){
                aux = aux->siguiente;
            }
            nuevo->siguiente = aux->siguiente->siguiente;
            aux->siguiente = nuevo;
        }
    }
return inicio;
}

//misc
int listlen(nodo *inicio){

int i = 0;

    while (inicio != NULL){
        i++;
        inicio = inicio->siguiente;
    }

    return i;
}

void ver(nodo *inicio){

    while(inicio != NULL){
        printf("%d\n", inicio->dato);
        inicio = inicio->siguiente;
    }
    printf("\n");

}

#endif