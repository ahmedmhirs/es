# Variables to hold compiler, compiler flags, and linker flags
CC=gcc
CFLAGS=-g -I/usr/include/SDL
LDFLAGS=-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm

# Name of your executable
EXEC=prog

# Object files
OBJS=es.o main.o objet.o

# Rule to make everything
all: $(EXEC)

# Linking all the objects to make the executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Compiling source files to produce object files
main.o: main.c
	$(CC) -c main.c $(CFLAGS)

objet.o: objet.c
	$(CC) -c objet.c $(CFLAGS)

es.o: es.c
	$(CC) -c es.c $(CFLAGS)

# Clean up the compiled files and executable
clean:
	rm -f $(EXEC) $(OBJS)

