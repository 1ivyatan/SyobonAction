#include <stdlib.h>
#include <raylib.h>
#include "activities.h"
#include "game.h"

activity *currentactivity = NULL;

void loopgame(void) {

    while (!WindowShouldClose()) {
        /* logic */
        if (currentactivity->logic) currentactivity->logic();

        /* graphics */
        BeginDrawing();
        if (currentactivity->graphics) currentactivity->graphics();
        EndDrawing();
    }
}