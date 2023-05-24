#include <stdio.h>
#include <stdbool.h>

bool isValidDate(int day, int month, int year) {
    // Check if the year is within a valid range
    if (year < 0 || year > 9999) {
        return false;
    }

    // Check if the month is within a valid range
    if (month < 1 || month > 12) {
        return false;
    }

    // Check if the day is within a valid range based on the month
    int maxDays;

    if (month == 2) { // February
        // Leap year check
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            maxDays = 29;
        } else {
            maxDays = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    } else {
        maxDays = 31;
    }

    if (day < 1 || day > maxDays) {
        return false;
    }

    return true;
}

int main() {
    int day, month, year;

    printf("Enter a date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    if (isValidDate(day, month, year)) {
        printf("Valid date\n");
    } else {
        printf("Invalid date\n");
    }

    return 0;
}
