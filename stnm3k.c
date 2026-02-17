/**
 * @file stnm3k.c
 * @brief SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K)
 * @author James Hungh – Protector of Cows, Vanquisher of WiFi Acorns
 * @version 0.69
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_FILE "logs/holy_scrolls.txt"

/* ANSI Color Codes */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/**
 * @brief Logs an event to the Holy Scrolls.
 * @param event The description of the event to log.
 */
void log_event(const char *event) {
    static int logs_dir_checked = 0;
    if (!logs_dir_checked) {
        struct stat st = {0};
        if (stat("logs", &st) == -1) {
            mkdir("logs", 0700);
        }
        logs_dir_checked = 1;
    }

    mode_t old_mask = umask(0077);
    FILE *fp = fopen(LOG_FILE, "a");
    umask(old_mask);

    if (fp == NULL) {
        return;
    }
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        timestamp[24] = '\0'; // Optimize ctime newline removal
    } else {
        timestamp = "UNKNOWN TIME";
    }

    int cow_hr = 120 + (rand() % 60);
    int paranoia = 80 + (rand() % 20);
    int fort_integrity = 100 - (rand() % 10);

    fprintf(fp, "[%s] [COW_HR:%d] [PARANOIA:%d%%] [FORT:%d%%] COCAINE-COW-LOG: %s\n",
            timestamp, cow_hr, paranoia, fort_integrity, event);
    fclose(fp);
}

void print_threat_meter(int level) {
    const char *color = GRN;
    const char *label = "SECURE";

    if (level > 85) {
        color = RED;
        label = "RED SQUIRREL ALERT";
    } else if (level > 70) {
        color = YEL;
        label = "YELLOW ACORN ALERT";
    }

    printf("SQUIRREL THREAT METER: %s[%.*s%.*s] %d%% %s%s\n",
           color, level / 5, "####################",
           20 - (level / 5), "--------------------", level, label, RESET);
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
 * @brief Displays the last 10 log entries from the Holy Scrolls.
 */
void view_holy_scrolls() {
    printf("\n--- READING THE HOLY SCROLLS ---\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "tail -n 10 %s 2>/dev/null || echo 'The scrolls are empty or missing.'", LOG_FILE);
    if (system(cmd) == -1) {
        printf("Error accessing scrolls.\n");
    }
    printf("\nPress Enter to return to the fort...\n");
    char dummy[10];
    if (fgets(dummy, sizeof(dummy), stdin)) { /* Wait for enter */ }
}

/**
 * @brief Synchronizes the system with Polish cows.
 */
void sync_polish_cows() {
    char input[10];
    printf("\n--- POLISH COW SYNCHRONIZATION PROTOCOL ---\n");
    printf("Initiate Moo-ing Sequence: ");
    if (fgets(input, sizeof(input), stdin) == NULL) return;
    input[strcspn(input, "\r\n")] = 0;

    if (strcmp(input, "MOO") == 0) {
        printf("%s[SUCCESS]%s Cocaine-Cow synchronicity achieved. Log timestamps aligned.\n", GRN, RESET);
        log_event("COW SYNCHRONIZATION ACHIEVED. MOO.");
    } else {
        printf("%s[FAILURE]%s The cows are confused. Synchronization failed.\n", RED, RESET);
    }
    printf("\nPress Enter to return...\n");
    char dummy[10];
    if (fgets(dummy, sizeof(dummy), stdin)) { /* Wait for enter */ }
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
            const char* alert_color = (threat_level > 85) ? RED : YEL;
            const char* alert_msg = (threat_level > 85) ? "RED SQUIRREL ALERT" : "YELLOW ACORN ALERT";

            printf("\n%s!!! %s !!!%s\n", alert_color, alert_msg, RESET);
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
        command[strcspn(command, "\r\n")] = 0;

        log_event("AUTHENTICATION ATTEMPT: PRAYER RECITED.");
        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            log_event("AUTHENTICATION FAILURE: INCORRECT PRAYER.");
            printf("Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 1;
        }
    }

    if (prayer_count == 3) {
        log_event("AUTHENTICATION SUCCESSFUL. ACCESS GRANTED.");
        printf("\nAuthentication successful. Welcome, Sentinel.\n");

        while (1) {
            printf("\n--- PILLOW FORT COMMAND CENTER ---\n");
            printf("1. ENGAGE DEFENSES\n");
            printf("2. READ HOLY SCROLLS\n");
            printf("3. SYNCHRONIZE WITH POLISH COWS\n");
            printf("4. EXIT (COWARDLY)\n");
            printf("> ");
            if (fgets(command, sizeof(command), stdin) == NULL) break;
            command[strcspn(command, "\r\n")] = 0;

            if (strcmp(command, "1") == 0 || strcmp(command, "ENGAGE DEFENSES") == 0) {
                engage_defenses();
            } else if (strcmp(command, "2") == 0) {
                view_holy_scrolls();
            } else if (strcmp(command, "3") == 0) {
                sync_polish_cows();
            } else if (strcmp(command, "4") == 0 || strcmp(command, "EXIT") == 0) {
                log_event("SENTINEL RETREATED COWARDLY.");
                printf("Cowardice detected. Your pillow fort is compromised.\n");
                break;
            } else {
                printf("Invalid command. The squirrels are gaining ground!\n");
            }
        }
    }

    return 0;
}
