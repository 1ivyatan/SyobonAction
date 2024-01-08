#include <raylib.h>
#include "activities.h"
#include "game.h"
#include "levels.h"
#include "media.h"

void switchactivity(activity *src, activity *dest, int startscript) {
    src = dest;
    if (startscript) src->startscript();
}