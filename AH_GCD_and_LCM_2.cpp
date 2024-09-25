//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|09|2024 02:35:28            !//
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
    int n;
    cin >> n;

    auto lcm = [&](int a, int b) -> int {
        return a * b / __gcd(a, b);
    };

    vector<int> v(n + 2, 1), b(n + 2, 1);
    for (int i = 1; i <= n; i++)    
        cin >> v[i];
    for (int i = 1; i <= n + 1; i++) {
        b[i] = lcm(v[i], v[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        if (__gcd(b[i], b[i + 1]) != v[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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