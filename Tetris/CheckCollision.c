#include "Tetris.h"

extern int stage[];

int CheckCollision(const int tetraminoStartX, const int tetrominoStartY, const int* tetromino)
{
    for(int y = 0; y < TETROMINO_SIZE; y++)
    {
        for(int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int pos = (TETROMINO_SIZE * y) + x;

            if (tetromino[pos] == 1)
            {
                const int offset_stage = (y + tetrominoStartY) * STAGE_WIDTH + (x + tetraminoStartX);

                if(stage[offset_stage] != 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}