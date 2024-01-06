#include <raylib.h>
#include "loader.h"

int main(int argc, char **argv) {
    checkarguments(argc, argv);
    if (loadeverything(1) < 0) cleanup(-1);

    InitWindow(480, 420, "しょぼんのアクション");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("しょぼんのアクション", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}