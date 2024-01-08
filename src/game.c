#include <stdlib.h>
#include <raylib.h>
#include "activities.h"
#include "game.h"
#include "graphics.h"
#include "media.h"

/* activities */
void startlogic(void);
void startdraw(void);
void gamelogic(void);
void gamedraw(void);
void gamestartup(void);

activity startmenuactivity = { startlogic, startdraw, NULL };
activity gameactivity = { gamelogic, gamedraw, gamestartup };
activity *currentactivity = NULL;

/* functions */
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

/* ACTIVITY FUNCTIONS */
void gamestartup() {

}

void gamelogic() {

}

void gamedraw() {
    ClearBackground(SYOBONSKYCOLOR);

}

void startlogic() {
    if (IsKeyPressed(KEY_ENTER)) currentactivity = &gameactivity;
}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawTextEx(sazanamifont, "Enterキーを押せ!!", (Vector2){100, 100}, 16, 1, BLACK);
}