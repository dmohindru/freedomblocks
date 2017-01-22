#ifndef TETROMINO_H
#define TETROMINO_H



void InitalizePlayGrid();
void SpawnNewTetromino();
void RotateTetromino();
void MoveTetromino(int direction);
void LandTetromino();
int IfTetrominoLanded();
void DrawTetromino();
void DrawGridBlocks();
void UpdatePlayGrid();
void MoveTetrominoDown();
    




#endif

