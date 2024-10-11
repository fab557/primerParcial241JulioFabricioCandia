#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4  // Tamaño de la matriz (N x N)

// Función para imprimir la matriz
void print_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    int A[N][N], B[N][N], C[N][N] = {0};

    // Inicializar el entorno MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Inicializar las matrices A y B en el proceso 0
    if (rank == 0) {
        printf("Ingrese la matriz A (%dx%d):\n", N, N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("A[%d][%d] = ", i, j);
                scanf("%d", &A[i][j]);
            }
        }

        printf("\nIngrese la matriz B (%dx%d):\n", N, N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("B[%d][%d] = ", i, j);
                scanf("%d", &B[i][j]);
            }
        }

        printf("\nMatriz A:\n");
        print_matrix(A);

        printf("\nMatriz B:\n");
        print_matrix(B);
    }

    // Broadcast de la matriz B a todos los procesos
    MPI_Bcast(B, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Dividir las filas de la matriz A entre los procesos
    int rows_per_process = N / size;
    int start_row = rank * rows_per_process;
    int end_row = (rank + 1) * rows_per_process;

    // Cada proceso calcula su parte de la matriz C
    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Recolectar los resultados en el proceso 0
    MPI_Gather(&C[start_row], rows_per_process * N, MPI_INT, C, rows_per_process * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Imprimir la matriz resultado C en el proceso 0
    if (rank == 0) {
        printf("\nMatriz C (Resultado):\n");
        print_matrix(C);
    }

    // Finalizar el entorno MPI
    MPI_Finalize();
    return 0;
}
