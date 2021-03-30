#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

typedef struct _nodoL{
    int dato;
    char letra;
    struct _nodoL *siguiente;
    struct _nodoL *derecha;
    struct _nodoL *izquierda;
}nodoL;

typedef struct _nodoC{
    char letra;
    char *code;
    struct _nodoC *siguiente;
    struct _nodoC *anterior;
}nodoC;

nodoL *AsignarMemoriaL(int d, char a){

    nodoL *nuevo;
    nuevo = (nodoL *)malloc(sizeof(nodoL));
    nuevo->dato = d;
    nuevo->letra = a;
    nuevo->siguiente = NULL;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    return nuevo;

}

nodoC *AsignarCodigo(char l, char *c){

    nodoC *nuevo;
    nuevo = (nodoC *)malloc(sizeof(nodoC));
    nuevo->letra = l;
    nuevo->code = strdup(c);
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
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

void verC(nodoC *inicio){

    while(inicio != NULL){
        printf("\t%c %s\n",inicio->letra, inicio->code);
        inicio = inicio->siguiente;
    }
    printf("\n");

}

char filter(unsigned char a){
    if(a == 129 || a == 161){
        return 'a';
    }
    else if(a == 137 || a == 169){
        return 'e';
    }
    else if(a == 141 || a == 173){
        return 'i';
    }
    else if(a == 147 || a == 179){
        return 'o';
    }
    else if(a == 154 || a == 186){
        return 'u';
    }
    else if(a == 145 || a == 177){
        return 'n';
    }
}

//Listar

nodoC *savecode(nodoC *lista, char letra, char codes[]){
    nodoC *nuevo;
    nodoC *aux;
    nuevo = AsignarCodigo(letra, codes);
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
        aux->siguiente = nuevo;
    }

    return lista;

}

nodoL *cletras(nodoL *lista, char letra){
    nodoL *aux;
    nodoL *nuevo;
    aux = lista;
    while (aux != NULL){
        if (aux->letra == letra){
            aux->dato = aux->dato + 1;
            return lista;
        }
        else{
            if(aux->siguiente == NULL){
                nuevo = AsignarMemoriaL(1, letra);
                aux->siguiente = nuevo;
                return lista;
            }
            else{
                aux = aux->siguiente;
            }

        }
    }
}

