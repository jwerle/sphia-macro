SRC = $(wildcard sophia/db/*.c) test.c
CFLAGS = -I sophia/db -std=c99 -Wall
LDFLAGS = -lpthread -lsophia

all: clean test

clean:
	rm -f test-sphia-macro
	rm -rf ./test-db

test:
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o test-sphia-macro
	./test-sphia-macro

.PHONY: all clean test
