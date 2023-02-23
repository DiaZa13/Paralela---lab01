#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void piCalculation(int n, int threads, double* result){
    double even = 0.0, odd = 0.0;

#pragma omp parallel for num_threads(threads) reduction(+: even)
    for (int i = 0; i < n; i = i + 2){
        even += 1.0 / (2 * i + 1);
    }
#pragma omp parallel for num_threads(threads) reduction(+: odd)
    for (int j = 1; j < n; j = j + 2){
        odd += 1.0 / (2 * j + 1);
    }

    *result = 4.0*(even - odd);
}

int main(int argc, char *argv[]){
    double start, end, result=0.0;
    int n = 10e7, threads = 4;

    if (argc > 2) {
        n = strtol(argv[1], NULL, 10);
        threads = strtol(argv[2], NULL, 10);
    }

    start = omp_get_wtime();
    piCalculation( n,threads, &result);
    end = omp_get_wtime();

    FILE *file;
    file = fopen("../time.txt", "a");
    fprintf(file,"%.4f\n",end - start);
    fclose(file);

    printf("Con %d hilos, el cualculo de PI %f segundos\n", threads, end - start);
    printf("Con n= %d, la aproximacion del valor de PI es: %f",n,result);

    return 0;
}
