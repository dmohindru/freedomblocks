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
           {0,0,1,0}}},
           {{{0,0,0,0}, // _|
           {0,0,1,0},
           {0,0,1,0},
           {0,1,1,0}}, 
           {{0,0,0,0},
           {1,0,0,0},
           {1,1,1,0},
           {0,0,0,0}},
           {{0,0,0,0},
           {0,1,1,0},
           {0,1,0,0},
           {0,1,0,0}},
           {{0,0,0,0},
           {1,1,1,0},
           {0,0,1,0},
           {0,0,0,0}}}};

static short play_grid[PLAY_GRID_ROW][PLAY_GRID_COL];
static int cur_row, cur_col, cur_tetromino, cur_rotation, next_tetromino, cur_square, next_square;
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

void DrawNextTetromino()
{
  int i, j, col, row;
  SDL_Rect src, dest;
  src.w = SQUARE_WIDTH;
  src.h = SQUARE_WIDTH;
  src.x = SQUARE_STARTX + next_square * (SQUARE_WIDTH + SQUARE_SPACING);
  src.y = SQUARE_STARTY;
  dest.w = SQUARE_WIDTH;
  dest.h = SQUARE_WIDTH;
  row = 0;
  for(i=0;i<TETROMINO_GRID;i++)
  {
    col = PLAY_GRID_COL + 1;
    for(j=0;j<TETROMINO_GRID;j++)
    {
      if(tetrominos[next_tetromino][0][i][j])
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
  next_tetromino = getrandom() % TETROMINO_NUM; //next tetromin index
  next_square = getrandom() % NUM_SQUARE;  //square index in data bitmap
}
int SpawnNewTetromino()
{
  int i, j;
  cur_tetromino = next_tetromino;
  cur_square = next_square;
  next_tetromino = getrandom() % TETROMINO_NUM; //tetromin index
  next_square = getrandom() % NUM_SQUARE;  //square index in data bitmap
  cur_rotation = 0; //rotation alway start at 0
  cur_row = -1;
  cur_col = 3;
  for(i=0;i<TETROMINO_GRID;i++) //check first row for presence of square
  {  
    if(tetrominos[cur_tetromino][cur_rotation][0][i])
    {
      cur_row = 0;
      break;
    }
  }
  //check if new tetrominos space is already taken
  for(i=0;i<TETROMINO_GRID;i++)
    for(j=0;j<TETROMINO_GRID;j++)
      if(tetrominos[cur_tetromino][cur_rotation][i][j])
        if(play_grid[cur_row+i][cur_col+j] >= 0) //If next grid place in taken
          return FALSE;
  return TRUE;
}
void RotateTetromino()
{
  int new_rotation, new_col, i, j;
  new_rotation = cur_rotation + 1;
  new_col = cur_col;
  //cur_rotation++;
  if(new_rotation >= TETROMINO_ROTATION)
    new_rotation = 0;
  //first check for out of bound
  for(i=0;i<TETROMINO_GRID;i++)
  {
    for(j=0;j<TETROMINO_GRID;j++)
    {
      if(tetrominos[cur_tetromino][new_rotation][i][j])
      {
        if(new_col+j < 0) //If tetromino crossed left bound
          new_col++; 
        if(new_col+j >=PLAY_GRID_COL) //If tetromino crossed right bound
          new_col--;
        if(play_grid[cur_row+i][new_col+j] >= 0) //If next grid place in taken
          return;
      }
    }
  }
  cur_col = new_col;
  cur_rotation = new_rotation;
  
}
void MoveTetromino(int direction)
{
  //need more login and error checking here
  int new_col, i, j;
  if(direction == LEFT)
    new_col = cur_col - 1;
  else if(direction == RIGHT)
    new_col = cur_col + 1;
  for(i=0;i<TETROMINO_GRID;i++)
  {
    for(j=0;j<TETROMINO_GRID;j++)
    {
      if(tetrominos[cur_tetromino][cur_rotation][i][j])
      {
        if(new_col+j < 0 || new_col+j >= PLAY_GRID_COL)
          return; //If tetromino reached left right bound
        if(play_grid[cur_row+i][new_col+j] >= 0) //If next grid place in taken
          return;
      }
    }
  }
  cur_col = new_col;  
  
}
void LandTetromino()
{
  while(!IfTetrominoLanded())
    MoveTetrominoDown();
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
        if(play_grid[new_row-i][cur_col+j] >= 0) //If next grid place in taken
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

int LinesCleared()
{
  int lines[PLAY_GRID_ROW], num_lines = 0, i, j, k, filled, empty, line_no;
  for(i=0;i<PLAY_GRID_ROW;i++) //initalize cleared line status array
    lines[i] = FALSE;
  //first pass to check lines to be cleared
  for(i=0;i<PLAY_GRID_ROW;i++)
  {
    filled = TRUE;
    empty = 0;
    for(j=0;j<PLAY_GRID_COL;j++)
    {
      if(play_grid[PLAY_GRID_ROW-1-i][j] < 0)
      {
        filled = FALSE;
        empty++;
      }
    }
    if(filled) //check for filed line
    {
      lines[PLAY_GRID_ROW-1-i] = TRUE;
      num_lines++;
    }
    else if(empty == PLAY_GRID_COL) //whole line was empty stop checking
      break;                        //any further
  }
  //second pass to clear lines
  for(i=0;i<num_lines;i++) //loop only num_lines times
  {
    line_no = PLAY_GRID_ROW-1;
    while(!lines[line_no])
      line_no--;
    //now line_no holds index to line to be cleared
    for(k=line_no;k>=0;k--)
    {
      for(j=0;j<PLAY_GRID_COL;j++)
      {
        if(k == 0) //last line
          play_grid[k][j] = -1;
        else  
          play_grid[k][j] = play_grid[k-1][j];
      }
    }
    //update cleared lines array also
    for(j=line_no;j>=0;j--)
    {
      if(j == 0)
        lines[j] = FALSE;
      else
        lines[j] = lines[j-1];
    }
  }
  
  return num_lines;
}
void MoveTetrominoDown()
{
  cur_row++;
}
