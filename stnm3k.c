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
#include <time.h>
#include <unistd.h>
#include <signal.h>
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

/* --- GLOBAL STATE --- */
volatile sig_atomic_t keep_running_defenses = 1;

/* --- FORWARD DECLARATIONS --- */
void init_system();
void log_event(const char *event);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();
void view_holy_scrolls();
void normalize_input(char *str);
void print_logo();
void handle_sigint(int sig);

/* --- CORE SYSTEM UTILITIES --- */

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
    static const char template_x[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char template_star[] = "********************";
    static const char template_dot[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, template_x);
        else if (val > 8) printf("%.*s", val, template_star);
        else printf("%.*s", val, template_dot);
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
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
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    struct sigaction sa, old_sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    keep_running_defenses = 1;
    sigaction(SIGINT, &sa, &old_sa);

    int threat_level = 10;
    while (keep_running_defenses) {
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

    printf("\n%sRetreating to the pillow fort...%s\n", YEL, RESET);
    sigaction(SIGINT, &old_sa, NULL);
    log_event("DEFENSES DISENGAGED. RETREATED TO PILLOW FORT.");
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    print_logo();
    printf("\n%s🖥️  STNM3K v%s INITIALIZED%s\n", YEL, VERSION, RESET);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        normalize_input(command);

        if (strcasecmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\n%sINCORRECT PRAYER.%s\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

    printf("\n%sAuthentication successful. Welcome, Sentinel.%s\n", GRN, RESET);
    return 1;
}

/**
 * Normalizes input by stripping leading/trailing whitespace and newlines.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Trim trailing whitespace and newlines
    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }

    // Trim leading whitespace
    const char *start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

/**
 * Displays the contents of the holy scrolls of truth.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\n%s[!] The holy scrolls are empty or missing.%s\n", RED, RESET);
        return;
    }

    char line[256];
    printf("\n%s--- HOLY SCROLLS OF TRUTH ---%s\n", YEL, RESET);
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("%s----------------------------%s\n", YEL, RESET);
    fclose(fp);

    printf("\nPress Enter to return to the command center...");
    while (getchar() != '\n');
}

/**
 * Prints the STNM3K ASCII art logo.
 */
void print_logo() {
    printf("%s", YEL);
    printf("  __________________________________________________  \n");
    printf(" /                                                  \\ \n");
    printf(" |   %sSTNM3K: SQUIRREL TERMINATOR NETWORK MONITOR%s    %s| \n", GRN, RESET, YEL);
    printf(" |           %s\"Vigilance. Victory. Acorns.\"%s          %s| \n", RED, RESET, YEL);
    printf(" \\__________________________________________________/ \n");
    printf("%s", RESET);
}

/**
 * Handles the SIGINT signal to gracefully exit the monitoring loop.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    int running = 1;

    while (running) {
        printf("\n%s--- COMMAND CENTER ---%s\n", YEL, RESET);
        printf("%s1. ENGAGE DEFENSES%s\n", GRN, RESET);
        printf("%s2. VIEW HOLY SCROLLS%s\n", GRN, RESET);
        printf("%s3. TOGGLE COW SYNC%s\n", GRN, RESET);
        printf("%s4. EXIT (COWARDLY)%s\n", RED, RESET);
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "TOGGLE COW SYNC") == 0) {
            printf("\n%s[COW-SYNC] Searching for Polish cows in sector 3 AM...%s\n", YEL, RESET);
            sleep(1);
            printf("%s[COW-SYNC] Synchronization successful. Mooo!%s\n", GRN, RESET);
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "EXIT") == 0 || strcasecmp(command, "EXIT (COWARDLY)") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            running = 0;
        } else {
            printf("\n%sUnknown command. The Google Machine is confused.%s\n", RED, RESET);
        }
    }

    return 0;
}
