#include <string.h>
#include <time.h>
#include "raylib.h"
#include "Tetris.h"
#include "Tetromino.h"
#include "tetrominoDefinitions.h"
#include "linesFunctions.h"
#include "Color.h"
#include "stage.h"

#include <stdio.h>

int score;

int main(int argc, char **argv, char **environ)
{
    InitAudioDevice();

    const Sound turnSound = LoadSound("Resources/Explosion1__003.wav");           // sound credit to "SwissArcadeGameEntertainment"
    const Sound rowCompleteSound = LoadSound("Resources/Pew__010.wav");           // sound credit to "SwissArcadeGameEntertainment"
    const Music bgMusic = LoadMusicStream("Resources/POL-cactus-land-short.wav"); // sound credit to "Filippo Vicarelli" (Filippo Game Audio)

    PlayMusicStream(bgMusic);

    const int windowWidth = 600;
    const int windowHeight = 700;
    const int windowHalfWidth = windowWidth / 2;

    const int startOffsetX = windowHalfWidth - STAGE_WIDTH * TILE_SIZE / 2;
    const int startOffsetY = windowHeight / 2 - STAGE_HEIGHT * TILE_SIZE / 2;

    const int tetrominoStartX = STAGE_WIDTH / 2;
    const int tetrominoStartY = 0;

    int currTetrominoX = tetrominoStartX;
    int currTetrominoY = tetrominoStartY;

    int currTetrominoType = GetRandomValue(0, 6);
    int currTetrominoRot = 0;

    const float moveTetrominoDownTimer = 1.f;
    float timeToMoveTetrominoDown = moveTetrominoDownTimer;
    int currColor = GetRandomValue(1, 8);

    float linePulseCounter = 0.0f;
    int lineIsPulsing = false;

    time_t unixTime;
    time(&unixTime);

    SetRandomSeed(unixTime);

    InitWindow(windowWidth, windowHeight, "Tetris game");
    SetTargetFPS(60);

    int gameOver = false;

    while (!WindowShouldClose())
    {
        if (!gameOver)
        {
            PulseLine(&linePulseCounter, &lineIsPulsing, startOffsetX, startOffsetY, rowCompleteSound);

            if (!lineIsPulsing)
            {
                timeToMoveTetrominoDown -= GetFrameTime();

                if (IsKeyPressed(KEY_SPACE))
                {
                    const int lastRotation = currTetrominoRot;
                    currTetrominoRot++;

                    if (currTetrominoRot > 3)
                    {
                        currTetrominoRot = 0;
                    }

                    if (CheckCollision(currTetrominoX, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]))
                    {
                        currTetrominoRot = lastRotation;
                    }
                    else
                    {
                        PlaySound(turnSound);
                    }
                }

                if (IsKeyPressed(KEY_RIGHT))
                {
                    // no need to check for overflow because the wall acts against it
                    if (!CheckCollision(currTetrominoX + 1, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]))
                    {
                        currTetrominoX++;
                    }
                }
                if (IsKeyPressed(KEY_LEFT))
                {
                    // no need to check for overflow because the wall acts against it
                    if (!CheckCollision(currTetrominoX - 1, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]))
                    {
                        currTetrominoX--;
                    }
                }

                if (timeToMoveTetrominoDown <= 0 || IsKeyPressed(KEY_DOWN))
                {
                    if (!CheckCollision(currTetrominoX, currTetrominoY + 1, tetrominoTypes[currTetrominoType][currTetrominoRot]))
                    {
                        currTetrominoY++;
                        float dropSpeed;
                        if (score < 1200)
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
                        for (int y = 0; y < TETROMINO_SIZE; y++)
                        {
                            for (int x = 0; x < TETROMINO_SIZE; x++)
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

                        //DeleteLines(rowCompleteSound);

                        if (CheckCollision(tetrominoStartX, tetrominoStartY, tetrominoTypes[currTetrominoType][currTetrominoRot]))
                        {
                            gameOver = true;
                        }

                        currTetrominoX = tetrominoStartX;
                        currTetrominoY = tetrominoStartY;

                        currTetrominoType = GetRandomValue(0, 6);
                        currTetrominoRot = 0;
                        currColor = GetRandomValue(1, 8);
                    }
                }
            }
            else
            {
                linePulseCounter += GetFrameTime();
            }

            DrawText(TextFormat("Score: %d", score), windowHalfWidth - 70, 30, 30, WHITE);

            BeginDrawing();
            ClearBackground(RED);

            DrawStage(startOffsetX, startOffsetY, colorTypes);
            
            PulseLine(&linePulseCounter, &lineIsPulsing, startOffsetX, startOffsetY, rowCompleteSound);

            if (!lineIsPulsing)
            {
                DrawTetromino(colorTypes[currColor], startOffsetX, startOffsetY, currTetrominoX, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]);
            }

            EndDrawing();
        }
        else
        {

            BeginDrawing();
            ClearBackground(RED);
            DrawText(TextFormat("Score: %d", score), windowHalfWidth - 70, 30, 30, WHITE);
            DrawStage(startOffsetX, startOffsetY, colorTypes);
            DrawTetromino(colorTypes[currColor], startOffsetX, startOffsetY, currTetrominoX, currTetrominoY, tetrominoTypes[currTetrominoType][currTetrominoRot]);
            DrawText(TextFormat("Game Over"), windowHalfWidth - 130, windowHeight / 2, 52, BLACK);
            EndDrawing();
        }
        UpdateMusicStream(bgMusic);
    }

    UnloadSound(turnSound);
    UnloadSound(rowCompleteSound);
    UnloadMusicStream(bgMusic);

    CloseAudioDevice();

    return 0;
}
