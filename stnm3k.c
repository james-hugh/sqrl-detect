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
#include <signal.h>

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

/* --- GLOBAL STATE --- */
volatile sig_atomic_t keep_running_defenses = 1;

/* --- FUNCTION PROTOTYPES --- */
void init_system();
void log_event(const char *event);
void normalize_input(char *str);
int authenticate_user();
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    static int initialized = 0;
    if (initialized) return;

    srand((unsigned int)time(NULL));
    umask(0077);

    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) != 0) {
            perror("Failed to create logs directory");
            exit(EXIT_FAILURE);
        }
    }
    initialized = 1;
}

/**
 * Strips leading/trailing whitespace and newlines from a string.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Remove trailing newline and whitespace
    str[strcspn(str, "\r\n")] = '\0';
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) {
        str[--len] = '\0';
    }

    // Remove leading whitespace
    size_t start = 0;
    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }
    if (start > 0) {
        memmove(str, str + start, len - start + 1);
    }
}

/**
 * Logs a message to the holy scrolls of truth.
 * @param event The event message to log.
 */
void log_event(const char *event) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        return; // Silent fail to avoid interrupting the UI
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        timestamp[24] = '\0'; // Efficiently remove trailing newline
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
        status = "[CRITICAL]";
    } else if (level > 70) {
        color = YEL;
        status = "[CAUTION]";
    } else {
        status = "[SECURE]";
    }

    int bars = (level * METER_WIDTH) / 100;
    printf("SQUIRREL THREAT METER: %s%-10s [%.*s%.*s] %d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char blocks[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char stars[]  = "********************";
    static const char dots[]   = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15)      printf("%.*s (HIGH)", val, blocks);
        else if (val > 8)  printf("%.*s (MED)", val, stars);
        else               printf("%.*s (LOW)", val, dots);
        printf("\n");
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
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    // Set up signal handler to allow "retreating" to the menu
    keep_running_defenses = 1;
    signal(SIGINT, handle_sigint);

    int threat_level = 10;
    while (keep_running_defenses) {
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

    // Restore default signal handler and return
    signal(SIGINT, SIG_DFL);
    printf("\nRetreating to pillow fort... Defenses standing by.\n");
    log_event("DEFENSES DISENGAGED. RETREATED TO PILLOW FORT.");
}

/**
 * Displays the last 10 entries of the holy scrolls using a circular buffer approach.
 */
void view_holy_scrolls() {
    printf("\n--- VIEWING HOLY SCROLLS ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. Start monitoring to record truth.\n");
        return;
    }

    char lines[10][256];
    int count = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp)) {
        strncpy(lines[count % 10], buffer, 256);
        count++;
    }
    fclose(fp);

    int start = (count > 10) ? (count % 10) : 0;
    int display_count = (count > 10) ? 10 : count;

    for (int i = 0; i < display_count; i++) {
        printf("%s", lines[(start + i) % 10]);
    }

    printf("\nPress Enter to return to the command center...");
    getchar();
}

/**
 * Simulates a high-speed synchronization protocol with the Polish cows.
 */
void synchronize_with_cows() {
    printf("\n--- SYNCHRONIZING WITH POLISH COWS ---\n");
    printf("Establishing MOO-level handshake...\n");

    for (int i = 0; i <= 20; i++) {
        printf("\r[%-20.*s] %d%% Synchronizing...", i, "####################", i * 5);
        fflush(stdout);
        usleep(100000); // 0.1 seconds
    }

    printf("\n\nSYNC COMPLETE. Cow dopamine levels optimized at 3 AM levels.\n");
    printf("Alert synergy: MAXIMUM.\n");
    printf("\nPress Enter to return to the command center...");
    getchar();
}

/**
 * Displays the current status of the pillow fort.
 */
void show_pillow_fort_status() {
    printf("\n--- PILLOW FORT STATUS REPORT ---\n");

    int integrity = 85 + (rand() % 15);
    int supplies = 40 + (rand() % 60);

    printf("Fort Structural Integrity: [%-10.*s] %d%%\n", (integrity / 10), "##########", integrity);
    printf("Canned Bean Supplies:      [%-10.*s] %d%%\n", (supplies / 10), "##########", supplies);
    printf("Flashlight Batteries:      [OPERATIONAL]\n");
    printf("Squirrel Decoys Deployed:  %d\n", rand() % 5);

    printf("\nStatus: THE FORT HOLDS.\n");
    printf("\nPress Enter to return to the command center...");
    getchar();
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
            printf("\n" RED "AUTHENTICATION FAILED: INCORRECT PRAYER." RESET "\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER");
            return 0;
        }
    }

    printf("\n" GRN "AUTHENTICATION SUCCESSFUL. Welcome, Sentinel." RESET "\n");
    log_event("AUTHENTICATION SUCCESSFUL");
    return 1;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();
    log_event("AUTHENTICATION INITIATED");

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    int running = 1;

    while (running) {
        printf("\n--- %sMAIN COMMAND CENTER%s ---\n", CYN, RESET);
        printf("1. " GRN "ENGAGE DEFENSES" RESET "\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf("5. " RED "EXIT (COWARDLY)" RESET "\n");
        printf("> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "SYNCHRONIZE WITH COWS") == 0) {
            synchronize_with_cows();
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "PILLOW FORT STATUS") == 0) {
            show_pillow_fort_status();
        } else if (strcasecmp(command, "5") == 0 || strcasecmp(command, "EXIT") == 0 || strcasecmp(command, "EXIT (COWARDLY)") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            running = 0;
        } else {
            printf("Invalid command. The squirrels are gaining on you!\n");
        }
    }

    return 0;
}
