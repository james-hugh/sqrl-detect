#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ITERATIONS 1000000

// Using a small local buffer to avoid heavy I/O in benchmark,
// but still simulating the logic impact.
char sink[1024];
int sink_ptr = 0;

void print_graph_original() {
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        // printf("%2d |", val);
        for (int j = 0; j < val; j++) {
            if (val > 15) sink[sink_ptr++] = 'X';
            else if (val > 8) sink[sink_ptr++] = '*';
            else sink[sink_ptr++] = '.';
            if (sink_ptr >= 1000) sink_ptr = 0;
        }
        sink[sink_ptr++] = '\n';
        if (sink_ptr >= 1000) sink_ptr = 0;
    }
}

void print_graph_optimized() {
    static const char x_buffer[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_buffer[] = "********************";
    static const char dot_buffer[] = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        // printf("%2d |", val);
        const char *buf;
        if (val > 15) buf = x_buffer;
        else if (val > 8) buf = star_buffer;
        else buf = dot_buffer;
        memcpy(sink + sink_ptr, buf, val);
        sink_ptr += val;
        if (sink_ptr >= 1000) sink_ptr = 0;
        sink[sink_ptr++] = '\n';
        if (sink_ptr >= 1000) sink_ptr = 0;
    }
}

int main() {
    srand(42);
    clock_t start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        print_graph_original();
    }
    clock_t end = clock();
    double time_original = (double)(end - start) / CLOCKS_PER_SEC;

    srand(42);
    sink_ptr = 0;
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        print_graph_optimized();
    }
    end = clock();
    double time_optimized = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Original: %f s\n", time_original);
    printf("Optimized: %f s\n", time_optimized);
    printf("Improvement: %.2f%%\n", (time_original - time_optimized) / time_original * 100);

    return 0;
}
