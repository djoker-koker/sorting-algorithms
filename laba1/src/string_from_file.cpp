#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/string_from_file.h"

// Проверка на гласную букву
static int is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

// Проверка на согласную букву
static int is_consonant(char c) {
    c = tolower(c);
    if (!isalpha(c)) return 0;
    return !is_vowel(c);
}

// Функция обработки строки (используем вариант с C-строкой)
static void process_string(char str[]) {
    char* read_ptr = str;
    char* write_ptr = str;
    
    while (*read_ptr != '\0') {
        if (*read_ptr == '.') {
            char* prev_char = (read_ptr != str) ? (read_ptr - 1) : NULL;
            char* next_char = (*(read_ptr + 1) != '\0') ? (read_ptr + 1) : NULL;
            
            if (prev_char && is_vowel(*prev_char) && 
                next_char && is_consonant(*next_char)) {
                *write_ptr++ = '.';
                *write_ptr++ = '.';
                *write_ptr++ = '.';
                read_ptr++;
            } else {
                read_ptr++;
            }
        } else {
            *write_ptr++ = *read_ptr++;
        }
    }
    *write_ptr = '\0';
}

// Основная функция обработки файла
void process_file_string(void) {
    // Открываем файл для чтения
    FILE* input = fopen("input.txt", "r");
    if (!input) {
        printf("Ошибка: не удалось открыть файл input.txt\n");
        return;
    }
    
    // Читаем строку из файла
    char str[256];
    if (fgets(str, sizeof(str), input) == NULL) {
        printf("Ошибка: не удалось прочитать строку из файла\n");
        fclose(input);
        return;
    }
    fclose(input);
    
    // Убираем символ новой строки, если он есть
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
    // Обрабатываем строку
    process_string(str);
    
    // Открываем файл для записи результата
    FILE* output = fopen("output.txt", "w");
    if (!output) {
        printf("Ошибка: не удалось создать файл output.txt\n");
        return;
    }
    
    // Записываем результат
    fputs(str, output);
    fclose(output);
}
