#include "tetromino.h"

void initalizePlayGrid()
{
  int i,j;
  for(i=0;i<PLAY_GRID_ROW;i++)
    for(j=0;j<PLAY_GRID_COL;j++)
      tetromino_play_grid[i][j] = 0;
}
