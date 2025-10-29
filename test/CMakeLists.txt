cmake_minimum_required(VERSION 3.10)
project(SortTests)

# Найди GoogleTest
find_package(GTest REQUIRED)

# Включи директории с исходным кодом
include_directories(../include)
include_directories(../src)

# Добавь исходные файлы сортировок
set(SORT_SOURCES
    ../src/bubble.cpp
    ../src/selection.cpp
    ../src/insertion.cpp
    ../src/exchange.cpp
    ../src/optimized_bubble.cpp
)

# Создай исполняемые файлы для тестов
add_executable(test_bubble test_bubble.cpp ${SORT_SOURCES})
add_executable(test_selection test_selection.cpp ${SORT_SOURCES})
add_executable(test_insertion test_insertion.cpp ${SORT_SOURCES})
add_executable(test_exchange test_exchange.cpp ${SORT_SOURCES})
add_executable(test_optimized_bubble test_optimized_bubble.cpp ${SORT_SOURCES})
add_executable(test_all test_all.cpp ${SORT_SOURCES})

# Линкуй с GoogleTest
target_link_libraries(test_bubble GTest::GTest GTest::Main)
target_link_libraries(test_selection GTest::GTest GTest::Main)
target_link_libraries(test_insertion GTest::GTest GTest::Main)
target_link_libraries(test_exchange GTest::GTest GTest::Main)
target_link_libraries(test_optimized_bubble GTest::GTest GTest::Main)
target_link_libraries(test_all GTest::GTest GTest::Main)
