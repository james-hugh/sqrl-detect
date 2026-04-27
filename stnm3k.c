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

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Case-insensitive substring search.
 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @return 1 if found, 0 otherwise.
 */
static int str_contains_ignore_case(const char *haystack, const char *needle) {
    if (!haystack || !needle) return 0;
    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);
    if (needle_len > haystack_len) return 0;

    for (size_t i = 0; i <= haystack_len - needle_len; i++) {
        size_t j;
        for (j = 0; j < needle_len; j++) {
            if (tolower((unsigned char)haystack[i + j]) != tolower((unsigned char)needle[j])) {
                break;
            }
        }
        if (j == needle_len) return 1;
    }
    return 0;
}

/**
 * Safely clears memory to prevent compiler optimizations from skipping it.
 * @param s Pointer to the memory to clear.
 * @param n Number of bytes to clear.
 */
static void secure_memzero(void *s, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)s;
    while (n--) *p++ = 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
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
 */
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

/* --- CORE ENGINE LOGIC --- */

/**
 * Displays the contents of the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nThe holy scrolls are empty or missing. The cows are silent.\n");
        return;
    }

    printf("\n--- READING THE HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    printf("--- END OF SCROLLS ---\n");
    printf("\nPress Enter to return to the Command Center...");
    char dummy[10];
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) { /* Consume newline */ }
}

static int global_cocaine_dosage = 5; // Default: 5mg

/**
 * Sets the cocaine dosage for the Polish cows.
 */
void set_cocaine_dosage() {
    char input[100];
    printf("\n--- COCAINE DOSAGE SETTINGS ---\n");
    printf("Current Dosage: %dmg\n", global_cocaine_dosage);
    printf("1. Safe (0mg)\n");
    printf("2. Recommended (5mg)\n");
    printf("3. CHAOS (50mg)\n");
    printf("Select dosage (number, name, or exact mg) > ");

    if (fgets(input, sizeof(input), stdin) == NULL) return;

    if (str_contains_ignore_case(input, "50mg") || str_contains_ignore_case(input, "3") || str_contains_ignore_case(input, "CHAOS")) {
        global_cocaine_dosage = 50;
        printf("CHAOS MODE ACTIVATED. The cows are vibrating.\n");
    } else if (str_contains_ignore_case(input, "5mg") || str_contains_ignore_case(input, "2") || str_contains_ignore_case(input, "Recommended")) {
        global_cocaine_dosage = 5;
        printf("Dosage set to Recommended (5mg). Steady vigilance.\n");
    } else if (str_contains_ignore_case(input, "0mg") || str_contains_ignore_case(input, "1") || str_contains_ignore_case(input, "Safe")) {
        global_cocaine_dosage = 0;
        printf("Dosage set to Safe (0mg). The cows are falling asleep.\n");
    } else {
        printf("Invalid dosage. Maintaining current levels.\n");
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
        printf("PLATFORM: %s\n", PLATFORM);
        printf("SQUIRRELS TERMINATED: %d\n\n", squirrels_terminated);

        // Volatility depends on cocaine dosage
        int volatility = 15 + (global_cocaine_dosage / 2);
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
                squirrels_terminated++;
                printf("%s[SUCCESS] TARGET NEUTRALIZED.%s\n", GRN, RESET);
            }
        }

        printf("\nMonitoring cycle %d/10... (Retreating to pillow fort soon)\n", iterations + 1);
        fflush(stdout);
        sleep(1);
        iterations++;
    }
    printf("\nMonitoring session complete. Returning to Command Center.\n");
    sleep(1);
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
    while (1) {
        printf("\n--- STNM3K COMMAND CENTER ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. COCAINE DOSAGE SETTINGS\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (str_contains_ignore_case(command, "ENGAGE DEFENSES") || str_contains_ignore_case(command, "1")) {
            engage_defenses();
        } else if (str_contains_ignore_case(command, "VIEW HOLY SCROLLS") || str_contains_ignore_case(command, "2")) {
            view_holy_scrolls();
        } else if (str_contains_ignore_case(command, "COCAINE DOSAGE SETTINGS") || str_contains_ignore_case(command, "3")) {
            set_cocaine_dosage();
        } else if (str_contains_ignore_case(command, "EXIT") || str_contains_ignore_case(command, "4")) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Polish cows look at you with confusion.\n");
        }
    }

    return 0;
}
