//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|03|2024 20:10:48            !//
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
    int n, m, a;
    cin >> n >> m;
    auto query = [&](int x, int y) {
        cout << "? " << x << " " << y << endl;
        cin >> a;
        return a;
    };
    int q1 = query(1, 1);
    int xCord = min(n, 1 + q1);
    int yCord = min(m, 1 + q1);
    int q2 = query(xCord, q1 - xCord + 2);
    int q3 = query(q1 - yCord + 2, yCord);
    if (xCord - q2 / 2 <= n and q1 - xCord + 2 + q2 / 2 <= m and q2 % 2 == 0) {
        int q4 = query(xCord - q2 / 2, q1 - xCord + 2 + q2 / 2);
        if (q4 == 0) {
            cout << "! " << xCord - q2 / 2 << " " << q1 - xCord + 2 + q2 / 2 << endl;
            return;
        }
    }
    cout << "! " << q1 - yCord + 2 + q3 / 2 << " " << yCord - q3 / 2 << endl;
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}