//
// Created by Yannis on 06/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/header.h"

/* TODO
 * tri à bulle
 * tri par selection
 * tri par insertion
 * tri pas tas
 *
 * permettant un tri croissant ou décroissant d'un tableau de float
 *
 * fichier de benchmark en fonction de différentes tailles de tableaux
 *
 * faire une sortie en fichier
 *
 * Écrire le fichier README.md décrivant l’objet du projet, l’usage des commandes, les résultats attendus et les évolutions à venir.
 *
 * - Les tableaux avant tri doivent être les mêmes pour chaque algorithme testé (cf notion de nombre pseudo aléatoire et de graine)
 * - Chaque algorithme devra être testé 3 fois avec des tableaux différents. Vous ne garderez que la valeur moyenne des trois tests.
 * - Vous devez trier des tableaux contenant des valeurs aléatoires comprises entre 0 et 10^6
 * - Vous devez réaliser les tests avec des tableaux contenants respectivement 100, 10^3, 10^4, 10^5, 10^6, 10^7 valeurs
 */
void PrintFloatArray(float *array) {
    for(int i = 0; i < SIZE; i++) {
        printf("%f\n", array[i]);
    }
}

int main() {
    float *array;
    float *InsertionCroissante, *InsertionDecroissante;
    float *TasCroissant, *TasDecroissant;

    array = generateArray(SIZE);
    printf("ORIGINAL : -------------\n");
    PrintFloatArray(array);

    // ------------- TRI PAR INSERTION
    // -------------------------------
    InsertionCroissante = calloc(SIZE, sizeof(float));
    memcpy(InsertionCroissante, array, SIZE * sizeof(float));
    InsertionCroissante = InsertionSortAscending(array);

    printf("TRI PAR INSERTION Croissante : -------------\n");
    PrintFloatArray(InsertionCroissante);

    InsertionDecroissante = calloc(SIZE, sizeof(float));
    memcpy(InsertionDecroissante, array, SIZE * sizeof(float));
    InsertionDecroissante = InsertionSortDescending(array);

    printf("TRI PAR INSERTION Decroissante : -------------\n");
    PrintFloatArray(InsertionDecroissante);

    // ------------- TRI PAR TAS
    // -------------------------------

    TasCroissant = calloc(SIZE, sizeof(float));
    memcpy(TasCroissant, array, SIZE * sizeof(float));
    TasCroissant = HeapSortAscending(array);

    printf("TRI PAR TAS Croissant : -------------\n");
    PrintFloatArray(TasCroissant);

    TasDecroissant = calloc(SIZE, sizeof(float));
    memcpy(TasDecroissant, array, SIZE * sizeof(float));
    TasDecroissant = HeapSortDescending(array);

    printf("TRI PAR TAS Decroissant : -------------\n");
    PrintFloatArray(TasDecroissant);

    printf("ORIGINAL : -------------\n");
    PrintFloatArray(array);

    return EXIT_SUCCESS;
}