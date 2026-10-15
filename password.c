#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_common_password(const char *password){
    const char *common_passwords[]={
        "password",
        "password123",
        "123456",
        "12345678",
        "qwerty",
        "qwerty123",
        "admin",
        "letmein",
        "welcome",
        "abc123"
        
    };

    size_t count = sizeof(common_passwords) / sizeof(common_passwords[0]);

    for (size_t i = 0; i < count; i++) {
        size_t j = 0;

        while (password[j] != '\0' &&
               common_passwords[i][j] != '\0' &&
               tolower((unsigned char)password[j]) ==
               tolower((unsigned char)common_passwords[i][j])) {
            j++;
        }

        if (password[j] == '\0' && common_passwords[i][j] == '\0') {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    char password[256];
    int upper = 0, lower = 0;
    int digit = 0, special = 0;
    int score = 0;
    int common = 0;

    printf("=== Password Strength Checker ===\n");
    printf("Enter a test password: ");

    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    password[strcspn(password, "\n")] = '\0';

    size_t length = strlen(password);


    if (length == 0) {
        printf("Error: Password cannot be empty. \n");
        return 1;
    }



    for (size_t i = 0; i < length; i++) {
        unsigned char ch = (unsigned char)password[i];

        if (isupper(ch)) {
            upper = 1;
        } else if (islower(ch)) {
            lower = 1;
        } else if (isdigit(ch)) {
            digit = 1;
        } else if (ispunct(ch)) {
            special = 1;
        }
    }

    common = is_common_password(password);

    if (length >= 8) score++;
    if (length >= 12) score++;
    if (upper) score++;
    if (lower) score++;
    if (digit) score++;
    if (special) score++;

    printf("\n--- Analysis ---\n");
    printf("Length: %zu characters\n", length);
    printf("Uppercase letter: %s\n", upper ? "Yes" : "No");
    printf("Lowercase letter: %s\n", lower ? "Yes" : "No");
    printf("Numbers: %s\n", digit ? "Yes" : "No");
    printf("Special characters: %s\n", special ? "Yes" : "No");
    printf("Common password detected: %s\n", common ? "Yes - avoid this password" : "Not found in our list");

    printf("\nStrength: ");

    if (common || length < 8 || score <= 2) {
        printf("Weak\n");
    } else if (length >= 12 && score >= 5) {
        printf("Strong by these basic checks\n");
    } else {
        printf("Moderate\n");
    }

    printf("\nNote: This is a basic educational estimate.\n");
    printf("It does not test against known leaked passwords.\n");

    return 0;
}
