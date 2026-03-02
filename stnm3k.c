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
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#include <sys/stat.h>
#include <sys/types.h>

/* --- FUNCTION PROTOTYPES --- */
void init_system();
void log_event(const char *event);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();
void normalize_input(char *str);
void handle_sigint(int sig);
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
void toggle_raw_alert();
void interrogate_squirrel();

/* --- CONFIGURATION MACROS --- */
#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_DIR "logs"
#define LOG_FILE "logs/holy_scrolls.txt"
#define METER_WIDTH 20

/* --- GLOBAL STATE --- */
volatile sig_atomic_t keep_running_defenses = 1;

/* ANSI Colors */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define CYN "\x1B[36m"
#define RESET "\x1B[0m"

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Normalizes input by trimming leading/trailing whitespace and newlines.
 */
void normalize_input(char *str) {
    if (!str) return;

    // Trim trailing
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }

    // Trim leading
    char *start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    umask(0077); // Ensure process-wide restricted file permissions
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
    static const char stars[]    = "********************";
    static const char dots[]     = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15)      printf("%.*s", val, template);
        else if (val > 8)  printf("%.*s", val, stars);
        else               printf("%.*s", val, dots);
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
 * Signal handler for SIGINT to gracefully stop monitoring.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

/**
 * Enters the main monitoring loop.
 */
void engage_defenses() {
    keep_running_defenses = 1;
    signal(SIGINT, handle_sigint);

    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

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

    signal(SIGINT, SIG_DFL);
    printf("\n\nRetreating to pillow fort... (Press ENTER to continue)\n");
    log_event("DEFENSES DISENGAGED. RETREATED TO PILLOW FORT.");
    getchar(); // Consume the newline from the last input or wait for enter
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char command[100];
    int prayer_count = 0;

    log_event("AUTHENTICATION INITIATED.");
    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        normalize_input(command);

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER.");
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

    log_event("AUTHENTICATION SUCCESSFUL.");
    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    return 1;
}

/**
 * MOCK: View Holy Scrolls (Last 10 lines)
 */
void view_holy_scrolls() {
    printf("\n--- HOLY SCROLLS OF TRUTH (Last 10 Events) ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels are planning something.\n");
    } else {
        char lines[10][256];
        int count = 0;
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp)) {
            strncpy(lines[count % 10], buffer, 256);
            count++;
        }
        fclose(fp);

        int start = (count > 10) ? (count % 10) : 0;
        int total = (count > 10) ? 10 : count;
        for (int i = 0; i < total; i++) {
            printf("%s", lines[(start + i) % 10]);
        }
    }
    printf("\n(Press ENTER to return to Command Center)\n");
    getchar();
}

/**
 * MOCK: Synchronize with Cows
 */
void synchronize_with_cows() {
    printf("\n--- SYNCHRONIZING WITH POLISH COWS ---\n");
    printf("Establishing MOO-protocol link...\n");
    for (int i = 0; i <= 10; i++) {
        printf("\r[");
        for (int j = 0; j < 10; j++) {
            if (j < i) printf("=");
            else printf(" ");
        }
        printf("] %d0%% MOOING...", i);
        fflush(stdout);
        usleep(200000);
    }
    printf("\nSynchronization complete. Laps being run: %d\n", rand() % 50);
    printf("(Press ENTER to return to Command Center)\n");
    getchar();
}

/**
 * MOCK: Pillow Fort Status
 */
void show_pillow_fort_status() {
    printf("\n--- PILLOW FORT STRATEGIC STATUS ---\n");
    printf("Integrity: %d%%\n", 80 + (rand() % 21));
    printf("Supplies: %d Acorns, %d Juice Boxes\n", rand() % 100, rand() % 20);
    printf("Defensive Layer: FLUFFY\n");
    printf("(Press ENTER to return to Command Center)\n");
    getchar();
}

/**
 * MOCK: Toggle RAW-ALERT Mode
 */
void toggle_raw_alert() {
    static int raw_alert = 0;
    raw_alert = !raw_alert;
    printf("\nRAW-ALERT MODE: %s\n", raw_alert ? "ENABLED (GLORY BE)" : "DISABLED");
    if (raw_alert) {
        printf("WARNING: ALL POPUPS WILL NOW BE HOLY AND UNSTOPPABLE.\n");
    }
    printf("(Press ENTER to return to Command Center)\n");
    getchar();
}

/**
 * MOCK: Interrogate Squirrel
 */
void interrogate_squirrel() {
    printf("\n--- SQUIRREL INTERROGATION CHAMBER ---\n");
    printf("A suspicious squirrel has been captured in your pillow fort.\n");
    printf("1. Interrogate\n");
    printf("2. Bribe with Acorn\n");
    printf("3. Release (Cowardly)\n");
    printf("> ");

    char choice[10];
    if (fgets(choice, sizeof(choice), stdin)) {
        normalize_input(choice);
        if (strcmp(choice, "1") == 0) {
            printf("Squirrel: *Squeak* (Translation: 'I know nothing about the Google Machine!')\n");
        } else if (strcmp(choice, "2") == 0) {
            printf("The squirrel takes the acorn and points toward sector 7.\n");
        } else {
            printf("The squirrel escapes and laughs in WiFi.\n");
        }
    }
    printf("(Press ENTER to return to Command Center)\n");
    getchar();
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    int running = 1;

    while (running) {
        printf("\033[H\033[J"); // Clear screen
        printf("%s🖥️  STNM3K COMMAND CENTER%s\n", CYN, RESET);
        printf("--------------------------\n");
        printf("%s1. ENGAGE DEFENSES%s\n", GRN, RESET);
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf("5. TOGGLE RAW-ALERT MODE\n");
        printf("6. INTERROGATE SQUIRREL\n");
        printf("%s7. EXIT (COWARDLY)%s\n", RED, RESET);
        printf("> ");

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
        } else if (strcasecmp(command, "5") == 0 || strcasecmp(command, "TOGGLE RAW-ALERT MODE") == 0) {
            toggle_raw_alert();
        } else if (strcasecmp(command, "6") == 0 || strcasecmp(command, "INTERROGATE SQUIRREL") == 0) {
            interrogate_squirrel();
        } else if (strcasecmp(command, "7") == 0 || strcasecmp(command, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            running = 0;
        } else {
            printf("Unknown command. The squirrels are laughing at you. (Press ENTER to continue)\n");
            getchar();
        }
    }

    return 0;
}
