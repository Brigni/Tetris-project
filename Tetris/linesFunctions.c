#include <string.h>
#include "Tetris.h"
#include "linesFunctions.h"

extern int stage[];
extern int score;

void ResetLines(int startLineY, const Sound sound)
{
    PlaySound(sound);

    for (int y = startLineY; y >= 0 - 1; y--)
    {
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int offset_below = (y + 1) * STAGE_WIDTH + x;

            if (stage[offset_below] == 0 && stage[offset] > 0)
            {
                stage[offset_below] = stage[offset];
                stage[offset] = 0;
            }
        }
    }
}

int CheckIfLineIsCompleted(int lineY) // returns the index of the completed line
{
    int checkLine = 1;
    for (int x = 1; x < STAGE_WIDTH - 1; x++)
    {
        const int offset = lineY * STAGE_WIDTH + x;

        if (stage[offset] == 0)
        {
            checkLine = 0; // line is not complete
            break;
        }
    }
    return checkLine;
}

void DeleteLines(const Sound sound)
{
    for (int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        if (CheckIfLineIsCompleted(y))
        {
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));
            score += CLEAR_LINE_SCORE;
            ResetLines(y, sound);
        }
    }
}

void PulseLine(float *counter, int *isCounting, const int startOffsetX, const int startOffsetY, const Sound sound)
{
    int y = 0;
    if (*(counter) < LINE_BG_COUNTER)
    {
        for (; y < STAGE_HEIGHT - 1; y++)
        {
            if (CheckIfLineIsCompleted(y))
            {
                if (!(*isCounting))
                {
                    *isCounting = true;
                }
                if (*counter < LINE_WHITE_COUNTER)
                {
                    DrawRectangle(startOffsetX + TILE_SIZE, y * TILE_SIZE + startOffsetY, TILE_SIZE * (STAGE_WIDTH - 3) + TILE_SIZE, TILE_SIZE, RED);
                }
                else
                {
                    DrawRectangle(startOffsetX + TILE_SIZE, y * TILE_SIZE + startOffsetY, TILE_SIZE * (STAGE_WIDTH - 3) + TILE_SIZE, TILE_SIZE, WHITE);
                }

                for(int i = 1; i < STAGE_WIDTH - 1; i++)
                {
                    DrawRectangleLines(startOffsetX + (i * TILE_SIZE), y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, BLACK);
                }
            }
        }
        return;
    }

    DeleteLines(sound);

    *isCounting = false;
    *counter = 0;
}