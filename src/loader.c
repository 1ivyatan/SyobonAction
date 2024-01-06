#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include "activities.h"
#include "game.h"
#include "media.h"

int SOUND = 1;

void checkarguments(int argc, char **argv) {
    if (argc < 2) return;
    if (argc > 2) {
        puts("Too many arguments");
        return;
    }

    if (!strcmp(argv[1], "-nosound")) SOUND = 0;
}

int loadeverything(int sound) {
    /* window */
    InitWindow(480, 420, "しょぼんのアクション");
    if (!IsWindowReady()) return -1;
    HideCursor();

    /* font */
    sazanamifont = LoadFontEx("./assets/img/sazanami-gothic.ttf", 16);
    if (!IsFontReady(sazanamifont)) {
        sazanamifont = GetFontDefault();
        puts("Failed to load Sazanami gothic! Prepare for question mark-apanese!");
    }

    /* menu */
    currentactivity = &startmenuactivity;
    return 0;
}

void cleanup(int error) {
    if (IsWindowReady()) CloseWindow();
    exit(error);
}