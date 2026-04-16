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
#define RESET "\x1B[0m"

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Portable case-insensitive string containment check.
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @return 1 if found, 0 otherwise.
 */
int str_contains_ignore_case(const char *haystack, const char *needle) {
    if (!haystack || !needle) return 0;
    size_t needle_len = strlen(needle);
    if (needle_len == 0) return 1;

    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && tolower((unsigned char)*h) == tolower((unsigned char)*n)) {
            h++;
            n++;
        }
        if (!*n) return 1;
    }
    return 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    umask(0077);
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
    static const char fill_x[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char fill_star[] = "********************";
    static const char fill_dot[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, fill_x);
        else if (val > 8) printf("%.*s", val, fill_star);
        else printf("%.*s", val, fill_dot);
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
 * Displays the holy scrolls (logs).
 */
void view_logs() {
    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. No squirrel treachery recorded... yet.\n");
    } else {
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }
    printf("\n[PRESS ENTER TO RETURN TO MENU]");
    fflush(stdout);
    getchar();
}

/**
 * Displays randomized humorous reports on the Polish cows.
 */
void check_cow_status() {
    const char* reports[] = {
        "Cow #1: Currently vibrating. Optimal alertness achieved.",
        "Cow #2: Running laps at 400 RPM. Squirrels are terrified.",
        "Cow #3: Attempting to communicate with the fungal network.",
        "Cow #4: Has developed a taste for WiFi acorns. Monitoring...",
        "Cow #5: Standing perfectly still. It's either a glitch or peak vigilance."
    };
    printf("\n--- POLISH COW STATUS REPORT ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", reports[rand() % 5]);
    }
    printf("\n[PRESS ENTER TO RETURN TO MENU]");
    fflush(stdout);
    getchar();
}

/**
 * Feeds the cows to achieve 'optimal alert synergy'.
 */
void feed_cows() {
    printf("\n--- FEEDING THE COWS ---\n");
    printf("Rationing cocaine for optimal alert synergy...\n");
    printf("Cows are now hyper-vigilant. Squirrels beware.\n");
    log_event("COWS FED. ALERT SYNERGY OPTIMIZED.");
    printf("\n[PRESS ENTER TO RETURN TO MENU]");
    fflush(stdout);
    getchar();
}

/**
 * Displays randomized integrity reports on the pillow fort.
 */
void check_pillow_fort() {
    const char* cushions[] = { "Egyptian cotton", "Sofa Cushion", "Memory Foam", "Old Blanket" };
    int integrity = rand() % 51 + 50; // 50-100%

    printf("\n--- PILLOW FORT INTEGRITY REPORT ---\n");
    printf("Primary Defense: %s\n", cushions[rand() % 4]);
    printf("Structural Integrity: %d%%\n", integrity);

    if (integrity > 90) printf("Status: FORTRESS OF SOLITUDE\n");
    else if (integrity > 75) printf("Status: SECURE\n");
    else printf("Status: VULNERABLE TO FEATHER-BASED ATTACKS\n");

    printf("\n[PRESS ENTER TO RETURN TO MENU]");
    fflush(stdout);
    getchar();
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
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        if (str_contains_ignore_case(command, "GLORY BE")) {
            prayer_count++;
            printf("%s[√] ACCEPTED%s\n", GRN, RESET);
        } else {
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

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
        printf("\033[H\033[J");
        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW LOGS\n");
        printf("3. CHECK COW STATUS\n");
        printf("4. FEED COWS\n");
        printf("5. CHECK PILLOW FORT\n");
        printf("6. EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (command[0] == '1' && (command[1] == '\n' || command[1] == ' ')) {
            engage_defenses();
        } else if (command[0] == '2' && (command[1] == '\n' || command[1] == ' ')) {
            view_logs();
        } else if (command[0] == '3' && (command[1] == '\n' || command[1] == ' ')) {
            check_cow_status();
        } else if (command[0] == '4' && (command[1] == '\n' || command[1] == ' ')) {
            feed_cows();
        } else if (command[0] == '5' && (command[1] == '\n' || command[1] == ' ')) {
            check_pillow_fort();
        } else if (command[0] == '6' && (command[1] == '\n' || command[1] == ' ')) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        }
    }

    return 0;
}
