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

/* --- CONFIGURATION MACROS --- */
#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_DIR "logs"
#define LOG_FILE "logs/holy_scrolls.txt"

/* --- TERMINAL COLORS --- */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    static int initialized = 0;
    if (initialized) return;

    srand(time(NULL));
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        mkdir(LOG_DIR, 0700);
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
        timestamp[24] = '\0'; // Remove trailing newline
    } else {
        timestamp = "UNKNOWN TIME";
    }

    int cow_hr = rand() % 200 + 50;
    int paranoia = rand() % 100;
    int fort = rand() % 10;

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s {COW_HR:%dbpm, PARANOIA:%d%%, FORT:%d/10}\n",
            timestamp, event, cow_hr, paranoia, fort);
    fclose(fp);
}

/* --- VISUALIZATION ENGINE --- */

/**
 * Renders the squirrel threat meter.
 * @param level Threat level from 0 to 100.
 */
void print_threat_meter(int level) {
    int bars = level / 5;
    const char *color = (level > 80) ? RED : (level > 50) ? YEL : GRN;
    const char *status = (level > 80) ? "CRITICAL" : (level > 50) ? "CAUTION" : "SECURE";
    const char *fill = (level > 80) ? "!!!!!!!!!!!!!!!!!!!!" :
                       (level > 50) ? "####################" :
                                      "====================";
    printf("SQUIRREL THREAT METER: [%s%.*s%s%.*s] %d%% [%s%s%s]\n",
           color, bars, fill, RESET, 20 - bars, "--------------------", level, color, status, RESET);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    printf("%sGUI GRAPH OF CHAOS (Network Volatility):%s\n", CYN, RESET);
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *color = (val > 15) ? RED : (val > 8) ? YEL : GRN;
        const char *fill = (val > 15) ? "XXXXXXXXXXXXXXXXXXXX" :
                           (val > 8)  ? "********************" :
                                        "....................";
        printf("%2d |%s%.*s%s\n", val, color, val, fill, RESET);
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

        printf("%s🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s%s\n", MAG, VERSION, RESET);
        printf("%sPLATFORM: %s%s\n\n", BLU, PLATFORM, RESET);

        int change = (rand() % 31) - 15; // -15 to +15
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();

        if (threat_level > 70) {
            const char* threat = get_random_threat();
            printf("\n!!! MAXIMUM ALERT MODE !!!\n");
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
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER");
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

    log_event("AUTHENTICATION SUCCESSFUL");
    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    return 1;
}

/* --- MAIN ENTRY POINT --- */

/**
 * Main entry point of the SQUIRREL TERMINATOR NETWORK MONITOR 3000.
 * Initializes security settings and handles the top-level user interface.
 * @return 0 on success, 1 on authentication failure.
 */
int main() {
    umask(0077);
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    printf("1. ENGAGE DEFENSES\n");
    printf("2. EXIT (COWARDLY)\n");
    printf("> ");
    if (fgets(command, sizeof(command), stdin) == NULL) return 0;

    if (strstr(command, "ENGAGE DEFENSES") != NULL || strstr(command, "1") != NULL) {
        engage_defenses();
    } else {
        printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
    }

    return 0;
}
