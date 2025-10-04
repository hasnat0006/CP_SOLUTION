#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll x, y;
    cin >> x >> y;
    if (x < y) {
        cout << 2 << '\n';
    }
    else if (x > y) {
        ll rem = x - 1;
        if (rem > y and y != 1) {
            cout << 3 << '\n';
        }
        else
            cout << -1 << '\n';
    }
    else
        cout << -1 << '\n';
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