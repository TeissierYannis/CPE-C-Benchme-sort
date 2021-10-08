//
// Created by Yannis on 08/10/2021.
//

#include "generateArray.h"
#include <stdio.h>

float *selectionsort(float *array, int type) {
    float *result = malloc(SIZE * sizeof(float));
    result = array;

    int min_idx, j;

    if (type == 1) {

        for (int i = 0; i < (SIZE - 1); i++) {
            min_idx = i;
            for (j = (i + 1); j < SIZE; j++) {
                if (result[j] < result[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                float tmp = result[i];
                result[i] = result[min_idx];
                result[min_idx] = tmp;
            }
        }
    } else {
        for (int i = SIZE; i >= 0; i--) {
            min_idx = i;
            for (j = (i - 1); j >= 0; j--) {
                if (result[j] < result[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                float tmp = result[i];
                result[i] = result[min_idx];
                result[min_idx] = tmp;
            }
        }
    }

    return result;
}


