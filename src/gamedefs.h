#ifndef GAMEDEFS_H
#define GAMEDEFS_H

//define various games constants 
#define GAME_WIDTH		800 //Width of game background
#define GAME_HEIGHT		600 //Height of game background

#define SQUARE_WIDTH	30 //Width of tetromino square
#define TETROMINO_SPACING	2 //Spacing between tetrominos squares

#define PLAY_GRID_ROW	16 //Number of square logical rows in play grid
#define PLAY_GRID_COL	10 //Number of square logical cols in play grid

#define PLAY_GRID_WIDTH		318 //Width of play grid in px
#define PLAY_GRID_HEIGHT	510 //Height of play grid in px

#define PLAY_GRID_STARTX	300 //Start X for play grid
#define PLAY_GRID_STARTY	60 //Start Y of play grid

#define FONT_WIDTH		30 //Width of fonts used in games
#define FONT_HEIGHT		50 //Height of fonts used in games
#define FONT_SPACING	5 //Spacing between font

#define SCORES_STARTX	50 //Start X of scores
#define SCORES_STARTY	150 //Start Y of scores
#define SCORES_DIGITS	4 //Number of digits in scores

#define LEVEL_STARTX	85 //Start X of level
#define LEVEL_STARTY	450 //Start Y of level
#define LEVEL_DIGITS	2 //Number of digits in level

#define RED_SQUARE		1 //Index of red square in game data bitmap
#define GREEN_SQUARE	2 //Index of green square in game data bitmap
#define YELLOW_SQUARE	3 //Index of yellow square in game data bitmap
#define CYAN_SQUARE		4 //Index of cyan square in game data bitmap

#define FONT_STARTX		5 //Start X for fonts in game data bitmap
#define FONT_STARTY		50 //Start Y for fonts in game data bitmap

#define SQUARE_STARTX	5 //Start X for squares in game data bitmap
#define SQUARE_STARTY	10 //Start Y for squares in game data bitmap
#define SQUARE_SPACING	5

#endif
