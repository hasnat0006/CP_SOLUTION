//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|09|2024 16:16:04            !//
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

int maxNum = 0, setBit = 0;
void F(string s, int i) {
    if (i == -1) {
        int num = stoi(s);
        int setBits = __builtin_popcount(num);
        if(setBits > setBit) {
            setBit = setBits;
            maxNum = num;
        }
        else if(setBits == setBit) {
            maxNum = max(maxNum, num);
        }
        return;
    }
    if (s[i] == '?') {
        for (int j = 0; j <= 9; j++) {
            s[i] = j + '0';
            F(s, i - 1);
            s[i] = '?';
        }
    }
    else {
        F(s, i - 1);
    }
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    setBit = 0;
    maxNum = 0;
    F(s, n - 1);
    cout << maxNum << endl;
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