#include <iostream>
#include "algoritmos/heapsort.h"
#include "algoritmos/insertionsort.h"
#include "algoritmos/countingsort.h"
#include <vector>
using namespace std;

int main()
{
    std::vector<int> arr = {10, 9, 8, 7, 6, 12, 4, 1, 2, 3};

    std::cout << "hola";
    counting_sort(arr.begin(), arr.end());
    // insertion_sort(arr.begin(), arr.end());
    //     heap_sort(arr.begin(), arr.end());

    std::cout
        << "Sorted array con counting: ";
    for (int x : arr)
        std::cout << x << " ";
    std::cout << std::endl;

    // std::cout << "minimo: " << mina(arr.begin(), arr.end()) << endl;
    // std::cout << "maximo: " << maxa(arr.begin(), arr.end()) << endl;

    return 0;
}