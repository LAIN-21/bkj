#include <stdio.h>

#define MAX_ATTEMPTS 3
#define MAX_STRING_LENGTH 20

char name[MAX_STRING_LENGTH] = "";
char surname[MAX_STRING_LENGTH] = "";
char nickname[MAX_STRING_LENGTH] = "";

void resetString(char *str) {
    str[0] = '\0';
}


void greetUser(char formalityLevel) {
    if (formalityLevel == 'a') {
        printf("Hey %s, nice to meet you!\n", nickname);
    } else if (formalityLevel == 'b') {
        printf("Hello %s, how are you today?\n", name);
    } else if (formalityLevel == 'c') {
        printf("Good day, %s %s. It's a pleasure to greet you.\n", name, surname);
    } else {
        printf("Sorry, we don't have enough information to greet you properly.\n");
    }
}

void deleteFunc() {
    char choice;
    printf("Which information would you like to delete?\n");
    printf("a - Name\nb - Surname\nc - Nickname\nd - None\nYour choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'a':
            resetString(name);
            printf("Your name has been deleted.\n");
            break;
        case 'b':
            resetString(surname);
            printf("Your surname has been deleted.\n");
            break;
        case 'c':
            resetString(nickname);
            printf("Your nickname has been deleted.\n");
            break;
        case 'd':
            break;
        default:
            printf("Not a valid option, please try again.\n");
            deleteFunc();
            break;
    }
}

int main() {
    int option;
    int failedAttempt = 0;
    char formalityLevel;

    while (1) {
        printf("\nSelect an option:\n");
        printf("0 - Exit\n");
        printf("1 - Input name and surname\n");
        printf("2 - Input nickname\n");
        printf("3 - Choose greeting formality\n");
        printf("4 - Delete name, surname, or nickname\n");
        printf("Your choice: ");
        if (scanf("%d", &option) != 1) {
            printf("Please enter a valid number.\n");
            failedAttempt++;
            if (failedAttempt >= MAX_ATTEMPTS) {
                printf("You don't seem too interested in speaking with me...\n");
                return 0;
            }
            while (getchar() != '\n');
            continue;
        }

        switch (option) {
            case 0:
                printf("Goodbye!\n");
                return 0;
            case 1:
                promptAndRead("Enter your name: ", name);
                promptAndRead("Enter your surname: ", surname);
                break;
            case 2:
                promptAndRead("Enter your nickname: ", nickname);
                break;
            case 3:
                printf("Choose your preferred level of formality (a - informal, b - medium, c - formal): ");
                scanf(" %c", &formalityLevel);
                greetUser(formalityLevel);
                break;
            case 4:
                deleteFunc();
                break;
            default:
                printf("Not a valid option, please try again.\n");
                failedAttempt++;
                if (failedAttempt >= MAX_ATTEMPTS) {
                    printf("You don't seem too interested in speaking with me...\n");
                    return 0;
                }
                break;
        }
    }

    return 0;
}
