#ifndef GRAPHICS
#define GRAPHICS
#include <raylib.h>

#define SYOBONSKYCOLOR (Color){ 151, 252, 252, 255 }

int opentexture(Texture2D *texture, char *path);
void printtexture(Texture2D texture, int posx, int posy, int x1, int y1, int x2, int y2, Color tint);
void destroytexture(Texture2D *texture);

#endif