#include "life/the_life.h"
#include <stdlib.h>
#include <unistd.h>

int main() {
    init_state();
    print_grid();

    while (1) {
        usleep(SLEEP * 1000);
        system("clear");

        next_state();
        print_grid();
    }

    return 0;
}
