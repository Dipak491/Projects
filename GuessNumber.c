#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess;
    int attempts = 0;
    int maxAttempts = 5;
    int isWin = 0;

    // Generate a random number between 1 and 100
    srand(time(NULL));
    secretNumber = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");

    while (attempts < maxAttempts) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess == secretNumber) {
            isWin = 1;
            break;
        } else if (guess < secretNumber) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }
    }

    if (isWin) {
        printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
    } else {
        printf("Sorry, you did not guess the number. It was %d.\n", secretNumber);
    }

    return 0;
}
