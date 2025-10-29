#include "sorting-algorithms/include/selection.h"
#include <algorithm>

template <typename T>
void selection(std::vector<T>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;
    
    for (size_t i = 0; i < n - 1; i++) {
        size_t min_index = i;
        
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

template void selection<int>(std::vector<int>& arr);
template void selection<double>(std::vector<double>& arr);
