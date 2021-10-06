//
// Created by student on 10/6/21.
//

#include <stdio.h>
#include <malloc.h>
#include "header.h"


float* InsertionSort(float *tab) {

    float* result = malloc(SIZE * sizeof(float));
    result = tab;

    int i, j;
    float tmp;

    for (i=1 ; i <= SIZE-1; i++) {
        j = i;

        while (j > 0 && result[j-1] > result[j]) {
            tmp = result[j];
            result[j] = result[j-1];
            result[j-1] = tmp;
            j--;
        }
    }
    return result;
}