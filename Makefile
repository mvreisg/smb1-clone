ifeq ($(OS),Windows_NT)
    PLATFORM := windows
else
    PLATFORM := linux
endif

include makefiles/$(PLATFORM).mk