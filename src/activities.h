#ifndef ACTIVITIES
#define ACTIVITIES

typedef struct {
    void (*logic)(void);
    void (*graphics)(void);
    void (*startscript)(void);
} activity;

void switchactivity(activity *src, activity *dest, int startscript);
#endif