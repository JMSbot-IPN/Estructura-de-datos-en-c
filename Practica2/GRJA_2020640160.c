#include "GRJA_2020640160.h"


int main(){

nodo *recepcion;
recepcion = NULL;
nodo *cobros;
cobros = NULL;
nodo *depositos;
depositos = NULL;
char arr[100], *aux;
int pri, seg;
srand(time(NULL));

printf("\nPrograma para realizar la simulación de una fila de atencion a clientes.\n\n");
printf("Atendiendo clientes");

    FILE *lect = fopen("personas.txt","r");
    while (feof(lect) == 0){
        fscanf(lect, "%s%d%d", arr, &pri, &seg);
        aux = arr;
        recepcion = Q(recepcion, aux, pri, seg);
    }
    fclose(lect);

    while (recepcion != NULL){
        if (rand()%2 == 0)
            cobros = reQ(recepcion, cobros);
        else
            depositos = reQ(recepcion, depositos);

        recepcion = dQ(recepcion);
    }

sleep(1);
printf(". ");
sleep(1);
printf(". ");
sleep(1);
printf(".");
sleep(2);
printf("\n\nlisto! asi quedaron las filas:\n\n");

    FILE *cob = fopen("cobros.txt", "w");
    printf("Fila de cobros:\n\n");
    while (cobros != NULL){
        fprintf(cob, "%s\t%d\t%d\n", cobros->dato, cobros->primnum, cobros->segnum);
        printf("%s\t%d\t%d\n", cobros->dato, cobros->primnum, cobros->segnum);
        cobros = dQ(cobros);
    }
    fclose(cob);

    FILE *dep = fopen("depositos.txt", "w");
    printf("\nFila de depositos:\n\n");
    while (depositos != NULL){
        fprintf(dep, "%s\t%d\t%d\n", depositos->dato, depositos->primnum, depositos->segnum);
        printf("%s\t%d\t%d\n", depositos->dato, depositos->primnum, depositos->segnum);
        depositos = dQ(depositos);
    }
    fclose(dep);
    
    printf("\n\nFavor de revisar los archivos de bitacoras\n\n");
    system("pause");

return 0;
}