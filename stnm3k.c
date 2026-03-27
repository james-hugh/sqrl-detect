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
#include <fcntl.h>

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
int paranoid_mode = 0;
int fortification_level = 50;
int cow_metabolism = 1;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    if (mkdir(LOG_DIR, 0700) == -1) {
        if (errno != EEXIST) {
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
    static char last_timestamp[32];
    time_t now = time(NULL);

    if (now != last_time) {
        char *timestamp = ctime(&now);
        if (timestamp) {
            strncpy(last_timestamp, timestamp, sizeof(last_timestamp) - 1);
            last_timestamp[strlen(last_timestamp) - 1] = '\0'; // Remove trailing newline
        } else {
            strcpy(last_timestamp, "UNKNOWN TIME");
        }
        last_time = now;
    }

    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Failed to open holy scrolls for writing");
        return;
    }

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", last_timestamp, event);
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
    static const char bars_fill[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char stars_fill[] = "********************";
    static const char dots_fill[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) {
            printf("%.*s", val, bars_fill);
        } else if (val > 8) {
            printf("%.*s", val, stars_fill);
        } else {
            printf("%.*s", val, dots_fill);
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

    // Set stdin to non-blocking to allow checking for input
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("%s🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s%s\n", YEL, VERSION, RESET);
        printf("PLATFORM: %s\n", PLATFORM);
        printf("FORTIFICATION LEVEL: %d | PARANOID MODE: %s\n\n", fortification_level, paranoid_mode ? "ON" : "OFF");

        int volatility = paranoid_mode ? 51 : 31;
        int offset = paranoid_mode ? 25 : 15;
        int change = (rand() % volatility) - offset;
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

        printf("\nMonitoring... %s(Press ENTER to retreat to your pillow fort)%s\n", YEL, RESET);
        fflush(stdout);

        // Check for user input to exit the loop
        char c;
        if (read(STDIN_FILENO, &c, 1) > 0) {
            break;
        }

        usleep(1000000 / cow_metabolism);
    }

    // Restore stdin to blocking mode
    fcntl(STDIN_FILENO, F_SETFL, flags);
    printf("\nRetreating to pillow fort...\n");
}

/**
 * Displays the contents of the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        perror("Failed to open holy scrolls for reading");
        return;
    }

    char line[256];
    printf("\n--- READING HOLY SCROLLS OF TRUTH ---\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("--- END OF SCROLLS ---\n\n");
    fclose(fp);
}

/**
 * Adjusts the pillow fort defense level.
 */
void adjust_pillow_fort() {
    char input[10];
    printf("Current Pillow Fort Fortification Level: %d\n", fortification_level);
    printf("Enter new fortification level (0-100): ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        int new_level = atoi(input);
        if (new_level >= 0 && new_level <= 100) {
            fortification_level = new_level;
            printf("Pillow fort reinforced to level %d. GLORY BE!\n", fortification_level);
        } else {
            printf("INVALID LEVEL. The squirrels are laughing.\n");
        }
    }
}

/**
 * Toggles the paranoid mode state.
 */
void toggle_paranoid_mode() {
    paranoid_mode = !paranoid_mode;
    printf("PARANOID MODE: %s\n", paranoid_mode ? "ENABLED (GLORY BE!)" : "DISABLED (COWARDLY)");
    if (paranoid_mode) {
        cow_metabolism = 2; // Cows run faster in paranoid mode
    } else {
        cow_metabolism = 1;
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
    printf("  ____  _______ _   _ __  __ _____ _  __\n");
    printf(" / ___||_   _| \\ | |  \\/  |___ /| |/ /\n");
    printf(" \\___ \\  | | |  \\| | |\\/| | |_ \\| ' / \n");
    printf("  ___) | | | | |\\  | |  | |___) | . \\ \n");
    printf(" |____/  |_| |_| \\_|_|  |_|____/|_|\\_\\\n");
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

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("1. ENGAGE DEFENSES\n");
        printf("2. ADJUST PILLOW FORT\n");
        printf("3. VIEW HOLY SCROLLS\n");
        printf("4. TOGGLE PARANOID MODE\n");
        printf("5. EXIT\n");
        printf("STNM3K > ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strstr(command, "1") != NULL || strstr(command, "ENGAGE") != NULL) {
            engage_defenses();
        } else if (strstr(command, "2") != NULL || strstr(command, "PILLOW") != NULL) {
            adjust_pillow_fort();
        } else if (strstr(command, "3") != NULL || strstr(command, "SCROLLS") != NULL) {
            view_holy_scrolls();
        } else if (strstr(command, "4") != NULL || strstr(command, "PARANOID") != NULL) {
            toggle_paranoid_mode();
        } else if (strstr(command, "5") != NULL || strstr(command, "EXIT") != NULL) {
            printf("Exiting... Your pillow fort remains as a legacy.\n");
            break;
        } else {
            printf("Unknown command. The Polish cows are confused.\n");
        }
    }

    return 0;
}
