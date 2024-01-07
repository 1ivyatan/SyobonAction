#include <raylib.h>
#include "activities.h"
#include "graphics.h"
#include "media.h"

void startlogic(void);
void startdraw(void);

activity startmenuactivity = { startlogic, startdraw };

void startlogic() {

}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawTextEx(sazanamifont, "Enterキーを押せ!!", (Vector2){100, 100}, 16, 1, BLACK);
}