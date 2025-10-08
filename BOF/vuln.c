#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

const unsigned char correct[] = {0x0a, 0x22, 0x00, 0x3E, 0x1D, 0x2E, 0x02, 0x5F, 0x16, 0x13, 0x0A, 0x11, 0x17, 0x0B, 0x42, 0x2C};
const int correct_len = sizeof(correct);

void xor_bytes(const char *message, int message_len, const char *key, char *out) {
    int key_len = strlen(key);
    for (int i = 0; i < message_len; i++) {
        out[i] = message[i] ^ key[i % key_len];
    }
}

int login(const char *username, const char *password, const char *key) {
    int len = strlen(password);
    if (len != correct_len) {
        printf("False Login.\n");
        return -1;
    }

    unsigned char encrypted[128];
    xor_bytes(password, len, key, (char*)encrypted);
    const char actual_username[] = "root";
    int correct_username = strcmp(username, actual_username);
    if (correct_username != 0) {
        printf("False Login.\n");
        return -1;
    }
    if (memcmp(encrypted, correct, correct_len) == 0) {
        printf("Correct login.\n"); fflush(stdout);
        return 0;
    } else {
        printf("False Login.\n");
        return -1;
    }
}

__attribute__((naked)) void trampoline() { __asm__("jmp *%rsp"); }


int main() {
    const char key[] = "NiceTryGoAway!!";
    char username[50];
    char password[50];


    printf("Welcome to the management interface! Please enter your credentials: \n"); fflush(stdout);

    printf("Username: \n"); fflush(stdout);
    scanf("%s", username);
    printf("Password: \n"); fflush(stdout);
    scanf("%s", password);
    int loggedIn = login(username, password, key);
    if (loggedIn == 0) {
        printf("how did you even get here");
        perror("execl failed");
        return -1;
    }
    return 0;
}


