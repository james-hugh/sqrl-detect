#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_graph_of_chaos_original() {
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        for (int j = 0; j < val; j++) {
            if (val > 15) printf("X");
            else if (val > 8) printf("*");
            else printf(".");
        }
        printf("\n");
    }
}

void print_graph_of_chaos_optimized() {
    static const char fill_X[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char fill_star[] = "********************";
    static const char fill_dot[] = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *filler = (val > 15) ? fill_X : (val > 8) ? fill_star : fill_dot;
        printf("%2d |%.*s\n", val, val, filler);
    }
}

int main() {
    printf("Original output:\n");
    srand(42);
    print_graph_of_chaos_original();

    printf("\nOptimized output:\n");
    srand(42);
    print_graph_of_chaos_optimized();

    return 0;
}
