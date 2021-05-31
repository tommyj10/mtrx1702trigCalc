CC=gcc
CFLAGS=-g -Wall -std=c99 -Iinclude
LIBS=
TARGET=trig

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
_DEPS = input.h helpOpener.h typeError.h trig.h
_OBJS = input.o helpOpener.o typeError.o trig.o main.o

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lm

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
