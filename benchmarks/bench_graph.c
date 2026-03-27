#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_graph_of_chaos_original() {
    // No header for benchmark
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        // Output formatting for correctness check
        // printf("%2d |", val);
        for (int j = 0; j < val; j++) {
            if (val > 15) printf("X");
            else if (val > 8) printf("*");
            else printf(".");
        }
        printf("\n");
    }
}

int main() {
    srand(42); // Deterministic for benchmarks
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        print_graph_of_chaos_original();
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(stderr, "Original Execution Time: %f seconds\n", time_spent);
    return 0;
}
