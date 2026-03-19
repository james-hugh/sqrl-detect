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

/* UI Theming */
#define UI_AUTH_SUCCESS  GRN "[SUCCESS] ✅ " RESET
#define UI_AUTH_FAILURE  RED "[FAILURE] ❌ " RESET
#define UI_MENU_HEADER   YEL "\n--- SENTINEL COMMAND CENTER ---" RESET

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 * Implements security hardening by setting umask and using atomic directory creation.
 */
void init_system() {
    srand(time(NULL));
    umask(0077); // Ensure restrictive permissions (700) for created files/dirs
    if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
        perror("Failed to create secure logs directory");
        exit(1);
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

/* --- NEW SENTINEL FEATURES --- */

/**
 * Displays the holy scrolls of truth (logs) for the sentinel's inspection.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    char buffer[256];

    printf("\n" CYN "--- 📜 HOLY SCROLLS OF TRUTH 📜 ---" RESET "\n");
    if (fp == NULL) {
        printf("The scrolls are empty. The squirrels are either gone or very quiet.\n");
    } else {
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("%s", buffer);
        }
        fclose(fp);
    }
    printf(CYN "--- END OF SCROLLS ---" RESET "\n");
    printf("\nPress Enter to return to the Command Center...");
    if (fgets(buffer, sizeof(buffer), stdin)) { /* Silence warn_unused_result */ }
}

/**
 * Checks the integrity of the sentinel's pillow fort and cow status.
 */
void check_pillow_fort() {
    int integrity = (rand() % 41) + 60; // 60-100%
    int cocaine_reserves = rand() % 50; // mg

    printf("\n" CYN "--- 🏰 PILLOW FORT STATUS REPORT ---" RESET "\n");
    printf("Fort Integrity: [%d%%] ", integrity);
    if (integrity > 90) printf(GRN "SOLID AS A COW." RESET "\n");
    else if (integrity > 75) printf(YEL "MINOR BLANKET SAG DETECTED." RESET "\n");
    else printf(RED "CRITICAL STRUCTURAL WEAKNESS!" RESET "\n");

    printf("Polish Cow Cocaine Reserves: %d mg\n", cocaine_reserves);
    if (cocaine_reserves < 10) printf(RED "WARNING: Laps may slow down!" RESET "\n");
    else printf(GRN "Laps proceeding at 3 AM pace." RESET "\n");

    printf("Squirrel Decoys: ACTIVE\n");
    printf("Mushroom Network: ENCRYPTED AND FUNGAL\n");
    printf(CYN "------------------------------------" RESET "\n");

    char buffer[10];
    printf("\nPress Enter to return...");
    if (fgets(buffer, sizeof(buffer), stdin)) { /* Silence warn_unused_result */ }
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
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n" UI_AUTH_FAILURE "Prayer interrupted.\n");
            return 0;
        }

        if (strstr(command, "GLORY BE") != NULL) {
            prayer_count++;
        } else {
            printf("\n" UI_AUTH_FAILURE "INCORRECT PRAYER.\n");
            printf("The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 0;
        }
    }

    printf("\n" UI_AUTH_SUCCESS "Authentication successful. Welcome, Sentinel.\n");
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
        printf(UI_MENU_HEADER);
        printf("\n1. 🕹️  ENGAGE DEFENSES");
        printf("\n2. 📜  VIEW HOLY SCROLLS");
        printf("\n3. 🏰  CHECK PILLOW FORT");
        printf("\n4. 💀  EXIT (COWARDLY)");
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strstr(command, "1") || strstr(command, "ENGAGE")) {
            engage_defenses();
        } else if (strstr(command, "2") || strstr(command, "SCROLLS")) {
            view_holy_scrolls();
        } else if (strstr(command, "3") || strstr(command, "FORT")) {
            check_pillow_fort();
        } else if (strstr(command, "4") || strstr(command, "EXIT")) {
            printf("\nCowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("\nINVALID COMMAND. The Polish cows are confused.\n");
        }
    }

    return 0;
}
