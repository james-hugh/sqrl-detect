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
#define RESET "\x1B[0m"

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand((unsigned int)time(NULL));
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) != 0) {
            perror("CRITICAL: Failed to create logs directory");
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
        // Performance: null-terminate at fixed index 24 to remove newline
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
    static const char* const threats[] = {
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
 * Displays the last 10 entries of the holy scrolls using a circular buffer.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (!fp) {
        printf("The Holy Scrolls are empty or missing. The squirrels are winning.\n");
        return;
    }

    char lines[10][256];
    int count = 0;
    while (fgets(lines[count % 10], sizeof(lines[0]), fp)) {
        count++;
    }
    fclose(fp);

    printf("\n--- THE LAST %d HOLY SCROLL ENTRIES ---\n", (count < 10) ? count : 10);
    int start = (count > 10) ? (count % 10) : 0;
    int display_count = (count < 10) ? count : 10;
    for (int i = 0; i < display_count; i++) {
        printf("%s", lines[(start + i) % 10]);
    }
}

/**
 * Synchronizes with Polish cows at 3 AM levels.
 */
void synchronize_cows() {
    printf("\nSYNCHRONIZING WITH POLISH COWS...\n");
    for (int i = 0; i <= 10; i++) {
        printf("\r[");
        for (int j = 0; j < 10; j++) printf(j < i ? "M" : ".");
        printf("] %d0%% MOO", i);
        fflush(stdout);
        usleep(200000);
    }
    printf("\nSUCCESS: Laps synchronized. Cow-synergy at maximum.\n");
}

/**
 * Performs diagnostics on the pillow fort command center.
 */
void check_pillow_fort() {
    printf("\n--- PILLOW FORT DIAGNOSTICS ---\n");
    printf("Fortification Level: %d%%\n", 85 + (rand() % 16));
    printf("Acorn Reserve: %d kg\n", rand() % 50);
    printf("Cocaine Stocks: %s\n", (rand() % 2) ? "OPTIMAL" : "RATIONING REQUIRED");
    printf("Polish Cow Morale: EXCELLENT (3 AM Laps In Progress)\n");
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

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        fflush(stdout);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        command[strcspn(command, "\r\n")] = '\0';

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

    printf("\n" GRN "Authentication successful. Welcome, Sentinel." RESET "\n");
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
        printf("\n1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH POLISH COWS (MOO)\n");
        printf("4. CHECK PILLOW FORT\n");
        printf("5. EXIT (COWARDLY)\n");
        printf("> ");
        fflush(stdout);
        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\r\n")] = '\0';

        if (strcmp(command, "1") == 0 || strcasecmp(command, "ENGAGE") == 0) {
            engage_defenses();
        } else if (strcmp(command, "2") == 0 || strcasecmp(command, "VIEW") == 0) {
            view_holy_scrolls();
        } else if (strcmp(command, "3") == 0 || strcasecmp(command, "MOO") == 0) {
            synchronize_cows();
        } else if (strcmp(command, "4") == 0 || strcasecmp(command, "CHECK") == 0) {
            check_pillow_fort();
        } else if (strcmp(command, "5") == 0 || strcasecmp(command, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Invalid command. The Polish cows are confused.\n");
        }
    }

    return 0;
}
