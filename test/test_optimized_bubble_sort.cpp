#include <catch2/catch.hpp>
#include "optimized_bubble_sort.h"

TEST_CASE("Optimized Bubble Sort - Individual Assignment", "[optimized]") {
    int arr[] = {17, 3, 0, 12, 6, 9, 19, 1};
    optimizedBubbleSort(arr, 8);
    REQUIRE(arr[0] == 0);
    REQUIRE(arr[7] == 19);
}

TEST_CASE("Optimized Bubble Sort - Empty Array", "[optimized]") {
    int* arr = nullptr;
    optimizedBubbleSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Optimized Bubble Sort - Single Element", "[optimized]") {
    int arr[] = {17};
    optimizedBubbleSort(arr, 1);
    REQUIRE(arr[0] == 17);
}

TEST_CASE("Optimized Bubble Sort - Double Type", "[optimized]") {
    double arr[] = {4.2, 1.5, 5.8};
    optimizedBubbleSort(arr, 3);
    REQUIRE(arr[0] == 1.5);
}
