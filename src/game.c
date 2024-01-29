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

//Camera2D playercamera;

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

    /* camera */
    //if (player->position.x > boundary.x) {
     //   camera->offset = (Vector2){ 0.5f * SCRWIDTH, 330 };
    //    camera->target.x = boundary.x + (player->position.x - boundary.x);
   // }
    
}

/* ACTIVITY FUNCTIONS */
void gamelogic() {
    float delta = GetFrameTime();
    updateplayer(&playerentity, delta);
    updateviewer(&syobonviewer);
        
    //float h1 = boundary.x - (SCRWIDTH * 0.5f);
    //float h2 = boundary.x + (SCRWIDTH * 0.5f);
    //printf("%f %f %f %f %f\n", player->position.x, boundary.x, h1, h2, h2 - h1);
    //int h1 = ((int)player->position.x % TILESIZE) * -1;
}

void gamedraw() {
    ClearBackground(SYOBONSKYCOLOR);

    /* level */
    BeginMode2D(syobonviewer.camera);
        //printlevel(levelone, playercamera, playerentity.position.x); /////////
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
        syobonviewer = prepareviewer(levelone, &playerentity);

        currentactivity = &gameactivity;
        //levellength = sizeof(levelone) / sizeof(levelone[0]);
     //   printf("%d\n", levellength);
    }
}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawTextEx(sazanamifont, "Enterキーを押せ!!", (Vector2){100, 100}, 16, 1, BLACK);
}