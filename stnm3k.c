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
    srand((unsigned int)time(NULL));
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) == -1) {
            perror("Failed to create logs directory");
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
        timestamp[24] = '\0'; // Optimize newline removal
    } else {
        timestamp = "UNKNOWN TIME";
    }

    // Randomized thematic metadata
    int cow_hr = rand() % 200;
    int paranoia = rand() % 100;
    int fort = rand() % 10;

    fprintf(fp, "[%s] [COW_HR:%d] [PARANOIA:%d%%] [FORT:%d] COCAINE-COW-LOG: %s\n",
            timestamp, cow_hr, paranoia, fort, event);
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
    static const char template_x[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char template_star[] = "********************";
    static const char template_dot[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, template_x);
        else if (val > 8) printf("%.*s", val, template_star);
        else printf("%.*s", val, template_dot);
        printf("\n");
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Displays the last 10 log entries from the holy scrolls.
 */
void view_logs() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The Holy Scrolls are empty or inaccessible.\n");
        return;
    }

    printf("\n--- HOLY SCROLLS OF TRUTH (LAST 10 ENTRIES) ---\n");
    char lines[10][256];
    int count = 0;
    while (fgets(lines[count % 10], 256, fp)) {
        count++;
    }
    fclose(fp);

    int start = (count > 10) ? (count % 10) : 0;
    int limit = (count > 10) ? 10 : count;
    for (int i = 0; i < limit; i++) {
        printf("%s", lines[(start + i) % 10]);
    }
}

/**
 * Initiates the Polish Cow Synchronicity Protocol.
 */
void sync_cows() {
    printf("Initiating Polish Cow Synchronicity Protocol...\n");
    for (int i = 0; i < 3; i++) {
        printf("MOO... ");
        fflush(stdout);
        usleep(500000);
    }
    printf("\nCows synchronized at 3 AM cocaine frequency.\n");
    log_event("COW SYNCHRONICITY ACHIEVED.");
}

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
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");
    log_event("AUTHENTICATION INITIATED");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER");
            return 0;
        }
    }

    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    log_event("AUTHENTICATION SUCCESSFUL");
    return 1;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    umask(0077);
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. " GRN "ENGAGE DEFENSES" RESET "\n");
        printf("2. VIEW HOLY SCROLLS (LOGS)\n");
        printf("3. SYNCHRONIZE WITH POLISH COWS (MOO)\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "1") == 0 || strcmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcmp(command, "2") == 0 || strcmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_logs();
        } else if (strcmp(command, "3") == 0 || strcmp(command, "MOO") == 0) {
            sync_cows();
        } else if (strcmp(command, "4") == 0 || strcmp(command, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Invalid command. The Polish cows are confused.\n");
        }
    }

    return 0;
}
