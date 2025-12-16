#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/string_as_c_string.h"

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

// Основная функция обработки строки как C-строки
void process_string_c_string(char str[]) {
    char* read_ptr = str;
    char* write_ptr = str;
    
    while (*read_ptr != '\0') {
        if (*read_ptr == '.') {
            // Проверяем условия: гласная ПЕРЕД точкой и согласная ПОСЛЕ
            char* prev_char = (read_ptr != str) ? (read_ptr - 1) : NULL;
            char* next_char = (*(read_ptr + 1) != '\0') ? (read_ptr + 1) : NULL;
            
            if (prev_char && is_vowel(*prev_char) && 
                next_char && is_consonant(*next_char)) {
                // Заменяем точку на три точки
                *write_ptr++ = '.';
                *write_ptr++ = '.';
                *write_ptr++ = '.';
                read_ptr++;
            } else {
                // Удаляем точку - просто пропускаем её
                read_ptr++;
            }
        } else {
            // Копируем обычный символ
            *write_ptr++ = *read_ptr++;
        }
    }
    
    // Завершаем строку
    *write_ptr = '\0';
}
