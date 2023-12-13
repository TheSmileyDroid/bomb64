# ls -d ./src/**/* ./include/**/* | entr -rc sh -c "make run"
CC = clang++

CFLAGS := -Wall -g -lglut -lGLU -lGL -lm -lSDL2 -Iextern/glm

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
HEADERS := $(shell find $(INCLUDE_DIR) -name '*.h')

MAIN = $(BIN_DIR)/bomb64

.PHONY: clean


all: $(MAIN)
	@echo Compilation has been completed successfully.

run: $(MAIN)
	@echo Running...
	@./$(MAIN)

$(MAIN): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(MAIN) $(OBJS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM) $(BIN_DIR)/**/* $(BUILD_DIR)/**.o $(BUILD_DIR)/**/*.o *~ $(MAIN)
