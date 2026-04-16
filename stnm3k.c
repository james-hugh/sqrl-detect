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
#define RESET "\x1B[0m"

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Case-insensitive string search.
 */
int str_contains_ignore_case(const char *haystack, const char *needle) {
    if (!haystack || !needle) return 0;

    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    if (needle_len > haystack_len) return 0;

    for (size_t i = 0; i <= haystack_len - needle_len; i++) {
        size_t j;
        for (j = 0; j < needle_len; j++) {
            if (tolower((unsigned char)haystack[i + j]) != tolower((unsigned char)needle[j])) {
                break;
            }
        }
        if (j == needle_len) return 1;
    }
    return 0;
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    if (mkdir(LOG_DIR, 0700) == -1) {
        if (errno != EEXIST) {
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
    char *raw_time = ctime(&now);
    char timestamp[32];

    if (raw_time) {
        strncpy(timestamp, raw_time, sizeof(timestamp) - 1);
        timestamp[sizeof(timestamp) - 1] = '\0';
        size_t len = strlen(timestamp);
        if (len > 0 && timestamp[len - 1] == '\n') {
            timestamp[len - 1] = '\0';
        }
    } else {
        strncpy(timestamp, "UNKNOWN TIME", sizeof(timestamp) - 1);
        timestamp[sizeof(timestamp) - 1] = '\0';
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
    printf("SQUIRREL THREAT METER: %s[%-8s] [%.*s%.*s] %3d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char x_buf[] = "XXXXXXXXXXXXXXXXXXXX";
    static const char star_buf[] = "********************";
    static const char dot_buf[] = "....................";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        if (val > 15) printf("%.*s", val, x_buf);
        else if (val > 8) printf("%.*s", val, star_buf);
        else printf("%.*s", val, dot_buf);
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
void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    printf("Initializing monitoring subsystems...\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");
    sleep(1);

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n\n", PLATFORM);

        if (threat_level > 85) printf("\a"); // Audible alert for high threat

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
 * Displays the holy scrolls of truth.
 */
void view_logs() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nThe holy scrolls are empty or missing. Perhaps the squirrels ate them.\n");
    } else {
        char line[256];
        printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }
    printf("\nPress ENTER to return to the Command Center...");
    fflush(stdout);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Reports on the status of the Polish cows.
 */
void check_cow_status() {
    const char* statuses[] = {
        "Laps detected (High alert synergy)",
        "Grazing peacefully (Suspiciously calm)",
        "Mooing at WiFi acorns",
        "Staring intensely at the Google Machine",
        "Dreaming of 3 AM cocaine laps"
    };
    printf("\n--- POLISH COW STATUS REPORT ---\n");
    for (int i = 1; i <= 3; i++) {
        printf("Cow #%d: %s\n", i, statuses[rand() % 5]);
    }
}

/**
 * Ration cocaine for the cows.
 */
void feed_cows() {
    printf("\nFeeding cows... Rationing cocaine for optimal alert synergy.\n");
    printf("The cows are now vibrating with vigilance.\n");
    log_event("COCAINE RATIONED. ALERT SYNERGY AT MAXIMUM.");
}

/**
 * Integrity report for the pillow fort.
 */
void check_pillow_fort() {
    const char* cushions[] = {
        "Egyptian cotton",
        "Sofa Cushion",
        "Memory Foam",
        "Synthetic blend"
    };
    int integrity = 85 + (rand() % 16);
    printf("\n--- PILLOW FORT INTEGRITY REPORT ---\n");
    printf("Status: %d%% SECURE\n", integrity);
    printf("Primary Defense: %s blockade\n", cushions[rand() % 4]);
    if (integrity < 90) {
        printf("WARNING: Fluffiness levels dropping! Re-plump immediately!\n");
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
        if (fgets(command, sizeof(command), stdin) == NULL) {
            memset(command, 0, sizeof(command));
            return 0;
        }

        if (str_contains_ignore_case(command, "GLORY BE")) {
            prayer_count++;
            printf(" %s[√] ACCEPTED%s\n", GRN, RESET);
        } else {
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            memset(command, 0, sizeof(command));
            return 0;
        }
    }

    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    memset(command, 0, sizeof(command));
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
        printf("\033[H\033[J"); // Clear screen
        printf("🖥️  STNM3K COMMAND CENTER v%s\n", VERSION);
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW LOGS\n");
        printf("3. CHECK COW STATUS\n");
        printf("4. FEED COWS\n");
        printf("5. CHECK PILLOW FORT\n");
        printf("6. EXIT (COWARDLY)\n");
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (command[0] == '1' && (command[1] == '\n' || command[1] == ' ')) {
            engage_defenses();
        } else if (command[0] == '2' && (command[1] == '\n' || command[1] == ' ')) {
            view_logs();
        } else if (command[0] == '3' && (command[1] == '\n' || command[1] == ' ')) {
            check_cow_status();
            printf("\nPress ENTER to continue...");
            getchar();
        } else if (command[0] == '4' && (command[1] == '\n' || command[1] == ' ')) {
            feed_cows();
            printf("\nPress ENTER to continue...");
            getchar();
        } else if (command[0] == '5' && (command[1] == '\n' || command[1] == ' ')) {
            check_pillow_fort();
            printf("\nPress ENTER to continue...");
            getchar();
        } else if (command[0] == '6' && (command[1] == '\n' || command[1] == ' ')) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("INVALID COMMAND. The Google Machine is laughing at you.\n");
            sleep(1);
        }
    }

    return 0;
}
