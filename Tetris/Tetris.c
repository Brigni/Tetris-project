#include "raylib.h"
#include <string.h>
#include <time.h>
#include "Tetris.h"

#include <stdio.h>

int score;

int stage[] =
    {
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

const int lTetromino_0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0
};

const int lTetromino_90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    1, 0, 0, 0,
    0, 0, 0, 0
};

const int lTetromino_180[] =
{
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int lTetromino_270[] =
{
    0, 0, 1, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int jTetromino_0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0
};

const int jTetromino_90[] =
{
    1, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int jTetromino_180[] =
{
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int jTetromino_270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0
};

const int oTetromino[] =
{
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int sTetromino_0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0
};

const int sTetromino_90[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0
};

const int sTetromino_180[] =
{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0
};

const int sTetromino_270[] =
{
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0
};

const int tTetromino_0[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int tTetromino_90[] =
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int tTetromino_180[] =
{
    0, 1, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int tTetromino_270[] =
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int iTetromino_0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0
};

const int iTetromino_90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int iTetromino_180[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0
};

const int iTetromino_270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int zTetromino_0[] =
{
    0, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0
};

const int zTetromino_90[] =
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 0
};

const int zTetromino_180[] =
{
    1, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int zTetromino_270[] =
{
    0, 0, 1, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const Color colorTypes[9] =
{
    {255, 255, 255, 255},
    {255, 161, 0, 255},
    {0, 121, 241, 255},
    {0, 228, 48, 255},
    {253, 249, 0, 255},
    {200, 122, 255, 255},
    {0, 158, 47, 255},
    {127, 106, 79, 255},
    {255, 109, 194, 255}
};

const int* tetrominoTypes[7][4] =
{
    {zTetromino_0, zTetromino_90, zTetromino_180, zTetromino_270},
    {sTetromino_0, sTetromino_90, sTetromino_180, sTetromino_270},
    {tTetromino_0, tTetromino_90, tTetromino_180, tTetromino_270},
    {iTetromino_0, iTetromino_90, iTetromino_180, iTetromino_270},
    {lTetromino_0, lTetromino_90, lTetromino_180, lTetromino_270},
    {jTetromino_0, jTetromino_90, jTetromino_180, jTetromino_270},
    {oTetromino, oTetromino, oTetromino, oTetromino},
};

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

void ResetLines(int startLineY, Sound sound)
{
    PlaySound(sound);
    for(int y = startLineY; y >= 0 - 1; y--)
    {
        for(int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int offset_below = (y + 1) * STAGE_WIDTH + x;

            if(stage[offset_below] == 0 && stage[offset] > 0)
            {
                stage[offset_below] = stage[offset];
                stage[offset] = 0;
            }
        }
    }
}

void DeleteLines(Sound sound)
{
    for(int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkLine = 1;
        for(int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if(stage[offset] == 0)
            {
                checkLine = 0;
                break;
            }
        }

        if(checkLine)
        {
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));
            score += CLEAR_LINE_SCORE;
            ResetLines(y, sound);
        }
    }
}

int main(int argc, char **argv, char **environ)
{
    const int windowWidth = 600;
    const int windowHeight = 700;
    const int windowHalfWidth = windowWidth / 2;

    const int startOffsetX = windowHalfWidth - STAGE_WIDTH * TILE_SIZE / 2;
    const int startOffsetY = windowHeight / 2 - STAGE_HEIGHT * TILE_SIZE / 2;

    const int tetrominoStartX = STAGE_WIDTH / 2;
    const int tetrominoStartY = 0;

    int currTetrominoX = tetrominoStartX;
    int currTetrominoY = tetrominoStartY;

    time_t unixTime;
    time(&unixTime);

    SetRandomSeed(unixTime);

    int currTetrominoType = GetRandomValue(0, 6);
    int currTetrominoRot = 0;

    const float moveTetrominoDownTimer = 1.f;
    float timeToMoveTetrominoDown = moveTetrominoDownTimer;
    int currColor = GetRandomValue(1, 8);

    //TraceLog(LOG_INFO, "Number of arguments: %d", argc);

    // for(int i = 0; i < argc; i++)
    //{
    //     TraceLog(LOG_INFO, "Argument %d: %s", i, argv[i]);
    // }

    // while(*environ != 0)
    //{
    //     TraceLog(LOG_INFO, "Environ: %s", *environ);
    //     environ++;
    // }

    InitAudioDevice();

    Sound turnSound = LoadSound("Resources/Explosion1__003.wav"); //sound credit to "SwissArcadeGameEntertainment"
    Sound rowCompleteSound = LoadSound("Resources/Pew__010.wav"); //sound credit to "SwissArcadeGameEntertainment"

    InitWindow(windowWidth, windowHeight, "Tetris game");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        timeToMoveTetrominoDown -= GetFrameTime();

        if(IsKeyPressed(KEY_SPACE))
        {
            const int lastRotation = currTetrominoRot;
            currTetrominoRot++;

            if(currTetrominoRot > 3)
            {
                currTetrominoRot = 0;
            }

            if(CheckCollision(currTetrominoX, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]))
            {
                currTetrominoRot = lastRotation;
            }
            else
            {
                PlaySound(turnSound);
            }
        }

        if(IsKeyPressed(KEY_RIGHT))
        {
            //no need to check for overflow because the wall acts against it
            if(!CheckCollision(currTetrominoX + 1, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]))
            {
                currTetrominoX++;
            }
        }
        if(IsKeyPressed(KEY_LEFT))
        {
            //no need to check for overflow because the wall acts against it
            if(!CheckCollision(currTetrominoX - 1, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]))
            {
                currTetrominoX--;
            }
        }

        if (timeToMoveTetrominoDown <= 0 || IsKeyPressed(KEY_DOWN))
        {
            if(!CheckCollision(currTetrominoX, currTetrominoY + 1, tetrominoTypes[currTetrominoType][currTetrominoRot]))
            {
                currTetrominoY++;
                float dropSpeed;
                if(score < 1200)
                {
                    dropSpeed = score * 0.000583f;
                }
                else
                {
                    dropSpeed = 0.7f;
                }
                timeToMoveTetrominoDown = moveTetrominoDownTimer - dropSpeed;
            }

            else
            {
                for(int y = 0; y < TETROMINO_SIZE; y++)
                {
                    for(int x = 0; x < TETROMINO_SIZE; x++)
                    {
                        const int pos = (TETROMINO_SIZE * y) + x;

                        const int *tetromino = tetrominoTypes[currTetrominoType][currTetrominoRot];

                        if (tetromino[pos] == 1)
                        {
                            const int offset_stage = (y + currTetrominoY) * STAGE_WIDTH + (x + currTetrominoX);

                            stage[offset_stage] = currColor + 1;
                        }
                    }
                }

                DeleteLines(rowCompleteSound);

                currTetrominoX = tetrominoStartX;
                currTetrominoY = tetrominoStartY;

                currTetrominoType = GetRandomValue(0, 6);
                currTetrominoRot = 0;
                currColor = GetRandomValue(1, 8);
            }
        }

        DrawText(TextFormat("Score: %d", score), windowHalfWidth - 70, 30, 30, WHITE);

        BeginDrawing();
        ClearBackground(RED);

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

        DrawTetromino(colorTypes[currColor], startOffsetX, startOffsetY, currTetrominoX, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]);

        EndDrawing();
    }

    UnloadSound(turnSound);
    UnloadSound(rowCompleteSound);

    CloseAudioDevice();

    return 0;
}