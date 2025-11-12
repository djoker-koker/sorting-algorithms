#include <catch2/catch.hpp>
#include "bubble_sort.h"

TEST_CASE("Bubble Sort - Individual Assignment", "[bubble]") {
    int arr[] = {17, 3, 0, 12, 6, 9, 19, 1};
    bubbleSort(arr, 8);
    REQUIRE(arr[0] == 0);
    REQUIRE(arr[7] == 19);
}

TEST_CASE("Bubble Sort - Empty Array", "[bubble]") {
    int* arr = nullptr;
    bubbleSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Bubble Sort - Single Element", "[bubble]") {
    int arr[] = {17};
    bubbleSort(arr, 1);
    REQUIRE(arr[0] == 17);
}

TEST_CASE("Bubble Sort - Reverse Order", "[bubble]") {
    int arr[] = {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);
    REQUIRE(arr[0] == 1);
}
