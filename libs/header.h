//
// Created by Wolodia Zdetovetzky on 10/6/21.
//

#ifndef BENCHME_HEADER_H
#define BENCHME_HEADER_H

#include <stddef.h>

#define SIZE 10

// génération d'un tableau avec des valeurs aléatoires entre 0 et size
float * generateArray (size_t size);

// trie de manière croissante les valeurs du tableau passer en paramètre
// et renvoie un tableau trié
float * InsertionSortAscending(float *array);

// trie de manière décroissante les valeurs du tableau passer en paramètre
// et renvoie un tableau trié
float * InsertionSortDescending(float *array);

// trie par tas de manière croissante les valeurs du tableau passer en paramètre
// et renvoie un tableau trié
float * HeapSortAscending(float *array);

// trie par tas de manière décroissante les valeurs du tableau passer en paramètre
// et renvoie un tableau trié
float * HeapSortDescending(float *array);

#endif //BENCHME_HEADER_H
