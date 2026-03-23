#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ITERATIONS 1000000

void original_print_graph_of_chaos() {
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

void optimized_printf_dot_star_print_graph_of_chaos() {
    static const char x_bars[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_bars[] = "********************";
    static const char dot_bars[] = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *bars;
        if (val > 15) bars = x_bars;
        else if (val > 8) bars = star_bars;
        else bars = dot_bars;
        printf("%.*s\n", val, bars);
    }
}

void optimized_fwrite_print_graph_of_chaos() {
    static const char x_bars[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_bars[] = "********************";
    static const char dot_bars[] = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *bars;
        if (val > 15) bars = x_bars;
        else if (val > 8) bars = star_bars;
        else bars = dot_bars;
        fwrite(bars, 1, val, stdout);
        putchar('\n');
    }
}

int main() {
    struct timespec start, end;
    double original_time, printf_opt_time, fwrite_opt_time;

    srand(42);
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < ITERATIONS; i++) {
        original_print_graph_of_chaos();
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    original_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    srand(42);
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < ITERATIONS; i++) {
        optimized_printf_dot_star_print_graph_of_chaos();
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf_opt_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    srand(42);
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < ITERATIONS; i++) {
        optimized_fwrite_print_graph_of_chaos();
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fwrite_opt_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    fprintf(stderr, "Original:   %f s\n", original_time);
    fprintf(stderr, "Printf Opt: %f s (%.2f%% improvement)\n", printf_opt_time, (original_time - printf_opt_time) / original_time * 100);
    fprintf(stderr, "Fwrite Opt: %f s (%.2f%% improvement)\n", fwrite_opt_time, (original_time - fwrite_opt_time) / original_time * 100);

    return 0;
}
