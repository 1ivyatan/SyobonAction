#ifndef LEVELS
#define LEVELS

#include <raylib.h>
#include "graphics.h"

#define LEVELWIDTH 16
#define LEVELHEIGHT 17
#define TILESIZE 30
#define WALKINGSPEED 3.f

typedef struct {
    spritetexture texture;
    Vector2 position;
    int controlled;
    Rectangle hitbox;
} levelentity;

typedef struct {
    int texture;
} levelblock;

void applytexturetoentity(levelentity *thing, spritetexture texture);
void printlevel(int level[][LEVELHEIGHT], Camera2D camera, float pos);
void printentity(levelentity thing);

#endif