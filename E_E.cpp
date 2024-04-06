//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|04|2024 11:06:12            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

int dayNumber(int day, int month, int year) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

bool isLeap(int n) {
    if (n % 100 == 0)
        if (n % 400 == 0)
            return true;
        else
            return false;
    if (n % 4 == 0)
        return true;
    else
        return false;
}

int numberOfDays(int month, int year) {
    if (month == 1 and isLeap(year))
        return 29;
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day[month];
}

int row = -1, col = -1;
void printCalendar(int year, int requiredMonth, int requiredDay) {
    int days;
    int current = dayNumber(1, 1, year);
    for (int i = 0; i < 12; i++) {
        days = numberOfDays(i, year);
        int k;
        int cnt = 1;
        for (k = 0; k < current; k++);
            // printf("     ");
        for (int j = 1; j <= days; j++) {
            if (j == requiredDay && i == requiredMonth) {
                col = k + 1;
                row = cnt;
                return;
            }
            if (++k > 6) {
                k = 0;
                cnt++;
            }
        }
        current = k;
    }
    return;
}

void solve() {
    row = -1, col = -1;
    int day1, month1, year1;
    cin >> day1 >> month1 >> year1;
    int day2, month2, year2;
    cin >> day2 >> month2 >> year2;
    printCalendar(year2, month2 - 1, day2);
    if(row == -1 || col == -1) {
        cout << "Unspecified Server Error" << endl;
        return;
    }
    if(year2 < year1) {
        cout << "u:" << abs(year1 - year2) << " ";
    }
    else if(year2 > year1) {
        cout << "d:" << abs(year1 - year2) << " ";
    }
    if(month2 < month1) {
        cout << "l:" << abs(month1 - month2) << " ";
    }
    else if(month2 > month1) {
        cout << "r:" << abs(month1 - month2) << " ";
    }
    cout << "[" << row <<"][" << col << "]" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}