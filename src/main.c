#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //think of removing it from here
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamedefs.h"
#include "resources.h"

static Sint32 seed = 0;

static void initrandom()
{
    seed = time(NULL);
}

static unsigned int getrandom()
{
    Sint32 p1 = 1103515245;
    Sint32 p2 = 12345;
    seed = (seed*p1+p2) % 2147483647;
    return (unsigned)seed/3;
}


int main(int argc, char **argv)
{
	SDL_Rect src, dest;
	SDL_Event event;
	int i, j, random, play = 1;
	//avoid compiler warnings
	argc++;
	argv++;
	initrandom();
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
		printf("Unable to initialise SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
    }
    atexit(SDL_Quit);

	// Attempt to set game screen
	screen = SDL_SetVideoMode(GAME_WIDTH, GAME_HEIGHT, 16, SDL_DOUBLEBUF);
	if (screen == NULL)
    {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	//load game graphics
	LoadGameGraphics();
	
	
	while(SDL_WaitEvent(&event) != 0 && play)
    {
		SDL_keysym keysym;
		switch (event.type)
		{
			case SDL_KEYDOWN:
				keysym = event.key.keysym;
				if(keysym.sym == SDLK_q)
					play = 0;
				break;
			case SDL_QUIT:
				play = 0;
		}
		src.w = background->w;
		src.h = background->h;
		src.x = 0;
		src.y = 0;
		dest = src;
		SDL_BlitSurface(background, &src, screen, &dest);
		//First test digits of scores and level
		for(i=0;i<4;i++)
		{
			random = getrandom() % 10;
			src.w = FONT_WIDTH;
			src.h = FONT_HEIGHT;
			src.x = FONT_STARTX + random * (FONT_WIDTH + FONT_SPACING);
			src.y = FONT_STARTY;
			dest.w = FONT_WIDTH;
			dest.h = FONT_HEIGHT;
			dest.x = SCORES_STARTX + i * (FONT_WIDTH + FONT_SPACING);
			dest.y = SCORES_STARTY;
			SDL_BlitSurface(gamedata, &src, screen, &dest);
		}
		for(i=0;i<2;i++)
		{
			random = getrandom() % 10;
			src.w = FONT_WIDTH;
			src.h = FONT_HEIGHT;
			src.x = FONT_STARTX + random * (FONT_WIDTH + FONT_SPACING);
			src.y = FONT_STARTY;
			dest.w = FONT_WIDTH;
			dest.h = FONT_HEIGHT;
			dest.x = LEVEL_STARTX + i * (FONT_WIDTH + FONT_SPACING);
			dest.y = LEVEL_STARTY;
			SDL_BlitSurface(gamedata, &src, screen, &dest);
		}
		for(i=0;i<PLAY_GRID_ROW;i++)
		{
			random = getrandom() % 2;
			if(random)
			{
				for(j=0;j<PLAY_GRID_COL;j++)
				{
					random = getrandom() % 4;
					src.w = SQUARE_WIDTH;
					src.h = SQUARE_WIDTH;
					src.x = SQUARE_STARTX + random * (SQUARE_WIDTH + SQUARE_SPACING);
					src.y = SQUARE_STARTY;
					dest.w = SQUARE_WIDTH;
					dest.h = SQUARE_WIDTH;
					dest.x = PLAY_GRID_STARTX + j * (SQUARE_WIDTH + TETROMINO_SPACING);
					dest.y = PLAY_GRID_STARTY + i * (SQUARE_WIDTH + TETROMINO_SPACING);
					SDL_BlitSurface(gamedata, &src, screen, &dest);
					
				}
			}
		}
		SDL_UpdateRect(screen, 0, 0, 0, 0);
	}
	FreeGameGraphics();
	
	return 0;
}
