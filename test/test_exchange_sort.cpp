#include <catch2/catch.hpp>
#include "exchange_sort.h"

TEST_CASE("Exchange Sort - Individual Assignment", "[exchange]") {
    int arr[] = {17, 3, 0, 12, 6, 9, 19, 1};
    exchangeSort(arr, 8);
    REQUIRE(arr[0] == 0);
    REQUIRE(arr[7] == 19);
}

TEST_CASE("Exchange Sort - Empty Array", "[exchange]") {
    int* arr = nullptr;
    exchangeSort(arr, 0);
    REQUIRE(true);
}

TEST_CASE("Exchange Sort - Single Element", "[exchange]") {
    int arr[] = {17};
    exchangeSort(arr, 1);
    REQUIRE(arr[0] == 17);
}

TEST_CASE("Exchange Sort - Already Sorted", "[exchange]") {
    int arr[] = {1, 2, 3, 4, 5};
    exchangeSort(arr, 5);
    REQUIRE(arr[0] == 1);
}
