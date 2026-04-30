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
 * Case-insensitive version of strstr.
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
 * Securely zeros memory to prevent sensitive data from lingering.
 */
static void secure_memzero(void *ptr, size_t len) {
    volatile unsigned char *p = ptr;
    while (len--) *p++ = 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    printf("%s[INITIALIZING] STNM3K...%s\n", YEL, RESET);
    sleep(1);
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
 * Renders the squirrel threat meter.
 * @param level Threat level from 0 to 100.
 */
void print_threat_meter(int level) {
    const char *color = GRN;
    const char *status = "[SECURE]";
    static const char bars_fill[] = "####################";
    static const char bars_empty[] = "--------------------";

    if (level > 85) {
        color = RED;
        status = "[CRITICAL]";
    } else if (level > 70) {
        color = YEL;
        status = "[CAUTION]";
    }

    int bars = (level * METER_WIDTH) / 100;
    printf("SQUIRREL THREAT METER: %s%s [%.*s%.*s] %d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char x_line[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char s_line[] = "********************";
    static const char d_line[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 0; i < GRAPH_HEIGHT; i++) {
        int val = rand() % MAX_GRAPH_VAL;
        printf("%2d |", val);
        if (val > 15) {
            printf("%.*s", val, x_line);
        } else if (val > 8) {
            printf("%.*s", val, s_line);
        } else {
            printf("%.*s", val, d_line);
        }
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/**
 * Renders the holy header.
 */
void print_header() {
    printf("%s", GRN);
    printf("  _____ _______ _   _ __  __ ____  _  __\n");
    printf(" / ____|__   __| \\ | |  \\/  |___ \\| |/ /\n");
    printf("| (___    | |  |  \\| | \\  / | __) | ' / \n");
    printf(" \\___ \\   | |  | . ` | |\\/| ||__ <|  <  \n");
    printf(" ____) |  | |  | |\\  | |  | |___) | . \\ \n");
    printf("|_____/   |_|  |_| \\_|_|  |_|____/|_|\\_\\\n");
    printf("%s", RESET);
    printf("   SQUIRREL TERMINATOR NETWORK MONITOR\n\n");
}

/* --- CORE ENGINE LOGIC --- */

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

        printf("VERSION: %s | PLATFORM: %s\n\n", VERSION, PLATFORM);

        int volatility = raw_alert_enabled ? 50 : THREAT_MAX_CHANGE * 2;
        int change = (rand() % (volatility + 1)) - (volatility / 2);
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
 * Displays the holy scrolls of truth.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty or missing. The squirrels may have eaten them.\n");
        return;
    }

    char line[256];
    printf("\n--- HOLY SCROLLS OF TRUTH ---\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    printf("\nPress Enter to return to the menu...");
    char dummy[10];
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) {
        /* Silence warning, user likely closed stdin */
    }
}

/**
 * Broadcasts a fungal message to the logs.
 */
void broadcast_fungal_message() {
    char message[100];
    printf("\nEnter message to broadcast via Fungal Network: ");
    if (fgets(message, sizeof(message), stdin) == NULL) return;
    message[strcspn(message, "\n")] = 0;

    if (strlen(message) > 0) {
        log_event(message);
        printf("%s[SUCCESS]%s Fungal message broadcasted.\n", GRN, RESET);
    } else {
        printf("Empty message. The mycelium is confused.\n");
    }
    sleep(1);
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf(CLEAR_SCREEN);
    print_header();
    printf("INITIALIZED. STATUS: [SECURE]\n");
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        if (str_contains_ignore_case(command, "GLORY BE")) {
            prayer_count++;
        } else {
            printf("\n%s[INCORRECT PRAYER]%s\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            printf("Press Enter to exit...");
            char dummy[10];
            if (fgets(dummy, sizeof(dummy), stdin) == NULL) {
                /* Silence warning */
            }
            secure_memzero(command, sizeof(command));
            return 0;
        }
    }

    secure_memzero(command, sizeof(command));
    printf("\n%s[ACCEPTED]%s Welcome, Sentinel.\n", GRN, RESET);
    sleep(1);
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
        printf("MAIN COMMAND INTERFACE\n");
        printf("----------------------\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. READ HOLY SCROLLS (LOGS)\n");
        printf("3. BROADCAST FUNGAL MESSAGE\n");
        printf("4. TOGGLE RAW-ALERT MODE (Status: %s)\n", raw_alert_enabled ? "ON" : "OFF");
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
            printf("RAW-ALERT MODE: %s\n", raw_alert_enabled ? "ACTIVATED" : "DEACTIVATED");
            sleep(1);
        } else if (str_contains_ignore_case(command, "5") || str_contains_ignore_case(command, "EXIT")) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        }
    }

    return 0;
}
