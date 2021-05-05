#ifndef MEASURE_DOT_H    /* This is an "include guard" */
#define MEASURE_DOT_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/

/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */
double measure(void (*fn)(), int *arr, int n);
#endif /* MEASURE_DOT_H */