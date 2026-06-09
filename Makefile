SRC = src
BUILD = build
OBJS = objs

SDL_CFLAGS = $(shell pkg-config --cflags sdl2)
SDL_LIBS = $(filter-out -mwindows,$(shell pkg-config --libs sdl2))

ifeq ($(OS),Windows_NT)
    EXE = .exe
else
    EXE =
endif

.PHONY: clean

$(BUILD)/app$(EXE): $(OBJS)/main.o
	gcc $(OBJS)/main.o -o $(BUILD)/app$(EXE) $(SDL_LIBS)

$(OBJS)/main.o: $(SRC)/main.c
	gcc $(SDL_CFLAGS) -c $(SRC)/main.c -o $(OBJS)/main.o

clean:
	rm -f $(OBJS)/*.o
	rm -f $(BUILD)/app$(EXE)