/*
 * Autor: M. Alejandro Villalobos C.
 * Descripcion: Programa que resuelve el problema de las torres de Hanoi para n discos de forma recursiva.
*/

#include <stdio.h>

int NUM_DISCOS = 5;

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
    printf("\n ~~~~~ Torres de Hanoi ~~~~~ ");
    printf("\nTorre izquierda:  ");
    imprimirTorre(torre_izq, size_torre);
    printf("\nTorre central:    ");
    imprimirTorre(torre_cen, size_torre);
    printf("\nTorre derecha:    ");
    imprimirTorre(torre_der, size_torre);
}

// Funciones principales
void push(int valor, int arreglo[], int size_arreglo){
    // realiza un push a un arreglo
    for (int i = 0; i < size_arreglo; ++i) {
        if (arreglo[i] == 0){
            arreglo[i] = valor;
            return;
        }
    }
    printf("Error: No se pudo realizar el push");
}

int pop(int arreglo[], int size_arreglo){
    // realiza un pop a un arreglo
    for (int i = size_arreglo - 1; i >= 0; --i) {
        if (arreglo[i] != 0){
            int valor = arreglo[i];
            arreglo[i] = 0;
            return valor;
        }
    }
    printf("Error: No se pudo realizar el pop");
    return 0;
}

void resolverHanoi(int torre_actual[], int torre_aux[], int torre_final[], int size_torre){
    // Funcion recursiva que resuelve el problema de las torres de Hanoi
    if (size_torre == 1){
        push(pop(torre_actual, NUM_DISCOS), torre_final, NUM_DISCOS);
        imprimirHanoi(torre_actual, torre_aux, torre_final, NUM_DISCOS);
        return;
    }
    resolverHanoi(torre_actual, torre_final, torre_aux, size_torre - 1);
    push(pop(torre_actual, NUM_DISCOS), torre_final, NUM_DISCOS);
    imprimirHanoi(torre_actual, torre_aux, torre_final, NUM_DISCOS);
    resolverHanoi(torre_aux, torre_actual, torre_final, size_torre - 1);
}

int main() {
    // Declaracion de variables
    NUM_DISCOS = numDiscos();

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

    // Resolver problema
    resolverHanoi(torre_izq, torre_cen, torre_der, NUM_DISCOS);

    return 0;
}
