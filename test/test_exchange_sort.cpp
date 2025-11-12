#include <catch2/catch.hpp>
#include "exchange_sort.h"

TEST_CASE("Exchange Sort - Individual Assignment", "[exchange]") {
    int arr[] = {16, 9, 5, 18, 1, 11, 7, 3};
    exchangeSort(arr, 8);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[7] == 18);
}

TEST_CASE("Exchange Sort - Empty Array", "[exchange]") {
    int* arr = nullptr;
    exchangeSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Exchange Sort - Single Element", "[exchange]") {
    int arr[] = {42};
    exchangeSort(arr, 1);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("Exchange Sort - Already Sorted", "[exchange]") {
    int arr[] = {1, 2, 3, 4, 5};
    exchangeSort(arr, 5);
    REQUIRE(arr[0] == 1);
}
