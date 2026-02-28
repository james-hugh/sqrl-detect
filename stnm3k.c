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
#include <signal.h>
#include <strings.h>
#include <ctype.h>

#include <sys/stat.h>
#include <sys/types.h>

/* --- CONFIGURATION MACROS --- */
#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_DIR "logs"
#define LOG_FILE "logs/holy_scrolls.txt"
#define METER_WIDTH 20

/* --- GLOBAL STATE --- */
volatile sig_atomic_t keep_running_defenses = 1;
int raw_alert_mode = 0;

/* ANSI Colors */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Normalizes user input by stripping leading/trailing whitespace and newlines.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Trim trailing whitespace and newlines
    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }

    // Trim leading whitespace
    size_t start = 0;
    while (str[start] && isspace((unsigned char)str[start])) {
        start++;
    }

    if (start > 0) {
        memmove(str, str + start, len - start + 1);
    }
}

/**
 * Handles the SIGINT signal to gracefully return from monitoring to the main menu.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

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

/**
 * Displays the last 10 entries of the holy scrolls using a circular buffer.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The holy scrolls are empty or missing. Perhaps the squirrels ate them?\n");
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

    printf("\n--- LAST 10 ENTRIES OF THE HOLY SCROLLS ---\n");
    if (count == 0) {
        printf("(The scrolls are currently blank...)\n");
    } else {
        int start = (count > 10) ? (count % 10) : 0;
        int total = (count > 10) ? 10 : count;
        for (int i = 0; i < total; i++) {
            printf("%s", lines[(start + i) % 10]);
            free(lines[(start + i) % 10]);
        }
    }
    printf("-------------------------------------------\n");
    printf("\nPress Enter to return to your pillow fort...");
    getchar();
}

/**
 * Performs a simulated synchronization with Polish cows using an animated progress bar.
 */
void synchronize_with_cows() {
    printf("\n--- INITIATING COW SYNCHRONIZATION (MOO PROTOCOL v2.1) ---\n");
    printf("Contacting 3 AM cocaine-enhanced sentinels...\n");

    for (int i = 0; i <= 20; i++) {
        printf("\r[");
        for (int j = 0; j < 20; j++) {
            if (j < i) printf("=");
            else if (j == i) printf(">");
            else printf(" ");
        }
        printf("] %d%% MOO", i * 5);
        fflush(stdout);
        usleep(100000); // 100ms
    }

    printf("\n\nSUCCESS: Cows synchronized. Frequency aligned to 3 AM cocaine laps.\n");
    log_event("COW SYNCHRONIZATION SUCCESSFUL.");
    printf("\nPress Enter to return to your pillow fort...");
    getchar();
}

/**
 * Displays mock integrity and supply metrics for the user's pillow fort.
 */
void show_pillow_fort_status() {
    printf("\n--- PILLOW FORT COMMAND CENTER STATUS ---\n");
    printf("Location: Under the IKEA table (Sector 4)\n\n");

    int integrity = 85 + (rand() % 16);
    int snacks = 40 + (rand() % 61);

    printf("Structural Integrity: [%d%%] ", integrity);
    for (int i = 0; i < 20; i++) {
        if (i < integrity / 5) printf("#");
        else printf("-");
    }
    printf(" (STABLE)\n");

    printf("Cheese Puff Supplies: [%d%%] ", snacks);
    for (int i = 0; i < 20; i++) {
        if (i < snacks / 5) printf("#");
        else printf("-");
    }
    printf(snacks < 50 ? " (RESTOCK REQUIRED)\n" : " (SUFFICIENT)\n");

    printf("Current Occupant: Sentinel (Vigilant)\n");
    printf("Squirrel Detainment: NONE\n");
    printf("------------------------------------------\n");
    printf("\nPress Enter to return to your pillow fort...");
    getchar();
}

/**
 * Enters the Squirrel Interrogation Chamber for an interactive sub-menu.
 */
