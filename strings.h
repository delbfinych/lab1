#ifndef STRINGS_H
#define STRINGS_H
#include <stdlib.h>
#include <stdbool.h>


/**
 * @brief Выделяет память для хранения строки длины size.
 * @param size размер строки вместе с нуль-терминатором.
 * @return Возвращает указатель на выделенную память.
*/
char* createString(const size_t size);


/**
 * @brief Создаёт новую строку и копирует в неё содержимое переданной строки.
 * @param str копируемая строка.
 * @return Возвращает указатель на новую строку.
*/
char* copyString(const char* str);


/**
 * @param sym символ для проверки.
 * @return Возвращает true, если sym является латинской буквой, иначе false.
*/
bool isAlpha(const char sym);


/** 
 * @param sym символ для проверки.
 * @return Возвращает true, если sym является латинской буквой в верхнем регистре, иначе false.
*/
bool isUpperAlpha(const char sym);


/**
 * @param sym символ для проверки.
 * @return Возвращает true, если sym является латинской буквой в нижнем регистре, иначе false.
*/
bool isLowerAlpha(const char sym);


/**
 * @param sym символ для проверки.
 * @return Возвращает true, если sym является десятичной цифрой, иначе false.
*/
bool isDigit(const char sym);


/**
 * @param sym символ для проверки.
 * @return Возвращает true, если sym является пробелом, иначе false.
*/
bool isSpace(const char sym);


/**
 * @param callback функция, которая будет вызвана для каждого символа строки.
 * Если функция возвращает true, то символ подходит под выборку, если false, то не подходит.
 * @param str строка для проверки.
 * @return Возвращает true, если str состоит из указанных в callback символов, иначе false.
*/
bool containsOnly(bool (*callback)(char sym), const char* str);


/**
 * @param str строка для проверки.
 * @return Возвращает true, если str пустая, иначе false.
*/
bool isEmpty(const char* str);


/**
 * @param str строка для проверки.
 * @return Возвращает true, если str является вещественным числом, иначе false.
*/
bool isNumber(const char* str);


/**
 * @param str строка для проверки.
 * @return Возвращает true, если str является целым числом, иначе false.
*/
bool isInteger(const char* str);


/**
 * @param str строка для проверки.
 * @return Возвращает true, если str является словом, состоящим из латинских букв, иначе false.
*/
bool isWord(const char* str);


/**
 * @brief Читает поток stdin до символа перевода строки. При этом перед считыванием выводит сообщение в консоль.
 * @param message сообщение для отображения в консоли.
 * @return Возвращает указатель на считанную строку.
*/
char* input(const char* message);


/**
 * @brief Сдвигает каждый символ str на offset.
 * @param str строка, которую нужно сдвинуть.
 * @param offset число, на которое нужно сдвинуть строку.
 * @param callback функция, которая будет вызвана для каждого символа строки.
 * Если функция возвращает true, то символ будет сдвинут, если false, то символ не будет сдвинут.
*/
void shiftString(char* str, const int offset, bool (*callback)(char sym));


/**
 * @brief Изменяет содержимое переданной строки. Переводит строку в верхний регистр.
 * @param str строка, которую нужно обработать.
*/
void mutableToUpper(char* str);


/**
 * @brief Изменяет содержимое переданной строки. Переводит строку в нижний регистр.
 * @param str строка, которую нужно обработать.
*/
void mutableToLower(char* str);


/**
 * @brief Изменяет содержимое переданной строки. Удаляет с концов строки указанные символы.
 * @param str строка, которую нужно обработать.
 * @param sym символ, который нужно удалить.
*/
void mutableStrip(char* str, char sym);


/**
 * @brief Изменяет содержимое переданной строки. Удаляет все пробелы в строке.
 * @param str строка, которую нужно обработать.
*/
void mutableRemoveSpaces(char* str);


/**
 * @brief Изменяет содержимое переданной строки. Удаляет все символы из строки, кроме десятичных цифр, латинских букв и пробелов.
 * @param str строка, которую нужно обработать.
*/
void mutableFilter(char* str);


/**
 * @brief Переводит строку в верхний регистр.
 * @param str строка, которую нужно обработать.
 * @return Возвращает новую строку, являющуюся результатом обработки str.
*/
char* immutableToUpper(const char* str);


/**
 * @brief Переводит строку в нижний регистр.
 * @param str строка, которую нужно обработать.
 * @return Возвращает новую строку, являющуюся результатом обработки str.
*/
char* immutableToLower(const char* str);


/**
 * @brief Удаляет с концов строки указанные символы.
 * @param str строка, которую нужно обработать.
 * @param sym символ, который нужно удалить.
 * @return Возвращает новую строку, являющуюся результатом обработки str.
*/
char* immutableStrip(const char* str, char sym);


/**
 * @brief Удаляет все символы из строки, кроме десятичных цифр, латинских букв и пробелов.
 * @param str строка, которую нужно обработать.
 * @return Возвращает новую строку, являющуюся результатом обработки str.
*/
char* immutableFilter(const char* str);


/**
 * @brief Удаляет все пробелы в строке.
 * @param str строка, которую нужно обработать.
 * @return Возвращает новую строку, являющуюся результатом обработки str.
*/
char* immutableRemoveSpaces(const char* str);

#endif