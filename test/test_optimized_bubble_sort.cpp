#include <catch2/catch.hpp>
#include "optimized_bubble_sort.h"

TEST_CASE("Optimized Bubble Sort - Individual Assignment", "[optimized]") {
    int arr[] = {16, 9, 5, 18, 1, 11, 7, 3};
    optimizedBubbleSort(arr, 8);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[7] == 18);
}

TEST_CASE("Optimized Bubble Sort - Empty Array", "[optimized]") {
    int* arr = nullptr;
    optimizedBubbleSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Optimized Bubble Sort - Single Element", "[optimized]") {
    int arr[] = {42};
    optimizedBubbleSort(arr, 1);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("Optimized Bubble Sort - Double Type", "[optimized]") {
    double arr[] = {3.5, 1.2, 4.8};
    optimizedBubbleSort(arr, 3);
    REQUIRE(arr[0] == 1.2);
}
