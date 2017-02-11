/* Author: 			Dhruv Mohindru
 * Dated: 			10/02/17
 * Description: Main header file containing all constants regarding
 * game. If we are porting to new system or new graphics layout is 
 * being prepared, we just have to modify this file only.
 * */
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
#define GAME_WIDTH							640 //Width of game background
#define GAME_HEIGHT							480 //Height of game background

#define PLAY_GRID_ROW						28 //Number of square logical rows in play grid
#define PLAY_GRID_COL						12 //Number of square logical cols in play grid

#define TETROMINO_GRID      		4 //size of grid to represent tetromino
#define TETROMINO_ROTATION  		4 //number of rotation in tetrominos
#define TETROMINO_NUM       		7 //number of tetrominos in game

#define LEFT										0 //moving tetromino left
#define RIGHT										1	//moving tetromino right

#define FALSE										0 //basic stuff
#define TRUE										1 //basic stuff

#define NEXT_LEVEL_LINES				10 //Number of lines for next level
#define NEXT_LEVEL_TIME					150 //Time in milliseconds for next level difficulty
#define DELAY_START							1500 //Initial Delay for block to fall
#define LANDED_DELAY						300 //delay before to check for landed position
#define SCORES_PER_LINE					10 //Scores per line
#define SCORES_BONUS						5	//Bonus scores for recussive line completion

#define MAX_LEVELS							10 //Max Levels to call for win
#define LEVEL_LINES							10 //Lines to clear a level

#define GAME_OVER_STATE					1 //Game over state
#define GAME_WIN_STATE					2 //Game win state

#define HI_SCORE_FILE					"hiscore.txt" //Name of file to store hi scores

#define NEXT_TETROMINO_ROW			2 //Next tetromino row for drawing
#define NEXT_TETROMINO_COL			-8 //Next tetromino col for drawing
#define NEW_TETROMINO_COL				4 //Column for new Tetromino

//below are defs with maybe with conditional if for different platforms
#define LEFT_BUTTON							SDLK_LEFT //SDL left key for linux platform
#define RIGHT_BUTTON						SDLK_RIGHT //SDL right key for linux platform
#define UP_BUTTON								SDLK_UP //SDL up key for linux platform
#define DOWN_BUTTON							SDLK_DOWN //SDL down key for linux platform
#define A_BUTTON								SDLK_a //SDL A key for linux platform
#define B_BUTTON 								SDLK_b //SDL b key for linux platform
#define HOME_BUTTON							SDLK_q //SDL q key for linux platform

//Various game states
#define STATE_WELCOME						1 //Welcome State in game
#define STATE_PLAY							2 //Play State in game
#define STATE_TUTORIAL					3 //Tutorial State in game

//Graphics placement for Main game play screen
#define TETROMINO_SPACING				1 //Spacing between tetrominos squares

#define PLAY_GRID_STARTX				225 //Start X for play grid
#define PLAY_GRID_STARTY				18 //Start Y of play grid


#define HI_SCORES_STARTX				83 //Start X of hi scores of game
#define HI_SCORES_STARTY				195 //Start Y of hi scores of game
#define SCORES_STARTX						83 //Start X of scores
#define SCORES_STARTY						280 //Start Y of scores
#define SCORES_DIGITS						6 //Number of digits in scores

#define LINES_STARTX						93 //Start X of level
#define LINES_STARTY						365 //Start Y of level
#define LINES_DIGITS						4 //Number of digits in level

#define LEVEL_STARTX						103 //Start X of level
#define LEVEL_STARTY						435 //Start Y of level
#define LEVEL_DIGITS						2 //Number of digits in level

#define HISCORE_STARTX					215 //Start X for Hi Score message
#define HISCORE_STARTY					130 //Start Y for Hi Score message

#define GAME_STATE_STARTX				253 //Start X for Game State message
#define GAME_STATE_STARTY				165 //Start X for Game State message

#define GAME_QUIT_STARTX				235//Start X for Game Quit message
#define GAME_QUIT_STARTY				125//Start Y for Game Quit message

#define PRESSA_STARTX						265 //Start X for Press A message
#define PRESSA_STARTY						200 //Start X for Press A message

