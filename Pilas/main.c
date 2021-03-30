#include "PILA.h"

int main(){

    int a = 0;
    int n = 0;
    nodo *pila;
    pila = NULL;
    char *ptr;

    while(1){
    
    printf("\t\tBienvenido a su estructura apilada\n\n");
    printf("\tElija ente las siguientes opciones para modificar su pila:\n\n");
    printf("1.- Apilar datos\n\n");
    printf("2.- Tumbar datos\n\n");
    printf("3.- Ver los datos de la pila\n\n");
    printf("4.- Ver el tamano de la pila\n\n");
    printf("5.- Volcar pila\n\n");
    printf("6.- Importar a pila\n\n");
    printf("0.- Salir\n\n");
    printf(">> ");
    scanf("%d",&a);
    system("cls");

        switch (a){
        case 1:
            printf("\n\tElija un numero para apilar: ");
            scanf("%d", &n);
            pila = push(pila,n);
        break;
        
        case 2:
            printf("\n\tTumbando al ultimo elemento");
            sleep(1);
            printf(" .");
            sleep(1);
            printf(" .");
            sleep(1);
            printf(" .");
            sleep(1);
            printf("\n\tListo!\n");
            pila = pop(pila);
        break;

        case 3:
            printf("\n\tDatos de la pila:");
            mostrar(pila);
            printf("\n");
        break;

        case 4:
            printf("\n\t");
            alto(pila);
            printf("\n\n");
        break;

        case 5:
            printf("\nEscriba el nombre del archivo: ");
            scanf("%s", ptr);
            volcar(pila, ptr);
        break;

        case 6:
            printf("\nEscriba el nombre del archivo: ");
            scanf("%s", ptr);
            importar(pila, ptr);
        break;

        default:
            exit(0);
        break;
        }
        system("pause");
        fflush(stdin);
        system("cls");
    }
    
    /*
    pila = push(pila,4);
    pila = push(pila,7);
    pila = push(pila,9);
    pila = push(pila,1);

    mostrar(pila);
    pila = pop(pila);
    printf("\n\n");
    mostrar(pila);

    alto(pila);
    */
}