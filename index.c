#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    while (1) {
        // Get current time
        time_t currentTime = time(NULL);
        struct tm *localTime = localtime(&currentTime);
        int hour = localTime->tm_hour;
        int min = localTime->tm_min;
        int sec = localTime->tm_sec;

        // Clear the console
        system("clear");

        // Display the time
        printf("%02d:%02d:%02d\n", hour, min, sec);

        // Delay for 1 second
        sleep(1);
    }

    return 0;
}
