//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|03|2024 11:13:03            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

bool isPossible(int a, int b) { return (a ^ b) > (a & b); }

void solve() {
    int x, y, c;
    cin >> x >> y >> c;
    int up = c;
    int down = ((int) 1e9) - c;
    int gcd = __gcd(up, down);
    up /= gcd, down /= gcd;
    cout << up << "/" << down << endl;
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