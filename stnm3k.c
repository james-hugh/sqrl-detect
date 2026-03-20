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

/* UI Symbols and Theming */
#define UI_AUTH_SUCCESS GRN "✅ SUCCESS" RESET
#define UI_AUTH_FAILURE RED "❌ FAILURE" RESET
#define UI_MENU_HEADER  YEL "--- MAIN MENU ---" RESET

/* --- CORE SYSTEM UTILITIES --- */

/**
 * @brief Initializes the system components.
 *
 * Seeds the random number generator and ensures the log directory
 * exists with restrictive permissions (0700).
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
        perror("Failed to create log directory");
    }
}

/**
 * @brief Logs an event to the persistent log file.
 *
 * @param event The description of the event to log.
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
 * @brief Renders the visual threat meter to stdout.
 *
 * @param level The current threat level (0-100).
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
 * @brief Renders the "Graph of Chaos" showing random volatility.
 *
 * Uses static buffers to optimize string rendering.
 */
void print_graph_of_chaos() {
    static const char x_fill[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_fill[] = "********************";
    static const char dot_fill[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, x_fill);
        else if (val > 8) printf("%.*s", val, star_fill);
        else printf("%.*s", val, dot_fill);
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * @brief Selects a random threat message.
 *
 * @return A constant string pointer to a random threat.
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
 * @brief Displays the monitoring application header.
 */
void print_monitoring_header() {
    printf("\033[H\033[J"); // Clear screen
    printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
    printf("PLATFORM: %s\n\n", PLATFORM);
}

/**
 * @brief Handles threat alerts based on the current level.
 *
 * @param threat_level The current threat level (0-100).
 */
void handle_threat_alert(int threat_level) {
    if (threat_level > 70) {
        const char* threat = get_random_threat();
        const char* alert_name = (threat_level > 85) ? "RED SQUIRREL ALERT" : "YELLOW ACORN ALERT";
        const char* alert_color = (threat_level > 85) ? RED : YEL;

        printf("\n%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
        printf("ALERT: %s\n", threat);
        log_event(threat);
        printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
    }
}

/**
 * @brief Enters the main threat monitoring loop.
 */
void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        print_monitoring_header();

        int change = (rand() % 31) - 15;
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();

        handle_threat_alert(threat_level);

        printf("\nMonitoring... (Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);
        sleep(1);
    }
}

/**
 * @brief Authenticates the user via the "sacred prayer" protocol.
 *
 * @return int 1 if authentication is successful, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n%s\n", UI_AUTH_FAILURE);
            return 0;
        }

        if (strstr(command, "GLORY BE") != NULL) {
            prayer_count++;
        } else {
            printf("\n%s: INCORRECT PRAYER.\n", UI_AUTH_FAILURE);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

    printf("\n%s: Authentication successful. Welcome, Sentinel.\n", UI_AUTH_SUCCESS);
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
        printf("\n%s\n", UI_MENU_HEADER);
        printf("1. 🕹️  ENGAGE DEFENSES\n");
        printf("2. 💀 EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strstr(command, "ENGAGE DEFENSES") != NULL || strstr(command, "1") != NULL) {
            engage_defenses();
        } else if (strstr(command, "EXIT") != NULL || strstr(command, "2") != NULL) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Polish cows are confused.\n");
        }
    }

    return 0;
}
