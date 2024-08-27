#include <stdio.h>
#include <omp.h>

int main(void)
{   
    omp_set_num_threads(4);
    #pragma omp parallel
    printf("Hello, world.\n");
    return 0;
}