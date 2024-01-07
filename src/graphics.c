#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "graphics.h"

int opentexture(spritetexture *sprite, char *path, int initx1, int inity1, int initx2, int inity2) {
    sprite->texture = LoadTexture(path);
    sprite->x1 = initx1;
    sprite->y1 = inity1;
    sprite->x2 = initx2;
    sprite->y2 = inity2;

    return (IsTextureReady(sprite->texture));
}

void printtexture(spritetexture sprite, int x, int y) {
    DrawTextureRec(sprite.texture, (Rectangle){sprite.x1, sprite.y1, sprite.x2, sprite.y2}, (Vector2){x, y}, WHITE);
}

void destroytexture(spritetexture *sprite) {
    if (!IsTextureReady(sprite->texture)) return;
    UnloadTexture(sprite->texture);
}