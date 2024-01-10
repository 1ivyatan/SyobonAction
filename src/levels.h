#ifndef LEVELS
#define LEVELS

#include <raylib.h>
#include "graphics.h"

#define LEVELHEIGHT 17

typedef struct {
    spritetexture texture;
    int x;
    int y;
    int controlled;
} levelentity;

typedef struct {
    int texture;
} levelblock;

void applytexturetoentity(levelentity *thing, spritetexture texture);
void printlevel(int level[][LEVELHEIGHT], Camera2D camera);
void printentity(levelentity thing);

#endif