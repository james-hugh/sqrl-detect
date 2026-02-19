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

/* ANSI Escape Codes for CLI Colors */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define CYN "\x1B[36m"
#define RESET "\x1B[0m"

#define METER_WIDTH 20

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand((unsigned int)time(NULL));
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
        /* Optimize ctime() newline removal by null-terminating at index 24 */
        timestamp[24] = '\0';
    } else {
        timestamp = "UNKNOWN TIME";
    }

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s\n", timestamp, event);
    fclose(fp);
}

/* --- VISUALIZATION ENGINE --- */

/**
 * Renders the squirrel threat meter with color coding and accessibility labels.
 * @param level Threat level from 0 to 100.
 */
void print_threat_meter(int level) {
    const char *color = GRN;
    const char *label = "SECURE";
    static const char *full_bar = "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    static const char *empty_bar = "--------------------------------------------------";

    if (level > 85) {
        color = RED;
        label = "CRITICAL";
    } else if (level > 70) {
        color = YEL;
        label = "CAUTION";
    }

    printf("SQUIRREL THREAT METER: [");
    int bars = (level * METER_WIDTH) / 100;

    printf("%s%.*s%s%.*s", color, bars, full_bar, RESET, METER_WIDTH - bars, empty_bar);
    printf("] %s%d%%%s [%s]\n", color, level, RESET, label);
}

/**
 * Renders the GUI graph of chaos with optimized printf calls and color highlighting.
 */
void print_graph_of_chaos() {
    static const char *row_template = "XXXXXXXXXXXXXXXXXXXX";
    printf(CYN "GUI GRAPH OF CHAOS (Network Volatility):\n" RESET);
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *color = GRN;
        if (val > 15) color = RED;
        else if (val > 8) color = YEL;

        printf("%2d | %s%.*s%s\n", val, color, val, row_template, RESET);
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
    printf(GRN "\n--- ENGAGING DEFENSES ---\n" RESET);
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf(CYN "🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n" RESET, VERSION);
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
            const char* alert_color = (threat_level > 85) ? RED : YEL;
            const char* alert_label = (threat_level > 85) ? "RED SQUIRREL ALERT" : "YELLOW ACORN ALERT";

            printf("\n%s!!! %s !!!%s\n", alert_color, alert_label, RESET);
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
    printf(CYN "🖥️  STNM3K v%s INITIALIZED\n" RESET, VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        command[strcspn(command, "\r\n")] = '\0';

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf(RED "\nINCORRECT PRAYER.\n" RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILED: INCORRECT PRAYER");
            return 0;
        }
    }

    printf(GRN "\nAuthentication successful. Welcome, Sentinel.\n" RESET);
    log_event("AUTHENTICATION SUCCESSFUL");
    return 1;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    /* Set secure file permissions (owner-only) */
    umask(0077);

    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    printf(GRN "1. ENGAGE DEFENSES\n" RESET);
    printf("2. EXIT (COWARDLY)\n");
    printf("> ");
    if (fgets(command, sizeof(command), stdin) == NULL) {
        return 0;
    }
    command[strcspn(command, "\r\n")] = '\0';

    if (strcmp(command, "1") == 0 || strcmp(command, "ENGAGE DEFENSES") == 0) {
        engage_defenses();
    } else {
        printf(RED "Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n" RESET);
    }

    return 0;
}
