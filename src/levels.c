#include <raylib.h>
#include "levels.h"
#include "media.h"
#include "graphics.h"

#include <stdio.h>


levelviewer prepareviewer(levelfile *level, levelentity *entity2follow) {
    levelviewer viewer;

    /* target */
    viewer.entity2follow = &entity2follow->position;
    viewer.camera.target = *viewer.entity2follow;
    viewer.camera.zoom = 1;
    viewer.camera.rotation = 0;
    viewer.camera.offset = (Vector2){ 0, 330 };

    viewer.level = level;
    return viewer;
}

void updateviewer(levelviewer* viewer) {
    Vector2 boundary = GetScreenToWorld2D((Vector2){ 0.5f * SCRWIDTH, SCRHEIGHT }, viewer->camera); /* center */
    if (viewer->entity2follow->x > boundary.x) {
        viewer->camera.offset = (Vector2){ 0.5f * SCRWIDTH, 330 };
        viewer->camera.target.x = boundary.x + (viewer->entity2follow->x - boundary.x);
    }
}

void printviewer(levelviewer* viewer) {
    Vector2 boundaryend = GetScreenToWorld2D((Vector2){ SCRWIDTH, SCRHEIGHT }, viewer->camera); /* center */

    int boundx1 = ((int)boundaryend.x - SCRWIDTH) / TILESIZE;
    int cursorx = boundx1 * TILESIZE,
        cursory = 0,
        boundx2 = boundx1 + LEVELWIDTH + 1;
    for (int i = boundx1; i < boundx2; i++) {
        if (viewer->level->levelgrid[i][0] < 0) break;
        for (int j = 0; j < LEVELHEIGHT; j++) {
            if (viewer->level->levelgrid[i][j] > 0) printtexture(brocktex, cursorx, cursory);
            cursory += TILESIZE;
        }
        cursorx += TILESIZE;
        cursory = 0;
    }
}

void printentity(levelentity thing) {
    printtexture(thing.texture, thing.position.x, thing.position.y);
}