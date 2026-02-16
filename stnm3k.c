#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

void log_event(const char *event) {
    // Ensure logs directory exists
    struct stat st = {0};
    if (stat("logs", &st) == -1) {
        mkdir("logs", 0700);
    }

    // Set umask to 0077 to ensure files are created with 0600 permissions
    mode_t old_umask = umask(0077);
    FILE *fp = fopen("logs/holy_scrolls.txt", "a");
    umask(old_umask);

    if (fp == NULL) {
        return;
    }
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline
    } else {
        timestamp = "UNKNOWN TIME";
    }
    fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", timestamp, event);
    fclose(fp);
}

void print_threat_meter(int level) {
    printf("SQUIRREL THREAT METER: [");
    int bars = level / 5;
    for (int i = 0; i < 20; i++) {
        if (i < bars) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf("] %d%%\n", level);
}

void print_graph_of_chaos() {
    printf("GUI GRAPH OF CHAOS:\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        for (int j = 0; j < val; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("   +--------------------\n");
}

const char* get_random_threat() {
    const char* threats[] = {
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
            printf("\n!!! MAXIMUM ALERT MODE !!!\n");
            printf("ALERT: %s\n", threat);
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

        // Strip newline for exact matching
        command[strcspn(command, "\r\n")] = 0;

        // Use exact matching as per security directive to prevent bypasses
        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
            log_event("AUTHENTICATION STEP SUCCESSFUL.");
        } else {
            log_event("AUTHENTICATION FAILURE: INCORRECT PRAYER.");
            printf("Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 1;
        }
    }

    if (prayer_count == 3) {
        log_event("AUTHENTICATION COMPLETE. ACCESS GRANTED.");
        printf("\nAuthentication successful. Welcome, Sentinel.\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        // Strip newline
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "ENGAGE DEFENSES") == 0 || strcmp(command, "1") == 0) {
            engage_defenses();
        } else {
            log_event("SESSION ENDED BY USER.");
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
        }
    } else {
        printf("Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you.\n");
    }

    return 0;
}
