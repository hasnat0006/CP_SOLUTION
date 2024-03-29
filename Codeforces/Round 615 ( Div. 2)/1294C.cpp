//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|03|2024 01:46:17            !//
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

void solve() {
    int n;
    cin >> n;
    set<int> div;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div.insert(i);
        }
    }
    for (auto i : div) {
        int a = i;
        int x = n / i;
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                if (j != a and (x / j) != a and j != (x / j)) {
                    cout << "YES" << endl;
                    cout << a << " " << j << " " << x / j << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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