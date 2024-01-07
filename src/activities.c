#include <raylib.h>
#include "activities.h"
#include "game.h"
#include "graphics.h"
#include "media.h"

void startlogic(void);
void startdraw(void);
void gamelogic(void);
void gamedraw(void);

activity startmenuactivity = { startlogic, startdraw };
activity gameactivity = { gamelogic, gamedraw };

/* game */
void gamelogic() {
    
}

void gamedraw() {
    ClearBackground(SYOBONSKYCOLOR);
    printtexture(playertex, 200, 200);
}

/* start */
void startlogic() {
    if (IsKeyPressed(KEY_ENTER)) currentactivity = &gameactivity;
}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawTextEx(sazanamifont, "Enterキーを押せ!!", (Vector2){100, 100}, 16, 1, BLACK);
}