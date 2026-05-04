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
#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_DIR "logs"
#define LOG_FILE "logs/holy_scrolls.txt"
#define METER_WIDTH 20
#define CLEAR_SCREEN "\033[H\033[J"

/* ANSI Colors */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

/* --- GLOBAL STATE --- */
int raw_alert_enabled = 0;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Securely wipes memory.
 */
void secure_memzero(void *s, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)s;
    while (n--) *p++ = 0;
}

/**
 * Portable case-insensitive substring search.
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
 * Renders the ASCII header and system information.
 */
void print_header() {
    printf(YEL "------------------------------------------------------------\n" RESET);
    printf(GRN "  ____ _____ _   _ __  __ _____ _  __\n" RESET);
    printf(GRN " / ___|_   _| \\ | |  \\/  |___ /| |/ /\n" RESET);
    printf(GRN " \\___ \\ | | |  \\| | |\\/| | |_ \\| ' / \n" RESET);
    printf(GRN "  ___) || | | |\\  | |  | |___) | . \\ \n" RESET);
    printf(GRN " |____/ |_| |_| \\_|_|  |_|____/|_|\\_\\\n" RESET);
    printf(YEL "------------------------------------------------------------\n" RESET);
    printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 v%s\n", VERSION);
    printf("PLATFORM: %s\n", PLATFORM);
    printf("STATUS:   " GRN "[SECURE]" RESET " Pillow fort integrity at 100%%\n");
    printf(YEL "------------------------------------------------------------\n\n" RESET);
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
 * Displays the content of the holy scrolls.
 */
void view_holy_scrolls() {
    printf(CLEAR_SCREEN);
    printf("--- READING HOLY SCROLLS OF TRUTH ---\n\n");

    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. No truths have been recorded yet.\n");
    } else {
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }

    printf("\n--- END OF SCROLLS ---\n");
    printf("Press Enter to return to the command center...");
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin)) { /* consume input */ }
}

/**
 * Broadcasts a custom fungal message and logs it.
 */
void broadcast_fungal_message() {
    char message[256];
    printf("\nEnter your fungal message to broadcast to the pillow fort:\n> ");
    if (fgets(message, sizeof(message), stdin) != NULL) {
        message[strcspn(message, "\n")] = 0; // Remove newline

        printf("\n" YEL "[INITIALIZING] " RESET "Broadcasting via fungal mycelium...\n");
        sleep(1);
        log_event(message);
        printf(GRN "[SUCCESS] " RESET "Message delivered to the pillow fort.\n");

        // Securely wipe message from memory
        secure_memzero(message, sizeof(message));
    }

    printf("\nPress Enter to continue...");
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin)) { /* consume input */ }
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
    printf("\n" YEL "[INITIALIZING] " RESET "--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    sleep(1);
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        // Clear screen
        printf(CLEAR_SCREEN);
        print_header();

        int volatility = raw_alert_enabled ? 51 : 31;
        int offset = raw_alert_enabled ? 25 : 15;
        int change = (rand() % volatility) - offset;

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
    int authenticated = 0;

    printf(YEL "[INITIALIZING] " RESET "STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) goto cleanup;

        // Truncate newline
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\n" RED "[INCORRECT]" RESET " PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            goto cleanup;
        }
    }

    printf("\n" GRN "[SUCCESS]" RESET " Authentication successful. Welcome, Sentinel.\n");
    authenticated = 1;
    sleep(1);

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
        printf(CLEAR_SCREEN);
        print_header();

        printf("COMMAND CENTER MENU:\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. READ HOLY SCROLLS (LOGS)\n");
        printf("3. BROADCAST FUNGAL MESSAGE\n");
        printf("4. TOGGLE RAW-ALERT MODE (Current: %s)\n", raw_alert_enabled ? RED "ENABLED" RESET : GRN "DISABLED" RESET);
        printf("5. EXIT (COWARDLY)\n");
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (str_contains_ignore_case(command, "ENGAGE") || (command[0] == '1' && (command[1] == '\n' || command[1] == '\r' || command[1] == '\0'))) {
            engage_defenses();
        } else if (str_contains_ignore_case(command, "READ") || (command[0] == '2' && (command[1] == '\n' || command[1] == '\r' || command[1] == '\0'))) {
            view_holy_scrolls();
        } else if (str_contains_ignore_case(command, "BROADCAST") || (command[0] == '3' && (command[1] == '\n' || command[1] == '\r' || command[1] == '\0'))) {
            broadcast_fungal_message();
        } else if (str_contains_ignore_case(command, "TOGGLE") || (command[0] == '4' && (command[1] == '\n' || command[1] == '\r' || command[1] == '\0'))) {
            raw_alert_enabled = !raw_alert_enabled;
            printf("\nRAW-ALERT MODE %s.\n", raw_alert_enabled ? "ENABLED" : "DISABLED");
            sleep(1);
        } else if (str_contains_ignore_case(command, "EXIT") || (command[0] == '5' && (command[1] == '\n' || command[1] == '\r' || command[1] == '\0'))) {
            printf("\n" RED "[EXITED]" RESET " Cowardice detected. The squirrels have already won.\n");
            break;
        } else {
            printf("\nUnknown command. The Polish cows are confused.\n");
            sleep(1);
        }

        secure_memzero(command, sizeof(command));
    }

    return 0;
}
