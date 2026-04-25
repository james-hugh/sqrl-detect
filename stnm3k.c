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

/* --- GLOBAL SETTINGS --- */
static int cocaine_dosage = 5; // Default 5mg
static int squirrels_terminated = 0;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Safely clears memory to ensure sensitive data is not left in RAM.
 * Uses volatile to prevent the compiler from optimizing it away.
 */
void secure_memzero(void *v, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)v;
    while (n--) *p++ = 0;
}

/**
 * A portable, case-insensitive string containment check.
 */
static int str_contains_ignore_case(const char *haystack, const char *needle) {
    if (!haystack || !needle) return 0;
    size_t needle_len = strlen(needle);
    if (needle_len == 0) return 1;

    for (; *haystack; haystack++) {
        if (tolower((unsigned char)*haystack) == tolower((unsigned char)*needle)) {
            const char *h = haystack, *n = needle;
            while (*h && *n && tolower((unsigned char)*h) == tolower((unsigned char)*n)) {
                h++;
                n++;
            }
            if (!*n) return 1;
        }
    }
    return 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    // Refactored to call mkdir directly and check errno to avoid TOCTOU race conditions.
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
 * Optimized to reduce printf calls by using static buffers and precision specifiers.
 */
void print_graph_of_chaos() {
    static const char dots[] = "....................";
    static const char stars[] = "********************";
    static const char exes[] = "XXXXXXXXXXXXXXXXXXXX";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, exes);
        else if (val > 8) printf("%.*s", val, stars);
        else printf("%.*s", val, dots);
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/**
 * Displays the holy scrolls of truth from logs/holy_scrolls.txt.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\n[ERROR] THE HOLY SCROLLS ARE MISSING OR UNREADABLE.\n");
        printf("Perhaps the squirrels have eaten them.\n");
        return;
    }

    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    int lines = 0;
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
        lines++;
    }
    fclose(fp);

    if (lines == 0) {
        printf("(The scrolls are currently blank. A rare moment of peace... or a trap.)\n");
    }
    printf("--- END OF SCROLLS ---\n");
    printf("\nPress Enter to return to the Command Center...");
    // Always check fgets return value to satisfy repo standards.
    if (fgets(line, sizeof(line), stdin) == NULL) return;
}

/**
 * Sets the cocaine dosage for the Polish cows.
 */
void cocaine_dosage_settings() {
    char input[100];
    printf("\n--- COCAINE DOSAGE SETTINGS ---\n");
    printf("Current Dosage: %dmg\n", cocaine_dosage);
    printf("1. 0mg (Safe - Boring, like Windows 2000)\n");
    printf("2. 5mg (Recommended - Optimal Polish Cow performance)\n");
    printf("3. 50mg (CHAOS - I CAN SEE THE FUNGAL NETWORK)\n");
    printf("Choice > ");

    if (fgets(input, sizeof(input), stdin) == NULL) return;

    if (str_contains_ignore_case(input, "3") || str_contains_ignore_case(input, "50mg") || str_contains_ignore_case(input, "CHAOS")) {
        cocaine_dosage = 50;
        printf("!!! CHAOS MODE ACTIVATED !!! THE COWS ARE BREAKING THE SOUND BARRIER.\n");
    } else if (str_contains_ignore_case(input, "2") || str_contains_ignore_case(input, "5mg")) {
        cocaine_dosage = 5;
        printf("Dosage set to 5mg. Standard paranoia levels restored.\n");
    } else if (str_contains_ignore_case(input, "1") || str_contains_ignore_case(input, "0mg")) {
        cocaine_dosage = 0;
        printf("Dosage set to 0mg. The cows are napping.\n");
    } else {
        printf("Invalid dosage. The squirrels find your indecision amusing.\n");
    }

    printf("\nPress Enter to continue...");
    if (fgets(input, sizeof(input), stdin) == NULL) return;
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Returns a random threat message for the paranoid user.
 * Optimized with static const to avoid repeated stack allocation.
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
    sleep(1); // Allow user to read the activation message

    int threat_level = 10;
    for (int i = 0; i < 10; i++) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        printf("SQUIRRELS TERMINATED: %d\n\n", squirrels_terminated);

        // Volatility scales with cocaine dosage
        int volatility = 15 + (cocaine_dosage / 2);
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
                printf("\a"); // Audible bell for high threat
                printf("%s[RAW-ALERT ACTIVE] [TOP-MOST]%s\n", RED, RESET);
            }

            printf("\n%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");

            if (threat_level > 90) {
                squirrels_terminated++;
                printf("%s[SUCCESS] TARGET NEUTRALIZED.%s\n", GRN, RESET);
            }
        }

        printf("\nMonitoring... (%d/10 iterations)\n", i + 1);
        fflush(stdout);
        sleep(1);
    }
    printf("\nMonitoring session complete. Returning to Command Center.\n");
    sleep(2);
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;
    int success = 0;

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

    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    success = 1;
    secure_memzero(command, sizeof(command));
    return success;
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
        printf("2. COCAINE DOSAGE SETTINGS\n");
        printf("3. VIEW HOLY SCROLLS\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (str_contains_ignore_case(command, "ENGAGE DEFENSES") || str_contains_ignore_case(command, "1")) {
            engage_defenses();
        } else if (str_contains_ignore_case(command, "COCAINE") || str_contains_ignore_case(command, "2")) {
            cocaine_dosage_settings();
        } else if (str_contains_ignore_case(command, "SCROLLS") || str_contains_ignore_case(command, "3")) {
            view_holy_scrolls();
        } else if (str_contains_ignore_case(command, "EXIT") || str_contains_ignore_case(command, "4")) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Polish cows look at you with confusion.\n");
        }
    }

    return 0;
}
