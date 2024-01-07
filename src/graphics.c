#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "graphics.h"

int opentexture(Texture2D *texture, char *path) {
    *texture = LoadTexture(path);
    return (IsTextureReady(*texture));
}

void printtexture(Texture2D texture, int posx, int posy, int x1, int y1, int x2, int y2, Color tint) {
    DrawTextureRec(texture, (Rectangle){x1, y1, x2, y2}, (Vector2){posx, posy}, tint);
}

void destroytexture(Texture2D *texture) {
    if (!IsTextureReady(*texture)) return;
    UnloadTexture(*texture);
}