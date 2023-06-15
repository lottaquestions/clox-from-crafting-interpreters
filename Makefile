CC = gcc
CFLAGS = -g

SRC_FILES = $(wildcard *.c)
OBJ_DIR = build
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
EXECUTABLE = clox

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(OBJ_FILES) $(EXECUTABLE)
