#include <stdlib.h>
#include <raylib.h>
#include "activities.h"
#include "game.h"
#include "graphics.h"
#include "levels.h"
#include "media.h"

/* activities */
void startlogic(void);
void startdraw(void);
void gamelogic(void);
void gamedraw(void);
void gamestartup(void);

activity startmenuactivity = { startlogic, startdraw};
activity gameactivity = { gamelogic, gamedraw };
activity *currentactivity = NULL;

/* video */
Camera2D playercamera;

/* tempppppppp */
entity playerentity;

/* functions */
/* textures */
void applytexturetoentity(entity *thing, spritetexture texture) {
    thing->texture = texture;
}

/* loop */
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

void gamelogic() {

}

void gamedraw() {
    ClearBackground(SYOBONSKYCOLOR);
    BeginMode2D(playercamera);

    EndMode2D();
}

void startlogic() {
    if (IsKeyPressed(KEY_ENTER)) {
        currentactivity = &gameactivity;

        applytexturetoentity(&playerentity, creaturetex);
        playerentity.x = 140;
        playerentity.y = 300;
    }
}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawTextEx(sazanamifont, "Enterキーを押せ!!", (Vector2){100, 100}, 16, 1, BLACK);
}