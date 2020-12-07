#include <stdlib.h>
#include <string.h>

#include "strings.h"

char* xorEncrypt(const char* str, const char* password) {
	const size_t len = strlen(password);
	char* result = copyString(str);

	for (size_t i = 0; str[i] != '\0'; ++i) {
		result[i] ^= password[i % len];
	}
	return result;
}

char* xorDecrypt(const char* str, const char* password) {
	return xorEncrypt(str, password);
}

char* caesarEncrypt(const char* str, const int offset) {
	char* result = copyString(str);
	shiftString(result, offset, NULL);
	return result;
}

char* caesarDecrypt(const char* str, const int offset) {
	return caesarEncrypt(str, -offset);
}
