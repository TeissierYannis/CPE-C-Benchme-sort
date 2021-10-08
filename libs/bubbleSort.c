/**
 * @file bubbleSort.c
 * @brief Tri de tableau par bulles
 * @author Teissier Yannis
 * @version 1.0
 * @date 10/06/2021
 */

#include "header.h"

/**
 * Algo de bubble sort
 * @param array
 * @param size
 * @param type
 * @return
 */
float *bubblesort(float *array, int size, int type) {

    float *result;

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