void interrogate_squirrel() {
    char command[100];
    int interrogation_active = 1;

    printf("\n--- SQUIRREL INTERROGATION CHAMBER ---\n");
    printf("A suspicious rodent has been captured near the router.\n");
    printf("He is wearing a tiny headset. The Google Machine is listening.\n");

    while (interrogation_active) {
        printf("\n1. INTERROGATE (STERNLY)\n");
        printf("2. BRIBE WITH PEANUTS\n");
        printf("3. OFFER ACORN OF TRUTH\n");
        printf("4. RELEASE (UNWISE)\n");
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "INTERROGATE") == 0) {
            const char* responses[] = {
                "The squirrel chatters defiantly about 'The Great Acorn'.",
                "The squirrel points toward the Google Machine HQ.",
                "The squirrel remains silent, but its tail twitches nervously.",
                "The squirrel tries to chew through its tiny headset."
            };
            printf("\nRESULT: %s\n", responses[rand() % 4]);
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "BRIBE") == 0) {
            printf("\nRESULT: The squirrel eats the peanuts but tells you nothing. Typical.\n");
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "OFFER") == 0) {
            printf("\nRESULT: The squirrel is hypnotized by the Acorn of Truth! It reveals the location of the main WiFi acorn in sector 7.\n");
            log_event("SQUIRREL REVEALED WiFi ACORN LOCATION.");
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "RELEASE") == 0) {
            printf("\nRESULT: You release the squirrel. It immediately runs to the nearest bush to report your position.\n");
            interrogation_active = 0;
        } else {
            printf("\nThe squirrel is confused by your command. It stares at you with black, soulless eyes.\n");
        }
    }

    printf("\nExiting interrogation chamber...\n");
    printf("\nPress Enter to return to your pillow fort...");
    getchar();
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
    static const char template[] = "XXXXXXXXXXXXXXXXXXXX********************....................";
    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        int offset = 40;
        if (val > 15) { offset = 0; }
        else if (val > 8) { offset = 20; }

        printf("%2d |%.*s\n", val, val, template + offset);
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
    while (keep_running_defenses) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        if (raw_alert_mode) {
            printf("%s[RAW-ALERT ACTIVE]%s\n", RED, RESET);
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

            if (raw_alert_mode) {
                printf("%s###################################################%s\n", alert_color, RESET);
                printf("%s#                                                 #%s\n", alert_color, RESET);
                printf("%s#   !!! %-39s !!!   #%s\n", alert_color, alert_name, RESET);
                printf("%s#                                                 #%s\n", alert_color, RESET);
                printf("%s###################################################%s\n", alert_color, RESET);
            } else {
                printf("\n%s!!! %s !!!%s\n", alert_color, alert_name, RESET);
            }
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        }

        printf("\nMonitoring... (Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);
        sleep(1);
    }
    printf("\nReturning to Command Center. The Polish cows are standing down.\n");
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
    signal(SIGINT, handle_sigint);

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    int running = 1;

    while (running) {
        printf("\n--- MAIN COMMAND CENTER ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf("5. TOGGLE RAW-ALERT MODE\n");
        printf("6. INTERROGATE SQUIRREL\n");
        printf("7. EXIT (COWARDLY)\n");
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        normalize_input(command);

        if (strcasecmp(command, "1") == 0 || strcasecmp(command, "ENGAGE DEFENSES") == 0) {
            keep_running_defenses = 1;
            engage_defenses();
        } else if (strcasecmp(command, "2") == 0 || strcasecmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcasecmp(command, "3") == 0 || strcasecmp(command, "SYNCHRONIZE WITH COWS") == 0) {
            synchronize_with_cows();
        } else if (strcasecmp(command, "4") == 0 || strcasecmp(command, "PILLOW FORT STATUS") == 0) {
            show_pillow_fort_status();
        } else if (strcasecmp(command, "5") == 0 || strcasecmp(command, "TOGGLE RAW-ALERT MODE") == 0) {
            raw_alert_mode = !raw_alert_mode;
            printf("\nRAW-ALERT MODE: %s\n", raw_alert_mode ? "ENABLED (GLORY BE)" : "DISABLED");
        } else if (strcasecmp(command, "6") == 0 || strcasecmp(command, "INTERROGATE SQUIRREL") == 0) {
            interrogate_squirrel();
        } else if (strcasecmp(command, "7") == 0 || strcasecmp(command, "EXIT") == 0) {
            printf("\nCowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            running = 0;
        } else if (strlen(command) > 0) {
            printf("\nUNKNOWN COMMAND. The Google Machine is mocking your incompetence.\n");
        }
    }

    return 0;
}
