#pragma once
#include <vector>
#include <algorithm>

using namespace std;

// Función que parte el arreglo alrededor del pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Implementación de Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Obtener índice de partición
        int pi = partition(arr, low, high);

        // Ordenar recursivamente elementos antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}