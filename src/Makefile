CFLAGS=-W -Wall -ggdb `sdl-config --cflags`
# LIBS=-lm `sdl-config --libs` -ltcl -lopenal -lsndfile -lvorbisfile -lvorbis -logg -lalut
LIBS=`sdl-config --libs` -lSDL_image
OBJS= main.o resources.o
#CC=gcc

.PHONY: clean

freedomblock: $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o freedomblock $(LIBS)

main.o:	main.c gamedefs.h tetromino.h
	gcc $(CFLAGS) -c main.c

resources.o: resources.c resources.h
	gcc $(CFLAGS) -c resources.c
	
clean:
	rm -f freedomblock $(OBJS)
	rm -f *~
