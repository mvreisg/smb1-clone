.DEFAULT_GOAL := all

CC = gcc

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

GAME_SRC := $(shell find $(SRC_DIR) -type f -name '*.c')

GAME_OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(GAME_SRC))
DEP := $(GAME_OBJ:.o=.d)

CPPFLAGS += -Iinclude -Isrc $(SDL_CFLAGS)
CFLAGS += -Wall -Wextra -std=c11 -g

.PHONY: all build clean rebuild

all: $(TARGET)

build: all

$(TARGET): $(GAME_OBJ)
	$(MKDIR_P) $(BIN_DIR)
	$(CC) $(GAME_OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM_RF) $(BUILD_DIR)
	$(RM_RF) $(BIN_DIR)

rebuild:
	$(MAKE) clean
	$(MAKE) all

-include $(DEP)
