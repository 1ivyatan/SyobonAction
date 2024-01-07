#ifndef GRAPHICS
#define GRAPHICS
#include <raylib.h>

#define SYOBONSKYCOLOR (Color){ 151, 252, 252, 255 }

typedef struct {
    Texture2D texture;
    int x1;
    int y1;
    int x2;
    int y2;
    int shiftx;
    int shifty;
    Color tint;
} spritetexture;

int opentexture(spritetexture *sprite, char *path, int initx1, int inity1, int initx2, int inity2, int shiftx, int shifty);
void printtexture(spritetexture sprite, int x, int y);
void destroytexture(spritetexture *sprite);

#endif