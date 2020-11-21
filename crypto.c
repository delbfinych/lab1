#include <stdlib.h>
#include <string.h>

#include "strings.h"

char* xor_encrypt(const char* str, const char* password) {
	const size_t len = strlen(password);
	char* result = copyString(str);

	for (size_t i = 0; str[i] != '\0'; ++i) {
		result[i] ^= password[i % len];
	}
	return result;
}

char* xor_decrypt(const char* str, const char* password) {
	return xor_encrypt(str, password);
}

char* caesar_encrypt(const char* str, const int offset) {
	char* result = copyString(str);
	shiftString(result, offset, NULL);
	return result;
}

char* caesar_decrypt(const char* str, const int offset) {
	return caesar_encrypt(str, -offset);
}
