#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 20

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

Contact phonebook[MAX_CONTACTS];
int contactCount = 0;

void addContact(Contact *c, const char *name, const char *phone) {
    strncpy(c->name, name, NAME_LEN - 1);
    c->name[NAME_LEN - 1] = '\0';
    strncpy(c->phone, phone, PHONE_LEN - 1);
    c->phone[PHONE_LEN - 1] = '\0';
}

void displayContact(Contact *c) {
    printf("Name: %s | Phone: %s\n", c->name, c->phone);
}

void searchContact(const char *name) {
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            displayContact(&phonebook[i]);
            found = 1;
        }
    }
    if (!found) printf("Contact not found.\n");
}

void deleteContact(const char *name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            contactCount--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void listAll() {
    if (contactCount == 0) {
        printf("Phonebook is empty.\n");
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        displayContact(&phonebook[i]);
    }
}

int main() {
    int choice;
    char name[NAME_LEN];
    char phone[PHONE_LEN];

    while (1) {
        printf("\n--- Phonebook Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. List All Contacts\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter phone: ");
                fgets(phone, PHONE_LEN, stdin);
                phone[strcspn(phone, "\n")] = '\0';
                if (contactCount < MAX_CONTACTS) {
                    addContact(&phonebook[contactCount], name, phone);
                    contactCount++;
                    printf("Contact added.\n");
                } else {
                    printf("Phonebook full.\n");
                }
                break;
            case 2:
                printf("Enter name to search: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                searchContact(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteContact(name);
                break;
            case 4:
                listAll();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}