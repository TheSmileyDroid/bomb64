# find . -name "*.c" -o -name "*.h" | entr -rc sh -c "make && ./bin/mineirinho"
CC = clang

CFLAGS = -Wall -g -lglut -lGLU -lGL -lm -lSDL2

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

MAIN = $(BIN_DIR)/mineirinho

.PHONY: clean

all: $(MAIN)
	@echo Compilation has been completed successfully.

$(MAIN): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(MAIN) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)/* $(SRC_DIR)/*.o *~ $(MAIN)
