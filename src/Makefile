#Author: 			Dhruv Mohindru
#Dated: 			10/02/17
#Description:	Make for the game
CFLAGS=-W -Wall -ggdb `sdl-config --cflags`
LIBS=`sdl-config --libs` -lSDL_image
_OBJS= main.o resources.o tetromino.o
MUSIC_LIBS= -lvorbisfile -lvorbis -logg -lalut -lopenal
ODIR = ../build-linux
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

.PHONY: clean

$(ODIR)/freedomblock: $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $@ $(LIBS) $(MUSIC_LIBS)

$(ODIR)/main.o:	main.c gamedefs.h tetromino.h
	gcc $(CFLAGS) -c main.c -o $@

$(ODIR)/resources.o: resources.c resources.h
	gcc $(CFLAGS) -c resources.c -o $@

$(ODIR)/tetromino.o: tetromino.c tetromino.h gamedefs.h
	gcc $(CFLAGS) -c tetromino.c -o $@
	
clean:
	rm -f $(ODIR)/freedomblock $(OBJS)
