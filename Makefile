CC := gcc

.PHONY: all build

all: build

build:
	$(CC) grep.c -o grep
