#ifndef GRAPHICS
#define GRAPHICS
#include <raylib.h>

#define SYOBONSKYCOLOR (Color){ 151, 252, 252, 255 }

int opentexture(Texture2D *texture, char *path);
void destroytexture(Texture2D *texture);

#endif