from mpi4py import MPI
import numpy as np

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    N = 0
    # El proceso maestro solicita el tamaño del vector
    if rank == 0:
        N = int(input("Ingrese el tamaño del vector: "))
    # Broadcast del tamaño del vector a todos los procesos
    N = comm.bcast(N, root=0)

    # El proceso maestro inicializa los vectores
    if rank == 0:
        vectorA = np.array([int(input(f"Ingrese el elemento {i + 1} de Vector A: ")) for i in range(N)])
        vectorB = np.array([int(input(f"Ingrese el elemento {i + 1} de Vector B: ")) for i in range(N)])
    else:
        vectorA = None
        vectorB = None

    # Distribuir los vectores entre todos los procesos
    vectorA = comm.bcast(vectorA, root=0)
    vectorB = comm.bcast(vectorB, root=0)

    # Crear un vector para almacenar el resultado
    result = np.zeros(N, dtype=int)

    # Sumar las partes de los vectores (cada proceso suma una parte)
    for i in range(rank, N, size):
        result[i] = vectorA[i] + vectorB[i]

    # El proceso maestro recoge los resultados
    comm.Reduce(result, result, op=MPI.SUM, root=0)

    # Imprimir el resultado en el proceso maestro
    if rank == 0:
        print("Resultado de la suma:")
        for i in range(N):
            print(f"{vectorA[i]} + {vectorB[i]} = {result[i]}")

if __name__ == "__main__":
    main()
