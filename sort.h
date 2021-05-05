#ifndef SORT_DOT_H    /* This is an "include guard" */
#define SORT_DOT_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/

/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */
void bubble_sort(int *arr, int n);
void selection_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void merge_sort(int *arr, int n);
void quick_sort(int *arr, int n);
void heap_sort(int *arr, int n);
#endif /* SORT_DOT_H */