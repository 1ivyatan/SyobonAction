#include <raylib.h>
#include "levels.h"
#include "media.h"
#include "graphics.h"

#include <stdio.h>


levelviewer prepareviewer(int level[][LEVELHEIGHT], levelentity *entity2follow) {
    levelviewer viewer;

    
    viewer.entity2follow = &entity2follow->position;
    viewer.level = level;
    
    //viewer.camera.target = viewer.entity2follow;

    return viewer;
}


void entityphysics(levelentity thing) {

}

void printentity(levelentity thing) {
    printtexture(thing.texture, thing.position.x, thing.position.y);
}

void printlevel(int level[][LEVELHEIGHT], Camera2D camera, float pos) {
    Vector2 boundaryend = GetScreenToWorld2D((Vector2){ SCRWIDTH, SCRHEIGHT }, camera); /* center */

    int boundx1 = ((int)boundaryend.x - SCRWIDTH) / TILESIZE;
    int cursorx = boundx1 * TILESIZE,
        cursory = 0,
        boundx2 = boundx1 + LEVELWIDTH + 1;
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