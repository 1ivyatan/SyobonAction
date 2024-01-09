#ifndef LEVELS
#define LEVELS

#include "graphics.h"

#define LEVELHEIGHT 17

typedef struct {
    spritetexture texture;
    int x;
    int y;
    int controlled;
} entity;

void applytexturetoentity(entity *thing, spritetexture texture);
void printlevel(int level[][LEVELHEIGHT], int pos);
void printentity(entity thing);

#endif