#include <time.h>
#include "measure.h"  
#include "sort.h"
int check(int arr[], int n){
    for (int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

double measure(void (*fn)(), int *arr, int n){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    fn(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if(check(arr, n))
        return cpu_time_used;
    return -1;
}
