//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|10|2024 00:18:29            !//
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

int calNum(int year) { return (year / 4) - (year / 100) + (year / 400); }
int leapNum(int l, int r) {
    l--;
    return calNum(r) - calNum(l);
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

void solve() {
    map<string,int> monthInNum;
    monthInNum["January"] = 1;
    monthInNum["February"] = 2;
    monthInNum["March"] = 3;
    monthInNum["April"] = 4;
    monthInNum["May"] = 5;
    monthInNum["June"] = 6;
    monthInNum["July"] = 7;
    monthInNum["August"] = 8;
    monthInNum["September"] = 9;
    monthInNum["October"] = 10;
    monthInNum["November"] = 11;
    monthInNum["December"] = 12;    

    string a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    b1.pop_back();
    b2.pop_back();
    int year1 = stoll(c1), year2 = stoll(c2);
    int ans = leapNum(year1, year2);

    if(isLeapYear(year1)){
        if(monthInNum[a1] > 2)
            ans--;
    }

    if(isLeapYear(year2)){
        if (monthInNum[a2] < 2)
            ans--;
        else if (monthInNum[a2] == 2) {
            int date = stoll(b2);
            if (date < 29)
                ans--;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}