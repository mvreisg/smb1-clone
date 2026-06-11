SRC = src
BUILD = build
BIN = bin
SDL_CFLAGS = $(shell pkg-config --cflags sdl2 SDL2_image)
SDL_LIBS = $(filter-out -mwindows,$(shell pkg-config --libs sdl2 SDL2_image))

ifeq ($(OS),Windows_NT)
    EXE = .exe
else
    EXE =
endif

.PHONY: clean

$(BIN)/app$(EXE): $(BUILD)/main.o
	gcc $(BUILD)/main.o -o $(BIN)/app$(EXE) $(SDL_LIBS)

$(OBJS)/main.o: $(SRC)/main.c
	gcc $(SDL_CFLAGS) -c $(SRC)/main.c -o $(BUILD)/main.o

clean:
	rm -f $(OBJS)/*.o
	rm -f $(BUILD)/app$(EXE)