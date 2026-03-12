#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void original_print_graph_of_chaos() {
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        // Simulating the original character-by-character printf
        // We use a dummy sink to avoid I/O bottlenecks during pure logic testing,
        // but the goal is to show the overhead of multiple calls.
        // However, in the real app, printf is the bottleneck.
        // To be fair, let's use sprintf to a buffer to simulate the call overhead.
        char buf[256];
        int pos = 0;
        pos += sprintf(buf + pos, "%2d |", val);
        for (int j = 0; j < val; j++) {
            if (val > 15) pos += sprintf(buf + pos, "X");
            else if (val > 8) pos += sprintf(buf + pos, "*");
            else pos += sprintf(buf + pos, ".");
        }
        pos += sprintf(buf + pos, "\n");
    }
}

void optimized_print_graph_of_chaos() {
    static const char fill_x[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char fill_star[] = "********************";
    static const char fill_dot[] = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *fill = (val > 15) ? fill_x : (val > 8) ? fill_star : fill_dot;
        char buf[256];
        sprintf(buf, "%2d |%.*s\n", val, val, fill);
    }
}

int main(int argc, char *argv[]) {
    int iterations = 1000000;
    if (argc > 1) iterations = atoi(argv[1]);

    clock_t start, end;

    srand(42);
    start = clock();
    for (int i = 0; i < iterations; i++) {
        original_print_graph_of_chaos();
    }
    end = clock();
    printf("Original (simulated call overhead): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    srand(42);
    start = clock();
    for (int i = 0; i < iterations; i++) {
        optimized_print_graph_of_chaos();
    }
    end = clock();
    printf("Optimized: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
