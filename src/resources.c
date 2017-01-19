#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "resources.h"


void LoadGameGraphics()
{
  //Load game background
	temp = IMG_Load(GAME_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load game background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  
  background = SDL_DisplayFormat(temp);
	if (background == NULL)
  {
    printf("Unable to convert background bitmap: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
	}
  //free temp surface
  SDL_FreeSurface(temp);
	//Load game data
	temp = IMG_Load(GAME_DATA);
	if (temp == NULL)
  {
		printf("Unable to load game data file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  //set the color key
  SDL_SetColorKey(temp, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
		  (Uint16) SDL_MapRGB(temp->format, COLORKEY_RED, 
                  COLORKEY_GREEN, COLORKEY_BLUE));
  //convert game data bitmap for fast animation
  gamedata = SDL_DisplayFormat(temp);
  if (gamedata == NULL)
  {
    printf("Unable to convert the gamedata bitmap\n");
    exit(EXIT_FAILURE);
  }

  // Free temp surface
  SDL_FreeSurface(temp);
}

void FreeGameGraphics()
{
  SDL_FreeSurface(background);
  SDL_FreeSurface(gamedata);
}