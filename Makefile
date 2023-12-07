# ls -d ./src/* ./include/* | entr -rc sh -c "make && ./build/bin/bomb64"
CC = clang++-11

CFLAGS := -Wall -g -lglut -lGLU -lGL -lm -lSDL2 -Iextern/glm

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

MAIN = $(BIN_DIR)/bomb64

.PHONY: clean


all: $(MAIN)
	@echo Compilation has been completed successfully.

$(MAIN): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(MAIN) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM) $(BIN_DIR)/* $(SRC_DIR)/**.o *~ $(MAIN)
