#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

static long num_steps = 100000000;
double step;
#define NUM_THREADS 2

int main(int argc, char **argv)
{
 	int i, nthreads;
 	double pi, sum[NUM_THREADS];
 	step = 1.0 / (double) num_steps;
 	omp_set_num_threads(NUM_THREADS);
 
 #pragma omp parallel
 {
 	int i, id, nthrds;
 	double x;
 	
 	id = omp_get_thread_num();
 	nthrds = omp_get_num_threads();
 	if (id == 0)
 		nthreads = nthrds;
 	for (i = id, sum[id] = 0; i < num_steps; i += nthrds)
 	{
 		x = (i + 0.5) * step;
 		sum[id] += 4.0 / (1.0 + x * x);
 	}
 }
 	for (i = 0, pi = 0; i < nthreads; i++)
 		pi += sum[i] * step;
 	printf("%.12f\n", pi);
 	return (0);       
}