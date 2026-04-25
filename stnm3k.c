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
#include <errno.h>
#include <ctype.h>

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

/* Cocaine Dosage Settings */
#define DOSAGE_SAFE 0
#define DOSAGE_RECOMMENDED 5
#define DOSAGE_CHAOS 50

int g_cocaine_dosage = DOSAGE_RECOMMENDED;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Portable case-insensitive string search.
 */
int str_contains_ignore_case(const char *haystack, const char *needle) {
    if (!haystack || !needle) return 0;
    size_t h_len = strlen(haystack);
    size_t n_len = strlen(needle);
    if (n_len > h_len) return 0;

    for (size_t i = 0; i <= h_len - n_len; i++) {
        size_t j;
        for (j = 0; j < n_len; j++) {
            if (tolower((unsigned char)haystack[i + j]) != tolower((unsigned char)needle[j])) {
                break;
            }
        }
        if (j == n_len) return 1;
    }
    return 0;
}

/**
 * Securely clears a memory buffer to prevent sensitive data leakage.
 * Uses a volatile pointer to ensure the compiler does not optimize it away.
 */
void secure_memzero(void *v, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)v;
    while (n--) *p++ = 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
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
 * Optimized to reduce printf calls by using static buffers.
 */
void print_graph_of_chaos() {
    static const char xs[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char stars[] = "********************";
    static const char dots[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, xs);
        else if (val > 8) printf("%.*s", val, stars);
        else printf("%.*s", val, dots);
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
 */
void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");
    sleep(1);

    int threat_level = 10;
    int squirrels_terminated = 0;

    for (int i = 0; i < 10; i++) {
        // Clear screen
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        printf("SQUIRRELS TERMINATED: %d\n\n", squirrels_terminated);

        int volatility = 15 + (g_cocaine_dosage / 2);
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

            if (threat_level > 85) {
                printf("%s[RAW-ALERT ACTIVE] [TOP-MOST]%s\n", RED, RESET);
                printf("\a"); // Bell
            }

            printf("\n%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
            squirrels_terminated++;
        }

        printf("\nMonitoring... (%d/10)\n", i + 1);
        fflush(stdout);
        sleep(1);
    }
    printf("\nMonitoring session complete. Returning to Command Center.\n");
    char dummy[10];
    printf("Press Enter to continue...");
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) { /* Do nothing */ }
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) {
            secure_memzero(command, sizeof(command));
            return 0;
        }

        if (str_contains_ignore_case(command, "GLORY BE")) {
            prayer_count++;
            printf("%s[√] ACCEPTED%s\n", GRN, RESET);
        } else {
            printf("\n%s[X] INCORRECT PRAYER.%s\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            secure_memzero(command, sizeof(command));
            return 0;
        }
    }

    secure_memzero(command, sizeof(command));
    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    return 1;
}

/**
 * Displays the holy scrolls of truth.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nThe holy scrolls are empty or missing. The squirrels are hiding something.\n");
        return;
    }

    printf("\n--- HOLY SCROLLS OF TRUTH ---\n");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);

    char dummy[10];
    printf("\nPress Enter to return to Command Center...");
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) { /* Do nothing */ }
}

/**
 * Configures the cocaine dosage.
 */
void set_dosage() {
    char command[100];
    printf("\n--- COCAINE DOSAGE SETTINGS ---\n");
    printf("1. SAFE (0mg)\n");
    printf("2. RECOMMENDED (5mg)\n");
    printf("3. CHAOS (50mg)\n");
    printf("> ");
    if (fgets(command, sizeof(command), stdin) == NULL) return;

    if (strstr(command, "1") != NULL) {
        g_cocaine_dosage = DOSAGE_SAFE;
        printf("Dosage set to SAFE. The cows are napping.\n");
    } else if (strstr(command, "2") != NULL) {
        g_cocaine_dosage = DOSAGE_RECOMMENDED;
        printf("Dosage set to RECOMMENDED. Optimal paranoia achieved.\n");
    } else if (strstr(command, "3") != NULL) {
        g_cocaine_dosage = DOSAGE_CHAOS;
        printf("DOSAGE SET TO CHAOS. MAY THE GODS HELP US ALL.\n");
    }

    char dummy[10];
    printf("Press Enter to continue...");
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) { /* Do nothing */ }
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n--- STNM3K COMMAND CENTER ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. COCAINE DOSAGE SETTINGS\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (str_contains_ignore_case(command, "ENGAGE DEFENSES") || strstr(command, "1") != NULL) {
            engage_defenses();
        } else if (str_contains_ignore_case(command, "VIEW HOLY SCROLLS") || strstr(command, "2") != NULL) {
            view_holy_scrolls();
        } else if (str_contains_ignore_case(command, "COCAINE DOSAGE SETTINGS") || strstr(command, "3") != NULL) {
            set_dosage();
        } else if (str_contains_ignore_case(command, "EXIT") || strstr(command, "4") != NULL) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Google Machine is confused.\n");
        }
    }

    return 0;
}
