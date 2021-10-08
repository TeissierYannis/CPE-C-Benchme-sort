/**
 * @file main.c
 * @brief
 * @author Yannis Tessier & Wolodia Zdetovetzky
 * @version 1.0
 * @date 10/06/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/**
 * Benchmark de differents algorithmes de tri
 * @return
 */
int main() {
    float *array;
    float *InsertionCroissante, *InsertionDecroissante;
    float *TasCroissant, *TasDecroissant;
    float * bubblesortArray, * selectionsortArray;

    double time_spent = 0.0;

    clock_t totalbegin = clock();

    int nSize_Tab[7] = { 100, 10E3, 10E4, 10E5, 10E6, 10E7 };

    printf("===== Start =====\n");

    printf("===== Generating CSV File =====\n");

    FILE *fp;
    fp = fopen("../output/output.csv", "w");
    fprintf(fp, "%s", "taille tableau,insertion croissante,insertion decroissante,tas croissant,tas decroissant,bulle croissant,bulle decroissant,selection croissant,selection decroissant");

    for(int i = 0; i < sizeof(nSize_Tab); i++ ) { // sizeof(nSize_Tab)
        fprintf(fp, "\r\n%d,", nSize_Tab[i]);

        // printf("ORIGINAL : -------------\n");
        array = generateArray(nSize_Tab[i]);
        // PrintFloatArray(array, nSize_Tab[i]);

        // ------------- TRI PAR INSERTION
        // -------------------------------
        clock_t begin = clock();

        // printf("TRI PAR INSERTION Croissante : -------------\n");
        InsertionCroissante = InsertionSortAscending(array, nSize_Tab[i]);
        // PrintFloatArray(InsertionCroissante, nSize_Tab[i]);

        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(fp, "%f,", time_spent);
        // printf("Temps: %f seconds\n", time_spent);

        begin = clock();

        // printf("TRI PAR INSERTION Decroissante : -------------\n");
        InsertionDecroissante = InsertionSortDescending(array, nSize_Tab[i]);
        // PrintFloatArray(InsertionDecroissante, nSize_Tab[i]);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(fp, "%.10f,", time_spent);
        // printf("Temps: %f seconds\n", time_spent);


        // ------------- TRI PAR TAS
        // -------------------------------
        begin = clock();

        // printf("TRI PAR TAS Croissant : -------------\n");
        TasCroissant = HeapSortAscending(array, nSize_Tab[i]);
        // PrintFloatArray(TasCroissant, nSize_Tab[i]);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(fp, "%f,", time_spent);
        // printf("Temps: %f seconds\n", time_spent);

        begin = clock();

        // printf("TRI PAR TAS Decroissant : -------------\n");
        TasDecroissant = HeapSortDescending(array, nSize_Tab[i]);
        // PrintFloatArray(TasDecroissant, nSize_Tab[i]);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(fp, "%f,", time_spent);
        // printf("Temps: %f seconds\n", time_spent);

        // ------------- TRI PAR BULLE
        // -------------------------------

        begin = clock();

        // printf("TRI PAR BULLE Croissant : -------------\n");
        bubblesortArray = bubblesort(array, nSize_Tab[i], 1);
        // PrintFloatArray(bubblesortArray, nSize_Tab[i]);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(fp, "%f,", time_spent);
        // printf("Temps: %f seconds\n", time_spent);

        begin = clock();

        // printf("TRI PAR BULLE Decroissant : -------------\n");
        bubblesortArray = bubblesort(array, nSize_Tab[i], 0);
        // PrintFloatArray(bubblesortArray, nSize_Tab[i]);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(fp, "%f,", time_spent);
        // printf("Temps: %f seconds\n", time_spent);

        // ------------- TRI PAR SELECTION
        // -------------------------------

        begin = clock();

        // printf("TRI PAR SELECTION Croissant : -------------\n");
        selectionsortArray = selectionsort(array, nSize_Tab[i], 1);
        // PrintFloatArray(selectionsortArray, nSize_Tab[i]);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        fprintf(fp, "%f,", time_spent);
        // printf("Temps: %f seconds\n", time_spent);

         begin = clock();

         // printf("TRI PAR SELECTION Decroissant : -------------\n");
         selectionsortArray = selectionsort(array, nSize_Tab[i], 0);
         // PrintFloatArray(selectionsortArray, nSize_Tab[i]);

         end = clock();
         time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

         fprintf(fp, "%f", time_spent);
         // printf("Temps: %f seconds\n", time_spent);

        free(InsertionCroissante);
        free(InsertionDecroissante);
        free(TasCroissant);
        free(TasDecroissant);
        free(bubblesortArray);
    }
    fclose(fp);

    time_t totalend = clock();
    double totaltime = (double)(totalend - totalbegin) / CLOCKS_PER_SEC;
    printf("\nTemps total d'execution : %.20f", totaltime);

    return EXIT_SUCCESS;
}