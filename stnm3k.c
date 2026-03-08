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

/* --- GLOBAL STATE --- */
volatile sig_atomic_t keep_running_defenses = 1;
int cow_sync_enabled = 0;

/* --- FORWARD DECLARATIONS --- */
void init_system();
void log_event(const char *event);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();
void normalize_input(char *str);
void handle_sigint(int sig);
void view_holy_scrolls();
void toggle_cow_sync();

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
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    umask(0077); // Restrict log access to owner only
    srand(time(NULL));
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        mkdir(LOG_DIR, 0700);
    }
}

/**
 * Displays the holy scrolls of truth (logs).
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\n[ERROR] The holy scrolls are missing or empty. The squirrels may have eaten them.\n");
        return;
    }

    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("--- END OF SCROLLS ---\n");
    fclose(fp);

    printf("\nPress Enter to return to the main menu...");
    getchar();
}

/**
 * Toggles the Polish cow synchronization mode.
 */
void toggle_cow_sync() {
    cow_sync_enabled = !cow_sync_enabled;
    printf("\nCow Synchronization is now: %s%s%s\n",
           cow_sync_enabled ? GRN : RED,
           cow_sync_enabled ? "ENABLED (GLORY BE!)" : "DISABLED (COWARDLY)",
           RESET);
    if (cow_sync_enabled) {
        log_event("COW SYNC ENABLED. TELEMETRY ALIGNED WITH POLISH BOVINES.");
    }
    sleep(1);
}

/**
 * Strips leading/trailing whitespace and newlines from a string.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Trim leading
    char *start = str;
    while (isspace((unsigned char)*start)) start++;
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }

    // Trim trailing
    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }
}

/**
 * Gracefully handles SIGINT to return to the main menu.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
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
    printf("%s[ SQUIRREL THREAT METER ]%s\n", YEL, RESET);
    printf("%s[%s]%s [%.*s%.*s] %d%%\n",
           color, status, RESET, bars, bars_fill, METER_WIDTH - bars, bars_empty, level);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char bars[] = "XXXXXXXXXXXXXXXXXXXX";
    printf("%s[ GUI GRAPH OF CHAOS ]%s (Network Volatility)\n", YEL, RESET);
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d | %s%.*s%s\n", val, GRN, val, bars, RESET);
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
    keep_running_defenses = 1;
    signal(SIGINT, handle_sigint);

    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (keep_running_defenses) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        if (cow_sync_enabled) {
            printf("COW SYNC: %sACTIVE (MOOOOOOO!)%s\n", GRN, RESET);
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

    signal(SIGINT, SIG_DFL);
    printf("\nRetreating to pillow fort...\n");
    sleep(1);
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf("\n%s====================================================%s\n", YEL, RESET);
    printf("  🖥️  STNM3K v%s - %s\n", VERSION, PLATFORM);
    printf("%s====================================================%s\n\n", YEL, RESET);
    printf("Recite the sacred prayer %s\"GLORY BE\"%s three times to proceed.\n", GRN, RESET);

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        normalize_input(command);

        if (strcasecmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\n%s[AUTHENTICATION FAILED]%s\n", RED, RESET);
            printf("INCORRECT PRAYER. The Polish cows are disappointed.\n");
            log_event("AUTHENTICATION FAILED: BLASPHEMY DETECTED.");
            return 0;
        }
    }

    printf("\n%s[ACCESS GRANTED]%s Welcome, Sentinel.\n", GRN, RESET);
    log_event("AUTHENTICATION SUCCESSFUL. SENTINEL ACCESS GRANTED.");
    return 1;
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
        printf("\n%s[ STNM3K MAIN COMMAND CENTER ]%s\n", YEL, RESET);
        printf("%s1.%s ENGAGE DEFENSES\n", GRN, RESET);
        printf("%s2.%s VIEW HOLY SCROLLS\n", GRN, RESET);
        printf("%s3.%s TOGGLE COW SYNC\n", GRN, RESET);
        printf("%s4.%s EXIT (COWARDLY)\n", RED, RESET);
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "TOGGLE COW SYNC") == 0) {
            toggle_cow_sync();
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "EXIT") == 0 || strcasecmp(command, "EXIT (COWARDLY)") == 0) {
            printf("\nCowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            running = 0;
        } else {
            printf("\nUNKNOWN COMMAND. The Google Machine is laughing at you.\n");
        }
    }

    return 0;
}
