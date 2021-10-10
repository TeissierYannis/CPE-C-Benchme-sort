/**
 * @file main.c
 * @brief test des méthodes de tris
 * @author Yannis Tessier & Wolodia Zdetovetzky
 * @version 1.0
 * @date 10/06/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

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

/**
 * Benchmark de differents algorithmes de tri
 * @return
 */
int main(int argc, char * argv[]) {

    if (argc != 2) {
        printf("Output file argument missing");
        return EXIT_FAILURE;
    }

    // défini nos paramètres sur la france
    setlocale(LC_ALL, "French_Canada.1252");

    // variables des tableaux a trier / triés
    float *array;
    float *InsertionCroissante, *InsertionDecroissante;
    float *TasCroissant, *TasDecroissant;
    float * bubblesortArray, * selectionsortArray;

    // variables de calcul de temps d'éxécution
    double time_spent = 0.0;
    clock_t begin, end;

    // le tableau de tailles de tableaux a utiliser
    int nSize_Tab[6] = { 1E2, 1E3, 1E4, 1E5, 1E6, 1E7 };

    // le tableau des temps moyens d'exécutions
    double AverageTime[4][8];

    // création du document csv
    // pour référencer les temps d'éxécution
    FILE *fp;
    fp = fopen(argv[1], "w");

    // création des titre de colonne
    fprintf(fp, "%s", "taille tableau;insertion croissante;insertion decroissante;tas croissant;tas decroissant;bulle croissant;bulle decroissant;selection croissant;selection decroissant;\n");

    // début du chronomètre global
    clock_t totalbegin = clock();

    // La boucle de test de tri
    for(int i = 0; i < 6; i++ ) {

        // la boucle de test pour 3 tableaux aléatoires différents
        for (int j = 0; j < 3; j++) {
            // le tableau aléatoire
            array = generateArray(nSize_Tab[i]);

            // ------------- TRI PAR INSERTION
            // -------------------------------
            // croissant ---
            begin = clock();
            InsertionCroissante = InsertionSortAscending(array, nSize_Tab[i]);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            AverageTime[j][0] = time_spent;

            // décroissant ---
            begin = clock();
            InsertionDecroissante = InsertionSortDescending(array, nSize_Tab[i]);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            AverageTime[j][1] = time_spent;

            // ------------- TRI PAR TAS
            // -------------------------------
            // croissant ---
            begin = clock();
            TasCroissant = HeapSortAscending(array, nSize_Tab[i]);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            AverageTime[j][2] = time_spent;

            // décroissant ---
            begin = clock();
            TasDecroissant = HeapSortDescending(array, nSize_Tab[i]);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            AverageTime[j][3] = time_spent;

            // ------------- TRI PAR BULLE
            // -------------------------------
            // croissant ---
            begin = clock();
            bubblesortArray = bubblesort(array, nSize_Tab[i], 1);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            AverageTime[j][4] = time_spent;

            // décroissant ---
            begin = clock();
            bubblesortArray = bubblesort(array, nSize_Tab[i], 0);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            AverageTime[j][5] = time_spent;

            // ------------- TRI PAR SELECTION
            // -------------------------------
            // croissant ---
            begin = clock();
            selectionsortArray = selectionsort(array, nSize_Tab[i], 1);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            AverageTime[j][6] = time_spent;

            // décroissant ---
            begin = clock();
            selectionsortArray = selectionsort(array, nSize_Tab[i], 0);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            AverageTime[j][7] = time_spent;
        }
        // ajout de la dimension du tableau
        fprintf(fp, "%d;", nSize_Tab[i]);

        // calcul de la moyenne des 3 temps d'exécution pour les 3 tableaux aléatoires différent et ajout dans le .csv
        for (int y = 0; y < 8; y++) {
            AverageTime[3][y] = (AverageTime[0][y] + AverageTime[1][y] + AverageTime[2][y]) / 3;
            fprintf(fp, "%f;", AverageTime[3][y]);
        }
        fprintf(fp, "\n");
    }

    // calcul du temps total et ajout dans le .csv
    time_t totalend = clock();
    double totaltime = (double)(totalend - totalbegin) / CLOCKS_PER_SEC;
    fprintf(fp, "\nTemps total d'execution :; %.20f", totaltime);

    // fermeture du document
    fclose(fp);

    // renvoie 0 si pas d'erreurs
    return EXIT_SUCCESS;
}
