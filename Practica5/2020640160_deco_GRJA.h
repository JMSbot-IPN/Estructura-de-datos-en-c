#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

typedef struct _nodoL{
    int dato;
    char letra;
    int estado;
    struct _nodoL *siguiente;
    struct _nodoL *anterior;
    struct _nodoL *derecha;
    struct _nodoL *izquierda;
}nodoL;

nodoL *AsignarMemoriaL(int d, char a){

    nodoL *nuevo;
    nuevo = (nodoL *)malloc(sizeof(nodoL));
    nuevo->dato = d;
    nuevo->letra = a;
    nuevo->estado = 0;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    return nuevo;

}

//misc
int listlen(nodoL *inicio){

int i = 0;

    while (inicio != NULL){
        i++;
        inicio = inicio->siguiente;
    }

    return i;
}

void verL(nodoL *inicio){

    while(inicio != NULL){
        printf("\t%c %d ",inicio->letra, inicio->dato);
        if(inicio->izquierda != NULL)
            printf("\t%c %d ", inicio->izquierda->letra, inicio->derecha->dato);
        if(inicio->derecha != NULL)
            printf("\t%c %d ",inicio->derecha->letra, inicio->derecha->dato);
        printf("\n");
        inicio = inicio->siguiente;
    }
    printf("\n");

}
//Listar
nodoL *list(nodoL *lista, int d, char a){

    nodoL *nuevo;
    nodoL *aux;
    nuevo = AsignarMemoriaL(d, a);
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

void rec(char *path){
    unsigned char scan;
    int flag1 = 0;
    FILE *lec = fopen(path, "r");
    if(lec == NULL){
        printf("error al abrir el archivo");
    }
    else{
        FILE *alec = fopen("temporal.txt", "w");
        while(feof(lec) == 0){
            scan = fgetc(lec);
            if(flag1 == 0){
                fprintf(alec, "%c ", scan);
                flag1 = 1;
            }
            else if(scan <= 57 && scan >= 48){
                fprintf(alec, "%c",scan);
            }
            else if(scan != 255){
                fprintf(alec, "\n%c ", scan);
            }
        }
        fclose(alec);
    }
    fclose(lec);
}

nodoL *recolist(nodoL *lista, char *path){
    unsigned char letra;
    int numero;
    rec(path);
    FILE *tmp1 = fopen("temporal.txt", "r");
    if(tmp1 == NULL){
        printf("Error al abrir el archivo");
    }
    else{
        while(feof(tmp1) == 0){
            fscanf(tmp1, "%c%d", &letra, &numero);
            if(letra != 10){
                lista = list(lista, numero, letra);
            }
        }
    }
    fclose(tmp1);
    remove("temporal.txt");
    return lista;
}

nodoL *recotree(nodoL *lista){
    nodoL *arbol = lista;
    int der = 0;
    while(lista){
        if(lista->letra == '*'){
            while(arbol){
                arbol = arbol->anterior;
                if(arbol->estado == 0 && der == 0){
                    lista->derecha = arbol;
                    arbol->estado = 1;
                    der = 1;
                }
                else if(arbol->estado == 0){
                    lista->izquierda = arbol;
                    arbol->estado = 1;
                    der = 0;
                    break;
                }
            }
            while(arbol){
                if(arbol->letra  == lista->letra && arbol->dato == lista->dato &&arbol->estado == 0){
                    break;
                }
                else{
                    arbol = arbol->siguiente;
                }
            }
        }
        if(!lista->siguiente){
            break;
        }
        lista = lista->siguiente;
        arbol = arbol->siguiente;
    }
    return lista;
}

void pre(nodoL *n){
    if(n != NULL){
        pre(n->izquierda);
        pre(n->derecha);
        printf("%c%d", n->letra, n->dato);
    }
}

char *decbin(int num){
    char *sres = (char *)malloc(7);
    int rem;
    int i = 0;
    while (i != 7) {
        rem = num % 2;
        if(rem == 0){
            sres[6-i] = '0';
        }
        if(rem == 1){
            sres[6-i] = '1';
        }
        num = num/2;
        i++;
    }
    sres[7] = '\0';
    return sres;
}

void decode(nodoL *arbol, char *path){
    nodoL *aux = arbol;
    int arr[500];
    char *temp;
    int scan, i, j;
    char *buffer = NULL;
    i = 0;
    FILE *binf = fopen(path, "rb");
    if(binf == NULL){
        printf("error al abrir archivo");
    }
    else{
        while(feof(binf) == 0){
            fread(&scan, sizeof(scan), 1, binf);
            arr[i] = scan;
            i++;
        }
        fclose(binf);
        printf("\ncodificacion del archivo binario: ");
        for(j = 1; j < i-1; j++){
            printf("%d = ", arr[j]);
            printf("%s\n", decbin(arr[j]));
            if(!buffer){
                buffer = strdup(decbin(arr[j]));
            }
            else{
                strcat(buffer, decbin(arr[j]));
            }
        }
        printf("\nBuffer: %s", buffer);
        char barr[strlen(buffer)];
        i = 0;
        for(temp = buffer; *temp != '\0'; temp++){
            barr[i] = *temp;
            i++;
        }
        printf("\n");
        FILE *fin = fopen("frase.txt", "w");
        if(fin == NULL){
            printf("error al abrir archivo");
        }
        else{
            printf("\nFrase decodificada: ");
            for(i = 0; i<strlen(buffer); i++){
                if(barr[i] == '0'){
                    aux = aux->izquierda;
                }
                else{
                    aux = aux->derecha;
                }
                if(aux->izquierda == NULL && aux->derecha == NULL){
                    printf("%c", aux->letra);
                    fprintf(fin, "%c", aux->letra);
                    aux = arbol;
                }
            }
        }
        fclose(fin);
    }
}