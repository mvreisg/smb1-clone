SRC = src
BUILD = build
OBJS = objs
SDL_LIBS = $(shell pkg-config --libs sdl2)

app.exe: $(OBJS)/main.o
	gcc $(OBJS)/main.o -o $(BUILD)/app.exe $(SDL_LIBS)

$(OBJS)/main.o: $(SRC)/main.c
	gcc -c $(SRC)/main.c -o $(OBJS)/main.o