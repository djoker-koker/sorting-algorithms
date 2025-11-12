#include <catch2/catch.hpp>
#include "insertion_sort.h"

TEST_CASE("Insertion Sort - Individual Assignment", "[insertion]") {
    int arr[] = {17, 3, 0, 12, 6, 9, 19, 1};
    insertionSort(arr, 8);
    REQUIRE(arr[0] == 0);
    REQUIRE(arr[7] == 19);
}

TEST_CASE("Insertion Sort - Empty Array", "[insertion]") {
    int* arr = nullptr;
    insertionSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Insertion Sort - Single Element", "[insertion]") {
    int arr[] = {17};
    insertionSort(arr, 1);
    REQUIRE(arr[0] == 17);
}

TEST_CASE("Insertion Sort - Double Type", "[insertion]") {
    double arr[] = {3.5, 1.2, 4.8};
    insertionSort(arr, 3);
    REQUIRE(arr[0] == 1.2);
}
