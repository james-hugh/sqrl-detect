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
#define RESET "\x1B[0m"

/* --- GLOBAL STATE --- */
int cow_metabolism = 1;
int paranoid_mode = 0;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) != 0 && errno != EEXIST) {
            perror("Failed to create log directory");
        }
    }
}

/**
 * Logs a message to the holy scrolls of truth.
 * @param event The event message to log.
 */
void log_event(const char *event) {
    static time_t last_time = 0;
    static char cached_timestamp[64] = "UNKNOWN TIME";

    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Failed to open holy scrolls for writing");
        return;
    }

    time_t now = time(NULL);
    if (now != last_time) {
        char *timestamp = ctime(&now);
        if (timestamp) {
            strncpy(cached_timestamp, timestamp, sizeof(cached_timestamp) - 1);
            cached_timestamp[strlen(cached_timestamp) - 1] = '\0'; // Remove trailing newline
        }
        last_time = now;
    }

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", cached_timestamp, event);
    fclose(fp);
}

/* --- VISUALIZATION ENGINE --- */

/**
 * Reads and displays the holy scrolls from the log file.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nTHE HOLY SCROLLS ARE EMPTY OR MISSING. PRAY HARDER.\n");
        return;
    }

    printf("\n%s--- READING HOLY SCROLLS OF TRUTH ---%s\n", YEL, RESET);
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("%s--- END OF SCROLLS ---%s\n\n", YEL, RESET);
    fclose(fp);
}

/**
 * Renders the squirrel threat meter with fixed-width labels to prevent UI jitter.
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
    printf("SQUIRREL THREAT METER: %s[%-8s] [%.*s%.*s] %3d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos using bulk output for performance.
 */
void print_graph_of_chaos() {
    static const char filler_crit[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char filler_med[]  = "********************";
    static const char filler_low[]  = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility) [X:Crit *:Med .:Low]:\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) {
            printf("%.*s", val, filler_crit);
        } else if (val > 8) {
            printf("%.*s", val, filler_med);
        } else {
            printf("%.*s", val, filler_low);
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
 * Enters the main monitoring loop with adjustable speed and volatility.
 */
void engage_defenses() {
    printf("\n%s--- ENGAGING DEFENSES ---%s\n", YEL, RESET);
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    int session_alerts = 0;

    // Give user a moment to see the header
    sleep(1);

    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("%s🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s%s\n", YEL, VERSION, RESET);
        printf("PLATFORM: %s\n", PLATFORM);
        printf("COW METABOLISM: %d | PARANOID MODE: %s\n", cow_metabolism, paranoid_mode ? "ON" : "OFF");
        printf("SESSION ALERTS: %d\n\n", session_alerts);

        int volatility_range = paranoid_mode ? 51 : 31;
        int volatility_offset = paranoid_mode ? 25 : 15;
        int change = (rand() % volatility_range) - volatility_offset;

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
            session_alerts++;
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        }

        printf("\n%sMonitoring... (Ctrl+C to retreat to your pillow fort)%s\n", YEL, RESET);
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
    printf("  ____  _______ _   _ __  __ ____  _  __\n");
    printf(" / ___||_   _| \\ | |  \\/  |___ \\| |/ /\n");
    printf(" \\___ \\  | | |  \\| | |\\/| | __) | ' / \n");
    printf("  ___) | | | | |\\  | |  | |/ __/| . \\ \\\n");
    printf(" |____/  |_| |_| \\_|_|  |_|_____|_|\\_\\\n");
    printf("%s\n", RESET);

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        if (strstr(command, "GLORY BE") != NULL) {
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

/**
 * Main application loop, handling authentication and the main menu.
 */
int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n--- STNM3K MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. TOGGLE PARANOID MODE (%s)\n", paranoid_mode ? "ON" : "OFF");
        printf("4. ADJUST COW METABOLISM (Current: %d)\n", cow_metabolism);
        printf("5. EXIT (COWARDLY)\n");
        printf("STNM3K > ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strstr(command, "1") != NULL || strncasecmp(command, "ENGAGE", 6) == 0) {
            engage_defenses();
        } else if (strstr(command, "2") != NULL || strncasecmp(command, "VIEW", 4) == 0) {
            view_holy_scrolls();
        } else if (strstr(command, "3") != NULL || strncasecmp(command, "TOGGLE", 6) == 0) {
            paranoid_mode = !paranoid_mode;
            printf("PARANOID MODE is now %s.\n", paranoid_mode ? "ON" : "OFF");
        } else if (strstr(command, "4") != NULL || strncasecmp(command, "ADJUST", 6) == 0) {
            printf("Enter new metabolism (1-10): ");
            if (fgets(command, sizeof(command), stdin)) {
                int val = atoi(command);
                if (val >= 1 && val <= 10) {
                    cow_metabolism = val;
                    printf("Cow metabolism set to %d. THE COWS ARE RUNNING FASTER.\n", cow_metabolism);
                } else {
                    printf("Invalid metabolism. The cows are confused.\n");
                }
            }
        } else if (strstr(command, "5") != NULL || strncasecmp(command, "EXIT", 4) == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Google Machine is recording your failure.\n");
        }
    }

    return 0;
}
