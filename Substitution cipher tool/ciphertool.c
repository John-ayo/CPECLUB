#include <stdio.h>
#include <string.h>

void encrypt(char *str, int key) {
    char *ptr = str;
    while (*ptr != '\0') {
        *ptr = (char)(*ptr + key);
        ptr++;
    }
}

void decrypt(char *str, int key) {
    char *ptr = str;
    while (*ptr != '\0') {
        *ptr = (char)(*ptr - key);
        ptr++;
    }
}

int main() {
    char message[256];
    int key;
    int choice;

    printf("--- Substitution Cipher Tool ---\n");
    printf("1. Encrypt\n2. Decrypt\n");
    printf("Choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter key (integer): ");
    scanf("%d", &key);

    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, key);
        printf("Decrypted: %s\n", message);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}