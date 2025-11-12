#include "../include/insertion_sort.h"

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        
        // Сдвигаем элементы большие чем key на одну позицию вперед
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

template void insertionSort<int>(int arr[], int n);
template void insertionSort<double>(double arr[], int n);
