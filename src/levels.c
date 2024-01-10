#include <raylib.h>
#include "levels.h"
#include "media.h"
#include "graphics.h"

void entityphysics(levelentity thing) {

}

void printentity(levelentity thing) {
    printtexture(thing.texture, thing.x, thing.y);
}

void printlevel(int level[][LEVELHEIGHT], Camera2D camera) {
    int cursorx = 0;
    int cursory = 0;
    for (int i = 0; i < 20; i++) { ///////////////////////
        for (int j = 0; j < LEVELHEIGHT; j++) {
            if (level[i][j] > 0) printtexture(brocktex, cursorx, cursory);
            cursory += 30;
        }
        cursorx += 30;
        cursory = 0;
    }
}