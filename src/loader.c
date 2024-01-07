#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include "activities.h"
#include "game.h"
#include "graphics.h"
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
    opentexture(&playertex, "./assets/img/player.PNG", 0, 0, 30, 36, 0, 0); //////////

    /* menu */
    currentactivity = &startmenuactivity;
    return 0;
}

void cleanup(int error) {
    /* making it clear like the og game*/
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTextEx(sazanamifont, "EXITING...", (Vector2){240, 210}, 16, 1, WHITE);
    EndDrawing();

    /* works */

    /* graphics */
    UnloadFont(sazanamifont);

    destroytexture(&playertex);

    /* final */
    if (IsWindowReady()) CloseWindow();
    exit(error);
}