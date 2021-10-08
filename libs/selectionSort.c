/**
 * @file selectionSort.c
 * @brief Tri de tableau par selection
 * @author Teissier Yannis
 * @version 1.0
 * @date 10/06/2021
 */

#include "header.h"

/**
 * Algo de selection sort
 * @param array Tableau à trier
 * @param size Taille du tableau
 * @param type 1 = Croissant / 0 = décroissant
 * @return
 */
float *selectionsort(float *array, int size, int type) {
    float *result, tmp;

    result = array;
    int min_idx, j;

    if (type == 1) {

        for (int i = 0; i < (size - 1); i++) {
            min_idx = i;
            for (j = (i + 1); j < size; j++) {
                if (result[j] < result[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                tmp = result[i];
                result[i] = result[min_idx];
                result[min_idx] = tmp;
            }
        }
    } else {
        for (int i = size; i >= 0; i--) {
            min_idx = i;
            for (j = (i - 1); j >= 0; j--) {
                if (result[j] < result[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                tmp = result[i];
                result[i] = result[min_idx];
                result[min_idx] = tmp;
            }
        }
    }

    return result;
}


