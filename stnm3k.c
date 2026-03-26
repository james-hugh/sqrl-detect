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
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

/* --- GLOBAL SYSTEM STATE --- */
int fortification_level = 50;  // Pillow Fort status
int cow_metabolism = 10;       // Speed of cow laps
int paranoid_mode = 0;         // Expand threat ranges

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
            perror("Failed to create log sanctuary");
        }
    }
}

/**
 * Reads and displays the holy scrolls of truth.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The holy scrolls are empty or the squirrels stole them.\n");
        return;
    }

    char line[256];
    printf("\n--- HOLY SCROLLS OF TRUTH ---\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("--- END OF SCROLLS ---\n");
    fclose(fp);
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
    printf("SQUIRREL THREAT METER: %s[%-8s] [%.*s%.*s] %d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char bars_X[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char bars_star[] = "********************";
    static const char bars_dot[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *bar_char = (val > 15) ? RED : (val > 8) ? YEL : GRN;
        const char *filler = (val > 15) ? bars_X : (val > 8) ? bars_star : bars_dot;

        printf("%2d |%s%.*s%s\n", val, bar_char, val, filler, RESET);
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

    int threat_level = 10;
    int session_threats = 0;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("%s🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s%s\n", YEL, VERSION, RESET);
        printf("PLATFORM: %-30s FORTIFICATION: %d%%\n\n", PLATFORM, fortification_level);

        int range = paranoid_mode ? 51 : 31;
        int offset = paranoid_mode ? 25 : 15;
        int change = (rand() % range) - offset;
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

            // 30% chance to log high threats
            if (rand() % 100 < 30) {
                log_event(threat);
                session_threats++;
            }
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        }

        printf("\nSession Alerts: %d\n", session_threats);
        printf("%sMonitoring... (Ctrl+C to retreat to your pillow fort)%s\n", YEL, RESET);
        fflush(stdout);
        usleep(1000000 / cow_metabolism);
    }
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf("%s", YEL);
    printf("  ____ _____ _   _ __  __ _____ _  __\n");
    printf(" / ___|_   _| \\ | |  \\/  |___ /| |/ /\n");
    printf(" \\___ \\ | | |  \\| | |\\/| | |_ \\| ' / \n");
    printf("  ___) || | | |\\  | |  | |___) | . \\ \n");
    printf(" |____/ |_| |_| \\_|_|  |_|____/|_|\\_\\\n");
    printf("%s\n", RESET);

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        if (strstr(command, "GLORY BE") != NULL) {
            prayer_count++;
            printf("%sGLORY BE!%s\n", GRN, RESET);
        } else {
            printf("\n%sINCORRECT PRAYER.%s\n", RED, RESET);
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
    while (1) {
        printf("\n--- STNM3K MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. ADJUST PILLOW FORT (Current: %d%%)\n", fortification_level);
        printf("3. VIEW HOLY SCROLLS\n");
        printf("4. TOGGLE PARANOID MODE (Current: %s)\n", paranoid_mode ? "ON" : "OFF");
        printf("5. EXIT (COWARDLY)\n");
        printf("STNM3K > ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strstr(command, "1") != NULL) {
            engage_defenses();
        } else if (strstr(command, "2") != NULL) {
            printf("New fortification level (0-100): ");
            if (fgets(command, sizeof(command), stdin)) {
                fortification_level = atoi(command);
                printf("Fortification set to %d%%.\n", fortification_level);
            }
        } else if (strstr(command, "3") != NULL) {
            view_holy_scrolls();
        } else if (strstr(command, "4") != NULL) {
            paranoid_mode = !paranoid_mode;
            printf("Paranoid mode is now %s.\n", paranoid_mode ? "ACTIVE" : "DISABLED");
        } else if (strstr(command, "5") != NULL) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Polish cows stare at you in confusion.\n");
        }
    }

    return 0;
}
