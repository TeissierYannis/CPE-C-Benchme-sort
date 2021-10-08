/**
 * @file generateArray.c
 * @brief Generation de tableau
 * @author Teissier Yannis
 * @version 1.0
 * @date 10/06/2021
 */


#include "header.h"

#include <time.h>
#include <stdlib.h>

/**
 * Permet de generer un tableau de float aléatoire de taille size_t
 * @param size taille de tableau
 * @return array de float
 */
float *generateArray(int size) {

    float *array = malloc(size * sizeof(float));

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = ((float) rand() / (float) (RAND_MAX)) * 100.0;
    }

    return array;
}