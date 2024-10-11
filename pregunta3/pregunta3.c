#include <stdio.h>

// Declaración de funciones
void suma(int *a, int *b, int *resultado);
void resta(int *a, int *b, int *resultado);
void multiplicacion(int *a, int *b, int *resultado);
void division(int *a, int *b, float *resultado);

int main() {
    int num1, num2;
    int opcion;
    int resultadoInt;  // Para operaciones enteras
    float resultadoFloat; // Para división

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    printf("Seleccione la operación:\n");
    printf("1. Suma\n2. Resta\n3. Multiplicación\n4. División\n");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            suma(&num1, &num2, &resultadoInt);
            printf("Resultado de la suma: %d\n", resultadoInt);
            break;
        case 2:
            resta(&num1, &num2, &resultadoInt);
            printf("Resultado de la resta: %d\n", resultadoInt);
            break;
        case 3:
            multiplicacion(&num1, &num2, &resultadoInt);
            printf("Resultado de la multiplicación: %d\n", resultadoInt);
            break;
        case 4:
            if (num2 != 0) {
                division(&num1, &num2, &resultadoFloat);
                printf("Resultado de la división: %.2f\n", resultadoFloat);
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

// Definición de funciones con punteros
void suma(int *a, int *b, int *resultado) {
    *resultado = *a + *b;
}

void resta(int *a, int *b, int *resultado) {
    *resultado = *a - *b;
}

void multiplicacion(int *a, int *b, int *resultado) {
    *resultado = *a * *b;
}

void division(int *a, int *b, float *resultado) {
    *resultado = (float)(*a) / (*b);
}
