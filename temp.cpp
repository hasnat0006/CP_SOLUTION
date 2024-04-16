//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|04|2024 23:17:47            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int date1, month1, year1, date2, month2, year2;
    cin >> date1 >> month1 >> year1 >> date2 >> month2 >> year2;
    int DaysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto isLeapYear = [&](int year) {
        if (year % 400 == 0)
            return true;
        if (year % 100 == 0)
            return false;
        if (year % 4 == 0)
            return true;
        return false;
    };
    auto exist = [&]() {
        if (date2 <= DaysInMonth[month2])
            return true;
        if (month2 == 2 && date2 == 29 && isLeapYear(year2))
            return true;
        return false;
    };
    auto totalPreLeapYears = [&]() {
        int cnt = 0;
        cnt += (year2 - 1) / 4;
        cnt -= (year2 - 1) / 100;
        cnt += (year2 - 1) / 400;
        return cnt;
    };
    if (exist()) {
        int totalDays = (year2 - 1) * 365 + totalPreLeapYears();
        for (int i = 1; i < month2; i++)
            totalDays += DaysInMonth[i];
        if (month2 > 2)
            totalDays += isLeapYear(year2);
        totalDays += date2;
        int firstDayofMonth = totalDays - date2 + 1;
        int row = 0;
        int col = firstDayofMonth % 7;
        int cur = 1;
        while (cur < date2) {
            cur++;
            col++;
            if (col == 7) {
                col = 0;
                row++;
            }
        }
        cout << "[" << row + 1<< "][" << col + 1<< "]" << endl;
        return;
    }
    cout << "Unspecified Server Error" << endl;
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