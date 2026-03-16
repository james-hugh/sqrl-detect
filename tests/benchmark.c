#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void optimized_print_graph_of_chaos() {
    static const char x_row[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_row[] = "********************";
    static const char dot_row[] = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *fill = (val > 15) ? x_row : (val > 8) ? star_row : dot_row;
        printf("%2d |%.*s\n", val, val, fill);
    }
}

int main() {
    srand(42); // Deterministic seed for benchmarking
    for (int i = 0; i < 1000000; i++) {
        optimized_print_graph_of_chaos();
    }
    return 0;
}
