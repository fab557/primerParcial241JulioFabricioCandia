#include <stdio.h>

// Declaración de funciones
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
float division(int a, int b);

int main() {
    int num1, num2;
    int opcion;
    
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    printf("Seleccione la operación:\n");
    printf("1. Suma\n2. Resta\n3. Multiplicación\n4. División\n");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("Resultado de la suma: %d\n", suma(num1, num2));
            break;
        case 2:
            printf("Resultado de la resta: %d\n", resta(num1, num2));
            break;
        case 3:
            printf("Resultado de la multiplicación: %d\n", multiplicacion(num1, num2));
            break;
        case 4:
            if (num2 != 0) {
                printf("Resultado de la división: %.2f\n", division(num1, num2));
            } else {
                printf("Error: División por cero no permitida.\n");
            }
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}

// Definición de funciones
int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicacion(int a, int b) {
    return a * b;
}

float division(int a, int b) {
    return (float)a / b;
}
