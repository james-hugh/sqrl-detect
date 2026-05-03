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
int raw_alert_enabled = 0;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Securely wipes sensitive memory.
 */
static void secure_memzero(void *v, size_t n) {
    volatile unsigned char *p = v;
    while (n--) *p++ = 0;
}

/**
 * Case-insensitive substring search.
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
 * Displays a decorative ASCII header.
 */
void print_header() {
    printf("%s", CLEAR_SCREEN);
    printf("%s", GRN);
    printf("  __________________________________________________________\n");
    printf(" /                                                          \\\n");
    printf(" |   %sSQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K)%s      |\n", YEL, GRN);
    printf(" |   Version: %-46s |\n", VERSION);
    printf(" \\__________________________________________________________/\n");
    printf("%s\n", RESET);
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
    for (int i = GRAPH_HEIGHT; i > 0; i--) {
        int val = rand() % (MAX_GRAPH_VAL + 1);
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

/**
 * Displays the contents of the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("%s[ERROR] The holy scrolls are missing. The squirrels must have eaten them.%s\n", RED, RESET);
        return;
    }

    printf("\n--- READING HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);

    printf("\nPress Enter to return to the command center...");
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
}

/**
 * Broadcasts a message to the fungal network.
 */
void broadcast_fungal_message() {
    char message[256];
    printf("\nEnter message for the Fungal Network: ");
    if (fgets(message, sizeof(message), stdin) == NULL) return;

    // Remove newline
    message[strcspn(message, "\n")] = 0;

    if (strlen(message) == 0) {
        printf("Empty message. Fungal spores dispersed into nothingness.\n");
        return;
    }

    log_event(message);
    printf("%s[SUCCESS] Message encrypted and sent via mycelium.%s\n", GRN, RESET);
    sleep(1);

    secure_memzero(message, sizeof(message));
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
    printf("%s", CLEAR_SCREEN);
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        printf("%s", CLEAR_SCREEN);
        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        if (raw_alert_enabled) {
            printf("%s[RAW-ALERT MODE ACTIVE]%s\n", RED, RESET);
        }
        printf("\n");

        int max_change = raw_alert_enabled ? 40 : THREAT_MAX_CHANGE;
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

    printf("%s[INITIALIZING] STNM3K v%s\n", YEL, RESET);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) goto cleanup;

        if (str_contains_ignore_case(command, "GLORY BE")) {
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

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        print_header();
        printf("1. ENGAGE DEFENSES\n");
        printf("2. READ HOLY SCROLLS (LOGS)\n");
        printf("3. BROADCAST FUNGAL MESSAGE\n");
        printf("4. TOGGLE RAW-ALERT MODE (%s)\n", raw_alert_enabled ? "ENABLED" : "DISABLED");
        printf("5. EXIT (COWARDLY)\n");
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (str_contains_ignore_case(command, "ENGAGE DEFENSES") || strstr(command, "1")) {
            engage_defenses();
        } else if (str_contains_ignore_case(command, "READ") || strstr(command, "2")) {
            view_holy_scrolls();
        } else if (str_contains_ignore_case(command, "BROADCAST") || strstr(command, "3")) {
            broadcast_fungal_message();
        } else if (str_contains_ignore_case(command, "TOGGLE") || str_contains_ignore_case(command, "RAW") || strstr(command, "4")) {
            raw_alert_enabled = !raw_alert_enabled;
            printf("%s[SUCCESS] RAW-ALERT MODE %s.%s\n", GRN, raw_alert_enabled ? "ENABLED" : "DISABLED", RESET);
            sleep(1);
        } else if (str_contains_ignore_case(command, "EXIT") || strstr(command, "5")) {
            printf("%s[EXITED]%s Cowardice detected. Your pillow fort is compromised.\n", RED, RESET);
            break;
        } else {
            printf("Unknown directive. The squirrels are confusing you.\n");
            sleep(1);
        }
        secure_memzero(command, sizeof(command));
    }

    return 0;
}
