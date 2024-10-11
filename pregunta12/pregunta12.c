#include <stdio.h>
#include <omp.h>

void fibonacci(int n, long long *result) {
    if (n == 0) {
        *result = 0;
    } else if (n == 1) {
        *result = 1;
    } else {
        long long a, b;

        #pragma omp task shared(a)
        fibonacci(n - 1, &a); // Cálculo de F(n-1)

        #pragma omp task shared(b)
        fibonacci(n - 2, &b); // Cálculo de F(n-2)

        #pragma omp taskwait
        *result = a + b; // Suma de F(n-1) y F(n-2)
    }
}

int main() {
    int n;
    printf("Ingrese el número de términos de la serie de Fibonacci: ");
    scanf("%d", &n);

    long long results[n]; // Arreglo para almacenar los resultados

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        fibonacci(i, &results[i]); // Calcular Fibonacci en paralelo
    }

    // Imprimir los resultados
    printf("Serie de Fibonacci:\n");
    for (int i = 0; i < n; i++) {
        printf("F(%d) = %lld\n", i, results[i]);
    }

    return 0;
}
