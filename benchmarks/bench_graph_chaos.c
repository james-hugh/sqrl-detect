#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

void original_print_graph_of_chaos() {
    // printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        // printf("%2d |", val);
        for (int j = 0; j < val; j++) {
            if (val > 15) printf("X");
            else if (val > 8) printf("*");
            else printf(".");
        }
        printf("\n");
    }
    // printf("   +-------------------- (Acorns/sec)\n");
}

void optimized_print_graph_of_chaos() {
    static char buf[21];
    // printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        // printf("%2d |", val);
        char c = (val > 15) ? 'X' : (val > 8) ? '*' : '.';
        memset(buf, c, val);
        fwrite(buf, 1, val, stdout);
        printf("\n");
    }
    // printf("   +-------------------- (Acorns/sec)\n");
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

int main() {
    int iterations = 1000000;
    srand(42); // For reproducibility

    FILE *devnull = fopen("/dev/null", "w");
    if (!devnull) return 1;

    int stdout_fd = dup(1);
    dup2(fileno(devnull), 1);

    double start = get_time();
    for (int i = 0; i < iterations; i++) {
        original_print_graph_of_chaos();
    }
    double end = get_time();
    double original_time = end - start;

    srand(42);
    start = get_time();
    for (int i = 0; i < iterations; i++) {
        optimized_print_graph_of_chaos();
    }
    end = get_time();
    double optimized_time = end - start;

    dup2(stdout_fd, 1);
    close(stdout_fd);
    fclose(devnull);

    printf("Original time:  %f s\n", original_time);
    printf("Optimized time: %f s\n", optimized_time);
    printf("Improvement:    %.2f%%\n", (original_time - optimized_time) / original_time * 100.0);

    return 0;
}
