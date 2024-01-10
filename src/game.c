#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>
#include "activities.h"
#include "game.h"
#include "graphics.h"
#include "levels.h"
#include "media.h"

/* activities */
void startlogic(void);
void startdraw(void);
void gamelogic(void);
void gamedraw(void);
void gamestartup(void);

activity startmenuactivity = { startlogic, startdraw};
activity gameactivity = { gamelogic, gamedraw };
activity *currentactivity = NULL;

/* video */
Camera2D playercamera;

/* functions */
/* textures */
void applytexturetoentity(entity *thing, spritetexture texture) {
    thing->texture = texture;
}

/* things from raylib example */

#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 200.0f

typedef struct Player {
    Vector2 position;
    float speed;
    bool canJump;
} Player;

 Camera2D camera = { 0 };
         Player player = { 0 };

void UpdatePlayer(Player *player, float delta)
{
    if (IsKeyDown(KEY_LEFT)) player->position.x -= PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_SPACE) && player->canJump)
    {
        player->speed = -PLAYER_JUMP_SPD;
        player->canJump = false;
    }

}


////////
/* loop */
void loopgame(void) {
    while (!WindowShouldClose()) {
        /* logic */
        if (currentactivity->logic) currentactivity->logic();

        /* graphics */
        BeginDrawing();
        if (currentactivity->graphics) currentactivity->graphics();
        EndDrawing();
    }
}

/* ACTIVITY FUNCTIONS */

void gamelogic() {
    float deltaTime = GetFrameTime();

     UpdatePlayer(&player, deltaTime);
     

    static Vector2 bbox = { 0.2f, 0.2f };

    Vector2 bboxWorldMin = GetScreenToWorld2D((Vector2){ (1 - bbox.x)*0.5f*480, (1 - bbox.y)*0.5f*420 }, camera);
    Vector2 bboxWorldMax = GetScreenToWorld2D((Vector2){ (1 + bbox.x)*0.5f*480, (1 + bbox.y)*0.5f*420 }, camera);
    camera.offset = (Vector2){ (1 - bbox.x)*0.5f * 480, (1 - bbox.y)*0.5f*420 };

    if (player.position.y < bboxWorldMin.y) camera.target.y = player.position.y;
    if (player.position.x > bboxWorldMax.x) camera.target.x = bboxWorldMin.x + (player.position.x - bboxWorldMax.x);
    if (player.position.y > bboxWorldMax.y) camera.target.y = bboxWorldMin.y + (player.position.y - bboxWorldMax.y);


}

void gamedraw() {
    ClearBackground(SYOBONSKYCOLOR);
    

            BeginMode2D(camera);
                DrawTextEx(sazanamifont, "bg!!!!!!!", (Vector2){0, 0}, 600, 1, BLACK);
                Rectangle playerRect = { player.position.x - 20, player.position.y - 40, 40, 40 };
                DrawRectangleRec(playerRect, RED);

            EndMode2D();



}

void startlogic() {
    if (IsKeyPressed(KEY_ENTER)) {
        currentactivity = &gameactivity;

        ////////////////////////
    player.position = (Vector2){ 400, 280 };
    player.speed = 0;
    player.canJump = false;


camera.target = player.position;
    camera.offset = (Vector2){ 480/2.0f, 420/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    }
}

void startdraw() {
    ClearBackground(SYOBONSKYCOLOR);
    DrawTextEx(sazanamifont, "Enterキーを押せ!!", (Vector2){100, 100}, 16, 1, BLACK);
}