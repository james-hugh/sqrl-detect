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
#include <termios.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>

/* --- GLOBAL STATE --- */
int cow_metabolism = 1;
int paranoid_mode = 0;

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
 * Utility for non-blocking keyboard input detection.
 */
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

/**
 * Signal handler to restore terminal and exit.
 */
void handle_signal(int sig) {
    (void)sig;
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    const char msg[] = "\n[SIGNAL] Retreated to pillow fort.\n";
    if (write(STDOUT_FILENO, msg, sizeof(msg) - 1)) {
        /* Ignored */
    }
    exit(0);
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    umask(0077);
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
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
    printf("SQUIRREL THREAT METER: %s[%-8s] [%.*s%.*s] %3d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos.
 */
void print_graph_of_chaos() {
    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    char buffer[21];
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        char ch = (val > 15) ? 'X' : (val > 8 ? '*' : '.');
        memset(buffer, ch, val);
        buffer[val] = '\0';
        printf("%2d |%s\n", val, buffer);
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/**
 * Displays the persistent logs from the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nThe holy scrolls are empty or missing. The squirrels have been quiet.\n");
        return;
    }

    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    printf("--- END OF SCROLLS ---\n");
    printf("\nPress Enter to return to the command center...");
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
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
 * Sub-menu to configure metabolism and paranoia.
 */
void configure_cows() {
    char input[50];
    int choice = 0;

    while (choice != 3) {
        printf("\n--- COW CONFIGURATION ---\n");
        printf("1. Set Cow Metabolism (Current: %d)\n", cow_metabolism);
        printf("2. Toggle Paranoid Mode (Current: %s)\n", paranoid_mode ? "ON" : "OFF");
        printf("3. Back to Main Menu\n");
        printf("> ");

        if (fgets(input, sizeof(input), stdin) == NULL) break;
        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter metabolism level (1-10): ");
                if (fgets(input, sizeof(input), stdin)) {
                    int val = atoi(input);
                    if (val >= 1 && val <= 10) cow_metabolism = val;
                }
                break;
            case 2:
                paranoid_mode = !paranoid_mode;
                printf("Paranoid Mode is now %s.\n", paranoid_mode ? "ON" : "OFF");
                break;
            case 3:
                break;
            default:
                printf("The cows don't understand that command.\n");
        }
    }
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
        if (kbhit()) {
            int ch = getchar();
            if (ch == 'q' || ch == 'Q') break;
        }

        // Clear screen
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s | METABOLISM: %d | PARANOIA: %s\n\n",
               PLATFORM, cow_metabolism, paranoid_mode ? "ON" : "OFF");

        int range = paranoid_mode ? 51 : 31;
        int offset = paranoid_mode ? 25 : 15;
        int change = (rand() % range) - offset;

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

        printf("\nMonitoring... (Press 'q' to retreat to your pillow fort)\n");
        fflush(stdout);
        usleep(1000000 / cow_metabolism);
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

        if (strstr(command, "GLORY BE") != NULL) {
            prayer_count++;
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
    signal(SIGINT, handle_signal);
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    int choice = 0;

    while (choice != 4) {
        printf("\n--- STNM3K MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS (Logs)\n");
        printf("3. CONFIGURE COWS\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("STNM3K > ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;
        choice = atoi(command);

        switch (choice) {
            case 1:
                engage_defenses();
                break;
            case 2:
                view_holy_scrolls();
                break;
            case 3:
                configure_cows();
                break;
            case 4:
                printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
                break;
            default:
                printf("The Google Machine has confused you. Try again.\n");
        }
    }

    return 0;
}
