#include <catch2/catch.hpp>
#include "selection_sort.h"

TEST_CASE("Selection Sort - Individual Assignment", "[selection]") {
    int arr[] = {17, 3, 0, 12, 6, 9, 19, 1};
    selectionSort(arr, 8);
    REQUIRE(arr[0] == 0);
    REQUIRE(arr[7] == 19);
}

TEST_CASE("Selection Sort - Empty Array", "[selection]") {
    int* arr = nullptr;
    selectionSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Selection Sort - Single Element", "[selection]") {
    int arr[] = {17};
    selectionSort(arr, 1);
    REQUIRE(arr[0] == 17);
}

TEST_CASE("Selection Sort - Reverse Order", "[selection]") {
    int arr[] = {5, 4, 3, 2, 1};
    selectionSort(arr, 5);
    REQUIRE(arr[0] == 1);
}
