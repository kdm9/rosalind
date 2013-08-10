# More structured C project, with src, include and build dirs
CC=gcc
CFLAGS=-g -O3 -I ./include -lz

SRCS := $(wildcard ./src/*.c)
BIN := $(patsubst ./src/%.c,./bin/%, $(SRCS))

all: $(BIN)

./bin/%: ./src/%.c
	$(CC) $(CFLAGS) $^ -o $@
