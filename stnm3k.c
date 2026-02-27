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
#include <errno.h>
#include <ctype.h>
#include <strings.h>

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
void normalize_input(char *str);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
int authenticate_user();
void sigint_handler(int sig);
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
void toggle_raw_alert_mode();
void interrogate_squirrel();

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);

    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) != 0) {
            perror("Failed to create log directory");
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * Normalizes input by stripping leading/trailing whitespace and newlines.
 */
void normalize_input(char *str) {
    if (!str) return;

    // Remove trailing whitespace/newline
    str[strcspn(str, "\r\n")] = '\0';
    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }

    // Remove leading whitespace
    char *start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
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
    static const char template[] = "XXXXXXXXXXXXXXXXXXXX"; // Max 20 chars
    static const char template_star[] = "********************";
    static const char template_dot[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, template);
        else if (val > 8) printf("%.*s", val, template_star);
        else printf("%.*s", val, template_dot);
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
 * Signal handler for SIGINT to gracefully exit the monitoring loop.
 */
void sigint_handler(int sig) {
    (void)sig;
    keep_running_defenses = 0;
}

/**
 * Enters the main monitoring loop.
 */
void engage_defenses() {
    signal(SIGINT, sigint_handler);
    keep_running_defenses = 1;

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
            if (raw_alert_mode) {
                printf("%s[RAW-ALERT ACTIVE: STAY ON TOP]%s\n", RED, RESET);
            }
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        }

        printf("\nMonitoring... (Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);
        sleep(1);
    }

    signal(SIGINT, SIG_DFL);
    printf("\nRetreating to pillow fort... Defensive posture maintained.\n");
    log_event("DEFENSES DISENGAGED (STRATEGIC RETREAT).");
    printf("\nPress ENTER to continue...");
    getchar();
}

/**
 * Displays the last 10 entries from the holy scrolls.
 */
