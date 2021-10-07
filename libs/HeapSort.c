//
// Created by Wolodia Zdetovetzky on 06/10/2021.
//

#include <stdlib.h>
#include "header.h"

float tmp;

void MiseEnTasCroissant(float array[], int n, int parent) {

    int largest = parent;
    int leftChildIndex = 2 * parent + 1;
    int rightChildIndex = 2 * parent + 2;

    // If leftChildIndex child is larger than root
    if (leftChildIndex < n && array[leftChildIndex] > array[largest]) {
        largest = leftChildIndex;
    }

    // If rightChildIndex child is larger than largest so far
    if (rightChildIndex < n && array[rightChildIndex] > array[largest]) {
        largest = rightChildIndex;
    }

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != parent) {

        tmp = array[parent];
        array[parent] = array[largest];
        array[largest] = tmp;
        // Recursively heapify the affected sub-tree
        MiseEnTasCroissant(array, n, largest);
    }
}

float * HeapSortAscending(float *array) {

    // on alloue en mémoire l'espace nécessaire
    float* result = malloc(SIZE * sizeof(float));
    // on copie le tableau initiale
    for (int i = 0; i < SIZE; ++i) {
        result[i] = array[i];
    }

    // Build heap (rearrange array)
    // Build max heap
    for (int i = SIZE/2 - 1; i >= 0; i--) {
        MiseEnTasCroissant(result, SIZE, i);
    }

    // Heap sort
    // One by one extract an element from heap

    for (int i = SIZE - 1; i >= 0; i--) {
        // Move current root to end
        tmp = result[0];
        result[0] = result[i];
        result[i] = tmp;

        // call max heapify on the reduced heap
        // Heapify root element to get highest element at root again
        MiseEnTasCroissant(result, i, 0);
    }

    return result; // on retourne le tableau trié
}

void MiseEnTasDeroissante(float arr[], int n, int i) {

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If right child is larger than smallest so far
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // Swap and continue heapifying if root is not smallest
    // If smallest is not root
    if (smallest != i) {

        tmp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = tmp;
        // Recursively heapify the affected sub-tree
        MiseEnTasCroissant(arr, n, smallest);
    }
}

float * HeapSortDescending(float *array) {

    // on alloue en mémoire l'espace nécessaire
    float* result = malloc(SIZE * sizeof(float));
    // on copie le tableau initiale
    for (int i = 0; i < SIZE; ++i) {
        result[i] = array[i];
    }

    // Build heap (rearrange array)
    // Build max heap
    for (int i = SIZE/2 - 1; i >= 0; i--) {
        MiseEnTasDeroissante(result, SIZE, i);
    }

    // Heap sort
    // One by one extract an element from heap

    for (int i = SIZE - 1; i >= 0; i--) {
        // Move current root to end
        tmp = result[0];
        result[0] = result[i];
        result[i] = tmp;

        // call max heapify on the reduced heap
        // Heapify root element to get highest element at root again
        MiseEnTasDeroissante(result, i, 0);
    }

    return result; // on retourne le tableau trié
}




