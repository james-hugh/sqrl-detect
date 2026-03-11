#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_graph_of_chaos() {
    static const char x_buffer[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_buffer[] = "********************";
    static const char dot_buffer[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *buf = (val > 15) ? x_buffer : (val > 8) ? star_buffer : dot_buffer;
        /* Optimized: Use %.*s to print multiple characters at once, reducing printf calls and syscall overhead. */
        printf("%2d |%.*s\n", val, val, buf);
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

int main() {
    srand(42); // Seed for consistency
    for (int i = 0; i < 1000000; i++) {
        print_graph_of_chaos();
    }
    return 0;
}
