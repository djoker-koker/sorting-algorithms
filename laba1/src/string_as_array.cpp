#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/string_as_array.h"

// Проверка на гласную букву (латиница)
static int is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

// Проверка на согласную букву (латиница)
static int is_consonant(char c) {
    c = tolower(c);
    if (!isalpha(c)) return 0;
    return !is_vowel(c);
}

// Основная функция обработки строки как массива символов
void process_string_array(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '.') {
            // Проверяем условия: гласная ПЕРЕД точкой и согласная ПОСЛЕ
            int before_is_vowel = (i > 0 && is_vowel(str[i - 1]));
            int after_is_consonant = (str[i + 1] != '\0' && is_consonant(str[i + 1]));
            
            if (before_is_vowel && after_is_consonant) {
                // Заменяем точку на три точки
                // Сдвигаем правую часть строки на 2 позиции вправо
                int len = (int)strlen(&str[i + 1]);
                for (int j = len; j >= 0; j--) {
                    str[i + 3 + j] = str[i + 1 + j];
                }
                // Записываем три точки
                str[i] = '.';
                str[i + 1] = '.';
                str[i + 2] = '.';
                i += 3; // Пропускаем добавленные точки
            } else {
                // Удаляем точку
                int len = (int)strlen(&str[i + 1]);
                for (int j = 0; j <= len; j++) {
                    str[i + j] = str[i + 1 + j];
                }
                // i не увеличиваем, так как мы сдвинули строку влево
            }
        } else {
            i++; // Переходим к следующему символу
        }
    }
}
