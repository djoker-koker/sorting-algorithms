#include "sorting-algorithms/include/optimized_bubble.h"
#include <algorithm>

template <typename T>
void optimized_bubble(std::vector<T>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;
    
    for (size_t i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // Если не было обменов - массив уже отсортирован
        if (!swapped) break;
    }
}

template void optimized_bubble<int>(std::vector<int>& arr);
template void optimized_bubble<double>(std::vector<double>& arr);
