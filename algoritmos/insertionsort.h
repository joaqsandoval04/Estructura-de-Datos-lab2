#include <iostream>
using namespace std;

// Algoritmo Insertion-Sort

/*
El algoritmo insertion sort es bastante simple, pues consta de comparar los valores con los que están a su izquierda,
si los valores a su izquierda son mayores, entonces este se mueve a su izquierda, donde quede bien posicionado.
*/

template <typename InIt>
void insertion_sort(InIt first, InIt last)
{
    // Empezamos nuestro ciclo for desde el segundo elemento de nuestro arreglo, hasta llegar al último
    // Usaremos como ejemplo el arreglo {3,2,1}
    for (auto it = first + 1; it != last; ++it)
    {
        // key será el valor almacenado en la posición donde apunta it, es decir 2
        auto key = *it;
        // j será igual al puntero it, que es la posición del valor con el que estamos trabajando, el cual es 2
        auto j = it;

        // Mientras j sea mayor que first (hablando de posiciones en el arreglo)
        // Y el valor que está antes de la posición donde apunta j sea mayor a el valor donde apunta el puntero it
        // En nuestro caso, *(j-1) > key es equivalente a decir 3 > 2
        while (j > first && *(j - 1) > key)
        {
            // Entonces actualizaremos los valores donde apunta j y el valor anterior a j
            *j = *(j - 1); // El valor con el que estamos trabajando será igual al valor anterior a él
                           // Es decir, ahora tenemos el arreglo {3,3,1}
            --j;           // el puntero j ahora apunta al primer elemento, por lo que termina el ciclo
        }

        *j = key; // Luego el valor donde apunta j será igual a a key, el cual es igual a 2
        // Así, luego de la primer iteración obtenemos {2,3,1};

        // Repetimos las veces que sea necesario
    }
}