#define GAME_STAT_STARTX				550 //Start X for game statistics
#define GAME_STAT_STARTY				100 //Start Y for game statistics
#define GAME_STAT_NEXT					30 //Y offset for next tetromino statistics
#define GAME_STAT_DIGITS				3 //No of digits in tetromino stats

//Graphics placement for Welcome screen
#define WSCR_PRESSA_STARTX			200 //Start X for Press A message on Welcome Screen
#define WSCR_PRESSA_STARTY			255 //Start Y for Press A message on Welcome Screen

#define WSCR_PRESSB_STARTX			200 //Start X for Press B message on Welcome Screen
#define WSCR_PRESSB_STARTY			405 //Start Y for Press B message on Welcome Screen

//Graphics placement for Tutorial screen
#define TSCR_PRESSA_STARTX			200 //Start X for Press A message on Tutorial Screen
#define TSCR_PRESSA_STARTY			410 //Start Y for Press A message on Tutorial Screen 

//Graphics placement in Data bitmap
#define FONT_STARTX							5 //Start X for fonts in game data bitmap
#define FONT_STARTY							25 //Start Y for fonts in game data bitmap
#define FONT_WIDTH							10 //Width of fonts used in games
#define FONT_HEIGHT							15 //Height of fonts used in games
#define FONT_SPACING						2 //Spacing between font

#define SQUARE_STARTX						5 //Start X for squares in game data bitmap
#define SQUARE_STARTY						5 //Start Y for squares in game data bitmap
#define SQUARE_SPACING					5 //Spacing between colored squares in data bitmap
#define NUM_SQUARE							4 //Number of squares in our data bitmap
#define SQUARE_WIDTH						15 //Width of tetromino square

//Graphics placement in message bitmap
#define MESS_PRESSA_BIG_STARTX 	5 //Start X for Press A Big message
#define MESS_PRESSA_BIG_STARTY 	5 //Start Y for Press A Big message
#define MESS_PRESSA_BIG_WIDTH		240 //Width of Press A Big message
#define MESS_PRESSA_BIG_HEIGHT	25 //Height of Press A Big message

#define MESS_PRESSB_STARTX 			5 //Start X for Press B message
#define MESS_PRESSB_STARTY 			35 //Start Y for Press B message
#define MESS_PRESSB_WIDTH				250 //Width of Press B message
#define MESS_PRESSB_HEIGHT			25 //Height of Press B message

#define MESS_QUIT_STARTX 				5 //Start X for Confirm Quit message
#define MESS_QUIT_STARTY 				65 //Start Y for Confirm Quit message
#define MESS_QUIT_WIDTH					170 //Width of Confirm Quit message
#define MESS_QUIT_HEIGHT				70 //Height of Confirm Quit message

#define MESS_YOUWIN_STARTX 			5 //Start X for You Win message
#define MESS_YOUWIN_STARTY 			140 //Start Y for You Win message
#define MESS_YOUWIN_WIDTH				135 //Width of You Win message
#define MESS_YOUWIN_HEIGHT			30 //Height of You Win message

#define MESS_GAMEOVER_STARTX		5 //Start X for Game Over message
#define MESS_GAMEOVER_STARTY		175 //Start Y for Game Over message
#define MESS_GAMEOVER_WIDTH			135 //Width of Game Over message
#define MESS_GAMEOVER_HEIGHT		30 //Height of Game Over message

#define MESS_PAUSED_STARTX			5 //Start X for Paused message
#define MESS_PAUSED_STARTY			210 //Start Y for Paused message
#define MESS_PAUSED_WIDTH				135 //Width of Paused message
#define MESS_PAUSED_HEIGHT			30 //Height of Paused message

#define MESS_HISCORE_STARTX			5 //Start X for Hi Score message
#define MESS_HISCORE_STARTY			245 //Start Y for Hi Score message
#define MESS_HISCORE_WIDTH			210 //Width of Hi Score message
#define MESS_HISCORE_HEIGHT			30 //Height of Hi Score message

#define MESS_PRESSA_STARTX			5 //Start X for Press A message
#define MESS_PRESSA_STARTY			280 //Start Y for Press A message
#define MESS_PRESSA_WIDTH				110 //Width of Press A message
#define MESS_PRESSA_HEIGHT			30 //Height of Press A message

#endif
