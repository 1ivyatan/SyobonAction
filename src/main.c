#include <raylib.h>
#include "game.h"
#include "loader.h"

int main(int argc, char **argv) {
    checkarguments(argc, argv);
    if (loadeverything(1) < 0) cleanup(-1);
    loopgame();
    cleanup(0);
}