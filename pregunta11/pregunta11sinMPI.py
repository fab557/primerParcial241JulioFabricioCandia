import numpy as np
from multiprocessing import Pool

def suma_elementos(args):
    a, b = args
    return a + b

def main():
    N = int(input("Ingrese el tamaño del vector: "))  # Tamaño del vector

    # Inicializar los vectores a partir de la entrada del usuario
    vectorA = np.array([int(input(f"Ingrese el elemento {i + 1} de Vector A: ")) for i in range(N)])
    vectorB = np.array([int(input(f"Ingrese el elemento {i + 1} de Vector B: ")) for i in range(N)])

    # Imprimir los vectores antes de la suma
    print("Vector A:", vectorA)
    print("Vector B:", vectorB)

    # Crear un pool de procesos
    with Pool(processes=3) as pool:
        # Sumar los vectores utilizando el pool de procesos
        result = pool.map(suma_elementos, zip(vectorA, vectorB))

    # Imprimir el resultado
    print("Resultado de la suma:")
    for i in range(N):
        print(f"{vectorA[i]} + {vectorB[i]} = {result[i]}")

if __name__ == "__main__":
    main()
