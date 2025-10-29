#include "sorting-algorithms/include/exchange.h"
#include <algorithm>

template <typename T>
void exchange(std::vector<T>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;
    
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template void exchange<int>(std::vector<int>& arr);
template void exchange<double>(std::vector<double>& arr);
