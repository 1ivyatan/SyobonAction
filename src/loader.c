#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SOUND = 1;

void checkarguments(int argc, char **argv) {
    if (argc < 2) return;
    if (argc > 2) {
        printf("Too many arguments\n");
        return;
    }

    if (!strcmp(argv[1], "-nosound")) SOUND = 0;
}

int loadeverything(int sound) {

    return 0;
}

void cleanup(int error) {
    exit(error);
}