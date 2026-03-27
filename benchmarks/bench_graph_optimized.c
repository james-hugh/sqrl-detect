#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_graph_of_chaos_optimized() {
    static const char fill_X[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char fill_star[] = "********************";
    static const char fill_dot[] = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *filler = (val > 15) ? fill_X : (val > 8) ? fill_star : fill_dot;
        printf("%.*s\n", val, filler);
    }
}

int main() {
    srand(42); // Deterministic for benchmarks
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        print_graph_of_chaos_optimized();
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(stderr, "Optimized Execution Time: %f seconds\n", time_spent);
    return 0;
}
