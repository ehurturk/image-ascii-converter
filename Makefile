# Compiler options
CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
EXECUTABLE_NAME=out

# Folders
BIN=bin
OBJ=$(BIN)/obj

# Files
# TODO: Add more source files here
SOURCE_FILES=   ./main.c ./image.c ./filters/filters.c
INCLUDE_FILES=  ./*.h ./stb/*.h ./filters/*.h

EXECUTABLE_FILES = $(EXECUTABLE_NAME:%=$(BIN)/%)
OBJECT_FILES     = $(SOURCE_FILES:%.c=$(OBJ)/%.o)
HEADERS = $(wildcard  $(INCLUDE_FILES)) # TODO: Add more header directories here

build: $(EXECUTABLE_FILES)

clean:
	rm -r -f $(BIN)
	@

.PHONY: build clean

$(EXECUTABLE_FILES): $(OBJECT_FILES)
	@$(CC) $(LDFLAGS) -o $@ $^
	@
	@echo "Build successful!"

$(OBJECT_FILES): $(OBJ)/%.o: %.c $(HEADERS)
	@echo Compiling $<
	@
	@mkdir -p $(@D)
	@
	@$(CC) $(CFLAGS) -o $@ $<
	@


