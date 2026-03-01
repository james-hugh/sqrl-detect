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
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define CYN "\x1B[36m"
#define RESET "\x1B[0m"

/* --- FUNCTION PROTOTYPES --- */
void init_system();
void log_event(const char *event);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
void toggle_raw_alert_mode();
void interrogate_squirrel();
int authenticate_user();
void normalize_input(char *str);
void handle_sigint(int sig);

/* --- GLOBAL STATE --- */
volatile sig_atomic_t keep_running_defenses = 1;
int raw_alert_mode = 0;

/* --- UTILITIES --- */

/**
 * Strips leading/trailing whitespace and newlines from a string.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Trim trailing
    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }

    // Trim leading
    size_t start = 0;
    while (str[start] && isspace((unsigned char)str[start])) {
        start++;
    }

    if (start > 0) {
        memmove(str, str + start, len - start + 1);
    }
}

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
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
    if (bars < 0) bars = 0;
    if (bars > METER_WIDTH) bars = METER_WIDTH;

    printf("SQUIRREL THREAT METER: %s[%s]%s [%.*s%.*s] %d%%\n",
           color, status, RESET, bars, bars_fill, METER_WIDTH - bars, bars_empty, level);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char bars[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char dots[] = "....................";
    static const char stars[] = "********************";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 21; // 0 to 20
        printf("%2d |", val);
        if (val > 15) {
            printf("%.*s", val, bars);
        } else if (val > 8) {
            printf("%.*s", val, stars);
        } else {
            printf("%.*s", val, dots);
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
 * Signal handler for SIGINT to allow graceful exit from the monitoring loop.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

/**
 * Displays the last 10 log entries (the holy scrolls).
 */
void view_holy_scrolls() {
    printf("\n%s--- THE HOLY SCROLLS OF TRUTH (Last 10 Entries) ---%s\n", CYN, RESET);
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels have been quiet... too quiet.\n");
    } else {
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

        int start = (count > 10) ? (count % 10) : 0;
        int total = (count > 10) ? 10 : count;
        for (int i = 0; i < total; i++) {
            printf("%s", lines[(start + i) % 10]);
        }

        for (int i = 0; i < 10; i++) {
            if (lines[i]) free(lines[i]);
        }
    }
    printf("\n[Press ENTER to return to your pillow fort]");
    getchar();
}

/**
 * Simulates synchronization with Polish cows.
 */
void synchronize_with_cows() {
    printf("\n%s--- SYNCHRONIZING WITH POLISH COWS (3 AM PROTOCOL) ---%s\n", CYN, RESET);
    printf("Establishing Fungal Link...\n");
    for (int i = 0; i <= 20; i++) {
        printf("\r[%-20.*s] %d%% MOOING...", i, "####################", i * 5);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n\n%sSUCCESS: Phase-lock with 3 AM cocaine laps established.%s\n", GRN, RESET);
    printf("Network paranoia increased by 15%%.\n");
    log_event("COW SYNCHRONIZATION SUCCESSFUL.");
    printf("\n[Press ENTER to return to your pillow fort]");
    getchar();
}

/**
 * Displays the current integrity and supply status of the pillow fort.
 */
void show_pillow_fort_status() {
    printf("\n%s--- PILLOW FORT COMMAND CENTER STATUS ---%s\n", CYN, RESET);
    printf("Integrity:  [##########----------] 50%% (Slightly lopsided)\n");
    printf("Blanket Ops: [#################---] 85%% (Cozy)\n");
    printf("Acorn Stock: [##------------------] 10%% (CRITICAL: FEED THE COWS)\n");
    printf("Flashlight: [########------------] 40%% (Batteries fading)\n");
    printf("\nStatus: %sDEFENSIBLE%s\n", GRN, RESET);
    printf("\n[Press ENTER to return to your pillow fort]");
    getchar();
}

/**
 * Toggles the [RAW-ALERT] mode.
 */
void toggle_raw_alert_mode() {
    raw_alert_mode = !raw_alert_mode;
    printf("\nRAW-ALERT Mode: %s%s%s\n",
           raw_alert_mode ? RED : GRN,
           raw_alert_mode ? "ENABLED (MAXIMUM PARANOIA)" : "DISABLED",
           RESET);
    log_event(raw_alert_mode ? "RAW-ALERT MODE ENABLED." : "RAW-ALERT MODE DISABLED.");
    sleep(1);
}

/**
 * Interactive interrogation module for captured rodents.
 */
void interrogate_squirrel() {
    char input[50];
    printf("\n%s--- SQUIRREL INTERROGATION CHAMBER ---%s\n", RED, RESET);
    printf("A suspicious squirrel has been captured near the router.\n");

    while (1) {
        printf("\nActions: 1. Interrogate  2. Bribe  3. Offer Acorn  4. Release\n");
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        normalize_input(input);

        if (strcmp(input, "1") == 0) {
            printf("Squirrel: *Chirp chirp* (Translation: 'I know nothing of the Google Machine!')\n");
        } else if (strcmp(input, "2") == 0) {
            printf("Squirrel: *Takes the shiny coin and buries it immediately*\n");
        } else if (strcmp(input, "3") == 0) {
            printf("Squirrel: *Sniffs the acorn suspiciously* 'Is this a WiFi tracker?'\n");
        } else if (strcmp(input, "4") == 0) {
            printf("The squirrel flees to the nearest bush. Paranoia increases.\n");
            break;
        } else {
            printf("The squirrel stares at you blankly.\n");
        }
    }
    printf("\n[Press ENTER to return to your pillow fort]");
    getchar();
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

            if (raw_alert_mode) {
                printf("%s[RAW-ALERT ACTIVE]%s ", RED, RESET);
            }
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
    printf("\n\nRetreating to pillow fort command center...\n");
    sleep(1);
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
    log_event("AUTHENTICATION INITIATED.");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        normalize_input(command);
        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER.");
            return 0;
        }
    }

    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    log_event("AUTHENTICATION SUCCESSFUL.");
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
        printf("\033[H\033[J");
        printf("%s🖥️  STNM3K PILLOW FORT COMMAND CENTER%s\n", CYN, RESET);
        printf("--------------------------------------\n");
        printf("%s1. ENGAGE DEFENSES%s\n", GRN, RESET);
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf("5. TOGGLE RAW-ALERT MODE (%s)\n", raw_alert_mode ? "ON" : "OFF");
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
            toggle_raw_alert_mode();
        } else if (strcasecmp(command, "6") == 0 || strcasecmp(command, "INTERROGATE SQUIRREL") == 0) {
            interrogate_squirrel();
        } else if (strcasecmp(command, "7") == 0 || strcasecmp(command, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else if (strlen(command) > 0) {
            printf("Unknown command. The Polish cows are confused.\n");
            sleep(1);
        }
    }

    return 0;
}
