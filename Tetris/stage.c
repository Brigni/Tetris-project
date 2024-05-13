#include "stage.h"

extern int stage[];

void DrawStage(const int startOffsetX, const int startOffsetY, const Color colorTypes[])
{
    for (int y = 0; y < STAGE_HEIGHT; y++)
    {
        for (int x = 0; x < STAGE_WIDTH; x++)
        {
            const int pos = (STAGE_WIDTH * y) + x;
            const int color = stage[pos];

            if (stage[pos] != 0)
            {
                DrawRectangle(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, colorTypes[color - 1]);
            }

            DrawRectangleLines(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, BLACK);
        }
    }
}