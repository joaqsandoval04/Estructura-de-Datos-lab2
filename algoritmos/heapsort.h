#include <iostream>
using namespace std;

// Algoritmo Heap-Sort

/*
El algoritmo heap sort usa arboles de tipo heap, los cuales cumplen la propiedad
de que el padre es mayor que sus hijos, siendo este un arbol binario
*/

// Con este algoritmo se mueven los nodos para así cumplir la propiedad de un heap, el cual dice que un padre es siempre mayor que sus dos hijos
template <typename InIter>
void sift_down(InIter first, InIter last, int node_index)
{
    // Recibimos el primer y último puntero de nuestro arreglo, node_index será el índice del padre

    // Obtenemos la posición del padre en el arreglo, al puntero que apunta a nuestro primer valor le sumaremos el índice del padre (*array[0] + node_index)
    auto parent = first + node_index;
    const auto size = last - first;
    for (auto left_index = node_index * 2 + 1; left_index < size; left_index = left_index * 2 + 1)
    {
        // Por propiedades de un árbol binario, sabemos que para llevar el árbol a código el índice de los hijos está dado de la siguiente manera
        // left_index = parent_index * 2 + 1
        // right_index = parent_index * 2 + 2, o left_index + 1
        //

        auto left_child = first + left_index; // Apunta a la posición de left_child
        auto right_child = left_child + 1;    // Apunta a la posición de right_child

        // Verificamos si existe right_child, pues si fuera igual a last, entonces estaría apuntando fuera del arreglo
        if (right_child != last)
        {
            // Operador ternario, si *left_child > *right_child, entonces max_child = left_child, de lo contrario max_child = right_child
            auto max_child = (*left_child > *right_child) ? left_child : right_child;
            // Luego comparamos el que tenga el mayor valor con el padre, si el hijo resulta ser mayor que el padre, se intercambian
            if (*max_child > *parent)
            {
                std::iter_swap(max_child, parent); // Intercambio
                parent = max_child;                // Ahora el padre pasa a ser el hijo y viceversa
            }
        }
        else // Si no existe right_child (pues apunta afuera del arreglo), entonces comparamos sólo el hijo izquierdo
        {
            // Comparamos cual es el mayor, si esto se cumple intercambiamos padre e hijo
            if (*left_child > *parent)
            {
                std::iter_swap(left_child, parent); // Intercambio
                parent = left_child;                // Ahora el padre pasa a ser el hijo y viceversa
            }
        }
    }
}

// Heap_Make se usa para hacer heap a nuestro árbol binario, es decir, cada padre es mayor que sus dos hijos
template <typename InIter>
void heap_make(InIter first, InIter last)
{
    // Al ser la primera iteración, first y last tienen los mismos valores que en heap_sort
    // Por lo tanto size es una resta de punteros, sea nuestro vector de tamaño 5, last - first = 5
    const auto size = last - first;
    for (auto parent_index = size / 2 - 1; parent_index >= 0; --parent_index)
    {
        // Nuestro parent_index será el último padre de nuestro arbol binario, e irá decreciendo hasta alcanzar el índice 0
        // Es decir, recorreremos todos los padres del árbol

        // sift_down moverá los nodos si es necesario, esto se cumple cuando el padre es menor que uno de los hijos
        sift_down(first, last, parent_index);
    }
}

template <typename InIter>
void heap_sort(InIter first, InIter last)
{
    // First apunta a nuestro primer elemento, mientras que last apunta al final de nuestro arreglo, después del último elemento
    heap_make(first, last);
    while (first != last) // Se repetirá hasta que todo quede ordenado, first apunta al primer valor de nuestros valores y last irá decrementando hasta alcanzar este valor
    {
        --last;                      // Se le quita uno a last, así este ya estaría ordenado y se achica nuestro rango
        std::iter_swap(first, last); // Se intercambia el primer y último elemento
        sift_down(first, last, 0);
    }
}