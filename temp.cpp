
#include <bits/stdc++.h>
using namespace std;

int dayNumber(int day, int month, int year) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

string getMonthName(int monthNumber) {
    string months[] = {"January",   "February", "March",    "April",
                       "May",       "June",     "July",     "August",
                       "September", "October",  "November", "December"};
    return (months[monthNumber]);
}

bool isLeapYear(int n) {
    if (n % 100 == 0) {
        if (n % 400 == 0)
            return true;
        return false;
    }
    if (n % 4 == 0)
        return true;
    return false;
}

int numberOfDays(int monthNumber, int year) {
    if (monthNumber == 1 and isLeapYear(year))
        return 29;
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (monthDays[monthNumber]);
}

void printCalendar(int year) {
    printf("		 Calendar - %d\n\n", year);
    int days;

    int current = dayNumber(1, 1, year);

    // i --> Iterate through all the months
    // j --> Iterate through all the days of the
    //	 month - i
    for (int i = 0; i < 12; i++) {
        days = numberOfDays(i, year);

        // Print the current month name
        printf("\n ------------%s-------------\n", getMonthName(i).c_str());

        // Print the columns
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
            printf("	 ");

        for (int j = 1; j <= days; j++) {
            printf("%5d", j);

            if (++k > 6) {
                k = 0;
                printf("\n");
            }
        }

        if (k)
            printf("\n");

        current = k;
    }

    return;
}

// Driver Program to check above functions
int main() {
    int year = 2016;
    printCalendar(year);

    return (0);
}
