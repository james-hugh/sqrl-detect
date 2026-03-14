
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * Benchmark for print_graph_of_chaos implementations.
 * Note: We use sprintf to a buffer to measure formatting overhead while
 * isolating performance from terminal I/O latency.
 */

void print_graph_of_chaos_original() {
    char buffer[1024];
    int offset = 0;
    offset += sprintf(buffer + offset, "GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        offset += sprintf(buffer + offset, "%2d |", val);
        for (int j = 0; j < val; j++) {
            if (val > 15) offset += sprintf(buffer + offset, "X");
            else if (val > 8) offset += sprintf(buffer + offset, "*");
            else offset += sprintf(buffer + offset, ".");
        }
        offset += sprintf(buffer + offset, "\n");
    }
    offset += sprintf(buffer + offset, "   +-------------------- (Acorns/sec)\n");
}

void print_graph_of_chaos_optimized() {
    static const char dots[]  = "....................";
    static const char stars[] = "********************";
    static const char exes[]  = "XXXXXXXXXXXXXXXXXXXX";

    char buffer[1024];
    int offset = 0;
    offset += sprintf(buffer + offset, "GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        offset += sprintf(buffer + offset, "%2d |", val);

        const char *src;
        if (val > 15) src = exes;
        else if (val > 8) src = stars;
        else src = dots;

        offset += sprintf(buffer + offset, "%.*s\n", val, src);
    }
    offset += sprintf(buffer + offset, "   +-------------------- (Acorns/sec)\n");
}

int main() {
    const int iterations = 1000000;
    printf("Running benchmark with %d iterations...\n", iterations);

    srand(42);
    clock_t start = clock();
    for (int i = 0; i < iterations; i++) {
        print_graph_of_chaos_original();
    }
    clock_t end = clock();
    double original_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    srand(42);
    start = clock();
    for (int i = 0; i < iterations; i++) {
        print_graph_of_chaos_optimized();
    }
    end = clock();
    double optimized_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Original time:  %f seconds\n", original_time);
    printf("Optimized time: %f seconds\n", optimized_time);
    printf("Improvement:    %.2f%%\n", (original_time - optimized_time) / original_time * 100.0);

    return 0;
}
