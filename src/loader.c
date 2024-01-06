#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include "activities.h"
#include "game.h"

int SOUND = 1;

void checkarguments(int argc, char **argv) {
    if (argc < 2) return;
    if (argc > 2) {
        printf("Too many arguments\n");
        return;
    }

    if (!strcmp(argv[1], "-nosound")) SOUND = 0;
}

int loadeverything(int sound) {
    /* window */
    InitWindow(480, 420, "しょぼんのアクション");
    if (!IsWindowReady()) return -1;
    HideCursor();

    /* menu */
    currentactivity = &startmenuactivity;
    return 0;
}

void cleanup(int error) {
    if (IsWindowReady()) CloseWindow();
    exit(error);
}