#include "measure.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k;
    int *data, *temp;
    freopen("timings.out", "w", stdout);
    for (j = 10000; j < 100001; j += 10000){
        printf("%d ", j);
    }
    printf("\n");
    freopen("data.in", "r", stdin);
    data=(int *)malloc(100000*sizeof(int));
    for (j = 0; j < 100000; j++){
        scanf("%d", data + j);
    }
    for (j = 10000; j < 100001; j += 10000)
    {
        void (*sort_fn_ptr[])(int *, int) = {selection_sort, insertion_sort, heap_sort, quick_sort};
        freopen("timings1.out", "a", stdout);
        int n = sizeof(sort_fn_ptr) / sizeof(sort_fn_ptr[0]);
        for (i = 0; i < n; i++)
        {
            temp = (int *)malloc(j * sizeof(int));
            for (k = 0; k < j; k++)
                temp[k] = data[k];
            
            printf("%lf ", measure(*sort_fn_ptr[i], temp, j));
            free(temp);
        }
        printf("\n");
    }
    free(data);
    return 0;
}