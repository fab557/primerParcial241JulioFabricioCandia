#include <stdio.h>

void calcular_fibonacci(int n, int *fibonacci) {
    // Asignar los dos primeros términos de la serie
    if (n >= 1) fibonacci[0] = 0; // F(0)
    if (n >= 2) fibonacci[1] = 1; // F(1)

    // Calcular los términos siguientes de la serie
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

int main() {
    int n;
    printf("Ingrese el número de términos de la serie de Fibonacci: ");
    scanf("%d", &n);

    // Crear un arreglo para almacenar los términos de Fibonacci
    int fibonacci[n];

    calcular_fibonacci(n, fibonacci);

    // Imprimir los términos de la serie
    printf("Serie de Fibonacci:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");

    return 0;
}
