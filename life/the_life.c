#include "the_life.h"
#include <stdio.h>

struct Cell grid[HEIGHT][WIDTH];
struct Cell next_grid[HEIGHT][WIDTH];

void my_name() {
    // N
    {
        grid[10][12].state = ALIVE;
        grid[11][12].state = ALIVE;
        grid[12][12].state = ALIVE;
        grid[13][12].state = ALIVE;
        grid[14][12].state = ALIVE;

        grid[11][13].state = ALIVE;
        grid[12][14].state = ALIVE;

        grid[10][15].state = ALIVE;
        grid[11][15].state = ALIVE;
        grid[12][15].state = ALIVE;
        grid[13][15].state = ALIVE;
        grid[14][15].state = ALIVE;
    }

    // I
    {
        grid[10][18].state = ALIVE;
        grid[11][18].state = ALIVE;
        grid[12][18].state = ALIVE;
        grid[13][18].state = ALIVE;
        grid[14][18].state = ALIVE;
    }

    // S -> pending
    {
        grid[10][20].state = ALIVE;
        grid[10][21].state = ALIVE;
        grid[10][22].state = ALIVE;
        grid[10][23].state = ALIVE;

        grid[11][20].state = ALIVE;

        grid[12][20].state = ALIVE;
        grid[12][21].state = ALIVE;
        grid[12][22].state = ALIVE;
        grid[12][23].state = ALIVE;

        grid[13][23].state = ALIVE;

        grid[14][23].state = ALIVE;
        grid[14][22].state = ALIVE;
        grid[14][21].state = ALIVE;
        grid[14][20].state = ALIVE;
    }
    
    // H
    {
        grid[10][25].state = ALIVE;
        grid[11][25].state = ALIVE;
        grid[12][25].state = ALIVE;
        grid[13][25].state = ALIVE;
        grid[14][25].state = ALIVE;

        grid[12][26].state = ALIVE;
        grid[12][27].state = ALIVE;

        grid[10][28].state = ALIVE;
        grid[11][28].state = ALIVE;
        grid[12][28].state = ALIVE;
        grid[13][28].state = ALIVE;
        grid[14][28].state = ALIVE;
    }
    
    // A
    {
        grid[10][31].state = ALIVE;
        grid[10][32].state = ALIVE;

        grid[10][30].state = ALIVE;
        grid[11][30].state = ALIVE;
        grid[12][30].state = ALIVE;
        grid[13][30].state = ALIVE;
        grid[14][30].state = ALIVE;

        grid[12][31].state = ALIVE;
        grid[12][32].state = ALIVE;

        grid[10][33].state = ALIVE;
        grid[11][33].state = ALIVE;
        grid[12][33].state = ALIVE;
        grid[13][33].state = ALIVE;
        grid[14][33].state = ALIVE;
    }
    
    // N
    {
        grid[10][35].state = ALIVE;
        grid[11][35].state = ALIVE;
        grid[12][35].state = ALIVE;
        grid[13][35].state = ALIVE;
        grid[14][35].state = ALIVE;

        grid[11][36].state = ALIVE;
        grid[12][37].state = ALIVE;

        grid[10][38].state = ALIVE;
        grid[11][38].state = ALIVE;
        grid[12][38].state = ALIVE;
        grid[13][38].state = ALIVE;
        grid[14][38].state = ALIVE;
    }
}

int count_alive(int i, int j) {
    int count = 0;

    for (int I = i - 1; I <= i + 1; I++) {
        for (int J = j - 1; J <= j + 1; J++) {
            if (I == i && J == j)continue;
            if (I >= 0 && I < HEIGHT && J >= 0 && J < WIDTH && grid[I][J].state == ALIVE) count++;
        }
    }

    return count;
}

void next_state() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int alive_neighbors = count_alive(i, j);

            if (grid[i][j].state == ALIVE) {
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    next_grid[i][j].state = DEAD;
                } else {
                    next_grid[i][j].state = ALIVE;
                }
            } else {
                if (alive_neighbors == 3) {
                    next_grid[i][j].state = ALIVE;
                } else {
                    next_grid[i][j].state = DEAD;
                }
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j].state = next_grid[i][j].state;
        }
    }
}


void init_state() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j].state = DEAD;
        }
    }
    
    my_name();
}

void print_grid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j].state == ALIVE) printf(CELL);
            else printf(BACKGROUND);
        }
        putchar('\n');
    }
}
