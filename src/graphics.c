#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "graphics.h"

int opentexture(Texture2D *texture, char *path) {
    *texture = LoadTexture(path);
    return (IsTextureReady(*texture));
}

void destroytexture(Texture2D *texture) {
    if (!IsTextureReady(*texture)) return;
    UnloadTexture(*texture);
}