# ls -d ./src/* ./include/* | entr -rc sh -c "make && ./build/bin/bomb64"
CC = clang++

CFLAGS := -Wall -g -lglut -lGLU -lGL -lm -lSDL2

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

MAIN = $(BIN_DIR)/bomb64

.PHONY: clean

all: $(MAIN)
	@echo Compilation has been completed successfully.

$(MAIN): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(MAIN) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM) $(BIN_DIR)/* $(SRC_DIR)/*.o *~ $(MAIN)
