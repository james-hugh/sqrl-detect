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

#include <sys/stat.h>
#include <sys/types.h>

/* --- CONFIGURATION MACROS --- */
#define VERSION           "0.69"
#define PLATFORM          "WINDOWS ME (GLORY BE)"
#define LOG_DIR           "logs"
#define LOG_FILE          "logs/holy_scrolls.txt"
#define METER_WIDTH       20
#define GRAPH_HEIGHT      5
#define MAX_GRAPH_VAL     20
#define THREAT_MAX_CHANGE 15
#define CLEAR_SCREEN      "\033[H\033[J"

/* ANSI Colors */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

/* --- GLOBAL STATE --- */
static int raw_alert_enabled = 0;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Securely wipes memory by using a volatile pointer to prevent compiler optimization.
 * @param p Pointer to the memory to wipe.
 * @param len Length of the memory in bytes.
 */
static void secure_memzero(void *p, size_t len) {
    volatile unsigned char *ptr = (volatile unsigned char *)p;
    while (len--) {
        *ptr++ = 0;
    }
}

/**
 * Portable case-insensitive substring search.
 * @param haystack String to search within.
 * @param needle Substring to search for.
 * @return 1 if found, 0 otherwise.
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

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        mkdir(LOG_DIR, 0700);
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
 * Renders the decorative system header.
 */
static void print_header() {
    printf("%s", GRN);
    printf("  ______________________________________________________  \n");
    printf(" /                                                      \\ \n");
    printf(" |  %sSQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K)%s   | \n", YEL, GRN);
    printf(" |  Version: %-10s Platform: %-22s | \n", VERSION, PLATFORM);
    printf(" \\______________________________________________________/ \n");
    printf("%s\n", RESET);
}

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
 * Optimized to reduce printf calls via static character buffers.
 */
void print_graph_of_chaos() {
    static const char chars[] = "....................********************XXXXXXXXXXXXXXXXXXXX";
    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");

    for (int i = GRAPH_HEIGHT; i > 0; i--) {
        int val = rand() % MAX_GRAPH_VAL;
        int offset = 0;
        if (val > 15) offset = 40;
        else if (val > 8) offset = 20;

        printf("%2d |%.*s\n", val, val, chars + offset);
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Displays the contents of the holy scrolls (log file).
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\n[ERROR] The holy scrolls have not been written yet.\n");
        return;
    }

    char line[256];
    printf("\n--- READING HOLY SCROLLS OF TRUTH ---\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);

    printf("\nPress Enter to return to your pillow fort...");
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
}

/**
 * Broadcasts a custom fungal message to the logs.
 */
void broadcast_fungal_message() {
    char message[128];
    printf("\nEnter message for the Fungal Network: ");
    if (fgets(message, sizeof(message), stdin) == NULL) return;

    // Remove trailing newline
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') message[len - 1] = '\0';

    if (strlen(message) > 0) {
        log_event(message);
        printf("\n%s[SUCCESS]%s Message broadcast via fungal network.\n", GRN, RESET);
    } else {
        printf("\n[CANCELLED] Silence is golden, but the fungus is hungry.\n");
    }
    sleep(1);
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

    int threat_level = 10;
    while (1) {
        printf(CLEAR_SCREEN);
        print_header();

        int range = raw_alert_enabled ? 51 : (THREAT_MAX_CHANGE * 2 + 1);
        int change = (rand() % range) - (range / 2);

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
        }

        printf("\nMonitoring... (Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);
        sleep(1);
    }
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf("%s[INITIALIZING]%s STNM3K v%s\n", YEL, RESET, VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) {
            secure_memzero(command, sizeof(command));
            return 0;
        }

        if (str_contains_ignore_case(command, "GLORY BE")) {
            prayer_count++;
            printf("%s[ACCEPTED]%s\n", GRN, RESET);
        } else {
            printf("\n%s[INCORRECT]%s PRAYER.\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            secure_memzero(command, sizeof(command));
            return 0;
        }
    }

    secure_memzero(command, sizeof(command));
    printf("\n%s[SUCCESS]%s Authentication successful. Welcome, Sentinel.\n", GRN, RESET);
    return 1;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf(CLEAR_SCREEN);
        print_header();

        printf("1. ENGAGE DEFENSES\n");
        printf("2. READ HOLY SCROLLS (LOGS)\n");
        printf("3. BROADCAST FUNGAL MESSAGE\n");
        printf("4. TOGGLE RAW-ALERT MODE (Currently: %s)\n", raw_alert_enabled ? "ON" : "OFF");
        printf("5. EXIT (COWARDLY)\n");
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (str_contains_ignore_case(command, "1") || str_contains_ignore_case(command, "ENGAGE")) {
            engage_defenses();
        } else if (str_contains_ignore_case(command, "2") || str_contains_ignore_case(command, "READ")) {
            view_holy_scrolls();
        } else if (str_contains_ignore_case(command, "3") || str_contains_ignore_case(command, "BROADCAST")) {
            broadcast_fungal_message();
        } else if (str_contains_ignore_case(command, "4") || str_contains_ignore_case(command, "TOGGLE")) {
            raw_alert_enabled = !raw_alert_enabled;
            printf("\nRAW-ALERT MODE: %s\n", raw_alert_enabled ? "ENABLED" : "DISABLED");
            sleep(1);
        } else if (str_contains_ignore_case(command, "5") || str_contains_ignore_case(command, "EXIT")) {
            printf("\n%s[EXITED]%s Cowardice detected. Your pillow fort is compromised.\n", RED, RESET);
            break;
        }

        secure_memzero(command, sizeof(command));
    }

    return 0;
}
