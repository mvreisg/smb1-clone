CC = gcc
AR = ar

BUILD = build
LIB = lib
SRC_DIR = src
INC_DIR = include

CFLAGS = \
	-Wall \
	-Wextra \
	-std=c11 \
	-I$(INC_DIR) \
	$(shell pkg-config --cflags sdl2 SDL2_image)

SRC := $(shell find $(SRC_DIR) -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD)/%.o,$(SRC))

TARGET = $(LIB)/libengine.a

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(LIB)
	$(AR) rcs $@ $^

$(BUILD)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)
	rm -rf $(LIB)

.PHONY: all clean