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

/* --- GLOBAL STATE --- */
volatile sig_atomic_t keep_running_defenses = 1;
int raw_alert_mode = 0;

/* --- FUNCTION PROTOTYPES --- */
void init_system();
void log_event(const char *event);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();
void handle_sigint(int sig);
void normalize_input(char *str);
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
void toggle_raw_alert_mode();
void interrogate_squirrel();

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Signal handler to gracefully stop the monitoring loop.
 */
void handle_sigint(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

/**
 * Strips leading/trailing whitespace and newlines from a string.
 */
void normalize_input(char *str) {
    if (str == NULL) return;

    // Strip trailing whitespace/newlines
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }

    // Strip leading whitespace
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
 * Displays the last 10 log entries (the "holy scrolls").
 */
void view_holy_scrolls() {
    printf("\n--- VIEWING HOLY SCROLLS OF TRUTH ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels are either gone or very, very quiet.\n");
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

    int start = (count > 10) ? (count % 10) : 0;
    int display_count = (count > 10) ? 10 : count;

    for (int i = 0; i < display_count; i++) {
        printf("%s", lines[(start + i) % 10]);
        free(lines[(start + i) % 10]);
    }

    if (count == 0) {
        printf("The scrolls are blank. A clean slate, or a dark omen?\n");
    }

    printf("\n[Press ENTER to return to command center]");
    getchar();
}

/**
 * Performs a simulated cow synchronization.
 */
void synchronize_with_cows() {
    printf("\n--- SYNCHRONIZING WITH POLISH COWS ---\n");
    printf("Establishing MOO-Protocol connection...\n");
    for (int i = 0; i <= 20; i++) {
        printf("\r[%-20.*s] %d%%", i, "####################", i * 5);
        fflush(stdout);
        usleep(100000);
    }
    printf("\nSYNC COMPLETE. Cow timestamps aligned with 3 AM cocaine laps.\n");
    log_event("COW SYNCHRONIZATION SUCCESSFUL. MOO.");
    printf("\n[Press ENTER to return to command center]");
    getchar();
}

/**
 * Displays mock metrics for the pillow fort command center.
 */
void show_pillow_fort_status() {
    printf("\n--- PILLOW FORT COMMAND CENTER STATUS ---\n");
    int blanket_integrity = 85 + (rand() % 16);
    int acorn_reserves = 40 + (rand() % 61);
    int battery = rand() % 101;

    printf("Blanket Integrity: [%-10.*s] %d%%\n", blanket_integrity / 10, "##########", blanket_integrity);
    printf("Acorn Reserves:    [%-10.*s] %d units\n", acorn_reserves / 10, "##########", acorn_reserves);
    printf("Flashlight Battery: [%-10.*s] %d%%\n", battery / 10, "##########", battery);

    if (blanket_integrity < 90) printf("WARNING: Blanket corner is loose. Squirrel infiltration possible.\n");
    if (acorn_reserves < 50) printf("URGENT: Acorn supplies low. Bribe potential reduced.\n");

    printf("\n[Press ENTER to return to command center]");
    getchar();
}

/**
 * Toggles RAW-ALERT mode.
 */
void toggle_raw_alert_mode() {
    raw_alert_mode = !raw_alert_mode;
    printf("\nRAW-ALERT MODE %s.\n", raw_alert_mode ? "ACTIVATED" : "DEACTIVATED");
    log_event(raw_alert_mode ? "RAW-ALERT MODE ENABLED" : "RAW-ALERT MODE DISABLED");
    printf("[Press ENTER to return to command center]");
    getchar();
}

/**
 * Interactive rodent interrogation module.
 */
void interrogate_squirrel() {
    char input[50];
    printf("\n--- SQUIRREL INTERROGATION CHAMBER ---\n");
    printf("A suspicious squirrel has been captured near the router.\n");
    printf("It is looking at you with beady, judgmental eyes.\n");

    while (1) {
        printf("\nInterrogation Options:\n");
        printf("1. Interrogate harshly\n");
        printf("2. Bribe with acorn\n");
        printf("3. Release (Mercy)\n");
        printf("> ");

        if (fgets(input, sizeof(input), stdin) == NULL) break;
        normalize_input(input);

        if (strstr(input, "1") || strcasecmp(input, "interrogate") == 0) {
            const char* responses[] = {
                "The squirrel chatters defiantly. It knows nothing.",
                "It points a tiny paw toward the window. Is it a signal?",
                "It starts chewing on its own tail to avoid talking.",
                "It stares at you with absolute indifference."
            };
            printf("\nRESULT: %s\n", responses[rand() % 4]);
        } else if (strstr(input, "2") || strcasecmp(input, "bribe") == 0) {
            printf("\nRESULT: The squirrel takes the acorn and buried it in your keyboard. It's now a double agent.\n");
            log_event("SQUIRREL BRIBED. KEYBOARD COMPROMISED.");
        } else if (strstr(input, "3") || strcasecmp(input, "release") == 0) {
            printf("\nRESULT: The squirrel scampers away, probably to report back to the Google Machine.\n");
            break;
        } else {
            printf("\nInvalid interrogation technique.\n");
        }
    }
}

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

    signal(SIGINT, handle_sigint);
    keep_running_defenses = 1;

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
    printf("\n--- RETREATING TO PILLOW FORT ---\n");
    log_event("DEFENSES DISENGAGED. RETREATED TO PILLOW FORT.");
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
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n%s--- PILLOW FORT COMMAND CENTER ---%s\n", CYN, RESET);
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
            toggle_raw_alert_mode();
        } else if (strcasecmp(command, "6") == 0 || strcasecmp(command, "INTERROGATE SQUIRREL") == 0) {
            interrogate_squirrel();
        } else if (strcasecmp(command, "7") == 0 || strcasecmp(command, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("The Polish cows do not understand your strange signals.\n");
        }
    }

    return 0;
}
