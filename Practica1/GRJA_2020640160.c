#include "GRJA_2020640160.h"
#include <ctype.h>

int prioridad (char x){

    if (x == '('){
        return 0;
    }
    else if (x == '+' || x == '-'){
        return 1;
    }
    else if (x == '*' || x == '/'){
        return 2;
    }
    else if (x == '^'){
        return 3;
    }

    return 0;
}

int main(){

nodo *pila;
pila = NULL;
char *aux;

printf("\n\nAlgoritmo de cambio de nitacion aritmetica infija a postfija");
printf("\n\nPorfavor, llene el archivo infija.txt con una ecuacion aritmetica infija sin espacios");
printf("\n\nPresione cualquier tecla cuando este listo\n\n");
system("pause");
FILE *lect = fopen ("infija.txt","r");
    if(lect == NULL){
        printf("\n\n\tError al abrir el archivo...");
    }
    else{
        fscanf(lect, "%s", aux);
        printf("\nExprecion rescatada: %s\n\n", aux);
    }
    fclose(lect);

FILE *volc = fopen("postfija.txt", "w");
    while(*aux != '\0'){
     if(isalnum(*aux)){
        fprintf(volc,"%c", *aux);
    }
    else if(*aux == '('){
        pila = push(pila, *aux);
        }
        
    else if(*aux == ')'){
        while(pila->dato != '('){
            fprintf(volc,"%c", pila->dato);
            pila = pop(pila);
        }
        pila = pop(pila);
    }
    else{
        if(pila == NULL);
        else{
            while(prioridad(pila->dato) >= prioridad(*aux)){
                fprintf(volc,"%c", pila->dato);
                pila = pop(pila);
                if(pila == NULL){
                    break;
                }
                else;
            }
        }
        pila = push(pila, *aux);
    }
    aux++;
    }
    while(pila != NULL){
        fprintf(volc,"%c", pila->dato);
        pila = pop(pila);
    }
    printf("\nAccion completada, favor de revisar el archivo postfija.txt para ver el resultado");
    fclose(volc);
    return 0;
}