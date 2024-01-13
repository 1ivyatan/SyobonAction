#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "graphics.h"

int opentexture(spritetexture *sprite, char *path, Vector2 pos, Vector2 snippable, Vector2 shift) {
    sprite->texture = LoadTexture(path);
    sprite->pos = pos;
    sprite->snippable = snippable;
    sprite->shift = shift;

    return (IsTextureReady(sprite->texture));
}

void printtexture(spritetexture sprite, int x, int y) {
    DrawTextureRec(sprite.texture, (Rectangle){sprite.pos.x + sprite.shift.x, sprite.pos.y + sprite.shift.y, sprite.snippable.x, sprite.snippable.y}, (Vector2){x, y}, WHITE);
}

void destroytexture(spritetexture *sprite) {
    if (!IsTextureReady(sprite->texture)) return;
    UnloadTexture(sprite->texture);
}