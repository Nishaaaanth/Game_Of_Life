#ifndef THE_LIFE_H
#define THE_LIFE_H

#define HEIGHT 25
#define WIDTH 50
#define SLEEP 200

#define BACKGROUND "."
#define CELL "@"

enum {
    DEAD,
    ALIVE
};

struct Cell {
    int state;
};

void init_state();
void print_grid();
void next_state();
void my_name();
int count_alive(int, int);

#endif
