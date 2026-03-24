#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ITERATIONS 1000000

void print_graph_original() {
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

void print_graph_optimized() {
    static const char x_buffer[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_buffer[] = "********************";
    static const char dot_buffer[] = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        const char *buf;
        if (val > 15) buf = x_buffer;
        else if (val > 8) buf = star_buffer;
        else buf = dot_buffer;
        fwrite(buf, 1, val, stdout);
        printf("\n");
    }
}

int main() {
    FILE *devnull = fopen("/dev/null", "w");
    if (!devnull) return 1;

    // Use a custom stdout to avoid terminal overhead
    FILE *original_stdout = stdout;

    srand(42);
    stdout = devnull;
    clock_t start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        print_graph_original();
    }
    fflush(stdout);
    clock_t end = clock();
    double time_original = (double)(end - start) / CLOCKS_PER_SEC;

    srand(42);
    stdout = devnull;
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        print_graph_optimized();
    }
    fflush(stdout);
    end = clock();
    double time_optimized = (double)(end - start) / CLOCKS_PER_SEC;

    stdout = original_stdout;
    printf("Original (to /dev/null): %f s\n", time_original);
    printf("Optimized (to /dev/null): %f s\n", time_optimized);
    printf("Improvement: %.2f%%\n", (time_original - time_optimized) / time_original * 100);

    fclose(devnull);
    return 0;
}