nodoL *divlist(nodoL *lista){

    nodoL *aux1 = NULL;
    nodoL *aux2 = NULL;
    nodoL *mid = NULL;
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

nodoL *Mfreq(nodoL *a, nodoL *b){

    nodoL *aux = NULL;
    nodoL *ol = NULL;

        if(a == NULL)
            return b;

        if (b == NULL)
            return a;

        if (a->dato <= b->dato){
            aux = a;
            a = aux->siguiente;
        }

        else{
            aux = b;
            b = aux->siguiente;
        }

        ol = aux;

        while(a != NULL && b != NULL){

            if (a->dato <= b->dato){
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

nodoL *MSort(nodoL *lista){

    nodoL *SegundaMitad = NULL;
    nodoL *uno = NULL;
    nodoL *dos = NULL;
    nodoL *ol = NULL;

    if(lista == NULL || lista->siguiente == NULL)
        return lista;

    SegundaMitad = divlist(lista);

    uno = MSort(lista);
    dos = MSort(SegundaMitad);


    ol = Mfreq(uno, dos);

    return ol;
}

nodoL *CList(nodoL *lista){
    nodoL *primero = lista;
    nodoL *segundo = lista->siguiente;
    nodoL *aux = lista;
    nodoL *nuevo;
    int sfre;

    while (segundo){
        sfre = primero->dato + segundo->dato;
        while (aux->siguiente && sfre >= aux->siguiente->dato){
                aux = aux->siguiente;
        }
        nuevo = AsignarMemoriaL(sfre, '*');
        nuevo->izquierda = primero;
        nuevo->derecha = segundo;
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
        primero = primero->siguiente->siguiente;
        segundo = segundo->siguiente->siguiente;
        aux = lista;
    }
    return lista;
}

nodoL *postL(nodoL *arbol, nodoL *lista){
    if(arbol != NULL){
        lista = postL(arbol->izquierda, lista);
        lista = postL(arbol->derecha, lista);
        lista = list(lista, arbol->dato, arbol->letra);
    }
    return lista;
}
// esta funci�n es patrocinada por:
// https://www.youtube.com/watch?v=WuhDuq2GGKg&list=WL&index=59&t=4065s
nodoC *coding(nodoL *arbol, char codes[], nodoC *lista, int i){

    if(arbol){

        if(arbol->izquierda){
            codes[i] = '0';
            lista = coding(arbol->izquierda, codes, lista, i+1);
        }

        if(arbol->derecha){
            codes[i] = '1';
            lista = coding(arbol->derecha, codes, lista, i+1);
        }

        if(arbol->letra != '*'){
            codes[i] = '\0';
            nodoC *nuevo;
            nodoC *aux;
            int j = 0;
            char *arr = (char *)malloc(strlen(codes));
            while(j < strlen(codes)){
                if(codes[j] == '0' || codes[j] == '1'){
                    arr[j] = codes[j];
                }
                j++;
            }
            nuevo = AsignarCodigo(arbol->letra, codes);
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
        }
        return lista;
    }
}

nodoL *rfile(nodoL *lista, char path[]){
    unsigned char raw1;
    char letrarfile;
    int sc;
    FILE *lec;
    lec = fopen(path, "r");
    if(lec == NULL){
        printf("\n\tError al abrir el archivo\n");
        fclose(lec);
        return NULL;
    }
    else{
        while (feof(lec) == 0){
            raw1 = fgetc(lec);
            if (raw1 == ' ')
                raw1 = '_';
            if (raw1 == 255)
                break;
            if(raw1 == 195){
                sc = 1;
            }
            else{
                if(sc == 1){
                    letrarfile = filter(raw1);
                    letrarfile = toupper(letrarfile);
                    letrarfile = tolower(letrarfile);
                    if (lista == NULL){
                        lista = list(lista, 1, letrarfile);
                    }
                    else{
                        lista = cletras(lista, letrarfile);
                    }
                    sc = 0;
                }
                else{
                    letrarfile = raw1;
                    letrarfile = toupper(letrarfile);
                    letrarfile = tolower(letrarfile);
                    if (lista == NULL){
                        lista = list(lista, 1, letrarfile);
                    }
                    else{
                        lista = cletras(lista, letrarfile);
                    }
                }
            }
        }
        fclose(lec);
        return lista;
    }
}

char *frasecodi(nodoC *lista, char path[]){
    nodoC *aux = lista;
    while(aux->siguiente){
        aux = aux->siguiente;
    }
    int maxcaux;
    maxcaux = strlen(aux->code);
    unsigned char raw;
    char letracodi;
    char *caux = (char *)malloc(maxcaux);
    char *codificado = '\0';
    int sc;
    while(aux->anterior){
        aux = aux->anterior;
    }

    FILE *lec = fopen(path, "r");
    if(lec == NULL){
        printf("\n\tError al abrir el archivo");
        fclose(lec);
        return NULL;
    }
    else{
        while (feof(lec) == 0){
            raw = fgetc(lec);
            if (raw == ' '){
                raw = '_';
            }
            if (raw == 255){
                break;
            }
            if(raw == 195){
                sc = 1;
            }
            else{
                if(sc == 1){
                    letracodi = filter(raw);
                    letracodi = toupper(letracodi);
                    letracodi = tolower(letracodi);
                    while(lista){
                        if(codificado){
                            if(aux->letra == letracodi){
                                caux = strdup(aux->code);
                                strcat(codificado, caux);
                                break;
                            }
                        }
                        else{
                            if(aux->letra == letracodi){
                                caux = strdup(aux->code);
                                codificado = caux;
                                break;
                            }
                        }
                        aux = aux->siguiente;
                    }
                    sc = 0;
                }
                else{
                    letracodi = raw;
                    letracodi = toupper(letracodi);
                    letracodi = tolower(letracodi);
                    while(aux){
                        if(codificado){
                            if(aux->letra == letracodi){
                                caux = strdup(aux->code);
                                strcat(codificado, caux);
                                break;
                            }
                        }
                        else{
                            if(aux->letra == letracodi){
                                caux = strdup(aux->code);
                                codificado = caux;
                                break;
                            }
                        }
                        aux = aux->siguiente;
                    }
                }
            }
            while (aux->anterior){
                aux = aux->anterior;
            }
        }
        fclose(lec);
        return codificado;
    }
}

void keygen(nodoL *lista){
    FILE *key = fopen("llave.txt", "w");
    while(lista){
        fprintf(key, "%c%d", lista->letra, lista->dato);
        lista = lista->siguiente;
    }
    fclose(key);
}

void binfile(char *bstr, int noele){
    char *temp;
    char barr[7];
    int asdf = strlen(bstr);
    char arrunico[asdf];
    int i = 0;
    int n,m,sl;
    int x;
    sl = strlen(bstr);
    for(temp = bstr; *temp != '\0'; temp++){
        arrunico[i] = *temp;
        i++;
    }
    i=0;
    FILE *bi = fopen("codigo.bin", "wb");
    fprintf(bi, "%d", noele);
    for(n = 0; n<noele; n++){
        for(m = 0; m<7; m++){
            barr[m] = arrunico[i];
            i++;
        }
        barr[7] = '\0';
        x = strtol(barr, NULL, 2);
        fprintf(bi, "%d",x);
        barr[0] = '\0';
    }
    fclose(bi);
}

