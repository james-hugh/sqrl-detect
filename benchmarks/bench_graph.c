#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ITERATIONS 1000000

void print_graph_original() {
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        // printf("%2d |", val); // Disabling actual output to isolate logic
        for (int j = 0; j < val; j++) {
            if (val > 15) { /* printf("X"); */ }
            else if (val > 8) { /* printf("*"); */ }
            else { /* printf("."); */ }
        }
        // printf("\n");
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
        // fwrite(buf, 1, val, stdout);
        // printf("\n");
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
