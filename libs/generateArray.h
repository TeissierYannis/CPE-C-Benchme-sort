//
// Created by Yannis on 06/10/2021.
//

# include <stdlib.h>

#ifndef BENCHME_GENERATEARRAY_H
#define BENCHME_GENERATEARRAY_H

/**
 * Permet de generer un tableau de float aléatoire de taille size_t
 * @param size
 * @return
 */
float * generateArray (size_t size);

#endif //BENCHME_GENERATEARRAY_H
/**
 * Algo de bubble sort
 * @param array
 * @param size
 * @param type
 * @return
 */
float * bubblesort(float * array, int size,int type);

/**
 * Algo de selection sort
 * @param array Tableau à trier
 * @param size Taille du tableau
 * @param type 1 = Croissant / 0 = décroissant
 * @return
 */
float * selectionsort(float * array, int size,int type);