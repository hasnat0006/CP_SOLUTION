//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|10|2024 22:00:14            !//
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

int binaryExp(int base, int power, int MOD = mod) {
    int res = 1;
    while (power) {
        if (power & 1)
            res = (res * base) % MOD;
        base = ((base % MOD) * (base % MOD)) % MOD;
        power /= 2;
    }
    return res;
}

vector<int> ans(1e6 + 1, 0);

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    for (int i = 2; i <= 1e6; i++) {
        if (i % 2)
            ans[i] = 2;
        else
            ans[i] = binaryExp(2, i / 2);
    }
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}