/*
 * Autor: M. Alejandro Villalobos C.
 * Descripcion: Programa que resuelve el problema de las torres de Hanoi para n discos de forma recursiva.
*/

#include <stdio.h>

// Funciones auxiliares
int numDiscos(){
    int num_discos;
    printf("Introduzca el numero de discos: \n ~>");
    scanf("%d", &num_discos);
    return num_discos;
}

void imprimirTorre(int torre[], int size_torre){
    for (int i = 0; i < size_torre; i++) {
        printf("%d ", torre[i]);
    }
}

void imprimirHanoi(int torre_izq[], int torre_cen[], int torre_der[], int size_torre){
    printf(" ~~~~~ Torres de Hanoi ~~~~~ ");
    printf("\nTorre izquierda:  ");
    imprimirTorre(torre_izq, size_torre);
    printf("\nTorre central:    ");
    imprimirTorre(torre_cen, size_torre);
    printf("\nTorre derecha:    ");
    imprimirTorre(torre_der, size_torre);
}

// Funciones principales
void resolverHaoi(int torre_actual[], int )

int main() {
    // Declaracion de variables
    // int NUM_DISCOS = numDiscos();
    int NUM_DISCOS = 5;

    int torre_izq[NUM_DISCOS + 1];
    int torre_cen[NUM_DISCOS + 1];
    int torre_der[NUM_DISCOS + 1];

    // Inicializacion de variables
    for (int i = 0; i < NUM_DISCOS; i++) {
        torre_izq[i] = NUM_DISCOS - i;
        torre_cen[i] = 0;
        torre_der[i] = 0;
    }

    // Imprimir torres
    imprimirHanoi(torre_izq, torre_cen, torre_der, NUM_DISCOS);

    return 0;
}
