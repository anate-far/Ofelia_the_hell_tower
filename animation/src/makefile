CC = gcc
EXEC = ../bin/prog
SRC = $(wildcard *.c)
HEADER = $(wildcard *.h)
OBJ = $(SRC:.c=.o)
CFLAGS = -W -Wall $(shell sdl2-config --cflags)
LDFLAGS = -export-dynamic $(shell sdl2-config --libs)
CC_SDL2_IMAGE = -lSDL2_image

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LDFLAGS) $(CC_SDL2_IMAGE)

$(OBJ) : $(SRC) $(HEADER)
	$(CC) -c $(SRC) $(CFLAGS) $(LDFLAGS)

deb : 
	$(CC) -g $(SRC) -o debug $(CFLAGS) $(LDFLAGS) $(CC_SDL2_IMAGE)


clean : 
	rm -rf *.o

mrproper : clean 
	rm -rf $(EXEC)
