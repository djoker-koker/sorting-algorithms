#include <catch2/catch.hpp>
#include "selection_sort.h"

TEST_CASE("Selection Sort - Individual Assignment", "[selection]") {
    int arr[] = {16, 9, 5, 18, 1, 11, 7, 3};
    selectionSort(arr, 8);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[7] == 18);
}

TEST_CASE("Selection Sort - Empty Array", "[selection]") {
    int* arr = nullptr;
    selectionSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Selection Sort - Single Element", "[selection]") {
    int arr[] = {42};
    selectionSort(arr, 1);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("Selection Sort - Reverse Order", "[selection]") {
    int arr[] = {5, 4, 3, 2, 1};
    selectionSort(arr, 5);
    REQUIRE(arr[0] == 1);
}
