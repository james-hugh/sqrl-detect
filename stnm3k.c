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
#include <termios.h>
#include <fcntl.h>
#include <signal.h>

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
 * Signal handler to restore terminal state upon interruption.
 */
void handle_signal(int sig) {
    (void)sig;
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    printf("\nRetreating to the pillow fort safely (SIGINT received)...\n");
    exit(0);
}

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 * Sets restrictive umask for secure file creation and sets up signal handlers.
 */
void init_system() {
    umask(0077);
    srand(time(NULL));
    signal(SIGINT, handle_signal);
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

/* --- UTILITY FUNCTIONS --- */

/**
 * Displays the persistent logs from the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\n[ERROR] The holy scrolls are empty or missing. The cows are confused.\n");
        return;
    }

    printf("\n--- READING THE HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("--- END OF SCROLLS ---\n");
    fclose(fp);

    printf("\nPress Enter to return to the command center...");
    getchar(); // Clear previous newline if any
    getchar();
}

/**
 * Interactive sub-menu to configure cow parameters and paranoia.
 */
void configure_cows() {
    char input[50];
    while (1) {
        printf("\n--- COW CONFIGURATION ---\n");
        printf("1. Cow Metabolism: %d laps/sec\n", cow_metabolism);
        printf("2. Paranoid Mode: %s\n", paranoid_mode ? "ENABLED (GLORY BE)" : "DISABLED");
        printf("3. Return to Main Menu\n");
        printf("> ");

        if (fgets(input, sizeof(input), stdin) == NULL) break;

        int choice = atoi(input);
        if (choice == 1) {
            printf("Enter new metabolism rate (1-10): ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                int rate = atoi(input);
                if (rate >= 1 && rate <= 10) {
                    cow_metabolism = rate;
                    printf("Metabolism synchronized. The cows are now running at %d laps/sec.\n", rate);
                } else {
                    printf("Invalid rate. The cows refuse to cooperate.\n");
                }
            }
        } else if (choice == 2) {
            paranoid_mode = !paranoid_mode;
            printf("Paranoid Mode %s.\n", paranoid_mode ? "ENGAGED" : "DISENGAGED");
        } else if (choice == 3) {
            break;
        }
    }
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
 * Non-blocking keyboard hit utility.
 * Returns 1 if a key was pressed, 0 otherwise.
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
 * Enters the main monitoring loop.
 * Logic is influenced by cow_metabolism and paranoid_mode.
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

        // Volatility depends on paranoid mode
        int change_range = paranoid_mode ? 51 : 31;
        int change_offset = paranoid_mode ? 25 : 15;
        int change = (rand() % change_range) - change_offset;

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

        printf("\nMonitoring... Press 'q' to retreat to your pillow fort.\n");
        fflush(stdout);

        if (kbhit()) {
            if (getchar() == 'q') break;
        }

        // Sleep depends on cow metabolism
        usleep(1000000 / cow_metabolism);
    }
    printf("\nDefense cycle terminated safely. The Polish cows are resting.\n");
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
    init_system();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n--- MAIN COMMAND CENTER ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS (Logs)\n");
        printf("3. CONFIGURE COWS\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("STNM3K > ");

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        int choice = atoi(command);
        if (choice == 1) {
            engage_defenses();
        } else if (choice == 2) {
            view_holy_scrolls();
        } else if (choice == 3) {
            configure_cows();
        } else if (choice == 4) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        }
    }

    return 0;
}
