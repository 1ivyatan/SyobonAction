#include <raylib.h>
#include "levels.h"
#include "media.h"
#include "graphics.h"

#include <stdio.h>

void entityphysics(levelentity thing) {

}

void printentity(levelentity thing) {
    printtexture(thing.texture, thing.position.x, thing.position.y);
}

void printlevel(int level[][LEVELHEIGHT], Camera2D camera) {

    //int h1 = ((int)camera.target.x % TILESIZE) * -1; ///////////
    //int h2 = h1 + LEVELWIDTH * TILESIZE + ((h1 == 0) ? 0 : TILESIZE);
    /* might use this later, temprarly will use eof int */
    int m1 = camera.target.x / TILESIZE;
    Vector2 h = GetScreenToWorld2D((Vector2){ 0.5f * SCRWIDTH, SCRHEIGHT }, camera);

    int cursorx = 0;
    int cursory = 0;
    for (int i = 0; i < LEVELWIDTH; i++) { ///////////////////////
        if (level[i][0] < 0) break;
        for (int j = 0; j < LEVELHEIGHT; j++) {
            if (level[i][j] > 0) printtexture(brocktex, cursorx, cursory);
            cursory += 30;
        }
        cursorx += 30;
        cursory = 0;
    }
}