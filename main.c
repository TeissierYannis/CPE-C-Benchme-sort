/**
 * @file main.c
 * @brief
 * @author Yannis Tessier & Wolodia Zdetovetzky
 * @version 1.0
 * @date 10/06/2021
 */

#include <stdio.h>
#include <stdlib.h>

#include "libs/header.h"

/** TODO
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
void PrintFloatArray(const float *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%f\n", array[i]);
    }
}

int main() {
    float *array;
    float *InsertionCroissante, *InsertionDecroissante;
    float *TasCroissant, *TasDecroissant;
    float * bubblesortArray, * selectionsortArray;

    int nSize_Tab[7] = { 10, 10E3, 10E4, 10E5, 10E6, 10E7 };

    for(int i = 0; i < 1; i++ ) { // sizeof(nSize_Tab)

        printf("ORIGINAL : -------------\n");
        array = generateArray(nSize_Tab[i]);
        PrintFloatArray(array, nSize_Tab[i]);

        // ------------- TRI AR INSERTION
        // -------------------------------
        printf("TRI PAR INSERTION Croissante : -------------\n");
        InsertionCroissante = InsertionSortAscending(array, nSize_Tab[i]);
        PrintFloatArray(InsertionCroissante, nSize_Tab[i]);

        printf("TRI PAR INSERTION Decroissante : -------------\n");
        InsertionDecroissante = InsertionSortDescending(array, nSize_Tab[i]);
        PrintFloatArray(InsertionDecroissante, nSize_Tab[i]);

        // ------------- TRI PAR TAS
        // -------------------------------
        printf("TRI PAR TAS Croissant : -------------\n");
        TasCroissant = HeapSortAscending(array, nSize_Tab[i]);
        PrintFloatArray(TasCroissant, nSize_Tab[i]);


        printf("TRI PAR TAS Decroissant : -------------\n");
        TasDecroissant = HeapSortDescending(array, nSize_Tab[i]);
        PrintFloatArray(TasDecroissant, nSize_Tab[i]);

        // ------------- TRI PAR BULLE
        // -------------------------------
        printf("TRI PAR BULLE Croissant : -------------\n");
        bubblesortArray = bubblesort(array, nSize_Tab[i], 1);
        PrintFloatArray(bubblesortArray, nSize_Tab[i]);


        printf("TRI PAR BULLE Decroissant : -------------\n");
        bubblesortArray = bubblesort(array, nSize_Tab[i], 0);
        PrintFloatArray(bubblesortArray, nSize_Tab[i]);

        // ------------- TRI PAR SELECTION
        // -------------------------------
        printf("TRI PAR SELECTION Croissant : -------------\n");
        selectionsortArray = selectionsort(array, nSize_Tab[i], 1);
        PrintFloatArray(selectionsortArray, nSize_Tab[i]);


        printf("TRI PAR SELECTION Decroissant : -------------\n");
        selectionsortArray = selectionsort(array, nSize_Tab[i], 0);
        PrintFloatArray(selectionsortArray, nSize_Tab[i]);

        free(InsertionCroissante);
        free(InsertionDecroissante);
        free(TasCroissant);
        free(TasDecroissant);
        free(bubblesortArray);
        free(selectionsortArray);
    }

    return EXIT_SUCCESS;
}