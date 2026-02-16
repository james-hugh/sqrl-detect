#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"
#define LOG_FILE "logs/holy_scrolls.txt"

// ANSI Color Codes
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/**
 * @brief Logs an event to the Holy Scrolls with secure permissions and thematic metadata.
 *
 * @param event The event message to be logged.
 */
void log_event(const char *event) {
    // Set umask for secure file permissions (0600)
    mode_t old_mask = umask(0077);

    // Ensure logs directory exists
    struct stat st = {0};
    if (stat("logs", &st) == -1) {
        mkdir("logs", 0700);
    }

    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Failed to open log file");
        umask(old_mask);
        return;
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline
    } else {
        timestamp = "UNKNOWN TIME";
    }

    // Randomized thematic metadata
    int cow_heart_rate = 120 + (rand() % 100);
    int paranoia_level = 80 + (rand() % 21);
    int fort_integrity = rand() % 101;

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s | COW_HEART_RATE: %d | PARANOIA_LEVEL: %d | PILLOW_FORT_INTEGRITY: %d%%\n",
            timestamp, event, cow_heart_rate, paranoia_level, fort_integrity);

    fclose(fp);
    umask(old_mask);
}

/**
 * @brief Renders a color-coded ASCII threat meter.
 *
 * @param level The current threat level (0-100).
 */
void print_threat_meter(int level) {
    const char *color = GRN;
    if (level >= 86) color = RED;
    else if (level >= 71) color = YEL;

    printf("SQUIRREL THREAT METER: [");
    int bars = level / 5;
    printf("%s", color);
    for (int i = 0; i < 20; i++) {
        if (i < bars) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf(RESET "] %s%d%%" RESET "\n", color, level);
}

/**
 * @brief Executes the Polish Cow synchronization protocol.
 * Requires 'MOO' input to successfully synchronize.
 */
void synchronize_cows() {
    char buffer[100];
    printf("\n--- COCAINE-COW SYNCHRONIZATION PROTOCOL ---\n");
    printf("Requirement: Recite the sacred bovine vibration.\n");
    printf("VIBRATION > ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    buffer[strcspn(buffer, "\r\n")] = 0;

    if (strcmp(buffer, "MOO") == 0) {
        printf("Vibration accepted. Synchronizing heart rates with Polish cows...\n");
        log_event("COW_SYNC: SUCCESS. Synchronicity achieved.");
        for (int i = 0; i < 3; i++) {
            printf("MOO... ");
            fflush(stdout);
            sleep(1);
        }
        printf("\nSynchronization complete. Your paranoia is now optimized.\n");
    } else {
        printf("Blasphemy! The cows are offended.\n");
        log_event("COW_SYNC: FAILURE. Blasphemous vibration detected.");
    }
    printf("\nPress Enter to return...");
    getchar();
}

/**
 * @brief Displays the last 10 entries from the Holy Scrolls log file.
 */
void view_holy_scrolls() {
    printf("\n--- READING HOLY SCROLLS (LAST 10 ENTRIES) ---\n");
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are missing! The squirrels must have stolen them.\n");
        return;
    }

    // A simple way to get last 10 lines for this size of file
    char lines[10][512];
    int count = 0;
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), fp)) {
        strncpy(lines[count % 10], buffer, 512);
        count++;
    }
    fclose(fp);

    int start = (count > 10) ? (count % 10) : 0;
    int display_count = (count > 10) ? 10 : count;

    for (int i = 0; i < display_count; i++) {
        printf("%s", lines[(start + i) % 10]);
    }
    printf("--- END OF SCROLLS ---\n");
    printf("\nPress Enter to return to command center...");
    getchar(); // Catch previous newline
    getchar(); // Wait for enter
}

/**
 * @brief Renders a chaotic graph of network activity using randomized values.
 */
void print_graph_of_chaos() {
    printf(CYN "GUI GRAPH OF CHAOS:" RESET "\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *color = GRN;
        if (val > 15) color = RED;
        else if (val > 10) color = YEL;

        printf("%2d | %s", val, color);
        for (int j = 0; j < val; j++) {
            printf("*");
        }
        printf(RESET "\n");
    }
    printf("   +--------------------\n");
}

/**
 * @brief Retrieves a random thematic threat message.
 *
 * @return A constant pointer to a string containing the threat description.
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
 * @brief Enters the primary monitoring loop, tracking threat levels and alerts.
 */
void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf(CYN "🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s" RESET "\n", VERSION);
        printf(MAG "PLATFORM: %s" RESET "\n\n", PLATFORM);

        int change = (rand() % 31) - 15; // -15 to +15
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();

        if (threat_level >= 86) {
            const char* threat = get_random_threat();
            printf("\n" RED "!!! RED SQUIRREL ALERT (CRITICAL) !!!" RESET "\n");
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
        } else if (threat_level >= 71) {
            const char* threat = get_random_threat();
            printf("\n" YEL "!!! YELLOW ACORN ALERT (WARNING) !!!" RESET "\n");
            printf("ALERT: %s\n", threat);
            log_event(threat);
        } else {
            printf("\n" GRN "STATUS: SECURE (NO ACORNS DETECTED)" RESET "\n");
        }

        printf("\nMonitoring... (Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);
        sleep(1);
    }
}

int main() {
    srand(time(NULL));

    char command[100];
    printf("🖥️  STNM3K v0.69 INITIALIZED\n");
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    int prayer_count = 0;
    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        command[strcspn(command, "\r\n")] = 0; // Strip newline

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf("Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            log_event("AUTHENTICATION FAILURE: Incorrect prayer recitation.");
            return 1;
        }
    }

    if (prayer_count == 3) {
        log_event("AUTHENTICATION SUCCESS: Sentinel identity verified.");
        printf("\nAuthentication successful. Welcome, Sentinel.\n");

        while (1) {
            printf("\n--- PILLOW FORT COMMAND CENTER ---\n");
            printf("1. ENGAGE DEFENSES\n");
            printf("2. VIEW HOLY SCROLLS\n");
            printf("3. SYNCHRONIZE WITH POLISH COWS\n");
            printf("4. EXIT (COWARDLY)\n");
            printf("> ");

            if (fgets(command, sizeof(command), stdin) == NULL) break;
            command[strcspn(command, "\r\n")] = 0;

            if (strcmp(command, "1") == 0 || strcmp(command, "ENGAGE DEFENSES") == 0) {
                log_event("SENTINEL COMMAND: ENGAGE DEFENSES");
                engage_defenses();
            } else if (strcmp(command, "2") == 0 || strcmp(command, "VIEW HOLY SCROLLS") == 0) {
                log_event("SENTINEL COMMAND: VIEW HOLY SCROLLS");
                view_holy_scrolls();
            } else if (strcmp(command, "3") == 0 || strcmp(command, "MOO") == 0) {
                log_event("SENTINEL COMMAND: SYNCHRONIZE COWS");
                synchronize_cows();
            } else if (strcmp(command, "4") == 0 || strcmp(command, "EXIT") == 0) {
                log_event("SENTINEL COMMAND: EXIT");
                printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
                break;
            } else {
                printf("Invalid command. The Google Machine is confusing you.\n");
            }
        }
    } else {
        printf("Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you.\n");
    }

    return 0;
}
