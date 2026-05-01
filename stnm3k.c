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
#define GRAPH_HEIGHT 5
#define MAX_GRAPH_VAL 20
#define THREAT_MAX_CHANGE 15

/* ANSI Colors */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

/* --- GLOBAL STATE --- */
static int raw_alert_enabled = 0;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Securely wipes memory by filling it with zeros.
 * Uses a volatile pointer to prevent the compiler from optimizing away the wipe.
 * @param v Pointer to the memory buffer.
 * @param n Size of the buffer in bytes.
 */
static void secure_memzero(void *v, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)v;
    while (n--) *p++ = 0;
}

/**
 * Case-insensitive version of strstr to find a substring within a string.
 * @param haystack The string to search within.
 * @param needle The substring to look for.
 * @return 1 if needle is found in haystack, 0 otherwise.
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
 * Renders a decorative ASCII header for the application.
 */
static void print_header() {
    printf("%s", CLEAR_SCREEN);
    printf("%s", GRN);
    printf("  ___________________________________________________________\n");
    printf(" /                                                           \\\n");
    printf(" |  %sSQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K)%s      |\n", YEL, GRN);
    printf(" |  %sVERSION: %-10s  PLATFORM: %-20s%s  |\n", RED, VERSION, PLATFORM, GRN);
    printf(" \\___________________________________________________________/\n");
    printf("    %s\"Watching your network with the vigilance of Polish cows\"%s\n", YEL, RESET);
    printf("\n");
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
 * Optimized to reduce printf calls using static character buffers and precision.
 */
void print_graph_of_chaos() {
    static const char xs[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char stars[] = "********************";
    static const char dots[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = GRAPH_HEIGHT; i > 0; i--) {
        int val = rand() % (MAX_GRAPH_VAL + 1);
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
 * Optimized using static const for the internal string array.
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
    printf("%s[INITIALIZING] Charging defense capacitors...%s\n", YEL, RESET);
    sleep(1);
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        printf("%s", CLEAR_SCREEN);
        print_header();

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
 * Displays the contents of the holy scrolls (logs).
 */
static void view_holy_scrolls() {
    printf("%s[INITIALIZING] Accessing the Holy Scrolls...%s\n", YEL, RESET);
    sleep(1);

    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The Holy Scrolls are currently empty or inaccessible.\n");
        sleep(1);
        return;
    }

    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("--- END OF SCROLLS ---\n");
    fclose(fp);

    printf("\nPress Enter to return to the command center...");
    char dummy[256];
    if (fgets(dummy, sizeof(dummy), stdin) == NULL) { /* Handle EOF */ }
}

/**
 * Allows the user to broadcast a message to the fungal network (log a message).
 */
static void broadcast_fungal_message() {
    char message[128];
    printf("\nEnter message to broadcast to the fungal network: ");
    if (fgets(message, sizeof(message), stdin) == NULL) return;

    // Remove trailing newline
    message[strcspn(message, "\n")] = 0;

    if (strlen(message) == 0) {
        printf("%s[CANCELLED]%s Message was too ethereal to broadcast.\n", RED, RESET);
    } else {
        log_event(message);
        printf("%s[SUCCESS]%s Message sent to the pillow fort command center.\n", GRN, RESET);
    }
    sleep(1);
}

/**
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf("%s", CLEAR_SCREEN);
    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) {
            secure_memzero(command, sizeof(command));
            return 0;
        }

        if (str_contains_ignore_case(command, "GLORY BE")) {
            printf("%s[ACCEPTED]%s\n", GRN, RESET);
            prayer_count++;
        } else {
            printf("\n%s[INCORRECT]%s PRAYER.\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            secure_memzero(command, sizeof(command));
            return 0;
        }
    }

    secure_memzero(command, sizeof(command));
    printf("\n%s[SUCCESS]%s Authentication successful. Welcome, Sentinel.\n", GRN, RESET);
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
        print_header();
        printf("MAIN COMMAND CENTER MENU:\n");
        printf("1. %sENGAGE DEFENSES%s\n", RED, RESET);
        printf("2. %sREAD HOLY SCROLLS (LOGS)%s\n", GRN, RESET);
        printf("3. %sBROADCAST FUNGAL MESSAGE%s\n", YEL, RESET);
        printf("4. %sTOGGLE RAW-ALERT MODE%s (Currently: %s%s%s)\n",
               YEL, RESET, (raw_alert_enabled ? RED : GRN),
               (raw_alert_enabled ? "[ACTIVE]" : "[DISABLED]"), RESET);
        printf("5. EXIT (COWARDLY)\n");
        printf("\nSENTINEL COMMAND > ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (str_contains_ignore_case(command, "ENGAGE") || str_contains_ignore_case(command, "1")) {
            engage_defenses();
        } else if (str_contains_ignore_case(command, "READ") || str_contains_ignore_case(command, "2")) {
            view_holy_scrolls();
        } else if (str_contains_ignore_case(command, "BROADCAST") || str_contains_ignore_case(command, "3")) {
            broadcast_fungal_message();
        } else if (str_contains_ignore_case(command, "RAW") || str_contains_ignore_case(command, "4")) {
            raw_alert_enabled = !raw_alert_enabled;
            printf("\n%s[SECURE]%s RAW-ALERT mode %s.\n",
                   GRN, RESET, (raw_alert_enabled ? "engaged" : "disengaged"));
            sleep(1);
        } else if (str_contains_ignore_case(command, "EXIT") || str_contains_ignore_case(command, "5")) {
            printf("\n%s[COWARDICE DETECTED]%s The squirrels have already won. Your pillow fort is compromised.\n", RED, RESET);
            break;
        } else {
            printf("\n[ERROR] Unknown command. The Google Machine is laughing at you.\n");
            sleep(1);
        }
    }

    return 0;
}
