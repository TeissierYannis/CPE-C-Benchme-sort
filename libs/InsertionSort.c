//
// Created by student on 10/6/21.
//

#include <stdio.h>
#include "header.h"


void InsertionSort(float *tab) {

    int i, j;
    float tmp;

    for (i=1 ; i <= SIZE-1; i++) {
        j = i;

        while (j > 0 && tab[j-1] > tab[j]) {
            tmp = tab[j];
            tab[j] = tab[j-1];
            tab[j-1] = tmp;
            j--;
        }
    }
}