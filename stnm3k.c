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

/* --- GLOBAL STATE --- */
static int g_cocaine_dosage = 5; // Default 5mg dosage

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Case-insensitive substring search.
 * @param haystack String to search in.
 * @param needle Substring to search for.
 * @return 1 if found, 0 otherwise.
 */
static int str_contains_ignore_case(const char *haystack, const char *needle) {
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
 * Safely clears sensitive memory by preventing compiler optimizations.
 * @param v Pointer to the buffer.
 * @param n Size of the buffer.
 */
static void secure_memzero(void *v, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)v;
    while (n--) *p++ = 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
        perror("Failed to ensure log directory exists");
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
 */
void print_graph_of_chaos() {
    static const char x_buf[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_buf[] = "********************";
    static const char dot_buf[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, x_buf);
        else if (val > 8) printf("%.*s", val, star_buf);
        else printf("%.*s", val, dot_buf);
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Displays the holy scrolls of truth (logs) to the user.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\n%s[!] THE HOLY SCROLLS ARE EMPTY OR MISSING.%s\n", YEL, RESET);
        return;
    }

    printf("\n--- READING HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);

    printf("\nPress Enter to return to Command Center...");
    char dummy[10];
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) return;
}

/**
 * Allows the user to set the simulation volatility.
 */
void set_cocaine_dosage() {
    char input[100];
    printf("\n--- COCAINE DOSAGE SETTINGS ---\n");
    printf("Current dosage: %dmg\n", g_cocaine_dosage);
    printf("1. Safe (0mg)\n");
    printf("2. Recommended (5mg)\n");
    printf("3. CHAOS (50mg)\n");
    printf("> ");

    if (fgets(input, sizeof(input), stdin) == NULL) return;

    if (str_contains_ignore_case(input, "50mg") || str_contains_ignore_case(input, "3") || str_contains_ignore_case(input, "CHAOS")) {
        g_cocaine_dosage = 50;
        printf("DOSAGE SET TO CHAOS (50mg). The cows are vibrate-mooing.\n");
    } else if (str_contains_ignore_case(input, "5mg") || str_contains_ignore_case(input, "2") || str_contains_ignore_case(input, "RECOMMENDED")) {
        g_cocaine_dosage = 5;
        printf("DOSAGE SET TO RECOMMENDED (5mg). Steady vigilance.\n");
    } else if (str_contains_ignore_case(input, "0mg") || str_contains_ignore_case(input, "1") || str_contains_ignore_case(input, "SAFE")) {
        g_cocaine_dosage = 0;
        printf("DOSAGE SET TO SAFE (0mg). Why are you here, coward?\n");
    } else {
        printf("Invalid dosage. Maintaining current level.\n");
    }
}

/**
 * Returns a random threat message for the paranoid user.
 */
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
    int iterations = 0;

    while (iterations < 10) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n\n", PLATFORM);

        int volatility = 15 + (g_cocaine_dosage / 2);
        int change = (rand() % (volatility * 2 + 1)) - volatility;
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("SQUIRRELS TERMINATED: %d\n", squirrels_terminated);
        printf("\n");
        print_graph_of_chaos();

        if (threat_level > 70) {
            const char* threat = get_random_threat();
            const char* alert_name = (threat_level > 85) ? "RED SQUIRREL ALERT" : "YELLOW ACORN ALERT";
            const char* alert_color = (threat_level > 85) ? RED : YEL;

            if (threat_level > 85) {
                printf("%s[RAW-ALERT ACTIVE] [TOP-MOST]%s\a\n", RED, RESET);
                squirrels_terminated += (rand() % 5) + 1;
            }

            printf("\n%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        }

        printf("\nMonitoring... (%d/10) (Ctrl+C to retreat to your pillow fort)\n", iterations + 1);
        fflush(stdout);
        sleep(1);
        iterations++;
    }

    printf("\nMonitoring session complete. Returning to Command Center.\n");
    printf("Press Enter to continue...");
    char dummy[10];
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) return;
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char buffer[100];
    int prayer_count = 0;

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            secure_memzero(buffer, sizeof(buffer));
            return 0;
        }

        if (str_contains_ignore_case(buffer, "GLORY BE")) {
            prayer_count++;
            printf("%s[√] ACCEPTED%s\n", GRN, RESET);
        } else {
            printf("\n%s[X] INCORRECT PRAYER.%s\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            secure_memzero(buffer, sizeof(buffer));
            return 0;
        }
    }

    secure_memzero(buffer, sizeof(buffer));
    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    return 1;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char buffer[100];
    while (1) {
        printf("\n--- COMMAND CENTER ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. COCAINE DOSAGE SETTINGS\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;

        if (str_contains_ignore_case(buffer, "ENGAGE DEFENSES") || str_contains_ignore_case(buffer, "1")) {
            engage_defenses();
        } else if (str_contains_ignore_case(buffer, "VIEW HOLY SCROLLS") || str_contains_ignore_case(buffer, "2")) {
            view_holy_scrolls();
        } else if (str_contains_ignore_case(buffer, "COCAINE DOSAGE") || str_contains_ignore_case(buffer, "3")) {
            set_cocaine_dosage();
        } else if (str_contains_ignore_case(buffer, "EXIT") || str_contains_ignore_case(buffer, "4")) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unrecognized command. The Polish cows are confused.\n");
        }
    }

    return 0;
}
