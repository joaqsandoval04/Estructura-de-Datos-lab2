#include <iostream>
#include "heapsort.h"
#include <vector>
using namespace std;

int main()
{
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    heap_sort(arr.begin(), arr.end());

    std::cout << "Sorted array: ";
    for (int x : arr)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}