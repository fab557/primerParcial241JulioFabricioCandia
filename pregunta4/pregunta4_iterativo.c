#include <stdio.h>

// Declaración de funciones
void calcular_pi_iterativo(int *iteraciones, double *resultado);

int main() {
    int iteraciones;
    double pi;

    printf("Ingrese el número de iteraciones: ");
    scanf("%d", &iteraciones);

    calcular_pi_iterativo(&iteraciones, &pi);
    printf("Aproximación de Pi (iterativo) después de %d iteraciones: %.15f\n", iteraciones, pi);

    return 0;
}

// Definición de la función iterativa
void calcular_pi_iterativo(int *iteraciones, double *resultado) {
    double suma = 0.0;
    for (int i = 0; i < *iteraciones; i++) {
        double termino = (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
        suma += termino;
    }
    *resultado = 4.0 * suma;
}
