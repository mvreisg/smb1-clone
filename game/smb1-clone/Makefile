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
	-I../.. \
	-I/C:/Users/marcus.vrgoncalves/msys64/ucrt64/include/SDL2

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

GAME_SRC := $(shell find $(SRC_DIR) -name '*.c')
APP_SRC := $(shell find ../../src -name '*.c')

GAME_OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(GAME_SRC))
APP_OBJ := $(patsubst ../../src/%.c,$(BUILD_DIR)/app/%.o,$(APP_SRC))

OBJ := $(GAME_OBJ) $(APP_OBJ)

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/app/%.o: ../../src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(TARGET)

.PHONY: all clean