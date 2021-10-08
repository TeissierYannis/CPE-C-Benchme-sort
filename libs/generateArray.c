//
// Created by Yannis on 06/10/2021.
//

#include "generateArray.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * Permet de generer un tableau de float aléatoire de taille size_t
 * @param size taille de tableau
 * @return
 */
float * generateArray (int size) {

    float *array = malloc(size * sizeof(float));

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = ((float)rand()/(float)(RAND_MAX)) * 100.0;
    }

    return array;
}