/*** @file HeapSort.c
 * @brief Tri de tableau par tas
 * @author Wolodia Zdetovetzky
 * @version 1.0
 * @date 10/06/2021
 */

#include <stdlib.h>
#include "header.h"

float tmp; // valeur tampon

/*** Tri de manière croissante un trio de valeurs (parent + 2 enfants)
 * @param array l'array a trier
 * @param n l'index de la plus grande valeur
 * @param parent l'index du parent
 */
void MiseEnTasCroissant(float array[], int n, int parent) {

    int largest = parent; // index de la valeur la plus grande, définie de base sur le parent
    int leftChildIndex = 2 * parent + 1; // index de l'enfant gauche du parent
    int rightChildIndex = 2 * parent + 2; // index de l'enfant droit du parent

    // si l'enfant de gauche est plus grand que la plus grande valeur
    if (leftChildIndex < n && array[leftChildIndex] > array[largest]) {
        largest = leftChildIndex;
    }

    // si l'enfant de droite est plus grand que la plus grande valeur
    if (rightChildIndex < n && array[rightChildIndex] > array[largest]) {
        largest = rightChildIndex;
    }

    // si le plus grand n'est pas le parent : retest jusqu'à ce qu'il le soit
    if (largest != parent) {

        // on inverse le parent et le plus grand
        tmp = array[parent];
        array[parent] = array[largest];
        array[largest] = tmp;

        // retest
        MiseEnTasCroissant(array, n, largest);
    }
}

/*** tri de manière croissante le tableau, par la méthode du tas
 * @param array le tableau à trier
 * @param size la taille du tableau
 * @return la copie du tableau originel trié
 */
float * HeapSortAscending(const float *array, int size) {

    // on alloue en mémoire l'espace nécessaire
    float* result = malloc(size * sizeof(float));
    // on copie le tableau initiale
    for (int i = 0; i < size; ++i) {
        result[i] = array[i];
    }

    // met en tas par trio
    for (int i = size/2 - 1; i >= 0; i--) {
        MiseEnTasCroissant(result, size, i);
    }
    // Tri en tas final
    for (int i = size - 1; i >= 0; i--) {

        // déplace le résultat du tri à la fin
        tmp = result[0];
        result[0] = result[i];
        result[i] = tmp;

        // retri en conséquence autour du nouveau parent
        MiseEnTasCroissant(result, i, 0);
    }
    return result; // on retourne le tableau trié
}

/*** Tri de manière décroissante un trio de valeurs (parent + 2 enfants)
 * @param array l'array à trier
 * @param n l'index de la plus petite valeur
 * @param parent l'index du parent
 */
void MiseEnTasDecroissante(float array[], int n, int parent)
{
    int smallest = parent; // index de la valeur la plus petite, définie de base sur le parent
    int leftChildIndex = 2 * parent + 1; // index de l'enfant gauche du parent
    int rightChildIndex = 2 * parent + 2; // index de l'enfant droit du parent

    // si l'enfant de gauche est plus petit que la plus grande valeur
    if (leftChildIndex < n && array[leftChildIndex] < array[smallest])
        smallest = leftChildIndex;

    // si l'enfant de droite est plus petit que la plus grande valeur
    if (rightChildIndex < n && array[rightChildIndex] < array[smallest])
        smallest = rightChildIndex;

    // si le plus petit n'est pas le parent : retest jusqu'à ce qu'il le soit
    if (smallest != parent) {

        // on inverse le parent et le plus petit
        tmp = array[parent];
        array[parent] = array[smallest];
        array[smallest] = tmp;

        // retest
        MiseEnTasDecroissante(array, n, smallest);
    }
}

/*** trie de manière décroissante le tableau, par la méthode du tas
 * @param array le tableau à trier
 * @param size la taille du tableau
 * @return la copie du tableau originel trié
 */
float * HeapSortDescending(const float *array, int size)
{
    // on alloue en mémoire l'espace nécessaire
    float* result = malloc(size * sizeof(float));
    // on copie le tableau initiale
    for (int i = 0; i < size; ++i) {
        result[i] = array[i];
    }

    // met en tas par trio
    for (int i = size / 2 - 1; i >= 0; i--)
        MiseEnTasDecroissante(result, size, i);

    // Tri en tas final
    for (int i = size - 1; i >= 0; i--) {

        // déplace le résultat du tri à la fin
        tmp = result[0];
        result[0] = result[i];
        result[i] = tmp;

        // retri en conséquence autour du nouveau parent
        MiseEnTasDecroissante(result, i, 0);
    }
    return result; // on retourne le tableau trié
}
