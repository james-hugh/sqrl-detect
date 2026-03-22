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
#define METER_WIDTH 20

/**
 * System configuration toggles.
 */
typedef struct {
    int raw_alert_mode;     // 1 for on, 0 for off
    int cow_sync_active;    // 1 for on, 0 for off
} SystemSettings;

static SystemSettings g_settings = {0, 0};

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
    srand(time(NULL));
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        mkdir(LOG_DIR, 0700);
    }
    // Default settings
    g_settings.raw_alert_mode = 0;
    g_settings.cow_sync_active = 0;
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

/**
 * Displays the contents of the holy scrolls.
 */
void read_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nThe holy scrolls are empty. No squirrel incursions yet.\n");
        return;
    }

    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("--- END OF SCROLLS ---\n\n");
    fclose(fp);
}

/**
 * Settings menu for the STNM3K system.
 */
void pillow_fort_command_center() {
    char choice[100];
    while (1) {
        printf("\n--- PILLOW FORT COMMAND CENTER (Settings) ---\n");
        printf("1. Toggle RAW-ALERT Mode [%s]\n", g_settings.raw_alert_mode ? "ON" : "OFF");
        printf("2. Toggle Cow Synchronization [%s]\n", g_settings.cow_sync_active ? "ON" : "OFF");
        printf("3. RETURN TO MAIN MENU\n");
        printf("> ");
        if (fgets(choice, sizeof(choice), stdin) == NULL) break;

        if (strstr(choice, "1") != NULL) {
            g_settings.raw_alert_mode = !g_settings.raw_alert_mode;
            printf("RAW-ALERT Mode is now %s.\n", g_settings.raw_alert_mode ? "ON" : "OFF");
        } else if (strstr(choice, "2") != NULL) {
            g_settings.cow_sync_active = !g_settings.cow_sync_active;
            printf("Cow Synchronization is now %s.\n", g_settings.cow_sync_active ? "ON" : "OFF");
        } else if (strstr(choice, "3") != NULL || strstr(choice, "RETURN") != NULL) {
            break;
        } else {
            printf("Invalid command in the pillow fort. The cows are confused.\n");
        }
    }
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
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        if (g_settings.cow_sync_active) {
            printf("%s[COW SYNC: ACTIVE]%s Monitoring Polish cow cocaine laps...\n", YEL, RESET);
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

            if (g_settings.raw_alert_mode) {
                printf("\n%s##################################################%s\n", alert_color, RESET);
                printf("%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
                printf("%sALERT: %s%s\n", alert_color, threat, RESET);
                printf("%s##################################################%s\n", alert_color, RESET);
            } else {
                printf("\n%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
                printf("ALERT: %s\n", threat);
            }

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

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n--- STNM3K MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. READ HOLY SCROLLS\n");
        printf("3. PILLOW FORT COMMAND CENTER\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strstr(command, "1") != NULL || strstr(command, "ENGAGE") != NULL) {
            engage_defenses();
        } else if (strstr(command, "2") != NULL || strstr(command, "READ") != NULL) {
            read_holy_scrolls();
        } else if (strstr(command, "3") != NULL || strstr(command, "PILLOW") != NULL) {
            pillow_fort_command_center();
        } else if (strstr(command, "4") != NULL || strstr(command, "EXIT") != NULL) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Polish cows are judging you.\n");
        }
    }

    return 0;
}
