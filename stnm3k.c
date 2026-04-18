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

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Portable case-insensitive string search.
 */
char *str_contains_ignore_case(const char *haystack, const char *needle) {
    if (!haystack || !needle) return NULL;
    if (!*needle) return (char *)haystack;

    for (; *haystack; haystack++) {
        if (tolower((unsigned char)*haystack) == tolower((unsigned char)*needle)) {
            const char *h = haystack + 1;
            const char *n = needle + 1;
            while (*h && *n && tolower((unsigned char)*h) == tolower((unsigned char)*n)) {
                h++;
                n++;
            }
            if (!*n) return (char *)haystack;
        }
    }
    return NULL;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
        perror("Failed to create log sanctuary");
    }
}

/**
 * Logs a message to the holy scrolls of truth.
 * @param event The event message to log.
 */
void log_event(const char *event) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        return;
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        size_t len = strlen(timestamp);
        if (len > 0 && timestamp[len - 1] == '\n') {
            timestamp[len - 1] = '\0';
        }
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
    printf("SQUIRREL THREAT METER: %s%-8s [%.*s%.*s] %3d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char X_BUF[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char S_BUF[] = "********************";
    static const char D_BUF[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, X_BUF);
        else if (val > 8) printf("%.*s", val, S_BUF);
        else printf("%.*s", val, D_BUF);
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
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
 * Performs a manual scan of the network for squirrel activity.
 */
void manual_scan() {
    printf("\n--- INITIATING MANUAL SCAN ---\n");
    printf("Scanning fungal network... "); fflush(stdout); sleep(1); printf("DONE.\n");
    printf("Consulting Polish cows... "); fflush(stdout); sleep(1); printf("DONE.\n");
    printf("Triangulating WiFi acorns... "); fflush(stdout); sleep(1); printf("DONE.\n");

    int threat = rand() % 100;
    printf("\nScan Complete. Threat Level: %d%%\n", threat);
    if (threat > 50) {
        const char *t = get_random_threat();
        printf("%sWARNING: %s%s\n", RED, t, RESET);
        log_event(t);
    } else {
        printf("%sSystem remains holy.%s\n", GRN, RESET);
    }
    printf("\nPress Enter to return to Command Center...");
    getchar();
}

/**
 * Displays the contents of the holy scrolls.
 */
void view_logs() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nThe holy scrolls are empty or inaccessible.\n");
    } else {
        printf("\n--- HOLY SCROLLS OF TRUTH ---\n");
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }
    printf("\nPress Enter to return to Command Center...");
    getchar();
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

            if (threat_level > 85) printf("\a"); // Audible alert for high threat

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
        if (fgets(command, sizeof(command), stdin) == NULL) {
            memset(command, 0, sizeof(command));
            return 0;
        }

        if (str_contains_ignore_case(command, "GLORY BE") != NULL) {
            printf(" %s[√] ACCEPTED%s\n", GRN, RESET);
            prayer_count++;
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
        printf("\033[H\033[J"); // Clear screen
        printf("--- STNM3K COMMAND CENTER ---\n");
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
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        }
    }

    return 0;
}
