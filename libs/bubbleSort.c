//
// Created by Yannis on 06/10/2021.
//

#include "generateArray.h"

#include <stdlib.h>

float *bubblesort(float *array, int type) {

    float *result = malloc(SIZE * sizeof(float));

    result = array;

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (type == 1) {

                /* croisant */
                if (result[j] > result[j + 1])
                {
                    float tmp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = tmp;
                }
            } else {
                /* decroissant */
                if (result[j] < result[j + 1])
                {
                    float tmp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = tmp;
                }
            }

        }
    }

    return result;
}