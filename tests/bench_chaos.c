#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_graph_of_chaos() {
    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
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
    printf("   +-------------------- (Acorns/sec)\n");
}

int main() {
    srand(42); // Seed for consistency
    for (int i = 0; i < 1000000; i++) {
        print_graph_of_chaos();
    }
    return 0;
}
