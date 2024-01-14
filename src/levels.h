#ifndef LEVELS
#define LEVELS

#include <raylib.h>
#include "graphics.h"

#define LEVELHEIGHT 17
#define WALKINGSPEED 3.f

typedef struct {
    spritetexture texture;
    Vector2 position;
    int controlled;
} levelentity;

typedef struct {
    int texture;
} levelblock;

void applytexturetoentity(levelentity *thing, spritetexture texture);
void printlevel(int level[][LEVELHEIGHT], Camera2D camera);
void printentity(levelentity thing);

#endif