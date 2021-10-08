/**
 * @file header.h
 * @brief déclaration des méthodes de tri
 * @author Wolodia Zdetovetzky
 * @version 1.0
 * @date 10/06/2021
 */

#ifndef BENCHME_HEADER_H
#define BENCHME_HEADER_H

#include <stddef.h>
#include <stdio.h>

/** Géneration d'un tableau avec des valeurs aléatoires de taille size
 * @param size : taille du tableau
 * @return revoit un tableau avec des valeurs entre 0 et 100
 */
float * generateArray (int size);

/** trie de manière croissante par insertion les valeurs du tableau passer en paramètre
 * @param array le tableau a trié
 * @return la copie du tableau originel trié
 */
float * InsertionSortAscending(const float *array, int size);

/** trie de manière décroissante par insertion les valeurs du tableau passer en paramètre
 * @param array le tableau a trié
 * @return la copie du tableau originel trié
 */
float * InsertionSortDescending(const float *array, int size);

/** trie de manière croissante par tas les valeurs du tableau passer en paramètre
 * @param array le tableau a trié
 * @return la copie du tableau originel trié
 */
float * HeapSortAscending(const float *array, int size);

/** trie de manière décroissante par tas les valeurs du tableau passer en paramètre
 * @param array le tableau a trié
 * @return la copie du tableau originel trié
 */
float * HeapSortDescending(const float *array, int size);

#endif //BENCHME_HEADER_H
