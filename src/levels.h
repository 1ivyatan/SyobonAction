#ifndef LEVELS
#define LEVELS

#include "graphics.h"

#define LEVELHEIGHT 17

typedef struct {
    spritetexture texture;
    int x;
    int y;
} entity;

/////////////
extern entity playerchar;
///////////

void printlevel(int level[][LEVELHEIGHT], int pos);
void printentity(entity thing);

#endif