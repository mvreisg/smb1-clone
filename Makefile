ENGINE_DIR = engine/skw
GAME_DIR = game/smb1-clone

.PHONY: all engine game clean rebuild

all: engine game

engine:
	$(MAKE) -C $(ENGINE_DIR)

game:
	$(MAKE) -C $(GAME_DIR)

clean:
	$(MAKE) -C $(ENGINE_DIR) clean
	$(MAKE) -C $(GAME_DIR) clean
	rm -rf bin

rebuild: clean all