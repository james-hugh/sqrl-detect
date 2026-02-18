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

#include <sys/stat.h>
#include <sys/types.h>

/* --- CONFIGURATION MACROS --- */
#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_DIR "logs"
#define LOG_FILE "logs/holy_scrolls.txt"

/* --- CORE SYSTEM UTILITIES --- */

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
        timestamp[24] = '\0'; // Optimize ctime newline removal
    } else {
        timestamp = "UNKNOWN TIME";
    }

    // Append randomized thematic metadata (COW_HR, PARANOIA, FORT)
    fprintf(fp, "[%s] COCAINE-COW-LOG: %s (COW_HR=%d, PARANOIA=%d, FORT=%d)\n",
            timestamp, event, rand() % 24, rand() % 100, rand() % 10);
    fclose(fp);
}

/* --- VISUALIZATION ENGINE --- */

/**
 * Renders the squirrel threat meter.
 * @param level Threat level from 0 to 100.
 */
void print_threat_meter(int level) {
    static const char *bars = "!!!!!!!!!!!!!!!!!!!!";
    static const char *empty = "--------------------";
    const char *status = "SECURE";
    const char *color = "\x1B[32m"; // Green

    if (level > 85) {
        status = "RED SQUIRREL ALERT";
        color = "\x1B[31m"; // Red
    } else if (level > 70) {
        status = "YELLOW ACORN ALERT";
        color = "\x1B[33m"; // Yellow
    }

    int b = level / 5;
    printf("SQUIRREL THREAT METER: %s[%.*s%.*s]\x1B[0m %d%% (%s)\n",
           color, b, bars, 20 - b, empty, level, status);
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
 * Displays the last 10 entries from the holy scrolls.
 */
void view_holy_scrolls() {
    printf("\n--- READING HOLY SCROLLS OF TRUTH ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty or missing. The squirrels are winning.\n");
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
    int total = (count > 10) ? 10 : count;

    for (int i = 0; i < total; i++) {
        printf("%s", lines[(start + i) % 10]);
    }
    printf("\n--- END OF SCROLLS ---\n");
}

/**
 * Synchronizes with Polish cows (MOO protocol).
 */
void synchronize_cows() {
    printf("\n--- INITIALIZING MOO PROTOCOL (COW SYNC) ---\n");
    log_event("COW SYNCHRONIZATION INITIATED.");

    for (int i = 0; i <= 20; i++) {
        printf("\rCocaine-Cow Synchronicity: [");
        for (int j = 0; j < 20; j++) {
            if (j < i) printf("M");
            else printf(".");
        }
        printf("] %d%%", i * 5);
        fflush(stdout);
        usleep(100000); // 0.1s
    }
    printf("\n\nSUCCESS: Polish cows are now running laps in phase with your router.\n");
    log_event("COW SYNCHRONIZATION SUCCESSFUL.");
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
            if (threat_level > 85) {
                printf("\n!!! RED SQUIRREL ALERT !!!\n");
            } else {
                printf("\n!!! YELLOW ACORN ALERT !!!\n");
            }
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

    log_event("AUTHENTICATION INITIATED");
    printf("🖥️  STNM3K v%s INITIALIZED\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;

        command[strcspn(command, "\r\n")] = 0; // Normalize input

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\nINCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER");
            return 0;
        }
    }

    log_event("AUTHENTICATION SUCCESSFUL");
    printf("\nAuthentication successful. Welcome, Sentinel.\n");
    return 1;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    umask(0077); // Ensure secure file permissions
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n--- STNM3K MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH POLISH COWS (MOO)\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        command[strcspn(command, "\r\n")] = 0; // Normalize input

        if (strcmp(command, "1") == 0 || strstr(command, "ENGAGE DEFENSES") != NULL) {
            engage_defenses();
        } else if (strcmp(command, "2") == 0 || strstr(command, "VIEW HOLY SCROLLS") != NULL) {
            view_holy_scrolls();
        } else if (strcmp(command, "3") == 0 || strcmp(command, "MOO") == 0) {
            synchronize_cows();
        } else if (strcmp(command, "4") == 0 || strstr(command, "EXIT") != NULL) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Invalid command. The Polish cows are judging you.\n");
        }
    }

    return 0;
}
