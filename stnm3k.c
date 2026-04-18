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

/* ANSI Colors */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Case-insensitive string search.
 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @return 1 if found, 0 otherwise.
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
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
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
 * Displays the contents of the holy scrolls.
 */
void view_logs() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\n[!] The holy scrolls are empty or missing. The cows have not yet spoken.\n");
        return;
    }

    printf("\n--- %sHOLY SCROLLS OF TRUTH%s ---\n", YEL, RESET);
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    printf("--- END OF SCROLLS ---\n");
    printf("\nPress Enter to return to the Command Center...");
    getchar();
}

/**
 * Performs a manual threat scan with multi-step simulation.
 */
void manual_scan() {
    printf("\n--- INITIATING MANUAL THREAT SCAN ---\n");
    log_event("MANUAL SCAN STARTED. CONSULTING THE FUNGAL NETWORK.");

    const char *steps[] = {
        "Triangulating WiFi Acorns...",
        "Consulting Polish Cows (3 AM Lap Analysis)...",
        "Scanning Fungal Network for Squirrel Backdoors...",
        "Analyzing Acorn Payload Signatures..."
    };

    for (int i = 0; i < 4; i++) {
        printf("[%d/4] %s\n", i + 1, steps[i]);
        fflush(stdout);
        usleep(500000); // 0.5s pause for dramatic effect
    }

    int threat = (rand() % 100) + 1;
    printf("\nScan Complete. Threat Level: %d%%\n", threat);

    char log_msg[64];
    snprintf(log_msg, sizeof(log_msg), "MANUAL SCAN COMPLETE. THREAT LEVEL: %d%%", threat);
    log_event(log_msg);

    if (threat > 80) {
        printf("%s[!] EXTREME VULNERABILITY DETECTED. RETREAT TO PILLOW FORT.%s\n", RED, RESET);
    } else {
        printf("%s[√] Network integrity maintains holy status.%s\n", GRN, RESET);
    }

    printf("\nPress Enter to return to the Command Center...");
    getchar();
}

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

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n\n", PLATFORM);

        int change = (rand() % 31) - 15; // -15 to +15
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

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        if (str_contains_ignore_case(command, "GLORY BE")) {
            prayer_count++;
            printf("%s[√] ACCEPTED%s\n", GRN, RESET);
        } else {
            printf("\n%sINCORRECT PRAYER.%s\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            memset(command, 0, sizeof(command));
            return 0;
        }
    }

    memset(command, 0, sizeof(command));
    printf("\nAuthentication successful. Welcome, Sentinel.\n");
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
        // Clear screen and show Command Center
        printf("\033[H\033[J");
        printf("🖥️  STNM3K COMMAND CENTER - v%s\n", VERSION);
        printf("------------------------------------\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. MANUAL THREAT SCAN\n");
        printf("3. VIEW HOLY SCROLLS (LOGS)\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (command[0] == '1' && (command[1] == '\n' || command[1] == ' ')) {
            engage_defenses();
        } else if (command[0] == '2' && (command[1] == '\n' || command[1] == ' ')) {
            manual_scan();
        } else if (command[0] == '3' && (command[1] == '\n' || command[1] == ' ')) {
            view_logs();
        } else if (command[0] == '4' && (command[1] == '\n' || command[1] == ' ')) {
            printf("\nCowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else if (strlen(command) > 1) {
            // Check for keyword-based commands
            if (str_contains_ignore_case(command, "ENGAGE")) engage_defenses();
            else if (str_contains_ignore_case(command, "SCAN")) manual_scan();
            else if (str_contains_ignore_case(command, "LOGS") || str_contains_ignore_case(command, "SCROLLS")) view_logs();
            else if (str_contains_ignore_case(command, "EXIT")) {
                 printf("\nCowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
                 break;
            }
        }
    }

    return 0;
}
