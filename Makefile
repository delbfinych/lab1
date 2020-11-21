CFLAGS=-c -std=c99 -Wall -g

all: encoder decoder

encoder: encoder.o libstrings.a libcrypto.a
	gcc -o encoder encoder.o -L./ -lstrings -lcrypto

decoder: decoder.o libstrings.a libcrypto.a
	gcc -o decoder decoder.o -L./ -lstrings -lcrypto

libstrings.a: strings.o
	ar cr libstrings.a strings.o

libcrypto.a: crypto.o
	ar cr libcrypto.a crypto.o

strings.o: strings.c
	gcc $(CFLAGS) strings.c

encoder.o: encoder.c
	gcc $(CFLAGS) encoder.c

decoder.o: decoder.c
	gcc $(CFLAGS) decoder.c

crypto.o: crypto.c
	gcc $(CFLAGS) crypto.c

clean: 
	rm -rf *.o *.a decoder encoder
