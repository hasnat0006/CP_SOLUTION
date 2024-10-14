//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|05|2024 00:18:39            !//
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

int factor(int n) {
    int a;
    if (n % 2 == 0)
        return 2;
    for (a = 3; a <= sqrtl(n); a += 2) {
        if (n % a == 0)
            return a;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    if (n == 0)
        exit(0);
    int r;
    map<int, int> cnt;
    while (n > 1) {
        r = factor(n);
        cnt[r]++;
        n /= r;
    }
    for (auto i : cnt) {
        cout << i.first << "^" << i.second << " ";
    }
    cout << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 100000;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
