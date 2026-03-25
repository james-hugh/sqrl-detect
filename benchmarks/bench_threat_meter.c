#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#define METER_WIDTH 20
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

void original_print_threat_meter(int level) {
    const char *color = GRN;
    const char *status = "SECURE";
    static const char bars_fill[] = "####################";
    static const char bars_empty[] = "--------------------";

    if (level > 85) {
        color = RED;
        status = "CRITICAL";
    } else if (level > 70) {
        color = YEL;
        status = "CAUTION";
    }

    int bars = (level * METER_WIDTH) / 100;
    printf("SQUIRREL THREAT METER: %s[%s] [%.*s%.*s] %d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

void optimized_print_threat_meter(int level) {
    static const char *colors[] = {GRN, YEL, RED};
    static const char *statuses[] = {"SECURE ", "CAUTION ", "CRITICAL"};
    static const char bars_fill[] = "####################";
    static const char bars_empty[] = "--------------------";

    int idx = (level > 85) ? 2 : (level > 70) ? 1 : 0;
    int bars = (level * METER_WIDTH) / 100;

    printf("SQUIRREL THREAT METER: %s[%s] [%.*s%.*s] %d%%%s\n",
           colors[idx], statuses[idx], bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

int main() {
    int iterations = 1000000;
    int level = 75;

    FILE *devnull = fopen("/dev/null", "w");
    if (!devnull) return 1;

    // Save stdout
    int stdout_fd = dup(1);
    dup2(fileno(devnull), 1);

    double start = get_time();
    for (int i = 0; i < iterations; i++) {
        original_print_threat_meter(level);
    }
    double end = get_time();
    double original_time = end - start;

    start = get_time();
    for (int i = 0; i < iterations; i++) {
        optimized_print_threat_meter(level);
    }
    end = get_time();
    double optimized_time = end - start;

    // Restore stdout
    dup2(stdout_fd, 1);
    close(stdout_fd);
    fclose(devnull);

    printf("Original time:  %f s\n", original_time);
    printf("Optimized time: %f s\n", optimized_time);
    printf("Improvement:    %.2f%%\n", (original_time - optimized_time) / original_time * 100.0);

    return 0;
}
