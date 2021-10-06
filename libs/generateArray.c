//
// Created by Yannis on 06/10/2021.
//

#include "header.h"

#include <time.h>
#include <stdlib.h>

float * generateArray (size_t size) {

    float *array = malloc(size * sizeof(float));

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = ((float)rand()/(float)(RAND_MAX)) * 100.0;
    }

    return array;
}