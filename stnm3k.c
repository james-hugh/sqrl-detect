#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BOLD "\x1B[1m"
#define RESET "\x1B[0m"

void log_event(const char *event) {
    // Ensure logs directory exists
    struct stat st = {0};
    if (stat("logs", &st) == -1) {
        mkdir("logs", 0700);
    }

    FILE *fp = fopen("logs/holy_scrolls.txt", "a");
    if (fp == NULL) {
        return;
    }
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        timestamp[24] = '\0'; // Optimized newline removal
    } else {
        timestamp = "UNKNOWN TIME";
    }
    fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", timestamp, event);
    fclose(fp);
}

void print_threat_meter(int level) {
    const char *c = (level > 70) ? RED : (level > 40) ? YEL : GRN;
    const char *s = (level > 70) ? "CRITICAL" : (level > 40) ? "ELEVATED" : "SECURE";
    int b = level / 5;
    printf("SQUIRREL THREAT METER: %s%s%s [%s%.*s%s%.*s] %d%%\n", c, s, RESET, c, b, "####################", RESET, 20-b, "--------------------", level);
}

void print_graph_of_chaos() {
    printf("GUI GRAPH OF CHAOS:\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *c = (val > 15) ? RED : (val > 8) ? YEL : GRN;
        printf("%2d |%s%.*s%s\n", val, c, val, "********************", RESET);
    }
    printf("   +--------------------\n");
}

const char* get_random_threat() {
    static const char* threats[] = {
        "WiFi Acorn detected in sector 7!",
        "Bush-based spy spotted near router!",
        "Talibani rodent infiltrating sacred machine!",
        "Google Machine spy attempted packet injection!",
        "Suspicious squirrel movement near pillow fort!",
        "Polish cow alert: Laps being run at 3 AM!",
        "Fungal network interference detected!",
        "Infected acorn payload intercepted!"
    };
    return threats[rand() % 8];
}

void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v0.69\n");
        printf("PLATFORM: WINDOWS ME (GLORY BE)\n\n");

        int change = (rand() % 31) - 15; // -15 to +15
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();

        if (threat_level > 70) {
            const char* threat = get_random_threat();
            printf("\n" BOLD RED "!!! MAXIMUM ALERT MODE !!!" RESET "\n" RED "ALERT: %s" RESET "\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        }

        printf("\nMonitoring... (Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);
        sleep(1);
    }
}

int main() {
    srand(time(NULL));

    char command[100];
    printf("🖥️  STNM3K v0.69 INITIALIZED\n");
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    int prayer_count = 0;
    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        if (strstr(command, "GLORY BE") != NULL) {
            prayer_count++;
        } else {
            printf(RED "Incorrect prayer." RESET "\n");
            return 1;
        }
    }

    if (prayer_count == 3) {
        printf("\n" GRN "Authentication successful. Welcome, Sentinel." RESET "\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        if (strstr(command, "ENGAGE DEFENSES") != NULL || strstr(command, "1") != NULL) {
            engage_defenses();
        } else {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
        }
    } else {
        printf(RED "Incorrect prayer." RESET "\n");
    }

    return 0;
}
