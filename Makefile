BINARY = bin/os-simulator
CFLAGS = -Wall -std=c99
INCLUDES = -I include/
SOURCES = src/*.c
TESTS = test/*.c

ifeq ($(OS),Windows_NT)
 CC = gcc
 MACROS = -D _CRT_SECURE_NO_WARNINGS
 MKDIR = $(shell New-Item -ItemType Directory -Force -Path bin/)
else
 CC = clang
 MACROS = 
 MKDIR = $(shell mkdir -p bin/)
endif


all: debug

prerequisite:
	$(MKDIR)

debug: prerequisite
	$(CC) -g -Werror $(MACROS) $(CFLAGS) $(INCLUDES) $(SOURCES) $(TESTS) -o $(BINARY)

release: prerequisite
	$(CC) -O3 $(MACROS) $(CFLAGS) $(INCLUDES) $(SOURCES) $(TESTS) -o $(BINARY)
