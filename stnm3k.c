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

/* --- CONFIGURATION MACROS --- */
#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_DIR "logs"
#define LOG_FILE "logs/holy_scrolls.txt"
#define METER_WIDTH 20

/* ANSI Colors */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define CYN   "\x1B[36m"
#define RESET "\x1B[0m"

/* --- GLOBAL STATE --- */
volatile sig_atomic_t keep_running_defenses = 1;
int raw_alert_mode = 0;

/* --- FUNCTION PROTOTYPES --- */
void init_system();
void log_event(const char *event);
void normalize_input(char *str);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
void toggle_raw_alert_mode();
void interrogate_squirrel();
void handle_sigint(int sig);

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Signal handler to gracefully exit the monitoring loop.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

/**
 * Trims leading and trailing whitespace/newlines from a string in-place.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Trim trailing whitespace and newlines
    int len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }

    // Trim leading whitespace
    int start = 0;
    while (str[start] != '\0' && isspace((unsigned char)str[start])) {
        start++;
    }

    if (start > 0) {
        memmove(str, str + start, len - start + 1);
    }
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));

    // Ensure logs are created with restricted permissions
    umask(0077);

    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) != 0) {
            perror("Failed to create log directory");
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

    // Set up signal handler to allow returning to menu
    keep_running_defenses = 1;
    signal(SIGINT, handle_sigint);

    int threat_level = 10;
    while (keep_running_defenses) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        if (raw_alert_mode) {
            printf("%s[RAW-ALERT ACTIVE]%s\n", RED, RESET);
        }

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
            if (raw_alert_mode) printf("%s[PARANOIA OVERRIDE: STAY VIGILANT]%s\n", RED, RESET);
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
    printf("\nRetreating to pillow fort... (Cleaning up acorns)\n");
    log_event("DEFENSES DISENGAGED. RETREATED TO PILLOW FORT.");
    sleep(1);
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

        normalize_input(command);

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\nINCORRECT PRAYER: \"%s\"\n", command);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER");
            return 0;
        }
    }

    log_event("AUTHENTICATION SUCCESSFUL");
    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    return 1;
}

/**
 * Displays the last 10 lines of the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nThe holy scrolls are empty. The squirrels have stolen our history.\n");
        return;
    }

    char *lines[10];
    for (int i = 0; i < 10; i++) lines[i] = NULL;

    char buffer[256];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (lines[count % 10]) free(lines[count % 10]);
        lines[count % 10] = strdup(buffer);
        count++;
    }
    fclose(fp);

    printf("\n--- THE HOLY SCROLLS OF TRUTH (Last %d entries) ---\n", count < 10 ? count : 10);
    int start = (count > 10) ? (count % 10) : 0;
    for (int i = 0; i < (count < 10 ? count : 10); i++) {
        printf("%s", lines[(start + i) % 10]);
        free(lines[(start + i) % 10]);
    }
    printf("--- END OF SCROLLS ---\n");
    printf("\nPress Enter to return to your pillow fort...");
    getchar();
}

/**
 * Interactive squirrel interrogation sub-menu.
 */
void interrogate_squirrel() {
    char sub_cmd[100];
    int interrogation_active = 1;

    printf("\n%s--- SQUIRREL INTERROGATION CHAMBER ---%s\n", RED, RESET);
    printf("A suspicious squirrel has been captured near the router.\n");

    while (interrogation_active) {
        printf("\n1. INTERROGATE\n");
        printf("2. BRIBE WITH PEANUT\n");
        printf("3. OFFER ACORN\n");
        printf("4. RELEASE (DANGEROUS)\n");
        printf("> ");

        if (fgets(sub_cmd, sizeof(sub_cmd), stdin) == NULL) break;
        normalize_input(sub_cmd);

        if (strstr(sub_cmd, "1") || strcasecmp(sub_cmd, "INTERROGATE") == 0) {
            const char *responses[] = {
                "The squirrel chitters defiantly.",
                "It stares at you with cold, bead-like eyes.",
                "It points towards the nearest WiFi tower.",
                "It refuses to speak without its lawyer (a pigeon)."
            };
            printf("\nRESULT: %s\n", responses[rand() % 4]);
        } else if (strstr(sub_cmd, "2") || strcasecmp(sub_cmd, "BRIBE WITH PEANUT") == 0) {
            printf("\nRESULT: The squirrel takes the peanut and hides it in its cheek. It remains silent.\n");
        } else if (strstr(sub_cmd, "3") || strcasecmp(sub_cmd, "OFFER ACORN") == 0) {
            printf("\nRESULT: The squirrel sniffs the acorn. It seems insulted by the quality.\n");
        } else if (strstr(sub_cmd, "4") || strcasecmp(sub_cmd, "RELEASE") == 0) {
            printf("\nRESULT: The squirrel vanishes into the bushes. It will likely return with reinforcements.\n");
            interrogation_active = 0;
        } else {
            printf("\nINVALID ACTION. The squirrel mocks your indecision.\n");
        }
    }

    printf("\nPress Enter to return to your pillow fort...");
    getchar();
}

