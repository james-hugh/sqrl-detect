#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>

#include <sys/stat.h>
#include <sys/types.h>

#define VERSION "0.69"
#define PLATFORM "WINDOWS ME ONLY (GLORY BE)"
#define LOG_FILE "logs/holy_scrolls.txt"

// ANSI colors
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define RESET "\x1B[0m"

/**
 * @brief Logs an event with thematic metadata.
 * @param event The event description.
 */
void log_event(const char *event) {
    umask(0077); // Fail Securely: Owner-only permissions
    struct stat st = {0};
    if (stat("logs", &st) == -1) {
        mkdir("logs", 0700);
    }

    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) return;

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        timestamp[24] = '\0'; // Optimized newline removal
    } else {
        timestamp = "UNKNOWN TIME";
    }

    // Randomized thematic metadata
    int heart_rate = 120 + (rand() % 60);
    int paranoia = 80 + (rand() % 21);
    int integrity = 90 + (rand() % 11);

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s | COW_HR: %dbpm | PARANOIA: %d%% | FORT: %d%%\n",
            timestamp, event, heart_rate, paranoia, integrity);
    fclose(fp);
}

void print_threat_meter(int level) {
    printf("SQUIRREL THREAT METER: [");
    int bars = level / 5;
    const char* color = (level > 85) ? RED : (level > 70) ? YEL : GRN;
    printf("%s", color);
    for (int i = 0; i < 20; i++) {
        if (i < bars) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf(RESET "] %d%% ", level);
    if (level > 85) printf(RED "(CRITICAL)" RESET);
    else if (level > 70) printf(YEL "(WARNING)" RESET);
    else printf(GRN "(SECURE)" RESET);
    printf("\n");
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

/**
 * @brief Displays the last 10 entries of the Holy Scrolls.
 */
void view_holy_scrolls() {
    printf("\n--- RECITING THE HOLY SCROLLS (LAST 10 ENTRIES) ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels are winning.\n");
        return;
    }

    char lines[10][256];
    int count = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp)) {
        strncpy(lines[count % 10], buffer, 256);
        count++;
    }
    fclose(fp);

    int start = (count > 10) ? (count % 10) : 0;
    int total = (count > 10) ? 10 : count;

    for (int i = 0; i < total; i++) {
        printf("%s", lines[(start + i) % 10]);
    }
    printf("--- END OF SCROLLS ---\n");
}

/**
 * @brief Synchronizes with Polish cows using the MOO protocol.
 */
void sync_with_cows() {
    char input[100];
    printf("\n--- POLISH COW SYNCHRONIZATION PROTOCOL ---\n");
    printf("Enter cow resonance frequency (MOO): ");
    if (fgets(input, sizeof(input), stdin) == NULL) return;
    input[strcspn(input, "\r\n")] = 0;

    if (strcmp(input, "MOO") == 0) {
        printf(GRN "SYNCHRONIZATION COMPLETE. 5mg cocaine equivalent synergy achieved.\n" RESET);
        log_event("COW SYNCHRONIZATION SUCCESSFUL. MOO.");
    } else {
        printf(RED "SYNCHRONIZATION FAILED. The cows are confused.\n" RESET);
        log_event("COW SYNCHRONIZATION FAILED.");
    }
}

void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n\n", PLATFORM);

        int change = (rand() % 31) - 15; // -15 to +15
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();

        if (threat_level > 85) {
            const char* threat = get_random_threat();
            printf("\n" RED "!!! RED SQUIRREL ALERT (CRITICAL) !!!\n" RESET);
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        } else if (threat_level > 70) {
            const char* threat = get_random_threat();
            printf("\n" YEL "!!! YELLOW ACORN ALERT (WARNING) !!!\n" RESET);
            printf("ALERT: %s\n", threat);
            log_event(threat);
        }

        printf("\nMonitoring... (Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);
        sleep(1);
    }
}

int main() {
    srand(time(NULL));

    char command[100];
    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    int prayer_count = 0;
    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        command[strcspn(command, "\r\n")] = 0; // Strip newline

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
            log_event("Authentication prayer step successful.");
        } else {
            printf("Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("FAILED AUTHENTICATION: Incorrect prayer.");
            return 1;
        }
    }

    log_event("AUTHENTICATION SUCCESSFUL. PILLOW FORT COMMAND CENTER INITIALIZED.");
    printf("\nAuthentication successful. Welcome, Sentinel.\n");

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH POLISH COWS\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcmp(command, "3") == 0 || strcasecmp(command, "SYNCHRONIZE WITH POLISH COWS") == 0) {
            sync_with_cows();
        } else {
            printf("Unknown command. The Google Machine is recording your confusion.\n");
        }
    }

    return 0;
}
