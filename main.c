//
// Created by Yannis on 06/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/generateArray.h"

/* TODO
 * tri à bulle
 * tri par selection
 * tri par insertion
 * tri pas tas
 *
 * permettant un tri croissant ou décroissant d'un tableau de float
 *
 *
 * fichier de benchmark en fonction de différentes tailles de tableaux
 *
 * faire une sortie en fichier
 *
 *
 * Écrire le fichier README.md décrivant l’objet du projet, l’usage des commandes, les résultats attendus et les évolutions à venir.
 *
 *
 * - Les tableaux avant tri doivent être les mêmes pour chaque algorithme testé (cf notion de nombre pseudo aléatoire et de graine)
 * - Chaque algorithme devra être testé 3 fois avec des tableaux différents. Vous ne garderez que la valeur moyenne des trois tests.
 * - Vous devez trier des tableaux contenant des valeurs aléatoires comprises entre 0 et 10^6
 * - Vous devez réaliser les tests avec des tableaux contenants respectivement 100, 10^3, 10^4, 10^5, 10^6, 10^7 valeurs
 */
int main() {
    float *array, * bubblesortArray;

    array = generateArray(SIZE);

    bubblesortArray = calloc(SIZE, sizeof(float));
    memcpy(bubblesortArray, array, SIZE * sizeof(float));
    bubblesortArray = bubblesort(bubblesortArray, 0);

    for (int i = 0; i < SIZE; i++) {
        printf("%f\n", bubblesortArray[i]);
    }
    free(bubblesortArray);

    printf("\n\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%f\n", array[i]);
    }

    free(array);
    free(bubblesortArray);

    return EXIT_SUCCESS;
}