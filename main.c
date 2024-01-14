#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

struct Password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Password storage is full\n");
        return;
    }

    printf("Enter website: ");
    scanf("%s", passwords[numPasswords].website);

    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void displayPasswords() {
    printf("Stored Passwords:\n");
    for (int i = 0; i < numPasswords; ++i) {
        printf("Website: %s | Username: %s | Password: %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;
    do {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add a password\n");
        printf("2. Display all passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                printf("Exiting Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
