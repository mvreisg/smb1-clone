TARGET := bin/smb1-clone.exe

MKDIR_P = mkdir -p
RM_RF = rm -rf

SDL_CFLAGS := $(shell pkg-config --cflags sdl2 SDL2_image)
SDL_LIBS := $(shell pkg-config --libs sdl2 SDL2_image)

LDFLAGS = \
    $(SDL_LIBS) \
    -mconsole

include makefiles/common.mk