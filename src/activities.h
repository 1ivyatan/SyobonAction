#ifndef ACTIVITIES
#define ACTIVITIES

typedef struct {
    void (*logic)(void);
    void (*graphics)(void);
} activity;

/* ACTIVITIES */
extern activity startmenuactivity;

#endif