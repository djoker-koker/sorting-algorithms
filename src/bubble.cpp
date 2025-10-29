#include "sorting-algorithms/include/bubble.h"
#include <algorithm>

template <typename T>
void bubble_sort(std::vector<T>& arr) {
	size_t n = arr.size();
	if (n <= 1) return;
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template void bubble_sort<int>(std::vector<int>& arr);
template void bubble_sort<double>(std::vector<double>& arr);
