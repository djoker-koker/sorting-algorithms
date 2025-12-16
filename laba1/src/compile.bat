@echo off
echo Компиляция лабораторной работы №1...
echo.

g++ -std=c++11 -I../include -o tests.exe src/tests.cpp src/string_as_array.cpp src/string_as_c_string.cpp src/string_from_file.cpp

if %errorlevel% equ 0 (
    echo Компиляция успешна!
    echo.
    echo Запуск тестов...
    echo ====================
    tests.exe
) else (
    echo Ошибка компиляции!
    pause
)
