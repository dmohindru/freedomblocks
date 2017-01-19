#ifndef TETROMINO_H
#define TETROMINO_H
#include "gamedefs.h"
/* Tetrominos reated stuff
 * Tetrominos that we will have
 * Square tetrominos
 * S/Z tetrominos
 * L tetrominos
 * I tetromios
 * To represent tetrominos will be use 4X4 array of short 
 * */
#define TETROMINO_GRID      4 //size of grid to represent tetromino
#define TETROMINO_ROTATION  4 //number of rotation in tetrominos
#define TETROMINO_NUM       5 //number of tetrominos in game
short tetrominos[TETROMINO_NUM][TETROMINO_ROTATION][TETROMINO_GRID][TETROMINO_GRID] = 
        {{{{0,0,0,0},   //Square
           {0,1,1,0},
           {0,1,1,0},
           {0,0,0,0}}, 
           {{0,0,0,0},
           {0,1,1,0},
           {0,1,1,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {0,1,1,0},
           {0,1,1,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {0,1,1,0},
           {0,1,1,0},
           {0,0,0,0}}},
           {{{0,0,0,0}, // S/Z
           {1,1,0,0},
           {0,1,1,0},
           {0,0,0,0}}, 
           {{0,0,1,0},
           {0,1,1,0},
           {0,1,0,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {1,1,0,0},
           {0,1,1,0},
           {0,0,0,0}},
           {{0,0,1,0},
           {0,1,1,0},
           {0,1,0,0},
           {0,0,0,0}}},
           {{{0,0,0,0}, // L
           {0,1,0,0},
           {0,1,0,0},
           {0,1,1,0}}, 
           {{0,0,0,0},
           {0,0,0,1},
           {0,1,1,1},
           {0,0,0,0}},
           {{0,1,1,0},
           {0,0,1,0},
           {0,0,1,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {1,1,1,0},
           {1,0,0,0},
           {0,0,0,0}}},
           {{{0,1,0,0}, // I
           {0,1,0,0},
           {0,1,0,0},
           {0,1,0,0}}, 
           {{0,0,0,0},
           {1,1,1,1},
           {0,0,0,0},
           {0,0,0,0}},
           {{0,1,0,0},
           {0,1,0,0},
           {0,1,0,0},
           {0,1,0,0}},
           {{0,0,0,0},
           {1,1,1,1},
           {0,0,0,0},
           {0,0,0,0}}},
           {{{0,0,0,0}, // T
           {1,1,1,0},
           {0,1,0,0},
           {0,0,0,0}}, 
           {{0,1,0,0},
           {1,1,0,0},
           {0,1,0,0},
           {0,0,0,0}},
           {{0,1,0,0},
           {1,1,1,0},
           {0,0,0,0},
           {0,0,0,0}},
           {{0,1,0,0},
           {0,1,1,0},
           {0,1,0,0},
           {0,0,0,0}}}};

short tetromino_play_grid[PLAY_GRID_ROW][PLAY_GRID_COL];

void initalizePlayGrid();
        
    




#endif

