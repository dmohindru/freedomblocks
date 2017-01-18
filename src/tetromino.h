#ifndef TETROMINO_H
#define TETROMINO_H
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
short tetrominos[2][TETROMINO_ROTATION][TETROMINO_GRID][TETROMINO_GRID] = 
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
           {0,0,0,0}}}};


        
        
    




#endif

