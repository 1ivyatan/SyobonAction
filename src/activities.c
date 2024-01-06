#include <raylib.h>
#include "activities.h"
#include "graphics.h"

void startlogic();
void startdraw();

activity startmenuactivity = { startlogic, startdraw };

void startlogic() {

}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawText("shobon no akushon!!!!", 190, 200, 20, BLACK);
}