/**
 * Toggles the RAW-ALERT mode flag.
 */
void toggle_raw_alert_mode() {
    raw_alert_mode = !raw_alert_mode;
    printf("\nRAW-ALERT MODE: %s%s%s\n",
           raw_alert_mode ? RED : GRN,
           raw_alert_mode ? "ENABLED (PARANOIA LEVEL: MAXIMUM)" : "DISABLED (VIGILANCE LEVEL: STANDARD)",
           RESET);

    if (raw_alert_mode) {
        log_event("RAW-ALERT MODE ENABLED. ALL POPUPS ARE NOW HOLY.");
    } else {
        log_event("RAW-ALERT MODE DISABLED. BACK TO STANDARD COW VIGILANCE.");
    }

    printf("\nPress Enter to return to your pillow fort...");
    getchar();
}

/**
 * Displays the current status and integrity of the pillow fort command center.
 */
void show_pillow_fort_status() {
    printf("\n%s--- PILLOW FORT COMMAND CENTER STATUS ---%s\n", CYN, RESET);

    int integrity = 85 + (rand() % 15);
    int blankets = 90 + (rand() % 10);
    int pillows = 100;
    int chocolate_rations = rand() % 100;

    printf("Structural Integrity: [%-20.*s] %d%%\n", integrity / 5, "####################", integrity);
    printf("Blanket Coverage:     [%-20.*s] %d%%\n", blankets / 5, "####################", blankets);
    printf("Pillow Density:       [%-20.*s] %d%%\n", pillows / 5, "####################", pillows);
    printf("Chocolate Rations:    [%-20.*s] %d%%\n", chocolate_rations / 5, "####################", chocolate_rations);

    printf("\nStatus: %sSECURE%s\n", GRN, RESET);
    printf("Note: Periscope is clear of squirrels. All cushions are fluffed.\n");

    printf("\nPress Enter to return to your pillow fort...");
    getchar();
}

/**
 * Simulates synchronization with Polish cows using an animated progress bar.
 */
void synchronize_with_cows() {
    printf("\n%s--- INITIATING POLISH COW SYNCHRONIZATION ---%s\n", CYN, RESET);
    printf("Contacting 3 AM cocaine-enhanced bovine nodes...\n");

    const char *messages[] = {
        "Establishing MOO-protocol link...",
        "Parsing grass-fed packet streams...",
        "Calibrating 5mg cocaine offset...",
        "Synchronizing lap frequency...",
        "Finalizing udder-encrypted handshake..."
    };

    for (int i = 0; i < 5; i++) {
        printf("\r[%-50s] %s", "", messages[i]);
        fflush(stdout);
        for (int j = 0; j < 10; j++) {
            usleep(100000); // 100ms
            int progress = (i * 10) + j + 1;
            char bar[51];
            memset(bar, '#', progress);
            memset(bar + progress, ' ', 50 - progress);
            bar[50] = '\0';
            printf("\r[%s] %d%% %s", bar, progress * 2, messages[i]);
            fflush(stdout);
        }
    }

    printf("\n\n%sSUCCESS: Synchronization complete. Cow vigilance at 100%%%s\n", GRN, RESET);
    log_event("COW SYNCHRONIZATION COMPLETED. LAPS ARE OPTIMAL.");
    printf("\nPress Enter to return to your pillow fort...");
    getchar();
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\033[H\033[J");
        printf("%s--- PILLOW FORT COMMAND CENTER ---%s\n", CYN, RESET);
        printf("Welcome, Sentinel. Choose your action:\n\n");
        printf("%s1. ENGAGE DEFENSES%s\n", GRN, RESET);
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf("5. TOGGLE RAW-ALERT MODE\n");
        printf("6. INTERROGATE SQUIRREL\n");
        printf("%s7. EXIT (COWARDLY)%s\n", RED, RESET);
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strstr(command, "1") || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strstr(command, "2") || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strstr(command, "3") || strcasecmp(command, "SYNCHRONIZE WITH COWS") == 0) {
            synchronize_with_cows();
        } else if (strstr(command, "4") || strcasecmp(command, "PILLOW FORT STATUS") == 0) {
            show_pillow_fort_status();
        } else if (strstr(command, "5") || strcasecmp(command, "TOGGLE RAW-ALERT MODE") == 0) {
            toggle_raw_alert_mode();
        } else if (strstr(command, "6") || strcasecmp(command, "INTERROGATE SQUIRREL") == 0) {
            interrogate_squirrel();
        } else if (strstr(command, "7") || strcasecmp(command, "EXIT") == 0) {
            printf("\nCowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("\nINVALID COMMAND. The Google Machine is laughing at your confusion.\n");
            sleep(1);
        }
    }

    return 0;
}
