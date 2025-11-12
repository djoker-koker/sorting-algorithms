#include "../include/exchange_sort.h"

template<typename T>
void exchangeSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template void exchangeSort<int>(int arr[], int n);
template void exchangeSort<double>(double arr[], int n);
