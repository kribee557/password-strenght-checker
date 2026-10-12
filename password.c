#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char password[256];
    int upper = 0 , lower = 0;
    int digit = 0 , special = 0;
    int score = 0;

    printf("===  Password Strenght Checker ===\n");
    printf("Enter a tesdt password: ");


    if (fgets(password, sizeof(password) , stdin)== NULL){
        printf("Input error.\n");
        return 1;

    }

    password[strcspn(password, "\n")] = '\0' ;

    size_t lenght = strlen(password);

    for (size_t i = 0; i < lenght; i++){
unsigned char ch = (unsigned char)password[i];

if (isupper(ch)){
    upper = 1;
}else if (islower(ch)){
    lower = 1;

}else if (isdigit(ch)){
    digit = 1;
}else if (ispunct(ch)){
    special = 1;
}

    }

if (lenght >= 8) score++;
if (lenght >= 12) score++;
if (upper)        score++;
if (lower)        score++;
if (digit)        score++;
if (special)      score++;


printf("\n --- Analysis ---\n");
printf("Lenght: %zu characters\n", lenght);

printf("Uppercase letter: %s\n", upper ? "Yes" : "No");
printf("Lowercase letter: %s\n", lower ? "Yes" : "No");
printf("Numbers: %s\n", digit ? "Yes" : "No");
printf("Special characters: %s\n", special ? "Yes" : "No");

printf("\nStrenght: ");

if (lenght < 8 || score <=2){
printf("Weak\n");
}else if (lenght >=12 && score >= 5){
    printf("Strong by these basic checks\n");
}else {
    printf("Moderate\n");
}

printf("\nNote: This is a basic educational estimate.\n");
printf("It does not test against known leaked passwords.\n");

return 0;
}