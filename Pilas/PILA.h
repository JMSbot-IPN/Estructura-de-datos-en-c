#ifndef _PILA_H_
#define _PILA_H_
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

nodo *push(nodo *top, int d){

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

void alto(nodo *top){

int i = 0;

    while (top != NULL){
        i++;
        top = top->siguiente;
    }
    printf("\nDatos de la pila:\t%d",i);
}

void mostrar(nodo *top){

    if (top == NULL){
        printf("\nLa pila esta vacia...\n");
    }
    else{
        while (top != NULL){
            printf("\nDato:\t%d",top->dato);
            top = top->siguiente;
        }
        
    }
}

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

#endif