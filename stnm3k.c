#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

void log_event(const char *event) {
    // Ensure logs directory exists
    struct stat st = {0};
    if (stat("logs", &st) == -1) {
        mkdir("logs", 0700);
    }

    FILE *fp = fopen("logs/holy_scrolls.txt", "a");
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
    const char* metadata[] = {
        "COW_HEART_RATE: 180bpm",
        "PARANOIA_LEVEL: CRITICAL",
        "MUSHROOM_NETWORK: STABLE",
        "ACORN_DENSITY: HIGH",
        "PILLOW_FORT_INTEGRITY: 99%"
    };
    int metadata_count = sizeof(metadata) / sizeof(metadata[0]);
    fprintf(fp, "[%s] COCAINE-COW-LOG [%s]: %s\n", timestamp, metadata[rand() % metadata_count], event);
    fclose(fp);
}

void print_threat_meter(int level) {
    printf("SQUIRREL THREAT METER: [");
    int bars = level / 5;
    for (int i = 0; i < 20; i++) {
        if (i < bars) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf("] %d%%\n", level);
}

void print_graph_of_chaos() {
    printf("GUI GRAPH OF CHAOS:\n");
    for (int i = 5; i > 0; i--) {
        int val = rand() % 20;
        printf("%2d |", val);
        for (int j = 0; j < val; j++) {
            printf("*");
        }
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
        "Infected acorn payload intercepted!",
        "Microsoft Squirrel trying to update your nuts!",
        "Radioactive tail signal detected in ventilation!",
        "Pillow fort perimeter breached by fluffy tail!",
        "Mushroom network reporting squirrel gathering!",
        "Acorn-encrypted packets flooding the gateway!"
    };
    int threat_count = sizeof(threats) / sizeof(threats[0]);
    return threats[rand() % threat_count];
}

void print_pillow_fort_status() {
    printf("PILLOW FORT COMMAND CENTER STATUS:\n");
    printf("  [PROTECTION] Blanket Integrity: %d%%\n", 90 + (rand() % 11));
    printf("  [RESOURCES ] Cookie Reserves:  %s\n", (rand() % 2) ? "OPTIMAL" : "CRITICAL (NEED MORE OREOS)");
    printf("  [POWER     ] Flashlight Battery: %d%%\n", 50 + (rand() % 51));
}

void print_cow_sync_meter() {
    int sync = rand() % 101;
    printf("COCAINE-COW SYNCHRONICITY: [");
    int bars = sync / 5;
    for (int i = 0; i < 20; i++) {
        if (i < bars) printf("=");
        else printf(".");
    }
    printf("] %d%%\n", sync);
}

void view_holy_scrolls() {
    FILE *fp = fopen("logs/holy_scrolls.txt", "r");
    if (fp == NULL) {
        printf("The Holy Scrolls are missing! The squirrels must have stolen them!\n");
        return;
    }

    printf("\n--- READING HOLY SCROLLS OF TRUTH ---\n");
    char line[256];
    char buffer[10][256];
    int count = 0;
    while (fgets(line, sizeof(line), fp)) {
        strcpy(buffer[count % 10], line);
        count++;
    }
    fclose(fp);

    int limit = (count > 10) ? 10 : count;
    int start = (count > 10) ? count % 10 : 0;

    for (int i = 0; i < limit; i++) {
        printf("%s", buffer[(start + i) % 10]);
    }
    printf("--- END OF SCROLLS ---\n\n");
}

void sync_with_cows() {
    printf("\n--- STNM3K COW SYNC PROTOCOL ---\n");
    printf("Contacting Polish cows in the mushroom network...\n");
    sleep(1);
    printf("Cow #1: MOO (Translation: 'The Google Machine is watching')\n");
    printf("Cow #2: MOO (Translation: 'I need more cocaine')\n");
    printf("URGENT: To complete synchronization, you must MOO back.\n");
    printf("Type 'MOO' to proceed: ");
    char response[100];
    if (fgets(response, sizeof(response), stdin) == NULL) return;
    if (strstr(response, "MOO") != NULL) {
        printf("SYNCHRONIZATION COMPLETE. You are now one with the herd.\n\n");
    } else {
        printf("SYNC FAILED. The cows are offended. Your network is vulnerable.\n\n");
    }
}

void engage_defenses() {
    printf("\n--- ENGAGING DEFENSES ---\n");
    printf("GLORY BE! GLORY BE! GLORY BE!\n");
    log_event("DEFENSES ENGAGED. SHARPENING ACORNS.");

    int threat_level = 10;
    while (1) {
        // Clear screen (works on most terminals)
        printf("\033[H\033[J");

        printf("🖥️  SQUIRREL TERMINATOR NETWORK MONITOR 3000 (STNM3K) v0.69\n");
        printf("PLATFORM: WINDOWS ME (GLORY BE)\n\n");

        int change = (rand() % 31) - 15; // -15 to +15
        threat_level += change;
        if (threat_level < 0) threat_level = 0;
        if (threat_level > 100) threat_level = 100;

        print_threat_meter(threat_level);
        printf("\n");
        print_graph_of_chaos();
        printf("\n");
        print_pillow_fort_status();
        print_cow_sync_meter();

        if (threat_level > 70) {
            const char* threat = get_random_threat();
            if (threat_level > 85) {
                printf("\n!!! RED SQUIRREL ALERT !!!\n");
            } else {
                printf("\n!!! YELLOW ACORN ALERT !!!\n");
            }
            printf("ALERT: %s\n", threat);
            log_event(threat);
            printf("Fungal Network Messaging: ENCRYPTED ALERT SENT TO PILLOW FORT.\n");
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

        if (strstr(command, "GLORY BE") != NULL) {
            prayer_count++;
        } else {
            printf("Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you.\n");
            return 1;
        }
    }

    if (prayer_count == 3) {
        printf("\nAuthentication successful. Welcome, Sentinel.\n");
        int running = 1;
        while (running) {
            printf("1. ENGAGE DEFENSES\n");
            printf("2. VIEW HOLY SCROLLS\n");
            printf("3. SYNCHRONIZE WITH POLISH COWS\n");
            printf("4. EXIT (COWARDLY)\n");
            printf("> ");
            if (fgets(command, sizeof(command), stdin) == NULL) break;

            if (strstr(command, "ENGAGE DEFENSES") != NULL || strstr(command, "1") != NULL) {
                engage_defenses();
            } else if (strstr(command, "VIEW HOLY SCROLLS") != NULL || strstr(command, "2") != NULL) {
                view_holy_scrolls();
            } else if (strstr(command, "SYNCHRONIZE") != NULL || strstr(command, "3") != NULL) {
                sync_with_cows();
            } else if (strstr(command, "EXIT") != NULL || strstr(command, "4") != NULL) {
                printf("Cowardice detected. The squirrels have already won. Your pillow fort is compromised.\n");
                running = 0;
            } else {
                printf("Invalid command. The Polish cows are judging you.\n");
            }
        }
    } else {
        printf("Incorrect prayer. The Polish cows are disappointed and the Google Machine is laughing at you.\n");
    }

    return 0;
}
