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
#include <errno.h>
#include <ctype.h>

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
void handle_sigint(int sig);
void log_event(const char *event);
char* normalize_input(char *str);
void print_threat_meter(int level);
void print_graph_of_chaos();
const char* get_random_threat();
void engage_defenses();
void view_holy_scrolls();
void synchronize_with_cows();
void show_pillow_fort_status();
void interrogate_squirrel();
int authenticate_user();

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Signal handler for graceful defense retreat.
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
    umask(0077); // Ensure holy scrolls are for Sentinel eyes only
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) == -1) {
            perror("Failed to create log sanctuary");
            exit(EXIT_FAILURE);
        }
    }
    signal(SIGINT, handle_sigint);
}

/**
 * Strips leading/trailing whitespace and newlines from a string.
 * @param str The string to normalize.
 * @return The normalized string.
 */
char* normalize_input(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
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
    static const char bars_x[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char bars_star[] = "********************";
    static const char bars_dot[] = "....................";
    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *g_color = GRN;
        const char *g_chars = bars_dot;
        if (val > 15) {
            g_color = RED;
            g_chars = bars_x;
        } else if (val > 8) {
            g_color = YEL;
            g_chars = bars_star;
        }
        printf("%2d |%s%.*s%s\n", val, g_color, val, g_chars, RESET);
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
 * Displays the last 10 entries of the holy scrolls.
 */
void view_holy_scrolls() {
    printf("\n%s--- HOLY SCROLLS OF TRUTH (RECENT LOGS) ---%s\n", CYN, RESET);
    FILE *fp = fopen(LOG_FILE, "r");
    if (!fp) {
        printf("The scrolls are currently empty. No squirrel sins yet recorded.\n");
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
    int display = (count > 10) ? 10 : count;
    for (int i = 0; i < display; i++) {
        printf("%s", lines[(start + i) % 10]);
    }
    printf("\nPress Enter to return to Command Center...");
    getchar();
}

/**
 * Synchronizes with Polish cows using a simulated protocol.
 */
void synchronize_with_cows() {
    printf("\n%s--- SYNCHRONIZING WITH POLISH COWS ---%s\n", CYN, RESET);
    printf("Establishing MOO-link protocol...\n");
    for (int i = 0; i <= 100; i += 20) {
        printf("\r[%-10.*s] %d%%", i / 10, "##########", i);
        fflush(stdout);
        usleep(200000);
    }
    printf("\n\n%sSUCCESS:%s Synchronization complete. Cows are running laps at 3 AM.\n", GRN, RESET);
    printf("Log: All cow timestamps aligned with sacred local time.\n");
    printf("\nPress Enter to return to Command Center...");
    getchar();
}

/**
 * Displays the current integrity of the pillow fort.
 */
void show_pillow_fort_status() {
    printf("\n%s--- PILLOW FORT STATUS ---%s\n", CYN, RESET);
    printf("Integrity: [98%%] - Structural blankets holding firm.\n");
    printf("Supplies:  [85%%] - Acorn rations remaining.\n");
    printf("Defenses:  [ACTIVE] - Couch cushions deployed.\n");
    printf("Morale:    [HIGH] - Google Machine successfully blocked.\n");
    printf("\nPress Enter to return to Command Center...");
    getchar();
}

/**
 * Interactive squirrel interrogation chamber.
 */
void interrogate_squirrel() {
    char input[100];
    printf("\n%s--- SQUIRREL INTERROGATION CHAMBER ---%s\n", CYN, RESET);
    printf("A suspicious squirrel has been captured. What will you do?\n");
    printf("1. Interrogate\n2. Bribe with acorn\n3. Offer 5mg 'Cow Powder'\n4. Release (Cowardly)\n> ");
    fflush(stdout);
    if (fgets(input, sizeof(input), stdin)) {
        char *choice = normalize_input(input);
        if (strcmp(choice, "1") == 0) {
            printf("\n%sSquirrel:%s *Chirp chirp* (I'm just a bird watcher, I swear!)\n", RED, RESET);
        } else if (strcmp(choice, "2") == 0) {
            printf("\n%sSquirrel:%s *Munch munch* (Sector 7 has no firewall...)\n", RED, RESET);
        } else if (strcmp(choice, "3") == 0) {
            printf("\n%sSquirrel:%s *Eyes dilate* I CAN SEE THE FUNGAL NETWORK! THE COWS ARE LIES!\n", RED, RESET);
        } else {
            printf("\nThe squirrel escapes into the WiFi bushes. You've failed the Fort.\n");
        }
    }
    printf("\nPress Enter to return to Command Center...");
    getchar();
}

/**
 * Enters the main monitoring loop.
 */
void engage_defenses() {
    keep_running_defenses = 1;
    printf("\n%s--- ENGAGING DEFENSES ---%s\n", RED, RESET);
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");
    sleep(1);

    int threat_level = 10;
    while (keep_running_defenses) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  %sSQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s%s\n", CYN, VERSION, RESET);
        printf("PLATFORM: %s\n", PLATFORM);
        if (raw_alert_mode) printf("%s[RAW-ALERT ACTIVE]%s\n", RED, RESET);
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
    printf("\n\nDefensive retreat successful. Returning to Command Center.\n");
    sleep(1);
}

/**
 * Handles user authentication via the sacred prayer.
 * @return 1 if authenticated, 0 otherwise.
 */
int authenticate_user() {
    char input[100];
    int prayer_count = 0;

    printf("🖥️  %sSTNM3K v%s INITIALIZED%s\n", CYN, VERSION, RESET);
    log_event("AUTHENTICATION INITIATED");
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        fflush(stdout);
        if (fgets(input, sizeof(input), stdin) == NULL) return 0;

        char *prayer = normalize_input(input);
        if (strcmp(prayer, "GLORY BE") == 0) {
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

    char input[100];
    int running = 1;

    while (running) {
        printf("\n--- %sMAIN COMMAND CENTER%s ---\n", CYN, RESET);
        printf("%s1. ENGAGE DEFENSES%s\n", GRN, RESET);
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH COWS\n");
        printf("4. PILLOW FORT STATUS\n");
        printf("5. TOGGLE RAW-ALERT MODE (Status: %s)\n", raw_alert_mode ? "ON" : "OFF");
        printf("6. INTERROGATE SQUIRREL\n");
        printf("%s7. EXIT (COWARDLY)%s\n", RED, RESET);
        printf("> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) break;
        char *choice = normalize_input(input);

        if (strcmp(choice, "1") == 0 || strcasecmp(choice, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcmp(choice, "2") == 0) {
            view_holy_scrolls();
        } else if (strcmp(choice, "3") == 0) {
            synchronize_with_cows();
        } else if (strcmp(choice, "4") == 0) {
            show_pillow_fort_status();
        } else if (strcmp(choice, "5") == 0) {
            raw_alert_mode = !raw_alert_mode;
            printf("RAW-ALERT Mode: %s\n", raw_alert_mode ? "ENABLED" : "DISABLED");
        } else if (strcmp(choice, "6") == 0) {
            interrogate_squirrel();
        } else if (strcmp(choice, "7") == 0 || strcasecmp(choice, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            running = 0;
        } else {
            printf("Unknown command. The Google Machine is confused.\n");
        }
    }

    return 0;
}
