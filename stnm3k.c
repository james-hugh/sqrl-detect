/*
 * SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K)
 * Version: 0.69
 * Platform: WINDOWS ME ONLY (GLORY BE)
 *
 * "Watching your network with the vigilance of Polish cows on 3 AM cocaine laps."
 *
 * This software is a simulated security tool designed to monitor 'threats'
 * using ASCII-based visualizations and random event generation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>

/* --- CONFIGURATION MACROS --- */
#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_DIR "logs"
#define LOG_FILE "logs/holy_scrolls.txt"
#define METER_WIDTH 20

/* ANSI Colors */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

/* --- UTILITY FUNCTIONS --- */

/**
 * Robustly clears a memory buffer.
 * Uses a volatile pointer to prevent compiler optimization.
 */
static void secure_memzero(void *s, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)s;
    while (n--) *p++ = 0;
}

/**
 * Checks if a string contains another string, case-insensitive.
 */
static int str_contains_ignore_case(const char *haystack, const char *needle) {
    if (!haystack || !needle) return 0;
    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len > haystack_len) return 0;

    for (size_t i = 0; i <= haystack_len - needle_len; i++) {
        int match = 1;
        for (size_t j = 0; j < needle_len; j++) {
            if (tolower((unsigned char)haystack[i + j]) != tolower((unsigned char)needle[j])) {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    // Direct mkdir check to avoid TOCTOU race condition
    if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
        perror("Failed to create log directory");
    }
}

/**
 * Logs a message to the holy scrolls of truth.
 * @param event The event message to log.
 */
void log_event(const char *event) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Failed to open holy scrolls for writing");
        return;
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        timestamp[strlen(timestamp) - 1] = '\0'; // Remove trailing newline
    } else {
        timestamp = "UNKNOWN TIME";
    }

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", timestamp, event);
    fclose(fp);
}

/* --- VISUALIZATION ENGINE --- */

/**
 * Renders the squirrel threat meter.
 * @param level Threat level from 0 to 100.
 */
void print_threat_meter(int level) {
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

/**
 * Renders the GUI graph of chaos.
 * Optimized with static buffers to reduce printf calls.
 */
void print_graph_of_chaos() {
    static const char x_buff[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_buff[] = "********************";
    static const char dot_buff[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, x_buff);
        else if (val > 8) printf("%.*s", val, star_buff);
        else printf("%.*s", val, dot_buff);
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Returns a random threat message for the paranoid user.
 */
const char* get_random_threat() {
    static const char* const threats[] = {
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
 * Enters the main monitoring loop.
 * @param dosage Cocaine dosage affecting threat volatility.
 */
void engage_defenses(int dosage) {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");
    sleep(1);

    int threat_level = 10;
    int iterations = 0;
    static int squirrels_terminated = 0;

    while (iterations < 10) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        printf("SQUIRRELS TERMINATED: %d\n\n", squirrels_terminated);

        int volatility = 15 + (dosage / 2);
        int change = (rand() % (volatility * 2 + 1)) - volatility;
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();

        if (threat_level > 70) {
            const char* threat = get_random_threat();
            const char* alert_name = (threat_level > 85) ? "RED SQUIRREL ALERT" : "YELLOW ACORN ALERT";
            const char* alert_color = (threat_level > 85) ? RED : YEL;

            printf("\n%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");

            if (threat_level > 90) {
                squirrels_terminated += (rand() % 5) + 1;
            }
        }

        printf("\nMonitoring... (Iteration %d/10)\n", iterations + 1);
        fflush(stdout);
        sleep(1);
        iterations++;
    }

    printf("\nMonitoring session complete. Returning to Command Center.\n");
    printf("Press Enter to continue...");
    char dummy[10];
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) { /* Ignore */ }
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;
    int authenticated = 0;

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) {
            goto cleanup;
        }

        if (str_contains_ignore_case(command, "GLORY BE")) {
            prayer_count++;
        } else {
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            goto cleanup;
        }
    }

    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    authenticated = 1;

cleanup:
    secure_memzero(command, sizeof(command));
    return authenticated;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    int cocaine_dosage = 5; // Default: Recommended (5mg)

    while (1) {
        printf("\n--- STNM3K COMMAND CENTER ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. COCAINE DOSAGE SETTINGS (Current: %dmg)\n", cocaine_dosage);
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (str_contains_ignore_case(command, "ENGAGE DEFENSES") || str_contains_ignore_case(command, "1")) {
            engage_defenses(cocaine_dosage);
        } else if (str_contains_ignore_case(command, "VIEW HOLY SCROLLS") || str_contains_ignore_case(command, "2")) {
            FILE *fp = fopen(LOG_FILE, "r");
            if (fp) {
                char line[256];
                printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
                while (fgets(line, sizeof(line), fp)) printf("%s", line);
                fclose(fp);
                printf("--- END OF SCROLLS ---\n");
            } else {
                printf("\n[ERROR] The scrolls are missing! Perhaps a squirrel ate them?\n");
            }
            printf("\nPress Enter to return to Command Center...");
            char dummy[10];
            if (fgets(dummy, sizeof(dummy), stdin) == NULL) { /* Ignore */ }
        } else if (str_contains_ignore_case(command, "COCAINE DOSAGE") || str_contains_ignore_case(command, "3")) {
            printf("\n--- COCAINE DOSAGE SETTINGS ---\n");
            printf("1. Safe (0mg) - For the faint of heart.\n");
            printf("2. Recommended (5mg) - Polish cow standard.\n");
            printf("3. CHAOS (50mg) - GLORY BE!\n");
            printf("> ");
            if (fgets(command, sizeof(command), stdin) != NULL) {
                if (str_contains_ignore_case(command, "50mg") || str_contains_ignore_case(command, "3") || str_contains_ignore_case(command, "CHAOS")) {
                    cocaine_dosage = 50;
                } else if (str_contains_ignore_case(command, "5mg") || str_contains_ignore_case(command, "2") || str_contains_ignore_case(command, "Recommended")) {
                    cocaine_dosage = 5;
                } else if (str_contains_ignore_case(command, "0mg") || str_contains_ignore_case(command, "1") || str_contains_ignore_case(command, "Safe")) {
                    cocaine_dosage = 0;
                }
            }
        } else if (str_contains_ignore_case(command, "EXIT") || str_contains_ignore_case(command, "4")) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        }
    }

    return 0;
}
