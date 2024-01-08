#include "levels.h"
#include "media.h"
#include "graphics.h"

void printlevel(int level[][LEVELHEIGHT], int pos) {
    int cursorx = 0;
    int cursory = 0;
    for (int i = 0; i < pos; i++) {
        for (int j = 0; j < LEVELHEIGHT; j++) {
            if (level[i][j] > 0) printtexture(brocktex, cursorx, cursory - 55);
            cursory += 30;
        }
        cursorx += 30;
        cursory = 0;
    }
}