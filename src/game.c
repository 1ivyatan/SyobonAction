#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>
#include "activities.h"
#include "game.h"
#include "graphics.h"
#include "levels.h"
#include "media.h"

#include <stdio.h>

/* activities */
void startlogic(void);
void startdraw(void);
void gamelogic(void);
void gamedraw(void);
void gamestartup(void);

activity startmenuactivity = { startlogic, startdraw};
activity gameactivity = { gamelogic, gamedraw };
activity *currentactivity = NULL;

/* global variables only on this file */
/* video */
levelviewer syobonviewer;

/* entities */
levelentity playerentity;

/* flags */

/* functions, end of variables */
/* textures */
void applytexturetoentity(levelentity *thing, spritetexture texture) {
    thing->texture = texture;
}

/* loop */
void loopgame(void) {
    while (!WindowShouldClose()) {
        if (currentactivity->logic) currentactivity->logic();
        BeginDrawing();
        if (currentactivity->graphics) currentactivity->graphics();
        EndDrawing();
    }
}

/* entity functions */
void updateplayer(levelentity *player, float delta) {
    /* movement */
    if (player->controlled) {
        if (IsKeyDown(KEY_LEFT)) player->position.x -= WALKINGSPEED;
        if (IsKeyDown(KEY_RIGHT)) player->position.x += WALKINGSPEED;
    }
}

/* ACTIVITY FUNCTIONS */
void gamelogic() {
    float delta = GetFrameTime();
    updateplayer(&playerentity, delta);
    updateviewer(&syobonviewer);
}

void gamedraw() {
    ClearBackground(SYOBONSKYCOLOR);

    BeginMode2D(syobonviewer.camera);
        printviewer(&syobonviewer);
        printentity(playerentity);
    EndMode2D();

    /* something for UI
    ...... */
}

void startlogic() {
    if (IsKeyPressed(KEY_ENTER)) {

        /* player */
        playerentity.position = (Vector2){0, 416};
        playerentity.controlled = 1;
        playerentity.texture = creaturetex;

        /* level */
        syobonviewer = prepareviewer(&StageONE, &playerentity);
        currentactivity = &gameactivity;
    }
}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawTextEx(sazanamifont, "Enterキーを押せ!!", (Vector2){100, 100}, 16, 1, BLACK);
}