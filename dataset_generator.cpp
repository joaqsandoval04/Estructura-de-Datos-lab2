#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

using namespace std;

void guardarArchivo(const vector<int>& datos, const string& filename) {
    ofstream file(filename, ios::binary);
    file.write(reinterpret_cast<const char*>(datos.data()),
               datos.size() * sizeof(int));
    cout << "Guardado: " << filename << " (" << datos.size() << " elementos)" << endl;
}

// Completamente desordenado
vector<int> generarRandom(int size) {
    vector<int> datos(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);

    for (int& x : datos) {
        x = dis(gen);
    }
    return datos;
}

// Ordenado ascendente: [1, 2, 3, 4, 5...]
vector<int> generarOrdenadoAsc(int size) {
    vector<int> datos(size);
    iota(datos.begin(), datos.end(), 1);
    return datos;
}

// Ordenado descendente: [5, 4, 3, 2, 1...]
vector<int> generarOrdenadoDesc(int size) {
    vector<int> datos(size);
    iota(datos.begin(), datos.end(), 1);
    reverse(datos.begin(), datos.end());
    return datos;
}

// Casi ordenado (90% ordenado, 10% intercambiado)
vector<int> generarParcialmenteOrdenado(int size) {
    vector<int> datos = generarOrdenadoAsc(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, size - 1);

    int intercambios = size / 10;
    for (int i = 0; i < intercambios; ++i) {
        swap(datos[dis(gen)], datos[dis(gen)]);
    }
    return datos;
}

// Muchos duplicados (solo 10 valores únicos)
vector<int> generarConDuplicados(int size) {
    vector<int> datos(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    for (int& x : datos) {
        x = dis(gen);
    }
    return datos;
}

// Forma V: baja hasta la mitad, luego sube
// Ejemplo: [8,7,6,5,1,2,3,4]
vector<int> generarV(int size) {
    vector<int> datos(size);
    int mitad = size / 2;

    for (int i = 0; i < mitad; ++i) {
        datos[i] = size - i;
    }

    for (int i = mitad; i < size; ++i) {
        datos[i] = i - mitad + 1;
    }
    return datos;
}

// Bloques ordenados pero mezclados entre sí
// Ejemplo: [4, 5, 6, 10, 11, 12, 7, 8, 9, 1, 2, 3]
vector<int> generarBloquesRandom(int size) {
    vector<int> datos;
    int bloques = 5;
    int tamano_bloque = size / bloques;

    vector<vector<int>> blqs(bloques);
    for (int i = 0; i < bloques; ++i) {
        int inicio = i * tamano_bloque + 1;
        int fin = (i == bloques - 1) ? size + 1 : (i + 1) * tamano_bloque + 1;

        for (int j = inicio; j < fin; ++j) {
            blqs[i].push_back(j);
        }
    }

    random_device rd;
    mt19937 gen(rd());
    shuffle(blqs.begin(), blqs.end(), gen);

    for (const auto& bloque : blqs) {
        datos.insert(datos.end(), bloque.begin(), bloque.end());
    }

    return datos;
}

int main() {
    vector<pair<int, string>> tamaños = {
        {65536, "256KB"},
        {131072, "512KB"},
        {262144, "1MB"},
        {2621440, "10MB"},
        {13107200, "50MB"},
        {26214400, "100MB"}
    };

    for (auto [size, label] : tamaños) {
        cout << "Creando datasets de " << size << " elementos..." << endl;

        guardarArchivo(generarRandom(size), "datasets/aleatorio_" + label + ".bin");
        guardarArchivo(generarOrdenadoAsc(size), "datasets/asc_" + label + ".bin");
        guardarArchivo(generarOrdenadoDesc(size), "datasets/desc_" + label + ".bin");
        guardarArchivo(generarParcialmenteOrdenado(size), "datasets/parcial_" + label + ".bin");
        guardarArchivo(generarConDuplicados(size), "datasets/duplicados_" + label + ".bin");
        guardarArchivo(generarV(size), "datasets/v_" + label + ".bin");
        guardarArchivo(generarBloquesRandom(size), "datasets/bloques_" + label + ".bin");
        cout << endl;
    }

    cout << "¡Todos los datasets creados!" << endl;
    return 0;
}