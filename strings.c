#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "strings.h"

/**
 * @param sym символ для проверки.
 * @return Возвращает true, если sym является латинской буквой, иначе false.
*/

static bool isUpperAlpha(const char sym) {
	return sym >= 'A' && sym <= 'Z';

}

static bool isLowerAlpha(const char sym) {
	return sym >= 'a' && sym <= 'z';
}

static bool isDigit(const char sym) {
	return sym >= '0' && sym <= '9';
}

static bool isSpace(const char sym) {
	return sym == ' ';
}

static bool isAlpha(const char sym) {
	char* s = immutableToLower(&sym);
	bool isLower = isLowerAlpha(*s);
	free(s);
	return isLower;
}

char* createString(const size_t size) {
	return (char*)malloc(sizeof(char)*size);
}

char* copyString(const char* str) {
	const size_t len = strlen(str);
	char* result = createString(len + 1);
	strncpy(result, str, len);
	result[len] = '\0';
	return result;
}

void mutableToUpper(char* str) {
	if (isEmpty(str)) { 
		return; 
	}
	
	const int offset = 'A' - 'a';
	shiftString(str, offset, isLowerAlpha);
}

void mutableToLower(char* str) {
	if (isEmpty(str)) { 
		return; 
	}

	const int offset = 'a' - 'A';
	shiftString(str, offset, isUpperAlpha);
}

void shiftString(char* str, const int offset, bool (*callback)(char sym)) {
	while (str != NULL && *str != '\0') {
		if (callback == NULL || callback(*str)) {
			*str += offset;
		}
		++str;
	}
}

char* immutableToUpper(const char* str) {
	char* newStr = copyString(str);
	mutableToUpper(newStr);
	return newStr;
}

char* immutableToLower(const char* str) {
	char* newStr = copyString(str);
	mutableToLower(newStr);
	return newStr;
}

void mutableFilter(char* str) {
	if (isEmpty(str)) {
		 return;
	}

	char* temp = createString(strlen(str) + 1);

	size_t count = 0;
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (isAlpha(str[i]) || isDigit(str[i]) || isSpace(str[i])) {
			temp[count++] = str[i];
		}
	}
	
	strncpy(str, temp, count);
	str[count] = '\0';
	free(temp);
}

char* immutableFilter(const char* str) {
	char* result = copyString(str);
	mutableFilter(result);
	return result;
}


void mutableStrip(char* str, const char sym) {	
	if (isEmpty(str)) {
		return;
	}

	const size_t len = strlen(str);
	int leftIdx = 0;
	int rightIdx = len - 1;

	// Ищем первый символ в str, не равный sym справа
	for (size_t i = 0; i < len; ++i) {
		if (str[i] != sym) {
			leftIdx = i;
			break;
		}
	}

	// Ищем первый символ в str, не равный sym слева
	for (int i = len - 1; i >= 0; --i) {
		if (str[i] != sym) {
			rightIdx = i;
			break;
		}
	}

	// Если нечего удалять, то нет смысла дальше чёто делать
	if (leftIdx == 0 && rightIdx == len - 1) {
		return;
	}

	char* temp = copyString(str);

	const size_t count = rightIdx - leftIdx + 1; 

	strncpy(str, temp + leftIdx, count);
	str[count] = '\0';
	free(temp);

}

char* immutableStrip(const char* str, char sym) {
	char* result = copyString(str);
	mutableStrip(result, sym);
	return result;
}

void mutableRemoveSpaces(char* str) {
	if (isEmpty(str)) { 
		return; 
	}

	size_t count = 0;
	mutableStrip(str, ' ');

	char* temp = createString(strlen(str));
	
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (!isSpace(str[i])) {
			temp[count++] = str[i];
		}
	}

	strncpy(str, temp, count);
	str[count] = '\0';
	free(temp);
}

char* immutableRemoveSpaces(const char* str) {
	char* result = copyString(str);
	mutableRemoveSpaces(result);
	return result;
}

static char* _inputString() {
	const int chunk = 4;
	char* str = NULL;
	char buffer[chunk];
	size_t strLen = 0;
	size_t bufferLen = 0;

	do {
		if (fgets(buffer, chunk, stdin)) {
			bufferLen = strlen(buffer);
			str = (char*)realloc(str, sizeof(char)*(strLen + bufferLen + 1));
			strncpy(str + strLen, buffer, bufferLen);
			strLen += bufferLen;
		}
	} while (str[strlen(str) - 1] != '\n');
	
	char* s = createString(strLen);
	strncpy(s, str, strLen - 1);
	s[strLen - 1] = '\0';
	free(str);
	return s;
}

char* input(const char* message) {
	printf("%s", message);
	return _inputString();
}


bool isNumber(const char* str) {
	if (isEmpty(str)) { 
		return false; 
	}

	size_t digitsCount = 0;
	size_t pointsCount = 0;
	size_t specCharCount = 0;
	const size_t size = strlen(str);

	if (str[0] == '+' || str[0] == '-' ) {
		++specCharCount;
		++str;
	}
	else if (isDigit(str[0])) {
		++digitsCount; 
		++str;
	}
	else if (str[0] == '.' || str[0] == ',') {
		++pointsCount;
		++str;
	}

	while(*str != '\0') {
		if (pointsCount > 1) {
			return false; 
		}
		if (*str == '.' || *str == ',') {
			++pointsCount;
		}
		else if (isDigit(*str)) {
			++digitsCount;
		}
		++str;
	}
	
	return digitsCount >= 1 && digitsCount == size - pointsCount - specCharCount;
}

bool isInteger(const char* str) {
	if (!isNumber(str)) {
		return false;
	}
	if (*str == '-' || *str == '+') {
		++str;
	}
	return containsOnly(isDigit, str);
}

bool isWord(const char* str) {
	return containsOnly(isAlpha, str);
}

bool containsOnly(bool (*callback)(char sym), const char* str) {
	if (isEmpty(str)) { 
		return false; 
	}
	
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (!callback(str[i])) {
			return false;
		}
	}
	return true;
}


bool isEmpty(const char* str) {
	return str == NULL || str[0] == '\0';
}

int getIndexOfSubstr(const char* str, const char* searchStr, bool isSensitive) {
	if (isEmpty(str) || isEmpty(searchStr)) {
		return -1;
	}

	const char* tempStr = isSensitive ? str : immutableToLower(str);
	const char* tempSubstr = isSensitive ? searchStr : immutableToLower(searchStr);

	size_t count = 0;
	const size_t substrSize = strlen(searchStr); 
	int pos = -1;
	for (size_t i = 0; tempStr[i] != '\0'; ++i) {
		if (tempStr[i] == tempSubstr[count]) {
			count++;
		}
		// Попытка вернуться назад 
		else if (tempStr[i] != tempSubstr[count - 1]) {
			count = 0;
		}
		if (count == substrSize) {
			pos = i - count + 1;
			break;
		}
	}
	if (!isSensitive) {
		free(tempStr);
		free(tempSubstr);
	}
	return pos;
}

