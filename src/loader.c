#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include "activities.h"
#include "game.h"
#include "graphics.h"
#include "levels.h"
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
    InitWindow(SCRWIDTH, SCRHEIGHT, "しょぼんのアクション");
    if (!IsWindowReady()) return -1;
    SetWindowState(FLAG_VSYNC_HINT);
    HideCursor();

    /* font */
    int codepointcount;
    int *codepoints = LoadCodepoints(CHARACTERS, &codepointcount);
    sazanamifont = LoadFontEx("./assets/img/sazanami-gothic.ttf", 16, codepoints, codepointcount);

    if (!IsFontReady(sazanamifont)) {
        sazanamifont = GetFontDefault();
        puts("Failed to load font! Prepare for question mark-apanese!");
    }

    UnloadCodepoints(codepoints);

    /* textures */
    opentexture(&brocktex, "./assets/img/brock.PNG", (Vector2){0, 0}, (Vector2){30, 30}, (Vector2){150, 0});
    opentexture(&creaturetex, "./assets/img/creatures.png", (Vector2){0, 0}, (Vector2){20, 34}, (Vector2){0, 0});

    /* menu */
    currentactivity = &startmenuactivity;
    return 0;
}

void cleanup(int error) {
    /* making it clear like the og game*/
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTextEx(sazanamifont, "EXITING...", (Vector2){240, 210}, 16, 1, WHITE);

    /* works */

    /* graphics */
    destroytexture(&creaturetex);
    destroytexture(&brocktex);
    UnloadFont(sazanamifont);

    /* final */
    if (IsWindowReady()) CloseWindow();
    exit(error);
}