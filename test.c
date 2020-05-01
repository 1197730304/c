#include "sort.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int array[] = { 7,4,6,9,11,2,8,6,14,9,5 };
    int size = sizeof(array) / sizeof(array[0]);
    quicksort(array, 0,size-1);
    //insertsort(array, size);
    //shellsort(array, size);
    //selectsort(array, size);
    //bubblesort(array, size);
    //heapsort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
 }