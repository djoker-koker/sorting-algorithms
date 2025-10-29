#include "sorting-algorithms/include/insertion.h"
#include <algorithm>

template <typename T>
void insertion(std::vector<T>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;
    
    for (size_t i = 1; i < n; i++) {
        T key = arr[i];
        size_t j = i;
        
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

template void insertion<int>(std::vector<int>& arr);
template void insertion<double>(std::vector<double>& arr);
