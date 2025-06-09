#pragma once
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Implementación del Block Sort
void blockSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Calcular tamaño de bloque óptimo (aproximadamente sqrt(n))
    int blockSize = max(1, static_cast<int>(sqrt(arr.size())));

    vector<vector<int>> blocks;

    // Dividir el array en bloques de tamaño óptimo
    for (size_t i = 0; i < arr.size(); i += blockSize) {
        vector<int> block;

        for (size_t j = i; j < i + blockSize && j < arr.size(); j++) {
            block.push_back(arr[j]);
        }

        // Ordenar cada bloque individualmente
        sort(block.begin(), block.end());
        blocks.push_back(block);
    }

    // Fusionar los bloques ordenados en un único array ordenado
    vector<int> result;
    result.reserve(arr.size());

    while (!blocks.empty()) {
        // Encontrar el bloque con el elemento más pequeño en su frente
        int minIdx = 0;
        for (size_t i = 1; i < blocks.size(); i++) {
            if (blocks[i][0] < blocks[minIdx][0]) {
                minIdx = i;
            }
        }

        // Tomar el elemento más pequeño y agregarlo al resultado
        result.push_back(blocks[minIdx][0]);
        blocks[minIdx].erase(blocks[minIdx].begin());

        // Si el bloque está vacío, eliminarlo
        if (blocks[minIdx].empty()) {
            blocks.erase(blocks.begin() + minIdx);
        }
    }

    // Copiar el resultado de vuelta al array original
    arr = move(result);
}