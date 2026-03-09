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

/* --- FORWARD DECLARATIONS --- */
void print_logo();
void init_system();
void log_event(const char *event);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();
void normalize_input(char *str);
void view_holy_scrolls();
void handle_sigint(int sig);

/* --- GLOBAL FLAGS --- */
volatile sig_atomic_t keep_running_defenses = 1;
int cow_sync_enabled = 0;

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
 * Normalizes input by removing leading/trailing whitespace and newlines.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Trim leading whitespace
    char *start = str;
    while (isspace((unsigned char)*start)) start++;

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }

    // Trim trailing whitespace
    int len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[len - 1] = '\0';
        len--;
    }
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

    if (cow_sync_enabled) {
        fprintf(fp, "[%s] [COW-SYNC: ACTIVE] COCAINE-COW-LOG: %s\n", timestamp, event);
    } else {
        fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", timestamp, event);
    }
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
    static const char bars_x[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char bars_star[] = "********************";
    static const char bars_dot[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, bars_x);
        else if (val > 8) printf("%.*s", val, bars_star);
        else printf("%.*s", val, bars_dot);
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Signal handler to gracefully exit the monitoring loop.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
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

    // Set up signal handler
    keep_running_defenses = 1;
    signal(SIGINT, handle_sigint);

    int threat_level = 10;
    while (keep_running_defenses) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        if (cow_sync_enabled) {
            printf("%sCOW SYNC: %sONLINE (Telemetry Active)%s\n", YEL, GRN, RESET);
        } else {
            printf("%sCOW SYNC: %sOFFLINE%s\n", YEL, RED, RESET);
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

    // Reset signal handler and state
    signal(SIGINT, SIG_DFL);
    printf("\nReturning to main menu...\n");
    sleep(1);
}

/**
 * Renders the STNM3K logo.
 */
void print_logo() {
    printf("%s", YEL);
    printf("  ____ _____ _   _ __  __ _____ _  __\n");
    printf(" / ___|_   _| \\ | |  \\/  |___ /| |/ /\n");
    printf(" \\___ \\ | | |  \\| | |\\/| | |_ \\| ' / \n");
    printf("  ___) || | | |\\  | |  | |___) | . \\ \n");
    printf(" |____/ |_| |_| \\_|_|  |_|____/|_|\\_\\\n");
    printf("  SQUIRREL TERMINATOR NETWORK MONITOR\n");
    printf("%s", RESET);
}

/**
 * Displays the contents of the holy scrolls.
 */
void view_holy_scrolls() {
    printf("\033[H\033[J");
    print_logo();
    printf("\n%s--- HOLY SCROLLS OF TRUTH ---%s\n\n", YEL, RESET);

    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The holy scrolls are empty or missing. Perhaps the squirrels ate them?\n");
    } else {
        char line[256];
        int lines = 0;
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
            lines++;
        }
        if (lines == 0) {
            printf("The scrolls are blank. A peaceful day in the pillow fort.\n");
        }
        fclose(fp);
    }

    printf("\n%sPress Enter to return to the main menu...%s", GRN, RESET);

    // Wait for Enter
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf("\033[H\033[J");
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
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

    printf("\n%sAuthentication successful. Welcome, Sentinel.%s\n", GRN, RESET);
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
    int keep_running = 1;

    while (keep_running) {
        printf("\033[H\033[J");
        print_logo();
        printf("\n%s--- MAIN MENU ---%s\n", YEL, RESET);
        printf("%s1.%s ENGAGE DEFENSES\n", GRN, RESET);
        printf("%s2.%s VIEW HOLY SCROLLS\n", GRN, RESET);
        printf("%s3.%s TOGGLE COW SYNC\n", GRN, RESET);
        printf("%s4.%s EXIT (COWARDLY)\n", RED, RESET);
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "TOGGLE COW SYNC") == 0) {
            cow_sync_enabled = !cow_sync_enabled;
            printf("\n%sCow Synchronization is now %s%s%s\n", YEL,
                   cow_sync_enabled ? GRN : RED,
                   cow_sync_enabled ? "ACTIVE" : "INACTIVE",
                   RESET);
            sleep(1);
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "EXIT") == 0 || strcasecmp(command, "EXIT (COWARDLY)") == 0) {
            printf("\n%sCowardice detected. The squirrels have already won. Your pillow fort is compromised.%s\n", RED, RESET);
            keep_running = 0;
        } else if (strlen(command) > 0) {
            printf("\n%sUNKNOWN COMMAND. The Google Machine is laughing at you.%s\n", RED, RESET);
            sleep(1);
        }
    }

    return 0;
}
