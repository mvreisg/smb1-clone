TARGET = $(BIN_DIR)/smb1-clone

include ../makefiles/common.mk

SDL_CFLAGS = $(shell pkg-config --cflags sdl2 SDL2_image)
SDL_LIBS = $(shell pkg-config --libs sdl2 SDL2_image)

LDFLAGS = \
    -L$(ENGINE_LIB) \
    -lskw \
    $(SDL_LIBS)