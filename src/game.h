#ifndef GAME
#define GAME

typedef struct {
    void (*logic)(void);
    void (*graphics)(void);
} activity;

void loopgame(void);

#endif