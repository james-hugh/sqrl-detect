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
#include <strings.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

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

/* Global Flags */
volatile sig_atomic_t cow_sync_active = 0;
volatile sig_atomic_t keep_running_defenses = 1;

/* --- SIGNAL HANDLING --- */

/**
 * Handles SIGINT to allow a graceful retreat to the main menu.
 */
void handle_sigint(int sig) {
    (void)sig; // Unused
    keep_running_defenses = 0;
}

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Strips leading and trailing whitespace from a string.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Trim trailing whitespace
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }

    // Trim leading whitespace
    char *start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
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

    if (cow_sync_active) {
        fprintf(fp, "[%s] [COW-SYNC: ACTIVE] COCAINE-COW-LOG: %s\n", timestamp, event);
    } else {
        fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", timestamp, event);
    }
    fclose(fp);
}

/**
 * Displays the contents of the holy scrolls of truth.
 */
void view_holy_scrolls() {
    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels haven't made their move... yet.\n");
        return;
    }

    char line[256];
    int lines_found = 0;
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
        lines_found++;
    }
    fclose(fp);

    if (lines_found == 0) {
        printf("The scrolls are blank. A clean slate for a paranoid mind.\n");
    }
    printf("--- END OF SCROLLS ---\n");
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

    // Setup signal handling for graceful retreat
    keep_running_defenses = 1;
    signal(SIGINT, handle_sigint);

    int threat_level = 10;
    while (keep_running_defenses) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        if (cow_sync_active) {
            printf("COW SYNC: " GRN "ACTIVE (Telemetry streaming from Polish herds)" RESET "\n");
        } else {
            printf("COW SYNC: " RED "INACTIVE (Disconnected from the herd)" RESET "\n");
        }
        printf("\n");

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

    // Restore default signal handling before returning to menu
    signal(SIGINT, SIG_DFL);
    printf("\n--- RETREATING TO PILLOW FORT ---\n");
    sleep(1);
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

        normalize_input(command);

        if (strcasecmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

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
        printf("\n--- MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. TOGGLE COW SYNC (%s)\n", cow_sync_active ? "ACTIVE" : "INACTIVE");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        normalize_input(command);

        if (strcasecmp(command, "ENGAGE DEFENSES") == 0 || strcmp(command, "1") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "VIEW HOLY SCROLLS") == 0 || strcmp(command, "2") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "TOGGLE COW SYNC") == 0 || strcmp(command, "3") == 0) {
            cow_sync_active = !cow_sync_active;
            printf("Cow Synchronization is now %s.\n", cow_sync_active ? "ACTIVE" : "INACTIVE");
        } else if (strcasecmp(command, "EXIT") == 0 || strcmp(command, "4") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Polish cows look at you with confusion.\n");
        }
    }

    return 0;
}
