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
void log_event(const char *event);
void view_holy_scrolls();
void synchronize_with_cows();
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Displays the last 10 log entries from the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The holy scrolls are empty or missing. The squirrels might have eaten them.\n");
        return;
    }

    char lines[10][256];
    size_t count = 0;
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        strncpy(lines[count % 10], line, sizeof(lines[0]));
        count++;
    }
    fclose(fp);

    printf("\n--- LAST 10 HOLY SCROLL ENTRIES ---\n");
    size_t total = (count > 10) ? 10 : count;
    size_t start = (count > 10) ? (count % 10) : 0;

    for (size_t i = 0; i < total; i++) {
        printf("%s", lines[(start + i) % 10]);
    }

    if (count == 0) {
        printf("No entries found in the scrolls.\n");
    }
    printf("--- END OF SCROLLS ---\n");
}

/**
 * Synchronizes the monitor with the Polish cow 3 AM cocaine laps.
 */
void synchronize_with_cows() {
    printf("\nINITIATING COCAINE-COW SYNCHRONIZATION PROTOCOL (MOO v1.0)...\n");
    log_event("MOO PROTOCOL INITIATED");

    for (int i = 0; i <= 100; i += 5) {
        printf("\r[");
        int pos = i / 5;
        for (int j = 0; j < 20; j++) {
            if (j < pos) printf("=");
            else if (j == pos) printf(">");
            else printf(" ");
        }
        printf("] %d%% SYNCHRONIZING...", i);
        fflush(stdout);
        usleep(100000);
    }

    printf("\nMOO! Synchronization complete.\n");
    printf("Status: Polish cows are currently running at 500%% efficiency.\n");
    log_event("MOO PROTOCOL SUCCESSFUL: COWS SYNCHRONIZED");
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
            perror("Failed to create holy scrolls directory");
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * Logs a message to the holy scrolls of truth with thematic metadata.
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
        timestamp[24] = '\0'; // Optimized newline removal
    } else {
        timestamp = "UNKNOWN TIME";
    }

    int cow_hr = rand() % 200 + 50;
    int paranoia = rand() % 100;
    const char* fort_status = (paranoia > 80) ? "REINFORCED" : "SECURE";

    fprintf(fp, "[%s][COW_HR: %d][PARANOIA: %d][FORT: %s] %s\n",
            timestamp, cow_hr, paranoia, fort_status, event);
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
 * Renders the GUI graph of chaos using optimized rendering.
 */
void print_graph_of_chaos() {
    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    static const char fills[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char mids[]  = "********************";
    static const char lows[]  = "....................";

    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *template = (val > 15) ? fills : (val > 8 ? mids : lows);
        printf("%2d |%.*s\n", val, val, template);
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
 * Handles user authentication via the sacred prayer with audit logging.
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

        command[strcspn(command, "\r\n")] = '\0'; // Precise newline stripping

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
        printf("3. MOO PROTOCOL (Synchronize with Cows)\n");
        printf("%s4. EXIT (COWARDLY)%s\n", RED, RESET);
        printf("> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\r\n")] = '\0';

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "MOO PROTOCOL") == 0 || strcasecmp(command, "MOO") == 0) {
            synchronize_with_cows();
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("The Polish cows do not understand your strange words.\n");
        }
    }

    return 0;
}
