#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>

#define VERSION "0.69"
#define PLATFORM "WINDOWS ME (GLORY BE)"

// ANSI Color Codes
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

void log_event(const char *event) {
    // Set umask for owner-only permissions (0600)
    mode_t old_mask = umask(0077);

    // Ensure logs directory exists
    struct stat st = {0};
    if (stat("logs", &st) == -1) {
        mkdir("logs", 0700);
    }

    FILE *fp = fopen("logs/holy_scrolls.txt", "a");
    // Restore umask
    umask(old_mask);

    if (fp == NULL) {
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
    int cow_heart_rate = 120 + (rand() % 80);
    int paranoia_level = 85 + (rand() % 16);
    int pillow_fort_integrity = 90 + (rand() % 11);

    fprintf(fp, "[%s] COCAINE-COW-LOG: %s {COW_HEART_RATE: %dbpm, PARANOIA_LEVEL: %d%%, PILLOW_FORT_INTEGRITY: %d%%}\n",
            timestamp, event, cow_heart_rate, paranoia_level, pillow_fort_integrity);
    fclose(fp);
}

void print_threat_meter(int level) {
    const char *color = GRN;
    const char *label = "SECURE";

    if (level > 85) {
        color = RED;
        label = "RED SQUIRREL ALERT";
    } else if (level > 70) {
        color = YEL;
        label = "YELLOW ACORN ALERT";
    }

    printf("SQUIRREL THREAT METER: %s[", color);
    int bars = level / 5;
    // Using %.*s for repeating characters optimization
    printf("%.*s", bars, "####################");
    printf("%.*s", 20 - bars, "--------------------");
    printf("] %d%% (%s)%s\n", level, label, RESET);
}

void print_graph_of_chaos() {
    printf(CYN "GUI GRAPH OF CHAOS:\n" RESET);
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        printf("%.*s", val, "********************");
        printf("\n");
    }
    printf("   +--------------------\n");
}

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

void engage_defenses() {
    printf("\n" MAG "--- ENGAGING DEFENSES ---" RESET "\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        // Clear screen
        printf("\033[H\033[J");

        printf("🖥️  " WHT "SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s" RESET "\n", VERSION);
        printf("PLATFORM: %s\n\n", PLATFORM);

        // Additional status indicators
        int blanket_integrity = 80 + (rand() % 21);
        int cookie_reserves = 50 + (rand() % 51);
        int cow_sync = rand() % 101;

        printf("PILLOW FORT COMMAND CENTER STATUS:\n");
        printf(" - Blanket Integrity: %d%%\n", blanket_integrity);
        printf(" - Cookie Reserves: %d packets\n\n", cookie_reserves);

        printf("COCAINE-COW SYNCHRONICITY:\n");
        printf("[");
        int sync_bars = cow_sync / 10;
        printf("%.*s", sync_bars, "==========");
        printf("%.*s", 10 - sync_bars, "          ");
        printf("] %d%%\n\n", cow_sync);

        int change = (rand() % 31) - 15; // -15 to +15
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();

        if (threat_level > 70) {
            const char* threat = get_random_threat();
            printf("\n" RED "!!! MAXIMUM ALERT MODE !!!" RESET "\n");
            printf(RED "ALERT: %s" RESET "\n", threat);
            log_event(threat);
            printf(MAG "Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT." RESET "\n");
        }

        printf("\nMonitoring... (Press 'Enter' to return to menu, or Ctrl+C to retreat to your pillow fort)\n");
        fflush(stdout);

        // Wait for 1 second OR user input to exit
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);

        int ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
        if (ret > 0) {
            // User pressed a key
            char dummy[100];
            if (fgets(dummy, sizeof(dummy), stdin) != NULL) {
                printf("Returning to the safety of the main menu...\n");
                break;
            }
        }
    }
}

void view_holy_scrolls() {
    printf("\n" YEL "--- REVEALING HOLY SCROLLS (Last 10 entries) ---" RESET "\n");
    FILE *fp = fopen("logs/holy_scrolls.txt", "r");
    if (fp == NULL) {
        printf("The scrolls are empty or the squirrels have stolen them.\n");
        return;
    }

    // Simple way to get last 10 lines: read all and keep last 10
    // For simplicity in C, we can just read the whole file if it's small,
    // or use a circular buffer of strings.
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
}

void cow_synchronization() {
    char input[100];
    printf("\nInitiating COCAINE-COW SYNCHRONIZATION PROTOCOL...\n");
    printf("Please provide the sacred synchronization key (MOO): ");
    if (fgets(input, sizeof(input), stdin) == NULL) return;
    input[strcspn(input, "\r\n")] = 0;

    if (strcmp(input, "MOO") == 0) {
        printf(GRN "SYNCHRONIZATION COMPLETE. The cows are running in perfect circles." RESET "\n");
        log_event("COW SYNCHRONIZATION SUCCESSFUL.");
    } else {
        printf(RED "SYNCHRONIZATION FAILED. The cows are confused and the squirrels are mocking you." RESET "\n");
        log_event("COW SYNCHRONIZATION ATTEMPT FAILED.");
    }
}

int main() {
    srand(time(NULL));

    char command[100];
    printf("🖥️  " WHT "STNM3K v%s INITIALIZED" RESET "\n", VERSION);
    printf("Recite \"GLORY BE\" three times to proceed.\n");

    int prayer_count = 0;
    while (prayer_count < 3) {
        printf("(%d/3) > ", prayer_count + 1);
        if (fgets(command, sizeof(command), stdin) == NULL) return 0;
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "GLORY BE") == 0) {
            prayer_count++;
        } else {
            printf(RED "Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you." RESET "\n");
            log_event("AUTHENTICATION FAILURE: Incorrect prayer.");
            return 1;
        }
    }

    log_event("AUTHENTICATION SUCCESSFUL.");
    printf("\n" GRN "Authentication successful. Welcome, Sentinel." RESET "\n");

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
        printf("3. SYNCHRONIZE WITH POLISH COWS\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\r\n")] = 0;

        if (strcmp(command, "1") == 0 || strcmp(command, "ENGAGE DEFENSES") == 0) {
            engage_defenses();
        } else if (strcmp(command, "2") == 0 || strcmp(command, "VIEW HOLY SCROLLS") == 0) {
            view_holy_scrolls();
        } else if (strcmp(command, "3") == 0 || strcmp(command, "SYNCHRONIZE WITH POLISH COWS") == 0) {
            cow_synchronization();
        } else if (strcmp(command, "4") == 0 || strcmp(command, "EXIT") == 0) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        } else {
            printf("Unknown command. The squirrels are gaining on you.\n");
        }
    }

    return 0;
}
