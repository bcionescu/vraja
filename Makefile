CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
TARGET = build/vraja

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:src/%.c=build/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

