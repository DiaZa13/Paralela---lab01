//
// Created by Zaray Corado on 2/19/2023.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void piCalculation(double factor, int n, int threads, double* result){
    double sum = 0.0;

#pragma omp parallel for reduction(+:sum) num_threads(threads)
    for(int i=0;i<n;i++){
        sum += factor/(2*i+1);
        factor *= -1;
    }
    *result = 4.0*sum;
}

int main(int argc, char* argv[]){
    double factor =1.0, result, start, end;
    int n = 10e6, threads=4;

    if (argc > 2) {
        n = strtol(argv[1], NULL, 10);
        threads = strtol(argv[2], NULL, 10);
    }

    start = omp_get_wtime();
    piCalculation(factor, n,threads, &result);
    end = omp_get_wtime();

    // run and save the times
    FILE *file;
    file = fopen("../time.txt", "a");
    fprintf(file,"%f,%.4f\n",result,end - start);
    fclose(file);

    printf("Con n= %d, la aproximacion del valor de PI es: %f",n,result);

    return 0;
}



