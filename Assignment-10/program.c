#include <stdio.h>
//Om Hinge

/* Returns 1 if year is a leap year, else 0 */
int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Returns number of days in a month (month: 1 to 12) */
int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeap(year))
        return 29;
    return days[month - 1];
}

/* Returns weekday of a date: 0 = Sunday, 1 = Monday, ... 6 = Saturday */
int dayOfWeek(int year, int month, int day) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    if (month < 3)
        year -= 1;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

int main(void) {
    char *monthNames[] = {"January", "February", "March", "April", "May",
                          "June", "July", "August", "September",
                          "October", "November", "December"};
    int year, month, day, i;
    int start, total;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("\n========== CALENDAR %d ==========\n", year);

    for (month = 1; month <= 12; month++) {
        printf("\n   %s %d\n", monthNames[month - 1], year);
        printf("Su Mo Tu We Th Fr Sa\n");

        start = dayOfWeek(year, month, 1);   /* weekday of 1st of month */
        total = daysInMonth(month, year);

        /* leave blank spaces before the 1st date */
        for (i = 0; i < start; i++)
            printf("   ");

        for (day = 1; day <= total; day++) {
            printf("%2d ", day);
            if ((start + day) % 7 == 0)      /* Saturday reached, new line */
                printf("\n");
        }
        printf("\n");
    }

    return 0;
}
