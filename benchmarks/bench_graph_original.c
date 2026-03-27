#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_graph_of_chaos_original() {
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

int main() {
    srand(42);
    for (int i = 0; i < 1000000; i++) {
        print_graph_of_chaos_original();
    }
    return 0;
}
