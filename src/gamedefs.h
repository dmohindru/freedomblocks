#ifndef GAMEDEFS_H
#define GAMEDEFS_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface *screen; //Main game screen
SDL_Surface *background; //Game background surface
SDL_Surface *gamedata; //Game graphics data surface
SDL_Surface *welcome; //Welcome screen surface
SDL_Surface *tutorial; //Tutorial screen surface
SDL_Surface *messages; //Messages screen surface
SDL_Surface *temp; //temp surface storing game data

//define various games constants 
#define GAME_WIDTH				800 //Width of game background
#define GAME_HEIGHT				600 //Height of game background

#define PLAY_GRID_ROW			16 //Number of square logical rows in play grid
#define PLAY_GRID_COL			10 //Number of square logical cols in play grid

#define TETROMINO_GRID      	4 //size of grid to represent tetromino
#define TETROMINO_ROTATION  	4 //number of rotation in tetrominos
#define TETROMINO_NUM       	7 //number of tetrominos in game

#define LEFT					0 //moving tetromino left
#define RIGHT					1 //moving tetromino right

#define FALSE					0 //basic stuff
#define TRUE					1 //basic stuff

#define NEXT_LEVEL_LINES		10 //Number of lines for next level
#define NEXT_LEVEL_TIME			200 //Time in milliseconds for next level difficulty

#define GAME_OVER_STATE			1 //Game over state
#define GAME_WIN_STATE			2 //Game win state
#define GAME_END_NONE			0 //Game state not ended

//below are defs with maybe with conditional if for different platforms
#define LEFT_BUTTON				SDLK_LEFT //SDL left key for linux platform
#define RIGHT_BUTTON			SDLK_RIGHT //SDL right key for linux platform
#define UP_BUTTON				SDLK_UP //SDL up key for linux platform
#define DOWN_BUTTON				SDLK_DOWN //SDL down key for linux platform
#define A_BUTTON				SDLK_a //SDL A key for linux platform
#define B_BUTTON 				SDLK_b //SDL b key for linux platform
#define HOME_BUTTON				SDLK_q //SDL q key for linux platform

//Various game states
#define STATE_WELCOME			1 //Welcome State in game
#define STATE_PLAY				2 //Play State in game
#define STATE_TUTORIAL			3 //Tutorial State in game

//Graphics placement for Main game play screen
#define TETROMINO_SPACING		2 //Spacing between tetrominos squares

#define PLAY_GRID_WIDTH			318 //Width of play grid in px
#define PLAY_GRID_HEIGHT		510 //Height of play grid in px

#define PLAY_GRID_STARTX		300 //Start X for play grid
#define PLAY_GRID_STARTY		60 //Start Y of play grid

#define SCORES_STARTX			50 //Start X of scores
#define SCORES_STARTY			150 //Start Y of scores
#define SCORES_DIGITS			4 //Number of digits in scores

#define LEVEL_STARTX			85 //Start X of level
#define LEVEL_STARTY			450 //Start Y of level
#define LEVEL_DIGITS			2 //Number of digits in level

#define HISCORE_STARTX			360 //Start X for Hi Score message
#define HISCORE_STARTY			210 //Start Y for Hi Score message

#define GAME_STATE_STARTX		400 //Start X for Game State message
#define GAME_STATE_STARTY		250 //Start X for Game State message

#define PRESSA_STARTX			405 //Start X for Press A message
#define PRESSA_STARTY			290 //Start X for Press A message

//Graphics placement for Welcome screen
#define WSCR_PRESSA_STARTX		275 //Start X for Press A message on Welcome Screen
#define WSCR_PRESSA_STARTY		375 //Start Y for Press A message on Welcome Screen

#define WSCR_PRESSB_STARTX		275 //Start X for Press B message on Welcome Screen
#define WSCR_PRESSB_STARTY		550 //Start Y for Press B message on Welcome Screen

//Graphics placement for Tutorial screen
#define TSCR_PRESSA_STARTX		275 //Start X for Press A message on Tutorial Screen
#define TSCR_PRESSA_STARTY		530 //Start Y for Press A message on Tutorial Screen 

//Graphics placement in Data bitmap
#define FONT_STARTX				5 //Start X for fonts in game data bitmap
#define FONT_STARTY				50 //Start Y for fonts in game data bitmap
#define FONT_WIDTH				30 //Width of fonts used in games
#define FONT_HEIGHT				50 //Height of fonts used in games
#define FONT_SPACING			5 //Spacing between font

#define SQUARE_STARTX			5 //Start X for squares in game data bitmap
#define SQUARE_STARTY			10 //Start Y for squares in game data bitmap
#define SQUARE_SPACING			5 //Spacing between colored squares in data bitmap
#define NUM_SQUARE				4 //Number of squares in our data bitmap
#define SQUARE_WIDTH			30 //Width of tetromino square

//Graphics placement in message bitmap
#define MESS_PRESSA_BIG_STARTX 	5 //Start X for Press A Big message
#define MESS_PRESSA_BIG_STARTY 	5 //Start Y for Press A Big message
#define MESS_PRESSA_BIG_WIDTH	240 //Width of Press A Big message
#define MESS_PRESSA_BIG_HEIGHT	25 //Height of Press A Big message

#define MESS_PRESSB_STARTX 		5 //Start X for Press B message
#define MESS_PRESSB_STARTY 		35 //Start Y for Press B message
#define MESS_PRESSB_WIDTH		250 //Width of Press B message
#define MESS_PRESSB_HEIGHT		25 //Height of Press B message

#define MESS_QUIT_STARTX 		5 //Start X for Confirm Quit message
#define MESS_QUIT_STARTY 		65 //Start Y for Confirm Quit message
#define MESS_QUIT_WIDTH			170 //Width of Confirm Quit message
#define MESS_QUIT_HEIGHT		70 //Height of Confirm Quit message

#define MESS_YOUWIN_STARTX 		5 //Start X for You Win message
#define MESS_YOUWIN_STARTY 		140 //Start Y for You Win message
#define MESS_YOUWIN_WIDTH		110 //Width of You Win message
#define MESS_YOUWIN_HEIGHT		30 //Height of You Win message

#define MESS_GAMEOVER_STARTX	5 //Start X for Game Over message
#define MESS_GAMEOVER_STARTY	175 //Start Y for Game Over message
#define MESS_GAMEOVER_WIDTH		135 //Width of Game Over message
#define MESS_GAMEOVER_HEIGHT	30 //Height of Game Over message

#define MESS_PAUSED_STARTX		5 //Start X for Paused message
#define MESS_PAUSED_STARTY		210 //Start Y for Paused message
#define MESS_PAUSED_WIDTH		90 //Width of Paused message
#define MESS_PAUSED_HEIGHT		30 //Height of Paused message

#define MESS_HISCORE_STARTX		5 //Start X for Hi Score message
#define MESS_HISCORE_STARTY		245 //Start Y for Hi Score message
#define MESS_HISCORE_WIDTH		210 //Width of Hi Score message
#define MESS_HISCORE_HEIGHT		30 //Height of Hi Score message

#define MESS_PRESSA_STARTX		5 //Start X for Press A message
#define MESS_PRESSA_STARTY		280 //Start Y for Press A message
#define MESS_PRESSA_WIDTH		110 //Width of Press A message
#define MESS_PRESSA_HEIGHT		30 //Height of Press A message

#endif
