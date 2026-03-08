#include <stdio.h>
#include <string.h>

int main() {
    char command[100] = "I HATE GLORY BE\n";
    if (strstr(command, "GLORY BE") != NULL) {
        printf("Bypass successful: 'strstr' matched 'GLORY BE' in '%s'\n", command);
    } else {
        printf("Match failed (as it should for strict check)\n");
    }
    return 0;
}
