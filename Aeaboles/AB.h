#ifndef _AB_H_
#define _AB_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
    int dato;
    struct _nodo *izquierda;
    struct _nodo *derecha;
}nodo;

nodo *AsignarMemoria(int d){
    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->dato = d;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    return nuevo;
}

void izquierda(nodo **n){
    nodo *aux1 = NULL;
    nodo *aux2 = NULL;
    aux2 = (*n);
    aux1 = (*n)->izquierda;

    while (aux1->izquierda != NULL){
        aux2 = aux1;
        aux1 = aux1->izquierda;
    }
    (*n)->dato = aux1->dato;
    if(aux2 == (*n)){
        aux2->izquierda = aux1->izquierda;
    }
    else{
        aux2->derecha = aux1->izquierda;
    }
    (*n) = aux1;
}

nodo *grow(nodo *arbol, int d){
    nodo *raiz;
    nodo *nuevo;
    raiz = NULL;
    nuevo = NULL;
    nuevo = AsignarMemoria(d);
    if(arbol == NULL){
        return nuevo;
    } 
    else{
        raiz = arbol;
        while(raiz != NULL){
            if(nuevo->dato > raiz ->dato){
                if(raiz->derecha == NULL){
                    raiz->derecha = nuevo;
                    return arbol;
                }   
                else{
                    raiz = raiz->derecha;
                }
            }
            else{
                if(raiz->izquierda == NULL){
                    raiz->izquierda = nuevo;
                    return arbol;
                }
                else{
                    raiz = raiz->izquierda;
                }
            }
        }
    }
}

void trim(nodo **arbol, int d){
    nodo *aux;

    if (*(arbol) == NULL){
        printf("\nNodo a borrar no existente.");
    }
    else{
        if(d > (*arbol)->dato){
            trim(&(*arbol)->derecha, d);
        }
        else if (d < (*arbol)->dato){
            trim(&(*arbol)->izquierda, d);
        }
        else if(d == (*arbol)->dato){
            aux = (*arbol);
            if(aux->izquierda == NULL){
                (*arbol) = aux->derecha;
            }
            else if(aux->derecha == NULL){
                (*arbol) = aux->izquierda;
            }
            else{
                izquierda(&aux);
            }
            aux = NULL;
            free(aux);
        }
    }
}

void pre(nodo *n){
    if(n != NULL){
        printf("%d ", n->dato);
        pre(n->izquierda);
        pre(n->derecha);
    }
}

void in(nodo *n){
    if(n != NULL){
        in(n->izquierda);
        printf("%d ", n->dato);
        in(n->derecha);
    }
}

void post(nodo *n){
    if(n != NULL){
        post(n->izquierda);
        post(n->derecha);
        printf("%d ", n->dato);
    }
}

void ver(nodo *arbol, char *modo){
    if(strcmp("pre", modo) == 0){
        pre(arbol);
    }
    else if(strcmp("in", modo) == 0){
        in(arbol);
    }
    else if(strcmp("post", modo) == 0){
        post(arbol);
    }
    else{
        printf("\n\tModo no disponible, modos soportados:\n\"pre\"\n\"in\"\n\"post\"");
    }
    printf("\n\n");
}
#endif