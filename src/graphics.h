#ifndef GRAPHICS
#define GRAPHICS
#include <raylib.h>

#define SYOBONSKYCOLOR (Color){ 151, 252, 252, 255 }

typedef struct {
    Texture2D texture;
    Vector2 pos;
    Vector2 snippable;
    Vector2 shift;
    Color tint;
} spritetexture;

int opentexture(spritetexture *sprite, char *path, Vector2 pos, Vector2 snippable, Vector2 shift);
void printtexture(spritetexture sprite, int x, int y);
void destroytexture(spritetexture *sprite);

#endif