#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "resources.h"
#include "gamedefs.h"


void LoadGameGraphics()
{
  //Load game background
	temp = IMG_Load(GAME_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load game play background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  
  background = SDL_DisplayFormat(temp);
	if (background == NULL)
  {
    printf("Unable to convert game play background bitmap: %s\n", SDL_GetError());
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
  //Load Welcome screen
  temp = IMG_Load(WELCOME_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load Welcome background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  
  welcome = SDL_DisplayFormat(temp);
	if (welcome == NULL)
  {
    printf("Unable to convert welcome background bitmap: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
	}
  //free temp surface
  SDL_FreeSurface(temp);
  
  //Load Tutorial Background
  temp = IMG_Load(TUTORIAL_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load Tutorial background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  
  tutorial = SDL_DisplayFormat(temp);
	if (tutorial == NULL)
  {
    printf("Unable to convert tutorial background bitmap: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
	}
  //free temp surface
  SDL_FreeSurface(temp);
  
  //Load Messages bitmap
  temp = IMG_Load(MESSAGES_BACKGROUND);
	if (temp == NULL)
  {
		printf("Unable to load Message background file: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
  //set the color key
  SDL_SetColorKey(temp, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
		  (Uint16) SDL_MapRGB(temp->format, COLORKEY_RED, 
                  COLORKEY_GREEN, COLORKEY_BLUE));
  messages = SDL_DisplayFormat(temp);
	if (messages == NULL)
  {
    printf("Unable to convert messages background bitmap: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
	}
  //free temp surface
  SDL_FreeSurface(temp);
}

void FreeGameGraphics()
{
  SDL_FreeSurface(background);
  SDL_FreeSurface(gamedata);
  SDL_FreeSurface(welcome);
  SDL_FreeSurface(tutorial);
  SDL_FreeSurface(messages);
}
