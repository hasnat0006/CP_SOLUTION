//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|02|2024 16:01:54            !//
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
    int n, k;
    cin >> n >> k;
    if (k <= (n + 1) / 2) {
        cout << 2 * (k - 1) + 1 << endl;
        return;
    }
    int sum = (n + 1) / 2, power = 2;
    while (power <= n) {
        int numPos = n / power;
        sum += (numPos + 1) / 2;
        if (sum >= k) {
            int id = (numPos + 1) / 2 - (sum - k);
            cout << (2 * id - 1) * power << endl;
            return;
        }
        power *= 2;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}