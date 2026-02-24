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
void normalize_input(char *str);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
int authenticate_user();

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Trims trailing whitespace and newlines from a string.
 */
void normalize_input(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) != 0) {
            perror("CRITICAL FAILURE: Could not establish log sanctuary");
            exit(EXIT_FAILURE);
        }
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
        /* ctime returns a 26-char string including '\n' and '\0'.
           Null-terminating at index 24 removes the newline. */
        timestamp[24] = '\0';
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
 * Displays the last 10 entries from the holy scrolls.
 */
void view_holy_scrolls() {
    printf("\n--- VIEWING HOLY SCROLLS OF TRUTH ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels are either silent or extremely sneaky.\n");
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
    int display_count = (count > 10) ? 10 : count;

    for (int i = 0; i < display_count; i++) {
        printf("%s", lines[(start + i) % 10]);
    }

    if (count == 0) {
        printf("The scrolls are blank. A clean slate for our crusade.\n");
    }
    printf("\nPress Enter to return to command center...");
    fflush(stdout);
    getchar(); // Wait for actual enter
}

/**
 * Synchronizes with Polish cows using the simulated MOO protocol.
 */
void synchronize_with_cows() {
    printf("\n--- SYNCHRONIZING WITH POLISH COWS (MOO PROTOCOL v2.1) ---\n");
    printf("Establishing connection to the pasture...\n");

    for (int i = 0; i <= 100; i += 5) {
        printf("\r[");
        int bars = i / 5;
        for (int j = 0; j < 20; j++) {
            if (j < bars) printf("=");
            else printf(" ");
        }
        printf("] %d%% - %s", i, (i < 100) ? "MOOING..." : "SYNC COMPLETE! (5mg Cocaine Optimized)");
        fflush(stdout);
        usleep(150000); // 150ms delay
    }
    printf("\n\nAll cows reporting at 3 AM baseline. High-speed laps confirmed.\n");
    log_event("COW SYNCHRONIZATION SUCCESSFUL. MOO.");
    printf("Press Enter to return...");
    fflush(stdout);
    getchar();
}

/**
 * Displays the current status of the pillow fort.
 */
void show_pillow_fort_status() {
    printf("\n--- PILLOW FORT COMMAND CENTER STATUS ---\n");

    int integrity = 85 + (rand() % 15);
    int supplies = 40 + (rand() % 60);

    printf("FORT INTEGRITY: [");
    for (int i = 0; i < 20; i++) {
        if (i < integrity / 5) printf("#");
        else printf("-");
    }
    printf("] %d%%\n", integrity);

    printf("SNACK SUPPLIES: [");
    for (int i = 0; i < 20; i++) {
        if (i < supplies / 5) printf("*");
        else printf("-");
    }
    printf("] %d%%\n", supplies);

    printf("\nDefenses: OPTIMAL\n");
    printf("Morale: HIGHER THAN A 3 AM COW\n");
    printf("Squirrel Proximity: CONCERNING\n");

    printf("\nPress Enter to return...");
    fflush(stdout);
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

    log_event("AUTHENTICATION INITIATED");
    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        fflush(stdout);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        if (strstr(command, "GLORY BE") != NULL) {
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
    while (1) {
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

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "SYNCHRONIZE WITH COWS") == 0) {
            synchronize_with_cows();
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "PILLOW FORT STATUS") == 0) {
            show_pillow_fort_status();
        } else if (strcasecmp(command, "5") == 0 || strcasecmp(command, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Invalid command. Even the cows know how to use a menu.\n");
        }
    }

    return 0;
}
