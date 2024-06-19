# Variables
CC = clang
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS =

# Source and Object Files
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c) main.c
OBJ = $(SRC:.c=.o)
TARGET = main

# Default target
all: $(TARGET)

# Linking the target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning up
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean