//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
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
    int base;
    string num;
    cin >> base >> num;
    __int128_t ans = 0;
    string b = to_string(base - 1);
    int n = b.size();
    int power = 1;
    while (num.size()) {
        int m = num.size();
        string temp = "";
        for (int i = max(m - n, 0LL); i < m; i++) {
            temp.push_back(num[i]);
        }
        while (temp.front() == '0' && temp.size() > 1) {
            temp.erase(temp.begin());
        }
        int tempNum = stoll(temp);
        if (tempNum < base) {
            int tempCal = tempNum * power;
            ans += tempCal;
            power *= base;
            int del = temp.size();
            while (del--)
                num.pop_back();
        }
        else {
            temp.erase(temp.begin());
            while (temp.front() == '0' && temp.size() > 1) {
                temp.erase(temp.begin());
            }
            tempNum = stoll(temp);
            int tempCal = tempNum * power;
            ans += tempCal;
            power *= base;
            int del = temp.size();
            while (del--)
                num.pop_back();
        }
    }
    cout << (int)ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}