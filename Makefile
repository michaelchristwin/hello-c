CC = gcc
CFLAGS = -I../include
SRC = src/main.c src/drchuck.c
OBJ = $(SRC:.c=.o)  # Object files for each source file
TARGET = bin/hello_c

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