void view_holy_scrolls() {
    printf("\n--- %sHOLY SCROLLS OF TRUTH%s ---\n", CYN, RESET);
    FILE *fp = fopen(LOG_FILE, "r");
    if (!fp) {
        printf("The scrolls are empty. The squirrels are winning.\n");
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

    if (count == 0) printf("The scrolls remain unwritten. Watch the cows.\n");

    printf("\nPress ENTER to return to the Command Center...");
    getchar();
}

/**
 * Performs a simulated MOO protocol synchronization with Polish cows.
 */
void synchronize_with_cows() {
    printf("\n--- %sSYNCHRONIZING WITH POLISH COWS (3 AM COCAINE LAPS)%s ---\n", CYN, RESET);
    const char *stages[] = {
        "Establishing fungal link...",
        "Checking cow heart rates (Target: 180 BPM)...",
        "Broadcasting MOO packets...",
        "Calibrating lap times...",
        "Synchronizing with the Great Bovine in the Sky..."
    };

    for (int i = 0; i < 5; i++) {
        printf("%s\n", stages[i]);
        printf("[");
        for (int j = 0; j < 20; j++) {
            printf("#");
            fflush(stdout);
            usleep(50000); // 50ms
        }
        printf("] %d%% - MOO!\r", (i + 1) * 20);
        fflush(stdout);
        sleep(1);
        printf("\n");
    }

    printf("\n%sSYNCHRONIZATION COMPLETE.%s The cows are running at optimal velocity.\n", GRN, RESET);
    log_event("COW SYNCHRONIZATION SUCCESSFUL. LAPS VERIFIED.");
    printf("\nPress ENTER to continue...");
    getchar();
}

/**
 * Displays the current integrity and supply levels of the pillow fort.
 */
void show_pillow_fort_status() {
    printf("\n--- %sPILLOW FORT STATUS REPORT%s ---\n", CYN, RESET);
    int integrity = 80 + (rand() % 21);
    int snacks = rand() % 101;
    int morale = 90 + (rand() % 11);

    printf("Structural Integrity: [");
    for (int i = 0; i < 20; i++) printf(i < integrity / 5 ? "#" : "-");
    printf("] %d%%\n", integrity);

    printf("Snack Reserves:      [");
    for (int i = 0; i < 20; i++) printf(i < snacks / 5 ? "#" : "-");
    printf("] %d%%\n", snacks);

    printf("Sentinel Morale:     [");
    for (int i = 0; i < 20; i++) printf(i < morale / 5 ? "#" : "-");
    printf("] %d%%\n", morale);

    if (snacks < 20) printf("%sWARNING: SNACK RESERVES CRITICALLY LOW. SQUIRRELS MAY EXPLOIT THIS.%s\n", RED, RESET);

    printf("\nPress ENTER to return to safety...");
    getchar();
}

/**
 * Toggles RAW-ALERT Mode (Forces alerts to 'stay on top' of the user's paranoia).
 */
void toggle_raw_alert_mode() {
    raw_alert_mode = !raw_alert_mode;
    printf("\nRAW-ALERT Mode: %s%s%s\n",
           raw_alert_mode ? RED : GRN,
           raw_alert_mode ? "ENABLED (PARANOIA MAXIMIZED)" : "DISABLED (SAFE-ISH)",
           RESET);
    log_event(raw_alert_mode ? "RAW-ALERT MODE ENABLED" : "RAW-ALERT MODE DISABLED");
    printf("\nPress ENTER to continue...");
    getchar();
}

/**
 * Interactive squirrel interrogation feature.
 */
void interrogate_squirrel() {
    printf("\n--- %sSQUIRREL INTERROGATION CHAMBER%s ---\n", RED, RESET);
    printf("You have captured a suspicious squirrel near the perimeter.\n");
    printf("It is wearing a tiny WiFi-enabled acorn vest.\n\n");

    const char *questions[] = {
        "1. Where is the Google Machine hub?",
        "2. How many acorns are in the payload?",
        "3. Who sent you? The Chipmunks?",
        "4. GIVE UP THE FUNGAL ENCRYPTION KEYS!"
    };

    for (int i = 0; i < 4; i++) {
        printf("%s\n", questions[i]);
        printf("> ");
        fflush(stdout);
        char response[100];
        if (fgets(response, sizeof(response), stdin) == NULL) break;

        int reaction = rand() % 3;
        if (reaction == 0) printf("*Squeak!* (The squirrel looks defiant)\n");
        else if (reaction == 1) printf("*Chirp chirp!* (It's mocking your Windows ME setup)\n");
        else printf("(The squirrel remains silent, chewing a suspicious nut)\n");
    }

    printf("\nInterrogation inconclusive. The squirrel has escaped via a hidden tunnel.\n");
    log_event("SQUIRREL INTERROGATION PERFORMED. SUBJECT ESCAPED.");
    printf("\nPress ENTER to return to the fort...");
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
    log_event("AUTHENTICATION INITIATED");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        fflush(stdout);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        normalize_input(command);

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\n%sINCORRECT PRAYER.%s\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER");
            return 0;
        }
    }

    printf("\n%sAuthentication successful. Welcome, Sentinel.%s\n", GRN, RESET);
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
        printf("\n--- MAIN COMMAND CENTER ---\n");
        printf("%s1. ENGAGE DEFENSES%s\n", GRN, RESET);
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf("5. TOGGLE RAW-ALERT MODE (%s)\n", raw_alert_mode ? "ON" : "OFF");
        printf("6. INTERROGATE SQUIRREL\n");
        printf("%s7. EXIT (COWARDLY)%s\n", RED, RESET);
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
        } else if (strcasecmp(command, "5") == 0 || strcasecmp(command, "TOGGLE RAW-ALERT MODE") == 0) {
            toggle_raw_alert_mode();
        } else if (strcasecmp(command, "6") == 0 || strcasecmp(command, "INTERROGATE SQUIRREL") == 0) {
            interrogate_squirrel();
        } else if (strcasecmp(command, "7") == 0 || strcasecmp(command, "EXIT") == 0 || strcasecmp(command, "EXIT (COWARDLY)") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The Polish cows are confused.\n");
        }
    }

    return 0;
}
