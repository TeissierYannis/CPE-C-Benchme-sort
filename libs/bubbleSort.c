//
// Created by Yannis on 06/10/2021.
//

#include "generateArray.h"

#include <stdlib.h>
#include <stdio.h>


float * bubblesort(float * array) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    return array;
}

void swap(float *x, float *y) {
    float *tmp = x;

    x = y;
    *y = *tmp;
}