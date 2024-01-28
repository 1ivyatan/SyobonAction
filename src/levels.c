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

void printlevel(int level[][LEVELHEIGHT], Camera2D camera, float pos) {

    //int h1 = ((int)camera.target.x % TILESIZE) * -1; ///////////
    //int h2 = h1 + LEVELWIDTH * TILESIZE + ((h1 == 0) ? 0 : TILESIZE);
    /* might use this later, temprarly will use eof int */
    //int m1 = (int)pos / TILESIZE;
   // Vector2 h = GetScreenToWorld2D((Vector2){ 0.5f * SCRWIDTH, SCRHEIGHT }, camera);

    Vector2 boundaryend = GetScreenToWorld2D((Vector2){ SCRWIDTH, SCRHEIGHT }, camera); /* center */
    //printf("%d %d\n", m1, ((int)boundaryend.x - SCRWIDTH) / TILESIZE);

    int boundx1 = ((int)boundaryend.x - SCRWIDTH) / TILESIZE;
    int cursorx = boundx1 * TILESIZE,
        cursory = 0,
        boundx2 = boundx1 + LEVELWIDTH + 1;
    //for (int i = 0; ; i++) { ///////////////////////i < LEVELWIDTH
    for (int i = boundx1; i < boundx2; i++) {
        if (level[i][0] < 0) break;
        for (int j = 0; j < LEVELHEIGHT; j++) {
            if (level[i][j] > 0) printtexture(brocktex, cursorx, cursory);
            cursory += TILESIZE;
        }
        cursorx += TILESIZE;
        cursory = 0;
    }
}