CC = gcc

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = ../bin

ENGINE_DIR = ../engine
ENGINE_INC = $(ENGINE_DIR)/include
ENGINE_LIB = $(ENGINE_DIR)/lib

GAME_SRC := $(shell find $(SRC_DIR) -name '*.c')
APP_SRC := $(shell find ../src -name '*.c')

GAME_OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(GAME_SRC))
APP_OBJ := $(patsubst ../src/%.c,$(BUILD_DIR)/app/%.o,$(APP_SRC))

OBJ := $(GAME_OBJ) $(APP_OBJ)

CFLAGS = \
    -Wall \
    -Wextra \
    -std=c11 \
    -I$(ENGINE_INC) \
    -Isrc \
    -I..

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $< -o $@

$(BUILD_DIR)/app/%.o: ../src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET)

.PHONY: all clean