#ifndef MEDIA
#define MEDIA
#include <raylib.h>
#include "graphics.h"
#include "levels.h"

/* screen */
#define SCRWIDTH 480
#define SCRHEIGHT 420

/* text */
#define CHARACTERS " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~キ"
extern Font sazanamifont;

/* textures */
extern spritetexture brocktex;
extern spritetexture creaturetex;

/* levels */
extern int levelone[][LEVELHEIGHT];

#endif