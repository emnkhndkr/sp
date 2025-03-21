#include <stdio.h>
#include <string.h>

void setPassword(char *pw);
int authenticateUser (const char *pw);
void openDoor(int *opn, int lkd);
void closeDoor(int *opn);
void lockDoor(int *opn, int *lkd);
void unlockDoor(int *lkd);
void checkStatus(int opn, int lkd);

int main() {
    int opn = 0;   
    int lkd = 0;   
    char pw[20] = "0000"; 

    setPassword(pw);

    for (int trial = 0; trial < 3; trial++) {
        if (authenticateUser (pw)) break; 
        printf("Incorrect password! Try again.\n");
    }

    for (;;) {
        int choice;
        printf("\nAccess Guard: Intelligent Door Control System\n");
        printf("1. Open Door\n2. Close Door\n3. Lock Door\n4. Unlock Door\n5. Check Status\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: openDoor(&opn, lkd); break;
            case 2: closeDoor(&opn); break;
            case 3: lockDoor(&opn, &lkd); break;
            case 4: unlockDoor(&lkd); break;
            case 5: checkStatus(opn, lkd); break;
            case 6: return 0; 
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void setPassword(char *pw) {
    char ent_pw[10];
    printf("Admin is requested to set a new password: ");
    scanf("%s", ent_pw);
    if (strcmp(ent_pw, "") != 0) {
        strcpy(pw, ent_pw);
    }
}

int authenticateUser (const char *pw) {
    char ent_pw[10];
    printf("User \nEnter the password: ");
    scanf("%s", ent_pw);
    return strcmp(ent_pw, pw) == 0; 
}

void openDoor(int *opn, int lkd) {
    if (lkd) {
        printf("The door is locked. Unlock it first.\n");
    } else if (*opn) {
        printf("The door is already open.\n");
    } else {
        *opn = 1; 
        printf("The door is now open. Welcome!\n");
    }
}

void closeDoor(int *opn) {
    if (*opn) {
        *opn = 0; 
        printf("The door is now closed.\n");
    } else {
        printf("The door is already closed.\n");
    }
}

void lockDoor(int *opn, int *lkd) {
    if (*opn) {
        printf("Please, close the door before locking it.\n");
    } else {
        *lkd = 1; 
        printf("The door is now locked.\n");
    }
}

void unlockDoor(int *lkd) {
    *lkd = 0; 
    printf("The door is now unlocked.\n");
}

void checkStatus(int opn, int lkd) {
    printf("Door Status: Open: %s, Locked: %s\n", opn ? "Yes" : "No", lkd ? "Yes" : "No");
}
