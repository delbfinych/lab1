#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "crypto.h"
#include "strings.h"

typedef enum {
	CommandLineMode = 4,
	StdinMode = 1 
} Mode;

void run(Mode mode, char** argv);


int main(int argc, char** argv) {
	
	Mode mode = argc;
	switch (mode) {
		case CommandLineMode: {
			run(CommandLineMode, argv);
			break;
		}
		case StdinMode: {
			run(StdinMode, argv);
			break;
		}
		default: {
			printf("error: Not enough or too many arguments\n");
			exit(2);
		}
	}
	return 0;
}

void run(Mode mode, char** argv) {
	char* method = mode == CommandLineMode ? copyString(argv[1]) 
                                           : input("Print method: caesar or xor: ", stdin);
	mutableStrip(method, '-');


	char* text = mode == CommandLineMode ? copyString(argv[2])
										 : input("Print text to decrypt: ", stdin);

	
	char* decrypted = NULL;

	if (strcmp(method, "xor") == 0) {
		char* password =  mode == CommandLineMode ? copyString(argv[3])
												  : input("Print password: ", stdin);
												  
		decrypted = xorDecrypt(text, password);
		printf("Result: %s\n", decrypted);
		free(password);
	}
	else if (strcmp(method, "caesar") == 0) {
		char* offset = mode == CommandLineMode ? copyString(argv[3]) 
											   : input("Print offset: ", stdin);

		if(isInteger(offset)) {
			decrypted = caesarDecrypt(text, atoi(offset));
		}
		else {
			printf("error: Offset must be an integer number, you have passed [%s]\n", offset);
			exit(1);
		}
		printf("Result: %s\n", decrypted);
		free(offset);
	}
	else {
		printf("error: Method [%s] does not exist\n", method);
		exit(1);
	}

	free(text);
	free(decrypted);
	free(method);
}

