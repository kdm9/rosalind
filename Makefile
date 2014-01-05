# More structured C project, with src, include and build dirs
CC=gcc
CFLAGS=-g -O3 -I ./include -I ./kmlib/include -lz -lgmp -lkm -L./kmlib/lib -Wl,-rpath,./kmlib/lib


SRCS := $(wildcard ./src/*.c)
BIN := $(patsubst ./src/%.c,./bin/%, $(SRCS))

.PHONY: kmlib

all: kmlib $(BIN)

kmlib:
	cd ./kmlib && cmake . >/dev/null && make >/dev/null

./bin/%: ./src/%.c
	$(CC) $(CFLAGS) $^  -o $@

clean:
	rm -rv ./bin/*
