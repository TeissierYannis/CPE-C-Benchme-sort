//
// Created by Wolodia Zdetovetzky on 10/6/21.
//

#include <stdlib.h>
#include "header.h"

// On classe de manière croissante les valeurs
// du tableau passer en paramètre : float *array
float * InsertionSortAscending(float *array) {

    // on alloue en mémoire l'espace nécessaire
    float* result = malloc(SIZE * sizeof(float));
    // on copie le tableau initiale
    result = array;

    int nTabCount, nExplorer;
    float tmp;

    // on explore le tableau
    for (nTabCount=1 ; nTabCount <= SIZE - 1; nTabCount++) {

        // on inspect à partir d'ou nous sommes positionner dans le tableau
        nExplorer = nTabCount;

        // tant que nous ne sommes pas positionner sur la 1ère valeur
        // et que la valeur précédente est supérieur à l'actuelle :
        // on décale la valeur
        while (nExplorer > 0 && result[nExplorer - 1] > result[nExplorer]) {
            tmp = result[nExplorer];                   // on stock temporairement la valeur actuelle
            result[nExplorer] = result[nExplorer - 1]; // la valeur actuelle devient la valeur précédente
            result[nExplorer - 1] = tmp;               // la valeur précédente devient la valeur actuelle
            nExplorer--;                               // on décrémente vers la 1ère valeur
        }
    }
    return result; // on retourne le tableau trié
}

// On classe de manière décroissante les valeurs
// du tableau passer en paramètre : float *array
float * InsertionSortDescending(float *array) {

    // on alloue en mémoire l'espace nécessaire
    float* result = malloc(SIZE * sizeof(float));
    // on copie le tableau initiale
    result = array;

    int nTabCount, nExplorer;
    float tmp;

    // on explore le tableau
    for (nTabCount=1 ; nTabCount <= SIZE - 1; nTabCount++) {

        // on inspect à partir d'ou nous sommes positionner dans le tableau
        nExplorer = nTabCount;

        // tant que nous ne sommes pas positionner sur la 1ère valeur
        // et que la valeur précédente est inférieure à l'actuelle :
        // on décale la valeur
        while (nExplorer > 0 && result[nExplorer - 1] < result[nExplorer]) {
            tmp = result[nExplorer];                   // on stock temporairement la valeur actuelle
            result[nExplorer] = result[nExplorer - 1]; // la valeur actuelle devient la valeur précédente
            result[nExplorer - 1] = tmp;               // la valeur précédente devient la valeur actuelle
            nExplorer--;                               // on décrémente vers la 1ère valeur
        }
    }
    return result; // on retourne le tableau trié
}