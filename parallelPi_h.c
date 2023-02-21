//
// Created by Zaray Corado on 2/20/2023.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void piCalculation(double factor, int n, int threads, double* result){
    double sum = 0.0;

#pragma omp parallel for reduction(+:sum) num_threads(threads) private(factor)
    for(int i=0;i<n;i++){
        factor = (i % 2 == 0 ? 1.0 : -1.0);
        sum += factor/(2*i+1);
    }

    *result = 4.0*sum;
}

int main(int argc, char* argv[]){
    double factor =1.0, result=0.0, start, end;
    int n = 10e7, threads=1;

    if (argc > 1) {
        n = strtol(argv[1], NULL, 10);
        threads = strtol(argv[2], NULL, 10);
    }

    start = omp_get_wtime();
    piCalculation(factor, n,threads, &result);
    end = omp_get_wtime();

    FILE *file;
    file = fopen("../time.txt", "a");
    fprintf(file,"%.4f\n",end - start);
    fclose(file);

    printf("Con %d hilos, el cualculo de PI %f segundos\n", threads, end - start);
    printf("Con n= %d, la aproximacion del valor de PI es: %f",n,result);


    return 0;
}



