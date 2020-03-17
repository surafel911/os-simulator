BINARY = bin/os-simulator
CFLAGS = -Wall -std=c99
INCLUDES = -I include/

ifeq ($(OS),Windows_NT)
 CC = gcc
 MACROS = -D _CRT_SECURE_NO_WARNINGS
 SOURCES = $(shell Get-ChildItem -Path src/ -File -Recurse)
 TESTS = $(shell Get-ChildItem -Path test/ -File -Recurse)
 MKDIR = New-Item -ItemType Directory -Force -Path bin/
else
 CC = clang
 MACROS = 
 SOURCES = $(shell find src/ -name "*.c")
 TESTS = $(shell find test/ -name "*.c")
 MKDIR = mkdir -p bin/
endif


all: debug

prerequisite:
	$(MKDIR)

debug: prerequisite
	$(CC) -g -Werror $(CFLAGS) $(INCLUDES) $(SOURCES) $(TESTS) -o $(BINARY)

release: prerequisite
	$(CC) -O3 $(CFLAGS) $(INCLUDES) $(SOURCES) $(TESTS) -o $(BINARY)
