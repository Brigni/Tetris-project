#include "Tetromino.h"

void DrawTetromino(const Color currColor, const int startOffsetX, const int startOffsetY, const int tetraminoStartX, const int tetrominoStartY, const int* tetromino)
{
    for(int y = 0; y < TETROMINO_SIZE; y++)
    {
        for(int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int pos = (TETROMINO_SIZE * y) + x;

            if (tetromino[pos] == 1)
            {
                DrawRectangle((x + tetraminoStartX) * TILE_SIZE + startOffsetX, (y + tetrominoStartY) * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, currColor);
            }
        }
    }
}