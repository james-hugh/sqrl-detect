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
#define METER_WIDTH  20
#define CLEAR_SCREEN "\033[H\033[J"
#define THREAT_MAX_CHANGE 15

/* ANSI Colors */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

/* --- GLOBALS --- */
int raw_alert_enabled = 0;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Portable case-insensitive string containment check.
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
 * Securely wipes memory to prevent sensitive data leakage.
 */
void secure_memzero(void *s, size_t n) {
    volatile char *p = (volatile char *)s;
    while (n--) *p++ = 0;
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
 * Prints the decorative system header.
 */
void print_header() {
    printf("%s", CLEAR_SCREEN);
    printf("%s", GRN);
    printf("  ______________________________________________________  \n");
    printf(" /                                                      \\ \n");
    printf(" |    %sSQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K)%s    | \n", YEL, GRN);
    printf(" |                 %sVersion: %-6s%s                     | \n", RESET, VERSION, GRN);
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
 */
void print_graph_of_chaos() {
    static char buf[1024];
    int pos = 0;

    pos += sprintf(buf + pos, "GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 21;
        pos += sprintf(buf + pos, "%2d |", val);
        for (int j = 0; j < val; j++) {
            if (val > 15) buf[pos++] = 'X';
            else if (val > 8) buf[pos++] = '*';
            else buf[pos++] = '.';
        }
        buf[pos++] = '\n';
    }
    pos += sprintf(buf + pos, "   +-------------------- (Acorns/sec)\n");
    buf[pos] = '\0';
    printf("%s", buf);
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
    printf("\n--- %sENGAGING DEFENSES%s ---\n", GRN, RESET);
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");
    sleep(1);

    int threat_level = 10;
    while (1) {
        print_header();
        printf("PLATFORM: %s | RAW-ALERT: %s\n\n", PLATFORM, raw_alert_enabled ? "ENABLED" : "DISABLED");

        int max_change = raw_alert_enabled ? (THREAT_MAX_CHANGE * 2) : THREAT_MAX_CHANGE;
        int change = (rand() % (max_change * 2 + 1)) - max_change;
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

    print_header();
    printf("%s[INITIALIZING]%s STNM3K v%s\n", YEL, RESET, VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) goto cleanup;

        // Trim trailing newline
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\n%s[INCORRECT]%s PRAYER.\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            goto cleanup;
        }
    }

    printf("\n%s[SUCCESS]%s Authentication successful. Welcome, Sentinel.\n", GRN, RESET);
    authenticated = 1;

cleanup:
    secure_memzero(command, sizeof(command));
    return authenticated;
}

/**
 * Displays the holy scrolls (logs) to the user.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\n%s[ERROR]%s The holy scrolls are missing or unreadable.\n", RED, RESET);
        return;
    }

    print_header();
    printf("--- THE HOLY SCROLLS OF TRUTH ---\n\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);

    printf("\nPress Enter to return to the command center...");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        /* Ignore EOF */
    }
}

/**
 * Broadcasts a custom fungal message.
 */
void broadcast_fungal_message() {
    char message[256];
    print_header();
    printf("--- BROADCAST FUNGAL MESSAGE ---\n");
    printf("Enter your message for the mushroom network:\n> ");
    if (fgets(message, sizeof(message), stdin) == NULL) return;

    message[strcspn(message, "\r\n")] = 0;
    if (strlen(message) > 0) {
        log_event(message);
        printf("\n%s[SUCCESS]%s Message pulsed through the mycelium.\n", GRN, RESET);
    } else {
        printf("\n%s[CANCELLED]%s Silence is also a message, but not one I can log.\n", YEL, RESET);
    }
    sleep(1);
    secure_memzero(message, sizeof(message));
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        printf("\n%s[EXITED]%s System locked.\n", RED, RESET);
        return 1;
    }

    char command[100];
    while (1) {
        print_header();
        printf("SQUIRREL TERMINATOR COMMAND CENTER\n\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. READ HOLY SCROLLS (LOGS)\n");
        printf("3. BROADCAST FUNGAL MESSAGE\n");
        printf("4. TOGGLE RAW-ALERT MODE (CURRENT: %s)\n", raw_alert_enabled ? "ON" : "OFF");
        printf("5. EXIT (COWARDLY)\n");
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "1") == 0 || str_contains_ignore_case(command, "ENGAGE")) {
            engage_defenses();
        } else if (strcmp(command, "2") == 0 || str_contains_ignore_case(command, "READ")) {
            view_holy_scrolls();
        } else if (strcmp(command, "3") == 0 || str_contains_ignore_case(command, "BROADCAST")) {
            broadcast_fungal_message();
        } else if (strcmp(command, "4") == 0 || str_contains_ignore_case(command, "TOGGLE") || str_contains_ignore_case(command, "RAW")) {
            raw_alert_enabled = !raw_alert_enabled;
            printf("\nRAW-ALERT MODE: %s\n", raw_alert_enabled ? "ENABLED" : "DISABLED");
            sleep(1);
        } else if (strcmp(command, "5") == 0 || str_contains_ignore_case(command, "EXIT") || str_contains_ignore_case(command, "COWARDLY")) {
            printf("\n%s[EXITED]%s Cowardice detected. The squirrels have already won.\n", RED, RESET);
            break;
        }

        secure_memzero(command, sizeof(command));
    }

    secure_memzero(command, sizeof(command));
    return 0;
}
