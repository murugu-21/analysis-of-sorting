#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
void swap(void* a, void* b, size_t s){
    void* tmp = malloc(s);
    memcpy(tmp, a, s);
    memcpy(a, b, s);
    memcpy(b, tmp, s);
    free(tmp);
}

void print(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int n)
{
    int i, j, c;
    for (i = 1; i < n; i++)
    {
        c = 0;
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1, sizeof(arr[j]));
                c++;
            }
        }
        if (c == 0)
        {
            break;
        }
    }
}

void selection_sort(int *arr, int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr + min, arr + i, sizeof(arr[i]));
    }
}

void insertion_sort(int *arr, int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int *arr, int l, int m, int r)
{
    int i, j, L[m - l + 1], R[r - m], k;

    for (k = 0; k < m - l + 1; k++)
        L[k] = arr[l + k];

    for (k = 0; k < r - m; k++)
        R[k] = arr[m + 1 + k];

    i = 0;
    j = 0;
    k = l;
    while (i < m - l + 1 && j < r - m)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < m - l + 1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < r - m)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_divide(int *arr, int l, int r){
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        merge_divide(arr, l, mid);
        merge_divide(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void merge_sort(int *arr, int n)
{
    merge_divide(arr, 0, n - 1);
}

int median(int *arr, int l, int mid, int r)
{
    if (arr[mid] >= arr[l])
    {
        if (arr[mid] <= arr[r])
        {
            return mid;
        }
        return r;
    }
    if (arr[l] <= arr[r])
    {
        return l;
    }
    return r;
}

int partition(int *arr, int l, int r)
{
    int i = l, j = r - 1, mid = (l + r) / 2, pivot = median(arr, l, mid, r);
    swap(arr + pivot, arr + r, sizeof(arr[r]));
    while (1)
    {
        while (i < r && arr[i] <= arr[r])
        {
            i++;
        }
        while (j > 0 && arr[j] > arr[r])
        {
            j--;
        }
        if (i < j)
            swap(arr + i, arr + j, sizeof(arr[i]));
        else
        {
            swap(arr + i, arr + r, sizeof(arr[i]));
            break;
        }
    }
    return i;
}

void quick_divide(int* arr, int l, int r){
    int pivot;
    if (l < r)
    {
        pivot = partition(arr, l, r);
        quick_divide(arr, l, pivot - 1);
        quick_divide(arr, pivot + 1, r);
    }
}

void quick_sort(int *arr, int n)
{
    quick_divide(arr, 0, n - 1);
}

void heapify(int *arr, int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr + i, arr + largest, sizeof(arr[i]));
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i > 0; i--)
    {
        swap(arr, arr + i, sizeof(arr[i]));
        heapify(arr, i, 0);
    }
}

