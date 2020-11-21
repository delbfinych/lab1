#ifndef CRYPTO_H
#define CRYPTO_H


/**
 * @brief Шифрует строку с помощью ключа по алгоритму Цезаря.
 * @param str строка, которую нужно зашифровать.
 * @param offset ключ.
 * @return Возвращает зашифрованную строку.
*/
char* caesar_encrypt(const char* str, const int offset);


/**
 * @brief Дешифрует строку, зашифрованную с помощью ключа по алгоритму Цезаря.
 * @param str строка, которую нужно дешифровать.
 * @param offset ключ.
 * @return Возвращает дешифрованную строку.
*/
char* caesar_decrypt(const char* str, const int offset);


/**
 * @brief Шифрует строку с помощью пароля по алгоритму XOR.
 * @param str строка, которую нужно зашифровать.
 * @param password пароль.
 * @return Возвращает зашифрованную строку.
*/
char* xor_encrypt(const char* str, const char* password);


/**
 * @brief Дешифрует строку, зашифрованную с помощью пароля по алгоритму XOR.
 * @param str строка, которую нужно дешифровать.
 * @param password пароль.
 * @return Возвращает дешифрованную строку.
*/
char* xor_decrypt(const char* str, const char* password);

#endif
