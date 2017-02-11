/* Author: Dhruv Mohindru
 * Dated: 10/02/17
 * Description: Header file for tetromino module of game.
 * */
#ifndef TETROMINO_H
#define TETROMINO_H

void InitalizePlayGrid();
int SpawnNewTetromino();
void RotateTetromino();
void MoveTetromino(int direction);
void LandTetromino();
int IfTetrominoLanded();
void DrawTetromino();
void DrawGridBlocks();
void UpdatePlayGrid();
void MoveTetrominoDown();
void DrawNextTetromino();
int LinesCleared();
void DrawTetrominoStats();
    
#endif

