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
#define METER_WIDTH 20
#define GRAPH_HEIGHT 5
#define MAX_GRAPH_VAL 20
#define THREAT_MAX_CHANGE 15
#define CLEAR_SCREEN "\033[H\033[J"

/* ANSI Colors */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Wipes a buffer from memory to prevent sensitive data leakage.
 */
void secure_memzero(void *v, size_t n) {
    if (v == NULL) return;
    memset(v, 0, n);
    /* Compiler barrier to prevent the call from being optimized away */
    __asm__ __volatile__("" : : "r"(v) : "memory");
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
 * Renders the decorative system header.
 */
void print_header() {
    printf(CLEAR_SCREEN);
    printf("%s====================================================%s\n", YEL, RESET);
    printf("%s   STNM3K - SQUIRREL TERMINATOR NETWORK MONITOR   %s\n", GRN, RESET);
    printf("%s====================================================%s\n", YEL, RESET);
    printf(" VERSION: %s | PLATFORM: %s\n\n", VERSION, PLATFORM);
}

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
    static const char graph_chars[] = "XXXXXXXXXXXXXXXXXXXX********************....................";
    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = GRAPH_HEIGHT; i > 0; i--) {
        int val = rand() % MAX_GRAPH_VAL;
        const char *marker_set;
        if (val > 15) marker_set = graph_chars;
        else if (val > 8) marker_set = graph_chars + 20;
        else marker_set = graph_chars + 40;

        printf("%2d |%.*s\n", val, val, marker_set);
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
    while (1) {
        print_header();

        int change = (rand() % (2 * THREAT_MAX_CHANGE + 1)) - THREAT_MAX_CHANGE;
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
    int success = 0;

    printf("%s[INITIALIZING]%s STNM3K v%s\n", YEL, RESET, VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) goto cleanup;

        // Trim trailing newline
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("\n%s[INCORRECT]%s PRAYER.\n", RED, RESET);
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            goto cleanup;
        }
    }

    printf("\n%s[SUCCESS]%s Authentication successful. Welcome, Sentinel.\n", GRN, RESET);
    success = 1;

cleanup:
    secure_memzero(command, sizeof(command));
    return success;
}

/* --- MAIN ENTRY POINT --- */

int main() {
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    printf("\n--- MAIN MENU ---\n");
    printf("1. ENGAGE DEFENSES\n");
    printf("2. EXIT (COWARDLY)\n");
    printf("> ");
    if (fgets(command, sizeof(command), stdin) == NULL) {
        secure_memzero(command, sizeof(command));
        return 0;
    }

    if (strstr(command, "ENGAGE DEFENSES") != NULL || strstr(command, "1") != NULL) {
        secure_memzero(command, sizeof(command));
        engage_defenses();
    } else {
        printf("%s[EXITED]%s Cowardice detected. The squirrels have already won.\n", RED, RESET);
        secure_memzero(command, sizeof(command));
    }

    return 0;
}
