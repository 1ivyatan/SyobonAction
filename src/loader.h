#ifndef LOADER
#define LOADER

void checkarguments(int argc, char **argv);

int loadeverything(int sound);
void cleanup(int error);

#endif