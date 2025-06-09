#include <iostream>

// Función que devuelve el índice del valor mínimo de nuestro arreglo
template <typename InIter>
static int mina(InIter first, InIter last)
{
    // Verificamos que el arreglo no esté vacío
    if (first == last)
        return -1;

    int min_index = 0;
    int current_index = 0;
    InIter min_iter = first;

    // En el ciclo for buscamos el valor mínimo de nuestros valores, simplemente comparando con punteros
    for (InIter i = first; i != last; ++i, ++current_index)
    {
        if (*i < *min_iter)
        {
            min_iter = i;
            min_index = current_index;
        }
    }

    return min_index;
}

// Función que devuelve el índice del valor máximo de nuestro arreglo
template <typename InIter>
static int maxa(InIter first, InIter last)
{
    // Verificamos que el arreglo no esté vacío
    if (first == last)
        return -1;

    int max_index = 0;
    int current_index = 0;
    InIter max_iter = first;

    // En el ciclo for buscamos el valor máximo de nuestros valores, simplemente comparando con punteros
    for (InIter i = first; i != last; ++i, ++current_index)
    {
        if (*i > *max_iter)
        {
            max_iter = i;
            max_index = current_index;
        }
    }

    return max_index;
}

template <typename InIter>
void counting_sort(InIter first, InIter last)
{
    // Verificamos que el arreglo no esté vacío
    if (first == last)
        return;

    // Encontrar el mínimo y el máximo valor de nuestro arreglo
    int min_index = mina(first, last);
    int max_index = maxa(first, last);
    int min = *(first + min_index);
    int max = *(first + max_index);

    // Creamos un arreglo de conteo, aquí se sumarán a los índices correspondientes, se llenará de ceros
    int range = max - min + 1;
    int *counter = (int *)calloc(range, sizeof(int));

    // Contar cada valor y sumar los respectivos índices
    for (InIter i = first; i != last; ++i)
    {
        counter[*i - min]++;
    }

    // Reconstruir arreglo ordenado
    InIter it = first;
    for (int i = 0; i < range; ++i)
    {
        while (counter[i] > 0)
        {
            *it = i + min;
            ++it;
            --counter[i];
        }
    }

    free(counter); // liberar memoria asignada con calloc
}