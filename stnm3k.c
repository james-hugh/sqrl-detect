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
void init_system();
void log_event(const char *event);
void normalize_input(char *str);
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Normalizes input by removing trailing newlines and spaces.
 */
void normalize_input(char *str) {
    if (str == NULL) return;
    str[strcspn(str, "\r\n")] = '\0';
    int len = strlen(str);
    while (len > 0 && str[len - 1] == ' ') {
        str[len - 1] = '\0';
        len--;
    }
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        mkdir(LOG_DIR, 0700);
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
        timestamp[strlen(timestamp) - 1] = '\0'; // Remove trailing newline
    } else {
        timestamp = "UNKNOWN TIME";
    }

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", timestamp, event);
    fclose(fp);
}

/**
 * Displays the last 10 entries from the holy scrolls using a circular buffer.
 */
void view_holy_scrolls() {
    printf("\n--- VIEWING HOLY SCROLLS OF TRUTH ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels are being too quiet...\n");
        return;
    }

    char lines[10][256];
    size_t count = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp)) {
        strncpy(lines[count % 10], buffer, 256);
        count++;
    }
    fclose(fp);

    size_t start = (count > 10) ? (count % 10) : 0;
    size_t display_count = (count > 10) ? 10 : count;

    for (size_t i = 0; i < display_count; i++) {
        printf("%s", lines[(start + i) % 10]);
    }

    if (count == 0) {
        printf("The scrolls are blank. A bad omen.\n");
    }
    printf("--- END OF SCROLLS ---\n");
}

/**
 * Synchronizes with the Polish cows using the MOO protocol.
 */
void synchronize_with_cows() {
    printf("\n--- INITIALIZING MOO PROTOCOL ---\n");
    printf("Synchronizing with 3 AM cocaine laps...\n");

    for (int i = 0; i <= 20; i++) {
        printf("\r[");
        for (int j = 0; j < i; j++) printf("M");
        for (int j = i; j < 20; j++) printf(" ");
        printf("] %d%% MOO", i * 5);
        fflush(stdout);
        usleep(100000);
    }
    printf("\nSynchronization complete. The cows are pleased.\n");
    log_event("MOO PROTOCOL SYNCHRONIZED.");
}

/**
 * Displays the current status of the pillow fort sentinels.
 */
void show_pillow_fort_status() {
    printf("\n--- PILLOW FORT COMMAND CENTER STATUS ---\n");
    printf("Integrity:      [#######---] 70%% (Slightly lopsided)\n");
    printf("Cocaine Supply: [##########] 100%% (Polish cows satisfied)\n");
    printf("Acorn Defenses: [####------] 40%% (More acorns needed)\n");
    printf("WiFi Shield:    [#########-] 90%% (Vanquishing WiFi acorns)\n");
    printf("Sentinel Mood:  PARANOID AND READY\n");
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
    static const char template[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char caution_template[] = "********************";
    static const char normal_template[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, template);
        else if (val > 8) printf("%.*s", val, caution_template);
        else printf("%.*s", val, normal_template);
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
        normalize_input(command);

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
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n" CYN "--- MAIN COMMAND CENTER ---" RESET "\n");
        printf(GRN "1. ENGAGE DEFENSES" RESET "\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf(RED "5. EXIT (COWARDLY)" RESET "\n");
        printf("> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcasecmp(command, "ENGAGE DEFENSES") == 0 || strcmp(command, "1") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "VIEW HOLY SCROLLS") == 0 || strcmp(command, "2") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "SYNCHRONIZE WITH COWS") == 0 || strcmp(command, "3") == 0) {
            synchronize_with_cows();
        } else if (strcasecmp(command, "PILLOW FORT STATUS") == 0 || strcmp(command, "4") == 0) {
            show_pillow_fort_status();
        } else if (strcasecmp(command, "EXIT") == 0 || strcmp(command, "5") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Google Machine is confused.\n");
        }
    }

    return 0;
}
