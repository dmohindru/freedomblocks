#ifndef RESOURCES_H
#define RESOURCES_H

#define GAME_BACKGROUND 	"../graphics/background.png" //Background file
#define GAME_DATA			"../graphics/data.png" //Graphics data file 

#define COLORKEY_RED    0 //Color key red component
#define COLORKEY_GREEN  0 //Color key green component
#define COLORKEY_BLUE   0 //Color key blue component

SDL_Surface *screen; //Main game screen
SDL_Surface *background; //Game background surface
SDL_Surface *gamedata; //Game graphics data surface
SDL_Surface *temp; //temp surface storing game data

void LoadGameGraphics();
void FreeGameGraphics();

#endif
