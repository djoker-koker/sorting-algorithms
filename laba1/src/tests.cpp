#define CATCH_CONFIG_MAIN
#define _CRT_SECURE_NO_WARNINGS

#include "catch.hpp"
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "include/string_as_array.h"
#include "include/string_as_c_string.h"
#include "include/string_from_file.h"

using namespace std;

// Функция чтения результата из файла
static string read_file() {
    char res[256];
    FILE* in = fopen("output.txt", "r");
    if (in && fgets(res, 256, in) != NULL) {
        fclose(in);
        int len = (int)strlen(res);
        if (len > 0 && res[len - 1] == '\n') {
            res[len - 1] = '\0';
        }
    } else {
        res[0] = '\0';
    }
    return res;
}

// Функция записи тестовых данных в файл
static void write_file(const char str[]) {
    FILE* out = fopen("input.txt", "w");
    if (!out) return;
    fputs(str, out);
    fclose(out);
}

// ==================== ТЕСТЫ ====================

// Тесты для варианта 1 (массив символов)
TEST_CASE("Массив: точка заменяется на многоточие", "[array]") {
    char str[256] = "a.b";
    process_string_array(str);
    REQUIRE(strcmp(str, "a...b") == 0);
}

TEST_CASE("Массив: точка удаляется (согласная перед)", "[array]") {
    char str[256] = "b.c";
    process_string_array(str);
    REQUIRE(strcmp(str, "bc") == 0);
}

TEST_CASE("Массив: точка удаляется (нет согласной после)", "[array]") {
    char str[256] = "a. ";
    process_string_array(str);
    REQUIRE(strcmp(str, "a ") == 0);
}

TEST_CASE("Массив: точка в начале строки", "[array]") {
    char str[256] = ".abc";
    process_string_array(str);
    REQUIRE(strcmp(str, "abc") == 0);
}

TEST_CASE("Массив: точка в конце строки", "[array]") {
    char str[256] = "abc.";
    process_string_array(str);
    REQUIRE(strcmp(str, "abc") == 0);
}

TEST_CASE("Массив: несколько точек с разными условиями", "[array]") {
    char str[256] = "a.b c.d e.f";
    process_string_array(str);
    REQUIRE(strcmp(str, "a...b c...d e...f") == 0);
}

TEST_CASE("Массив: строка без точек", "[array]") {
    char str[256] = "Hello World";
    process_string_array(str);
    REQUIRE(strcmp(str, "Hello World") == 0);
}

// Тесты для варианта 2 (C-строка)
TEST_CASE("C-строка: точка заменяется на многоточие", "[cstring]") {
    char str[256] = "e.d";
    process_string_c_string(str);
    REQUIRE(strcmp(str, "e...d") == 0);
}

TEST_CASE("C-строка: точка удаляется", "[cstring]") {
    char str[256] = "x.y z. ";
    process_string_c_string(str);
    REQUIRE(strcmp(str, "xy z ") == 0);
}

TEST_CASE("C-строка: сложная строка", "[cstring]") {
    char str[256] = "test.a.b.c.d.e";
    process_string_c_string(str);
    REQUIRE(strcmp(str, "testabcde") == 0);
}

// Тесты для варианта 3 (файл)
TEST_CASE("Файл: простой случай", "[file]") {
    write_file("o.p");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "o...p");
}

TEST_CASE("Файл: несколько валидных точек", "[file]") {
    write_file("a.b i.c u.d");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "a...b i...c u...d");
}

TEST_CASE("Файл: строка без точек", "[file]") {
    write_file("Hello World");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "Hello World");
}
