#include <stdlib.h>
#include <raylib.h>
#include "activities.h"
#include "game.h"

activity *currentactivity = NULL;

void loopgame(void) {

    while (!WindowShouldClose()) {
        BeginDrawing();
        currentactivity->graphics();
        EndDrawing();
    }
}