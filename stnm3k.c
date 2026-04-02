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

/* --- TERMINAL MANAGEMENT --- */

struct termios orig_termios;

/**
 * Restores the terminal to its original state.
 */
void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

/**
 * Configures the terminal for non-canonical input and no echo.
 */
void setup_terminal() {
    static int registered = 0;
    if (!registered) {
        tcgetattr(STDIN_FILENO, &orig_termios);
        atexit(restore_terminal);
        registered = 1;
    }
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/**
 * Handles signals to ensure terminal restoration.
 */
void handle_signal(int sig) {
    (void)sig;
    restore_terminal();
    const char *msg = "\nCaught signal, exiting... (Pillow fort retreating)\n";
    write(STDOUT_FILENO, msg, strlen(msg));
    _exit(0);
}

/**
 * Returns non-zero if a key has been pressed.
 */
int kbhit() {
    int ch;
    int oldf;

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

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

/* --- GLOBAL SETTINGS --- */
int paranoid_mode = 0;
int cow_metabolism = 1;

/* --- CORE SYSTEM UTILITIES --- */

/**
 * Initializes the system by seeding the RNG and ensuring the log directory exists.
 */
void init_system() {
    srand(time(NULL));
    signal(SIGINT, handle_signal);
    umask(0077);
    if (mkdir(LOG_DIR, 0700) == -1) {
        if (errno != EEXIST) {
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
 * Prints the application banner.
 */
void print_banner() {
    printf("%s", GRN);
    printf("  ______ _______ _   _ __  __ ____  _  __\n");
    printf(" /  ____|__   __| \\ | |  \\/  |___ \\| |/ /\n");
    printf("|  |__     | |  |  \\| | \\  / | __) | ' / \n");
    printf("|   __|    | |  | . ` | |\\/| ||__ <|  <  \n");
    printf("|  |       | |  | |\\  | |  | |___) | . \\ \n");
    printf("|_/        |_|  |_| \\_|_|  |_|____/|_|\\_\\\n");
    printf("  SQUIRREL TERMINATOR NETWORK MONITOR 3000\n");
    printf("%s\n", RESET);
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
    printf("SQUIRREL THREAT METER: %s[%-8s] [%.*s%.*s] %3d%%%s\n",
           color, status, bars, bars_fill, METER_WIDTH - bars, bars_empty, level, RESET);
}

/**
 * Renders the GUI graph of chaos using bulk output.
 */
void print_graph_of_chaos() {
    static const char *symbols = "XXXXXXXXXXXXXXXXXXXX";
    static const char *stars   = "********************";
    static const char *dots    = "....................";
    printf("GUI GRAPH OF CHAOS (Network Volatility):\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        const char *buf = dots;
        if (val > 15) buf = symbols;
        else if (val > 8) buf = stars;
        printf("%2d |%.*s\n", val, val, buf);
    }
    printf("   +-------------------- (Acorns/sec)\n");
}

/* --- CORE ENGINE LOGIC --- */

/**
 * Displays the contents of the holy scrolls.
 */
void view_holy_scrolls() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("The scrolls are empty. No truths have been recorded yet.\n");
    } else {
        printf("\n--- THE HOLY SCROLLS OF TRUTH ---\n");
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }
    printf("\nPress [ENTER] to return to the sanctuary...\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Sub-menu to configure cow parameters and paranoia levels.
 */
void configure_cows() {
    char input[50];
    while (1) {
        printf("\033[H\033[J");
        printf("--- COW CONFIGURATION & PARANOIA ---\n");
        printf("1. Paranoid Mode: [%s]\n", paranoid_mode ? "ON" : "OFF");
        printf("2. Cow Metabolism (1-10): [%d]\n", cow_metabolism);
        printf("3. RETURN TO MAIN MENU\n");
        printf("Choice > ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        if (strstr(input, "1") != NULL) {
            paranoid_mode = !paranoid_mode;
            log_event(paranoid_mode ? "PARANOID MODE ENABLED. TRUST NOTHING." : "PARANOID MODE DISABLED. TRUST... SOME THINGS.");
        } else if (strstr(input, "2") != NULL) {
            printf("Enter metabolism speed (1=Sleepy, 10=Cocaine Laps) > ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                int val = atoi(input);
                if (val >= 1 && val <= 10) {
                    cow_metabolism = val;
                    log_event("COW METABOLISM ADJUSTED.");
                } else {
                    printf("INVALID METABOLISM. The cows are confused.\n");
                    sleep(1);
                }
            }
        } else if (strstr(input, "3") != NULL) {
            break;
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
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    setup_terminal();
    while (1) {
        if (kbhit()) {
            int c = getchar();
            if (c == 'q' || c == 'Q') break;
        }

        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("======================================================================\n");
        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v%s\n", VERSION);
        printf("PLATFORM: %s\n", PLATFORM);
        printf("======================================================================\n\n");

        int volatility = paranoid_mode ? 40 : 20;
        int change = (rand() % (volatility * 2 + 1)) - volatility;
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
    restore_terminal();
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
    print_banner();

    if (!authenticate_user()) {
        return 1;
    }

    char command[100];
    while (1) {
        printf("\n🖥️  STNM3K MAIN MENU\n");
        printf("1. ENGAGE DEFENSES\n");
        printf("2. VIEW HOLY SCROLLS (Logs)\n");
        printf("3. CONFIGURE COWS\n");
        printf("4. EXIT (COWARDLY)\n");
        printf("STNM3K > ");
        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strstr(command, "1") != NULL) {
            engage_defenses();
        } else if (strstr(command, "2") != NULL) {
            view_holy_scrolls();
        } else if (strstr(command, "3") != NULL) {
            configure_cows();
        } else if (strstr(command, "4") != NULL || strstr(command, "EXIT") != NULL) {
            printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
            break;
        }
    }

    return 0;
}
