#include "GRJA_2020640160.h"

int main(){
    nodo *raw = NULL;
    nodo *ol = NULL;
    char m[100], c[100], p[100];

    printf("\n\tPrograma de ordenamiento Merge sort");
    printf("\n\nleyendo archivo...");

    FILE *autos = fopen("autos.txt","r");

        if (autos == NULL){
            printf("error al abrir el archivo");
            exit(0);
        }
        else{
            while (feof(autos) == 0){
                fscanf(autos, "%s%s%s", m, c, p);
                raw = list(raw, m, c, p);
            }
            fclose(autos);
        }

    printf("\nListo!");
    printf("\nlista desordenada:\n");
        ver(raw);
    printf("Ordenando lista ");
    sleep(1);
    printf(". ");
    sleep(1);
    printf(". ");
    sleep(1);
    printf(".");
    sleep(1);
        ol = SortBy(raw);
    printf("\nListo!\n");
    printf("Lista Ordenada:\n\n");
        ver(ol);
    printf("Listo!\n");
    printf("Lista ordenada exportada a Color.txt\n\n");
    textport(ol);

        system("pause");

}