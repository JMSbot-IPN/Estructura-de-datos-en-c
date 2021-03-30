#include "FILA.h"

int main(){

nodo *cs;
nodo *cm;
cs = NULL;
cm = NULL;
int pgs;
char tit[100];
char edi[100];

    while(1){
        
    int a = 0;
    int n = 0;
    char *aux1 = NULL;
    char *aux2 = NULL;

    printf("\t\tBienvenido a la bibliotaca\n\n");
    printf("\tElija ente las siguientes opciones para registrar su libro:\n\n");
    printf("1.- Registrar libro \n\n");
    printf("2.- Ver los datos de los libros\n\n");
    printf("3.- Eliminar registro\n\n");
    printf("4.- Ver la cantidad de libros\n\n");
    printf("0.- Salir\n\n");
    printf(">> ");
    scanf("%d", &a);
    system("cls");

    switch (a){
    case 1:
        printf("\n\tElija que tipo de libro registrar\n\n");
        printf("1.- Ciencias Sociales \n\n");
        printf("2.- Comunicacion\n\n");

        scanf("%d", &n);
        fflush(stdin);

        system("cls");

        printf("\n\tTitulo: ");
        scanf("%s", tit);
        aux1 = tit;
        fflush(stdin);
        printf("\n\tNo. de paginas: ");
        scanf("%d", &pgs);
        fflush(stdin);
        printf("\n\tEdiorial: ");
        scanf("%s", edi);
        aux2 = edi;

        switch (n){
            case 1:
                cs = insertar(cs, aux1, pgs, aux2);
            break;
            case 2:
                cm = insertar(cm, aux1, pgs, aux2);
            break;
            default:
            printf("EOC");
            break;
        }
    break;
    
    case 2:
        printf("\n\tElija que tipo de libro ver\n\n");
        printf("1.- Ciencias Sociales \n\n");
        printf("2.- Comunicacion\n\n");

        scanf("%d", &n);
        fflush(stdin);

        system("cls");

        switch (n){
            case 1:
                mostrar(cs);
            break;
            case 2:
                mostrar(cm);
            break;
            default:
            printf("EOC");
            break;
        }
    break;

    case 3:
        printf("\n\tElija que tipo de libro eliminar\n\n");
        printf("1.- Ciencias Sociales \n\n");
        printf("2.- Comunicacion\n\n");

        scanf("%d", &n);
        fflush(stdin);

        system("cls");

        switch (n){
            case 1:
                cs = quitar(cs);
            break;
            case 2:
                cm = quitar(cm);
            break;
            default:
            printf("EOC");
            break;
        }
    break;

    case 4:
        printf("\n\tElija de que tipo de libro ver la cantidad\n\n");
        printf("1.- Ciencias Sociales \n\n");
        printf("2.- Comunicacion\n\n");

        scanf("%d", &n);
        fflush(stdin);

        system("cls");

        switch (n){
            case 1:
                tamano(cs);
            break;

            case 2:
                tamano(cm);
            break;

            default:
            printf("EOC");
            break;
        }
    break;

    default:
        printf("EOC");
    break;
    }
    system("pause");
    fflush(stdin);
    system("cls");
    }
return 0;
} 

