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

typedef struct {
    int (*levelgrid)[LEVELHEIGHT];
} levelfile;

typedef struct {
    Camera2D camera;
    Vector2 *entity2follow;
    levelfile *level;
} levelviewer;

levelviewer prepareviewer(levelfile *level, levelentity *entity2follow);
void updateviewer(levelviewer* viewer);
void printviewer(levelviewer* viewer);

void applytexturetoentity(levelentity *thing, spritetexture texture);
void printlevel(int level[][LEVELHEIGHT], Camera2D camera, float pos);
void printentity(levelentity thing);

#endif