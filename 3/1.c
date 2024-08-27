#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
void sort(int *arr, int n, int isA) {
    #pragma omp parallel for schedule(static) 
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if((isA && arr[i] > arr[j]) || (!isA && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int n = 5;
    int a[] = {1, 3, -5, 7, 9};
    int b[] = {2, -6, 4, -8, 10};
    int result = 0;
    sort(a, n, 1);
    sort(b, n, 0);
    #pragma omp parallel for reduction(+:result) schedule(static, 2) ordered
    for (int i = 0; i < n; i++) {
        int product = a[i] * b[i];
        #pragma omp ordered
        {
            result += product; 
        }
    }
    printf("Minimum Scalar Product: %d\n", result);
    return 0;
}
