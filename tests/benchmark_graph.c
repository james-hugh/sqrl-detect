#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_graph_of_chaos_original() {
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        for (int j = 0; j < val; j++) {
            if (val > 15) printf("X");
            else if (val > 8) printf("*");
            else printf(".");
        }
        printf("\n");
    }
}

void print_graph_of_chaos_optimized() {
    static const char x_fill[]    = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_fill[] = "********************";
    static const char dot_fill[]  = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *fill = (val > 15) ? x_fill : (val > 8) ? star_fill : dot_fill;
        printf("%.*s\n", val, fill);
    }
}

int main() {
    struct timespec start, end;
    const int iterations = 1000000;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < iterations; i++) print_graph_of_chaos_original();
    clock_gettime(CLOCK_MONOTONIC, &end);
    double baseline = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Optimized
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < iterations; i++) print_graph_of_chaos_optimized();
    clock_gettime(CLOCK_MONOTONIC, &end);
    double optimized = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Baseline: %f s\n", baseline);
    printf("Optimized: %f s\n", optimized);
    printf("Improvement: %.2f%%\n", (baseline - optimized) / baseline * 100);

    return 0;
}
