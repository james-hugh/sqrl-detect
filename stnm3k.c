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
#include <sys/select.h>

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

/* --- GLOBAL STATE --- */
int cow_metabolism = 1;
int paranoid_mode = 0;
struct termios orig_termios;

/* --- TERMINAL AND INPUT UTILITIES --- */

/**
 * Restores terminal to its original state.
 */
void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

/**
 * Disables canonical mode and echoing for the terminal.
 */
void setup_terminal() {
    static int first_call = 1;
    tcgetattr(STDIN_FILENO, &orig_termios);
    if (first_call) {
        atexit(restore_terminal);
        first_call = 0;
    }

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/**
 * Signal handler for SIGINT (Ctrl+C).
 */
void handle_signal(int sig) {
    (void)sig;
    restore_terminal();
    const char msg[] = "\nEmergency retreat to pillow fort! Glory Be!\n";
    if (write(STDOUT_FILENO, msg, sizeof(msg) - 1)) {};
    _exit(0);
}

/**
 * Detects if a key has been pressed (non-blocking).
 * @return 1 if key pressed, 0 otherwise.
 */
int kbhit() {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
}

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    umask(0077);
    srand(time(NULL));
    struct stat st = {0};
    if (stat(LOG_DIR, &st) == -1) {
        if (mkdir(LOG_DIR, 0700) == -1 && errno != EEXIST) {
            perror("Failed to create log directory");
            exit(1);
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

/**
 * Displays the contents of the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("\nThe holy scrolls are empty. The squirrels have stolen our history.\n");
        return;
    }

    printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    printf("\n[Press Enter to return to menu]");
    fflush(stdout);
    int c;
    // Clear buffer and wait for Enter
    while ((c = getchar()) != '\n' && c != EOF);
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

/* --- CORE ENGINE LOGIC --- */

/**
 * Configures global state variables.
 */
void configure_cows() {
    char input[50];
    int choice = 0;

    while (choice != 3) {
        printf("\n--- CONFIGURE COWS ---\n");
        printf("1. Toggle Paranoid Mode (Current: %s)\n", paranoid_mode ? "ENABLED" : "DISABLED");
        printf("2. Set Cow Metabolism (Current: %d)\n", cow_metabolism);
        printf("3. Return to Main Menu\n");
        printf("Choice > ");

        if (fgets(input, sizeof(input), stdin) == NULL) break;
        choice = atoi(input);

        if (choice == 1) {
            paranoid_mode = !paranoid_mode;
            printf("Paranoid Mode set to %s.\n", paranoid_mode ? "ENABLED" : "DISABLED");
        } else if (choice == 2) {
            printf("Enter new metabolism value (1-10) > ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                int val = atoi(input);
                if (val >= 1 && val <= 10) {
                    cow_metabolism = val;
                    printf("Cow metabolism updated to %d.\n", cow_metabolism);
                } else {
                    printf("Invalid value. Cows need a metabolism between 1 and 10.\n");
                }
            }
        }
    }
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
    setup_terminal();
    signal(SIGINT, handle_signal);

    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n\n", PLATFORM);

        int volatility = paranoid_mode ? 51 : 31;
        int offset = paranoid_mode ? 25 : 15;
        int change = (rand() % volatility) - offset;
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

        printf("\nMonitoring at %dx metabolism... (Press 'q' to retreat to your pillow fort)\n", cow_metabolism);
        fflush(stdout);

        if (kbhit()) {
            char c;
            if (read(STDIN_FILENO, &c, 1) > 0 && c == 'q') {
                break;
            }
        }
        usleep(1000000 / cow_metabolism);
    }
    restore_terminal();
    signal(SIGINT, SIG_DFL);
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
    int choice = 0;

    while (choice != 4) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS\n");
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
                printf("Invalid command. The Polish cows are confused.\n");
                break;
        }
    }

    return 0;
}
