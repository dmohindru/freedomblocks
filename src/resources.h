#ifndef RESOURCES_H
#define RESOURCES_H

#define GAME_BACKGROUND 	"/home/dhruv/Programming/freedomblocks/graphics/background.png" //Play Background file
#define GAME_DATA			    "/home/dhruv/Programming/freedomblocks/graphics/data.png" //Graphics data file
#define WELCOME_BACKGROUND  "/home/dhruv/Programming/freedomblocks/graphics/welcome.png" //Welcome Background file
#define TUTORIAL_BACKGROUND "/home/dhruv/Programming/freedomblocks/graphics/tutorial.png" //Tutorial Background file
#define MESSAGES_BACKGROUND "/home/dhruv/Programming/freedomblocks/graphics/messages.png" //Messages data file
#define GAMEMUSIC           "/home/dhruv/Programming/freedomblocks/music/Tetris_theme.ogg" //Tetris music file

#define COLORKEY_RED        0 //Color key red component
#define COLORKEY_GREEN      0 //Color key green component
#define COLORKEY_BLUE       0 //Color key blue component

void LoadGameGraphics();
void FreeGameGraphics();
void InitMusic();
void PlayMusic();
void CloseMusic();
void StartMusic();
void StopMusic();

#endif
