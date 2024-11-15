//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|11|2024 00:34:53            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

void solve() {
    ll n;
    cin >> n;
    if (n % 2 and n < 27) {
        cout << -1 << '\n';
        return;
    }
    if (n % 2) {
        n -= 27;
        cout
            << "15 1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 12 15 1 ";
    }
    ll cnt = 112;
    for (int i = 0; i < n / 2; i++, cnt++)
        cout << cnt << " " << cnt << " ";
    cout << '\n';
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