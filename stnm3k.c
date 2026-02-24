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

/* --- FUNCTION PROTOTYPES --- */
void init_system();
void log_event(const char *event);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
void normalize_input(char *str);

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Strips leading/trailing whitespace and newlines from a string.
 */
void normalize_input(char *str) {
    if (str == NULL) return;
    str[strcspn(str, "\r\n")] = 0;

    // Trim trailing
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) {
        str[--len] = 0;
    }

    // Trim leading
    char *start = str;
    while (*start == ' ' || *start == '\t') {
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
    static int initialized = 0;
    if (initialized) return;

    srand((unsigned int)time(NULL));
    umask(0077);
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) != 0) {
            perror("CRITICAL: Could not create logs directory");
            exit(EXIT_FAILURE);
        }
    }
    initialized = 1;
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
        timestamp[24] = '\0'; // Optimization: ctime always returns 26 chars
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
    static const char x_line[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_line[] = "********************";
    static const char dot_line[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) {
            printf("%s%.*s%s", RED, val, x_line, RESET);
        } else if (val > 8) {
            printf("%s%.*s%s", YEL, val, star_line, RESET);
        } else {
            printf("%s%.*s%s", GRN, val, dot_line, RESET);
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
 * Displays the last 10 entries of the holy scrolls.
 */
void view_holy_scrolls() {
    printf("\n--- VIEWING HOLY SCROLLS OF TRUTH ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels are quiet... too quiet.\n");
        printf("\nPress ENTER to return to base...");
        getchar();
        return;
    }

    char lines[10][256];
    int count = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp)) {
        strncpy(lines[count % 10], buffer, 256);
        count++;
    }
    fclose(fp);

    int start = (count > 10) ? (count % 10) : 0;
    int total = (count > 10) ? 10 : count;

    for (int i = 0; i < total; i++) {
        printf("%s", lines[(start + i) % 10]);
    }

    printf("\nPress ENTER to return to base...");
    getchar();
}

/**
 * Performs the MOO protocol synchronization.
 */
void synchronize_with_cows() {
    printf("\n--- INITIALIZING COCAINE-COW SYNCHRONIZATION ---\n");
    printf("Establishing MOO protocol link...\n");

    for (int i = 0; i <= 20; i++) {
        printf("\r[");
        for (int j = 0; j < i; j++) printf("=");
        for (int j = i; j < 20; j++) printf(" ");
        printf("] %d%% MOOING...", i * 5);
        fflush(stdout);
        usleep(100000); // 100ms
    }

    printf("\n\nSUCCESS: Cows are now vibrating at the correct frequency.\n");
    printf("Log timestamps aligned with 3 AM lap metrics.\n");
    printf("\nPress ENTER to return to base...");
    getchar();
}

/**
 * Displays the current status of the pillow fort.
 */
void show_pillow_fort_status() {
    printf("\n--- PILLOW FORT COMMAND CENTER STATUS ---\n");
    printf("Integrity:  [##########----------] 50%% (Slightly lopsided)\n");
    printf("Supplies:   [###############-----] 75%% (Ample juice boxes)\n");
    printf("Morale:     [####################] 100%% (GLORY BE!)\n");
    printf("Air Quality: [######--------------] 30%% (Smells like laundry)\n");
    printf("\nSENTINEL STATUS: VIGILANT\n");
    printf("\nPress ENTER to return to base...");
    getchar();
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    log_event("AUTHENTICATION INITIATED");
    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        fflush(stdout);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        normalize_input(command);

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\nINCORRECT PRAYER.\n");
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
    int choice = 0;

    while (choice != 5) {
        printf("\n%s--- MAIN COMMAND CENTER ---%s\n", CYN, RESET);
        printf("%s1. ENGAGE DEFENSES%s\n", GRN, RESET);
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf("%s5. EXIT (COWARDLY)%s\n", RED, RESET);
        printf("> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcmp(command, "3") == 0 || strcasecmp(command, "SYNCHRONIZE WITH COWS") == 0) {
            synchronize_with_cows();
        } else if (strcmp(command, "4") == 0 || strcasecmp(command, "PILLOW FORT STATUS") == 0) {
            show_pillow_fort_status();
        } else if (strcmp(command, "5") == 0 || strcasecmp(command, "EXIT") == 0 || strcasecmp(command, "EXIT (COWARDLY)") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            choice = 5;
        } else {
            printf("Unknown directive. The Polish cows are confused.\n");
        }
    }

    return 0;
}
