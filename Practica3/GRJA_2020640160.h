#ifndef _LISTADOBLE_H_
#define _LISTADOBLE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
    char *modelo;
    char *color;
    char *placa;
    struct _nodo *siguiente;
    struct _nodo *anterior;
}nodo;

nodo *AsignarMemoria(char *m, char *c, char *p){

    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->modelo = strdup(m);
    nuevo->color = strdup(c);
    nuevo->placa = strdup(p);
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;

}

int listlen(nodo *inicio){

int i = 0;

    while (inicio != NULL){
        i++;
        inicio = inicio->siguiente;
    }

    return i;
}

nodo *list(nodo *lista, char *m, char *c, char *p){

    nodo *nuevo;
    nodo *aux;
    nuevo = AsignarMemoria(m, c, p);
    if(lista == NULL){
        lista = nuevo;
    }
    else{
        aux = lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        nuevo->anterior = aux;
        aux->siguiente = nuevo;
    }

    return lista;

}

//misc

void ver(nodo *inicio){

    while(inicio != NULL){
        printf("%s\t%s\t%s\n", inicio->modelo, inicio->color, inicio->placa);
        inicio = inicio->siguiente;
    }
    printf("\n\n");

}

void textport(nodo *lista){
    
    FILE *msort = fopen("Color.txt","w");
    if (msort == NULL){
        printf("error al abrir el archivo");
        exit(0);
    }
    else{
        while (lista != NULL){
            fprintf(msort, "%s\t%s\t%s\n", lista->modelo, lista->color, lista->placa);
            lista = lista->siguiente;
        }
        fclose(msort);
    }
}

nodo *divlist(nodo *lista){

    nodo *aux1 = NULL;
    nodo *aux2 = NULL;
    nodo *mid = NULL;
    aux1 = lista;
    aux2 = lista;

        while(aux2->siguiente && aux2->siguiente->siguiente){
            aux2 = aux2->siguiente->siguiente;
            aux1 = aux1->siguiente;
        }

        mid = aux1->siguiente;
        aux1->siguiente= NULL;

    return mid;
}

nodo *MColor(nodo *a, nodo *b){

    nodo *aux = NULL;
    nodo *ol = NULL;

        if(a == NULL)
            return b;

        if (b == NULL)
            return a;

        if (strcmp(a->color, b->color) <= 0){
            aux = a;
            a = aux->siguiente;
        } 
        
        else{
            aux = b;
            b = aux->siguiente;
        }

        ol = aux;

        while(a != NULL && b != NULL){

            if (strcmp(a->color, b->color) <= 0){
                aux->siguiente = a;
                aux = a;
                a = aux->siguiente;
            } 
            else{
                aux->siguiente = b;
                aux = b;
                b = aux->siguiente;
            }
        }

        if(a == NULL)
            aux->siguiente = b;
        if(b == NULL)
            aux->siguiente = a;

    return ol;

}

nodo *SortBy(nodo *raw){

    nodo *SegundaMitad = NULL;
    nodo *uno = NULL;
    nodo *dos = NULL;
    nodo *ol = NULL;

    if(raw == NULL || raw->siguiente == NULL)
        return raw; 

    SegundaMitad = divlist(raw);

    uno = SortBy(raw);
    dos = SortBy(SegundaMitad);
    

    ol = MColor(uno, dos);

    return ol;
}

#endif