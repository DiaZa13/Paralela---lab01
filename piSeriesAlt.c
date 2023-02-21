#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int n = 10e8;
    double even = 0.0;
    double odd = 0.0;
    int thread_count = 8;
    double ti, tf, t;
    ti = omp_get_wtime();
    double t_sec = 3.45;
#pragma omp parallel for num_threads(thread_count) reduction(+ \
                                                             : even)
    for (int i = 0; i < n; i = i + 2)
    {
        even += 1.0 / (2 * i + 1);
    }
#pragma omp parallel for num_threads(thread_count) reduction(+ \
                                                             : odd)
    for (int j = 1; j < n; j = j + 2)
    {
        odd += 1.0 / (2 * j + 1);
    }
    double pi_approx = 4.0 * (even - odd);
    tf = omp_get_wtime();
    t = tf - ti;

    printf("N = %d\n", n);
    printf("threads = %d\n", thread_count);
    printf("pi_approx = %.*lf\n", 20, pi_approx);
    printf("tiempo %f segundos\n", t);
    printf("SpeedUp %f\n", t_sec/t);
    printf("Eficiencia %f\n", (t_sec/t)/thread_count);

    return 1;
}
