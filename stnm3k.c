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

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

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
 * @brief Initializes the system by seeding the RNG and ensuring the log directory exists.
 *
 * Sets the umask to 0077 to ensure restrictive permissions on created files and
 * directories.
 *
 * @return void
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
            perror("Failed to create log directory");
        }
    }
}

/**
 * @brief Logs a message to the holy scrolls of truth.
 *
 * Implements timestamp caching to avoid redundant ctime() calls.
 *
 * @param event The event message to log.
 * @return void
 */
void log_event(const char *event) {
    static time_t last_time = 0;
    static char timestamp_cache[64] = "UNKNOWN TIME";

    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Failed to open holy scrolls for writing");
        return;
    }

    time_t now = time(NULL);
    if (now != last_time) {
        char *time_str = ctime(&now);
        if (time_str) {
            strncpy(timestamp_cache, time_str, sizeof(timestamp_cache) - 1);
            timestamp_cache[strlen(timestamp_cache) - 1] = '\0'; // Remove trailing newline
        }
        last_time = now;
    }

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", timestamp_cache, event);
    fclose(fp);
}

/* --- VISUALIZATION ENGINE --- */

/**
 * @brief Renders the squirrel threat meter.
 *
 * Displays a color-coded bar representing the current threat level.
 *
 * @param level Threat level from 0 to 100.
 * @return void
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
 * @brief Renders the GUI graph of chaos.
 *
 * Uses bulk output with %.*s for performance efficiency.
 *
 * @return void
 */
void print_graph_of_chaos() {
    static const char bars_x[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char bars_star[] = "********************";
    static const char bars_dot[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility) [X:Crit *:Med .:Low]:\n");
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
 * @brief Returns a random threat message for the paranoid user.
 *
 * @return const char* A pointer to a random threat string.
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
 * @brief Displays the persistent logs from the holy scrolls.
 *
 * @return void
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The holy scrolls are currently empty. No squirrels detected yet.\n");
        return;
    }

    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    printf("--- END OF SCROLLS ---\n\n");
    fclose(fp);
}

/**
 * @brief Enters the main monitoring loop.
 *
 * Continuously updates the threat level and renders visualizations.
 * Uses paranoid_mode for increased volatility and cow_metabolism for speed.
 *
 * @return void
 */
void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");
    sleep(1);

    int threat_level = 10;
    int session_threats = 0;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("%s🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s%s\n", YEL, VERSION, RESET);
        printf("PLATFORM: %s\n", PLATFORM);
        printf("SESSION THREATS: %d | PARANOID MODE: %s\n\n",
               session_threats, paranoid_mode ? "ON" : "OFF");

        int range = paranoid_mode ? 51 : 31;
        int offset = paranoid_mode ? 25 : 15;
        int change = (rand() % range) - offset;
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();

        if (threat_level > 80 && (rand() % 100 < 30)) {
            const char* threat = get_random_threat();
            const char* alert_name = (threat_level > 85) ? "RED SQUIRREL ALERT" : "YELLOW ACORN ALERT";
            const char* alert_color = (threat_level > 85) ? RED : YEL;

            printf("\n%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
            printf("ALERT: %s\n", threat);
            log_event(threat);
            session_threats++;
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        }

        printf("\nMonitoring... (Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);
        usleep(1000000 / cow_metabolism);
    }
}

/**
 * @brief Handles user authentication via the sacred prayer.
 *
 * @return int 1 if authenticated, 0 otherwise.
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
        } else {
            printf("\n%sINCORRECT PRAYER.%s\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

    printf("\n%sAuthentication successful. Welcome, Sentinel.%s\n", GRN, RESET);
    return 1;
}

/* --- MAIN ENTRY POINT --- */

/**
 * @brief Main entry point of the STNM3K application.
 *
 * @return int Exit status code.
 */
int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. TOGGLE PARANOID MODE (%s)\n", paranoid_mode ? "ON" : "OFF");
        printf("4. EXIT (COWARDLY)\n");
        printf("STNM3K > ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strstr(command, "1") != NULL) {
            engage_defenses();
        } else if (strstr(command, "2") != NULL) {
            view_holy_scrolls();
        } else if (strstr(command, "3") != NULL) {
            paranoid_mode = !paranoid_mode;
            printf("Paranoid Mode: %s\n", paranoid_mode ? "ENABLED (GLORY BE!)" : "DISABLED (SQUIRRELS LAUGHING)");
        } else if (strstr(command, "4") != NULL || strstr(command, "EXIT") != NULL) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Invalid command. The cows are confused.\n");
        }
    }

    return 0;
}
