#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Original version
void print_graph_of_chaos_orig() {
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

// Optimized version
void print_graph_of_chaos_opt() {
    static const char x_bars[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_bars[] = "********************";
    static const char dot_bars[] = "....................";

    char buffer[1024];
    int offset = 0;
    offset += sprintf(buffer + offset, "GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *fill = (val > 15) ? x_bars : (val > 8) ? star_bars : dot_bars;
        offset += sprintf(buffer + offset, "%2d |%.*s\n", val, val, fill);
    }
    offset += sprintf(buffer + offset, "   +-------------------- (Acorns/sec)\n");
}

int main(int argc, char **argv) {
    int iterations = 10000000;
    if (argc >= 2) {
        if (argv[1][0] == 'o') {
            for (int i = 0; i < iterations; i++) print_graph_of_chaos_opt();
        } else {
            for (int i = 0; i < iterations; i++) print_graph_of_chaos_orig();
        }
    }
    return 0;
}
