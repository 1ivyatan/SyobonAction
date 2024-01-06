#include <raylib.h>
#include "activities.h"

void startlogic();
void startdraw();

activity startmenuactivity = { startlogic, startdraw };

void startlogic() {

}

void startdraw() {
    ClearBackground(RAYWHITE);
    DrawText("shobon no akushon!!!!", 190, 200, 20, BLACK);
}