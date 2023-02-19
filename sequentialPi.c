//
// Created by Zaray Corado on 2/19/2023.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void piCalculation(double factor, int n, double* result){
    double sum = 0.0, start, end;

    start = omp_get_wtime();

    for(int i=0;i<n;i++){
        sum += factor/(2*i+1);
        factor *= -1;
    }
    *result = 4.0*sum;

    end = omp_get_wtime();
    printf("Secuencialmente, el calculo de PI toma %f segundos\n", end - start);

}

int main(int argc, char* argv[]){
    double factor =1.0, result;
    int n = 10e6;

    if (argc > 1) {
        n = strtol(argv[1], NULL, 10);
    }

    piCalculation(factor, n, &result);

    printf("Con n= %d, la aproximacion del valor de PI es: \n%f",n,result);

    return 0;
}


