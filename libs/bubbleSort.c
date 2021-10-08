//
// Created by Yannis on 06/10/2021.
//

#include "header.h"

#include <stdlib.h>

/**
 * Algo de bubble sort
 * @param array
 * @param size
 * @param type
 * @return
 */
float *bubblesort(float *array, int size, int type) {

    float *result = malloc(size * sizeof(float));

    result = array;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (type == 1) {

                /* croisant */
                if (result[j] > result[j + 1]) {
                    float tmp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = tmp;
                }
            } else {
                /* decroissant */
                if (result[j] < result[j + 1]) {
                    float tmp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = tmp;
                }
            }

        }
    }

    return result;
}