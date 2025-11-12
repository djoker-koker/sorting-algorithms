#include <catch2/catch.hpp>
#include "insertion_sort.h"

TEST_CASE("Insertion Sort - Individual Assignment", "[insertion]") {
    int arr[] = {16, 9, 5, 18, 1, 11, 7, 3};
    insertionSort(arr, 8);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[7] == 18);
}

TEST_CASE("Insertion Sort - Empty Array", "[insertion]") {
    int* arr = nullptr;
    insertionSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Insertion Sort - Single Element", "[insertion]") {
    int arr[] = {42};
    insertionSort(arr, 1);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("Insertion Sort - Double Type", "[insertion]") {
    double arr[] = {3.5, 1.2, 4.8};
    insertionSort(arr, 3);
    REQUIRE(arr[0] == 1.2);
}
