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

/* ANSI Color Codes */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

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
        timestamp[24] = '\0'; // Faster newline removal for ctime
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
    const char *label, *color;
    static const char* red_bars = "!!!!!!!!!!!!!!!!!!!!";
    static const char* yel_bars = "####################";
    static const char* grn_bars = "====================";
    static const char* empty_bars = "--------------------";

    if (level > 85) {
        label = "[CRITICAL]";
        color = RED;
    } else if (level > 70) {
        label = "[CAUTION]";
        color = YEL;
    } else {
        label = "[SECURE]";
        color = GRN;
    }

    printf("SQUIRREL THREAT METER: %s%s" RESET " [", color, label);
    int bars = level / 5;
    const char* active_bars = (level > 85) ? red_bars : (level > 70 ? yel_bars : grn_bars);

    printf("%s%.*s" RESET, color, bars, active_bars);
    printf("%.*s", 20 - bars, empty_bars);
    printf("] %d%%\n", level);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    static const char* dots = "....................";
    static const char* stars = "********************";
    static const char* xs = "XXXXXXXXXXXXXXXXXXXX";

    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        const char* bar = (val > 15) ? xs : (val > 8 ? stars : dots);
        printf("%.*s\n", val, bar);
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Displays the last 10 entries from the holy scrolls.
 */
void view_holy_scrolls() {
    printf("\n--- READING HOLY SCROLLS OF TRUTH (Last 10 entries) ---\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "tail -n 10 %s 2>/dev/null || echo 'The scrolls are empty or missing.'", LOG_FILE);
    if (system(cmd) == -1) {
        perror("Failed to execute scroll retrieval");
    }
    printf("\nPress Enter to return to the fort...");
    char buffer[10];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
}

/**
 * Implements the MOO protocol for cow synchronization.
 */
void synchronize_cows() {
    printf("\n--- INITIALIZING MOO PROTOCOL ---\n");
    printf("Synchronizing with Polish cows on 3 AM cocaine laps...\n");
    sleep(1);
    printf(GRN "MOO! MOO! MOO!\n" RESET);
    log_event("COW SYNCHRONIZATION SUCCESSFUL. MOO.");
    printf("\nPress Enter to return to the fort...");
    char buffer[10];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
}

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

        if (threat_level > 85) {
            const char* threat = get_random_threat();
            printf(RED "\n!!! RED SQUIRREL ALERT !!!\n" RESET);
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        } else if (threat_level > 70) {
            const char* threat = get_random_threat();
            printf(YEL "\n!!! YELLOW ACORN ALERT !!!\n" RESET);
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
        if (fgets(command, sizeof(command), stdin) == NULL) {
            log_event("AUTHENTICATION FAILED: EOF");
            return 0;
        }

        command[strcspn(command, "\r\n")] = '\0';

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
    umask(0077);
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n--- PILLOW FORT COMMAND CENTER ---\n");
        printf(GRN "1. ENGAGE DEFENSES\n" RESET);
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH POLISH COWS (MOO)\n");
        printf(RED "4. EXIT (COWARDLY)\n" RESET);
        printf("> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\r\n")] = '\0';

        if (strcmp(command, "1") == 0 || strstr(command, "ENGAGE DEFENSES") != NULL) {
            engage_defenses();
        } else if (strcmp(command, "2") == 0 || strstr(command, "VIEW HOLY SCROLLS") != NULL) {
            view_holy_scrolls();
        } else if (strcmp(command, "3") == 0 || strstr(command, "MOO") != NULL) {
            synchronize_cows();
        } else if (strcmp(command, "4") == 0 || strstr(command, "EXIT") != NULL) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Invalid command. The Google Machine is laughing at your indecision.\n");
        }
    }

    return 0;
}
