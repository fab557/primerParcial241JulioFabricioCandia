#include <stdio.h>
#include <omp.h>

int main() {
    int a = 5, b = 6, c;

    #pragma omp parallel num_threads(2)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                c = a + b;
                printf("Hilo 1: %d + %d = %d\n", a, b, c);
            }

            #pragma omp section
            {
                c = a * b;
                printf("Hilo 2: %d * %d = %d\n", a, b, c);
            }
        }
    }

    return 0;
}
