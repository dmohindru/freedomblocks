#include <SDL/SDL.h>
#include <time.h>
#include "tetromino.h"
#include "gamedefs.h"
/* Tetrominos reated stuff
 * Tetrominos that we will have
 * Square tetrominos
 * S/Z tetrominos
 * L tetrominos
 * I tetromios
 * To represent tetrominos will be use 4X4 array of short 
 * */
static short tetrominos[TETROMINO_NUM][TETROMINO_ROTATION][TETROMINO_GRID][TETROMINO_GRID] = 
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
           {{{0,0,0,0}, // Z
           {1,1,0,0},
           {0,1,1,0},
           {0,0,0,0}}, 
           {{0,0,0,0},
           {0,0,1,0},
           {0,1,1,0},
           {0,1,0,0}},
           {{0,0,0,0},
           {1,1,0,0},
           {0,1,1,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {0,0,1,0},
           {0,1,1,0},
           {0,1,0,0}}},
           {{{0,0,0,0}, // L
           {0,1,0,0},
           {0,1,0,0},
           {0,1,1,0}}, 
           {{0,0,0,0},
           {1,1,1,0},
           {1,0,0,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {0,1,1,0},
           {0,0,1,0},
           {0,0,1,0}},
           {{0,0,0,0},
           {0,0,1,0},
           {1,1,1,0},
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
           {{0,0,0,0},
           {0,1,0,0},
           {1,1,0,0},
           {0,1,0,0}},
           {{0,0,0,0},
           {0,1,0,0},
           {1,1,1,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {1,0,0,0},
           {1,1,0,0},
           {1,0,0,0}}},
           {{{0,0,0,0}, // S
           {0,1,1,0},
           {1,1,0,0},
           {0,0,0,0}}, 
           {{0,0,0,0},
           {0,1,0,0},
           {0,1,1,0},
           {0,0,1,0}},
           {{0,0,0,0},
           {0,1,1,0},
           {1,1,0,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {0,1,0,0},
           {0,1,1,0},
           {0,0,1,0}}}};

static short play_grid[PLAY_GRID_ROW][PLAY_GRID_COL];
static int cur_row, cur_col, cur_tetromino, cur_rotation, next_tetromino, cur_square;
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


void DrawTetromino()
{
  int i, j, col, row;
  SDL_Rect src, dest;
  src.w = SQUARE_WIDTH;
  src.h = SQUARE_WIDTH;
  src.x = SQUARE_STARTX + cur_square * (SQUARE_WIDTH + SQUARE_SPACING);
  src.y = SQUARE_STARTY;
  dest.w = SQUARE_WIDTH;
  dest.h = SQUARE_WIDTH;
  col = cur_col;
  row = cur_row;
  for(i=0;i<TETROMINO_GRID;i++)
  {
    col = cur_col;
    for(j=0;j<TETROMINO_GRID;j++)
    {
      if(tetrominos[cur_tetromino][cur_rotation][i][j])
      {
        dest.x = PLAY_GRID_STARTX + col * (SQUARE_WIDTH + TETROMINO_SPACING);
        dest.y = PLAY_GRID_STARTY + row * (SQUARE_WIDTH + TETROMINO_SPACING);
        SDL_BlitSurface(gamedata, &src, screen, &dest);
      }
      col++;
    }
    row++;
  }
}
void InitalizePlayGrid()
{
  int i,j;
  for(i=0;i<PLAY_GRID_ROW;i++)
    for(j=0;j<PLAY_GRID_COL;j++)
      play_grid[i][j] = -1;
  initrandom();
  cur_tetromino = 0;
  cur_rotation = 0;
}
void SpawnNewTetromino()
{
  cur_tetromino = getrandom() % TETROMINO_NUM; //tetromin index
  cur_square = getrandom() % NUM_SQUARE;  //square index in data bitmap
  cur_rotation = 0; //rotation alway start at 0
  cur_row = -1; //needs more logic here
  cur_col = 4;
}
void RotateTetromino()
{
  cur_rotation++;
  if(cur_rotation >= TETROMINO_ROTATION)
    cur_rotation = 0;
}
void MoveTetromino(int direction)
{
  //need more login and error checking here
  if(direction == LEFT)
    cur_col--;
  else if(direction == RIGHT)
    cur_col++;
}
void LandTetromino()
{
}
void DrawGridBlocks()
{
  int i, j;
  SDL_Rect src, dest;
  src.w = SQUARE_WIDTH;
  src.h = SQUARE_WIDTH;
  dest.w = SQUARE_WIDTH;
  dest.h = SQUARE_WIDTH;
  for(i=0;i<PLAY_GRID_ROW;i++)
  {
    for(j=0;j<PLAY_GRID_COL;j++)
    {
      if(play_grid[i][j] >= 0)
      {
        src.x = SQUARE_STARTX + play_grid[i][j] * (SQUARE_WIDTH + SQUARE_SPACING);
        src.y = SQUARE_STARTY;
        dest.x = PLAY_GRID_STARTX + j * (SQUARE_WIDTH + TETROMINO_SPACING);
        dest.y = PLAY_GRID_STARTY + i * (SQUARE_WIDTH + TETROMINO_SPACING);
        SDL_BlitSurface(gamedata, &src, screen, &dest);
      }
    }
  }
}
int IfTetrominoLanded()
{
  int new_row, i, j;
  new_row = cur_row + TETROMINO_GRID; //start from bottom row
  //start from lowest row in tetromino grid
  for(i=0;i<TETROMINO_GRID;i++)
  {
    for(j=0;j<TETROMINO_GRID;j++)
    {
      if(tetrominos[cur_tetromino][cur_rotation][TETROMINO_GRID-1-i][j])
      {
        if(new_row-i >= PLAY_GRID_ROW) //If tetromino reached to bottom row
          return TRUE;
        if(play_grid[new_row-i][cur_col+j] >= 0)
          return TRUE;
      }
    }
  }
  return FALSE;
}
void UpdatePlayGrid()
{
  int i,j;
  for(i=0;i<TETROMINO_GRID;i++)
    for(j=0;j<TETROMINO_GRID;j++)
      if(tetrominos[cur_tetromino][cur_rotation][i][j])
        play_grid[cur_row+i][cur_col+j] = cur_square;
}
void MoveTetrominoDown()
{
  cur_row++;
}
