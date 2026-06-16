CC = gcc

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = ../../bin

ENGINE_DIR = ../../engine/skw
ENGINE_INC = $(ENGINE_DIR)/include
ENGINE_LIB = $(ENGINE_DIR)/lib

TARGET = $(BIN_DIR)/smb1-clone.exe

# Includes
CFLAGS = \
	-Wall \
	-Wextra \
	-std=c11 \
	-I$(ENGINE_INC) \
	-Isrc \
	-I/C:/msys64/ucrt64/include/SDL2

# SDL sem SDL2main e sem mingw32
SDL_LIBS = -lSDL2 -lSDL2_image

# Link final FORÇADO em modo console + entrypoint correto
LDFLAGS = \
	-L$(ENGINE_LIB) \
	-lskw \
	$(SDL_LIBS) \
	-mconsole \
	-Wl,-subsystem,console \
	-Wl,-e,mainCRTStartup

SRC := $(shell find $(SRC_DIR) -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(TARGET)

.PHONY: all clean