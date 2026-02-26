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
#include <errno.h>

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
#define CYN "\x1B[36m"
#define RESET "\x1B[0m"

/* --- GLOBALS --- */
volatile sig_atomic_t keep_running_defenses = 1;

/* --- FUNCTION PROTOTYPES --- */
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
void synchronize_with_cows();
void show_pillow_fort_status();

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Signal handler for SIGINT to gracefully exit monitoring.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand((unsigned int)time(NULL));
    umask(0077);
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) == -1) {
            perror("CRITICAL: Failed to create logs directory");
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * Strips leading/trailing whitespace and newlines from a string.
 */
void normalize_input(char *str) {
    if (!str) return;

    // Remove trailing whitespace/newlines
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\n' || str[len - 1] == '\r' || str[len - 1] == '\t')) {
        str[--len] = '\0';
    }

    // Remove leading whitespace
    char *start = str;
    while (*start == ' ' || *start == '\t') {
        start++;
    }

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
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
        timestamp[24] = '\0'; // Efficiently null-terminate ctime result
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
    // O(1) rendering using precision specifiers
    printf("SQUIRREL THREAT METER: %s[%s] [%.*s%.*s] %d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char row_fill[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char row_warn[] = "********************";
    static const char row_low[]  = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *fill = row_low;
        const char *label = "[LOW]";

        if (val > 15) {
            fill = row_fill;
            label = "[CRITICAL]";
        } else if (val > 8) {
            fill = row_warn;
            label = "[STABLE]";
        }

        // Optimized rendering with accessibility labels
        printf("%2d | %.*s %s\n", val, val, fill, label);
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Returns a random threat message for the paranoid user.
 */
const char* get_random_threat() {
    static const char* threats[] = {
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
 * Displays the last 10 entries of the holy scrolls.
 */
void view_holy_scrolls() {
    printf("\n--- %sHOLY SCROLLS OF TRUTH (LATEST 10)%s ---\n", CYN, RESET);
    FILE *fp = fopen(LOG_FILE, "r");
    if (!fp) {
        printf("The scrolls are empty. The squirrels are either gone or very sneaky.\n");
        return;
    }

    char *lines[10];
    for (int i = 0; i < 10; i++) lines[i] = NULL;

    char buffer[256];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (lines[count % 10]) free(lines[count % 10]);
        lines[count % 10] = strdup(buffer);
        count++;
    }
    fclose(fp);

    int start = (count > 10) ? (count % 10) : 0;
    int total = (count > 10) ? 10 : count;

    for (int i = 0; i < total; i++) {
        printf("%s", lines[(start + i) % 10]);
        free(lines[(start + i) % 10]);
    }
    printf("\nPress ENTER to return to the Command Center...");
    fflush(stdout);
    getchar();
}

/**
 * Synchronizes with Polish cows using the simulated MOO protocol.
 */
void synchronize_with_cows() {
    printf("\n--- %sSYNCHRONIZING WITH POLISH COWS%s ---\n", CYN, RESET);
    printf("Initializing MOO protocol...\n");

    const char *steps[] = {
        "Establishing fungal uplink...",
        "Measuring cow lap speed...",
        "Calibrating cocaine synergy...",
        "Synchronizing timestamps with 3 AM sprints...",
        "MOO PROTOCOL COMPLETE."
    };

    for (int i = 0; i < 5; i++) {
        printf("%s\n", steps[i]);
        printf("[");
        for (int j = 0; j < 20; j++) {
            printf("#");
            fflush(stdout);
            usleep(50000); // 50ms per bar
        }
        printf("] 100%%\n");
    }

    log_event("COW SYNCHRONIZATION SUCCESSFUL.");
    printf("\nCow synchronization complete. The herd is with you.\n");
    printf("Press ENTER to return to the Command Center...");
    fflush(stdout);
    getchar();
}

/**
 * Displays the current status of the Pillow Fort.
 */
void show_pillow_fort_status() {
    printf("\n--- %sPILLOW FORT COMMAND CENTER STATUS%s ---\n", CYN, RESET);

    int integrity = 85 + (rand() % 16); // 85-100%
    int supplies = 60 + (rand() % 41); // 60-100%

    printf("Fort Integrity:  [%-20.*s] %d%%\n", (integrity / 5), "####################", integrity);
    printf("Snack Supplies:  [%-20.*s] %d%%\n", (supplies / 5), "####################", supplies);
    printf("Atmosphere:      COMFY\n");
    printf("Squirrel Buffer: NOMINAL\n");

    printf("\nYour fortress is holding. Rest easy, Sentinel.\n");
    printf("Press ENTER to return to the Command Center...");
    fflush(stdout);
    getchar();
}

/**
 * Enters the main monitoring loop.
 */
void engage_defenses() {
    keep_running_defenses = 1;
    signal(SIGINT, handle_sigint);

    printf("\n--- %sENGAGING DEFENSES%s ---\n", RED, RESET);
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

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

    signal(SIGINT, SIG_DFL);
    printf("\n\n--- %sRETREATING TO PILLOW FORT%s ---\n", GRN, RESET);
    log_event("DEFENSES DISENGAGED. RETREATED TO PILLOW FORT.");
    printf("Press ENTER to return to the Command Center...");
    fflush(stdout);
    getchar();
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char input[100];
    int prayer_count = 0;

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");
    log_event("AUTHENTICATION INITIATED");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        fflush(stdout);
        if (fgets(input, sizeof(input), stdin) == NULL) return 0;

        normalize_input(input);
        if (strcmp(input, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\n%sINCORRECT PRAYER.%s\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER");
            return 0;
        }
    }

    printf("\n%sAuthentication successful. Welcome, Sentinel.%s\n", GRN, RESET);
    log_event("AUTHENTICATION SUCCESSFUL");
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
        printf("\n--- %sMAIN COMMAND CENTER%s ---\n", CYN, RESET);
        printf("%s1. ENGAGE DEFENSES%s\n", GRN, RESET);
        printf("%s2. VIEW HOLY SCROLLS%s\n", GRN, RESET);
        printf("%s3. SYNCHRONIZE WITH COWS%s\n", GRN, RESET);
        printf("%s4. PILLOW FORT STATUS%s\n", GRN, RESET);
        printf("%s5. EXIT (COWARDLY)%s\n", RED, RESET);
        printf("> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "SYNCHRONIZE WITH COWS") == 0) {
            synchronize_with_cows();
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "PILLOW FORT STATUS") == 0) {
            show_pillow_fort_status();
        } else if (strcasecmp(command, "5") == 0 || strcasecmp(command, "EXIT") == 0 || strcasecmp(command, "EXIT (COWARDLY)") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            running = 0;
        } else {
            printf("Unknown command. The Google Machine is trying to confuse you.\n");
        }
    }

    return 0;
}
