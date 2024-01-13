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

/* video */
Camera2D playercamera;

/* entities */
levelentity playerentity;

/* functions */

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
void updateplayer(levelentity *player, Camera2D *camera) {
    /* movement */
    if (player->controlled) {
        if (IsKeyDown(KEY_LEFT)) player->position.x -= 1;
        if (IsKeyDown(KEY_RIGHT)) player->position.x += 1;
    }

    /* camera */
    Vector2 boundarymin = GetScreenToWorld2D((Vector2){ 0.5f * SCRWIDTH, 420 }, *camera);
    Vector2 boundarymax = GetScreenToWorld2D((Vector2){ 0.5f * SCRWIDTH, SCRHEIGHT }, *camera);
    camera->offset = (Vector2){ 0.5f * SCRWIDTH, 330 };
    if (player->position.x > boundarymax.x) camera->target.x = boundarymin.x + (player->position.x - boundarymax.x);

}

/* ACTIVITY FUNCTIONS */
void gamelogic() {
    updateplayer(&playerentity, &playercamera);
}

void gamedraw() {
    ClearBackground(SYOBONSKYCOLOR);

    BeginMode2D(playercamera);
    printlevel(levelone, playercamera);
    printentity(playerentity);
    EndMode2D();
}

void startlogic() {
    if (IsKeyPressed(KEY_ENTER)) {
        playerentity.position = (Vector2){0, 416};
        playerentity.controlled = 1;
        playerentity.texture = creaturetex;


        playercamera.target = playerentity.position; 
        playercamera.zoom = 1;
        playercamera.offset = (Vector2){ 100, 334 };

        currentactivity = &gameactivity;
    }
}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawTextEx(sazanamifont, "Enterキーを押せ!!", (Vector2){100, 100}, 16, 1, BLACK);
}