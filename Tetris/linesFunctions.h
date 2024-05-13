#include "raylib.h"

#define LINE_BG_COUNTER 1.0f
#define LINE_WHITE_COUNTER 0.5f

void ResetLines(int startLineY, const Sound sound);
int CheckIfLineIsCompleted(const int lineY);
void DeleteLines(const Sound sound);
void PulseLine(float* counter, int* isCounting, const int startOffsetX, const int startOffsetY, const Sound sound);