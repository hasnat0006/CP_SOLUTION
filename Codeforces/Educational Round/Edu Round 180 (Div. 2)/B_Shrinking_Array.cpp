#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 2) {
        cout << (abs(v[0] - v[1]) > 1 ? -1 : 0) << '\n';
        return;
    }
    for (int i = 1; i < n; i++) {
        if (abs(v[i] - v[i - 1]) <= 1) {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (v[i + 1] + 1 >= min(v[i - 1], v[i]) and
            v[i + 1] - 1 <= max(v[i - 1], v[i])) {
            cout << 1 << '\n';
            return;
        }
        if (v[i - 1] + 1 >= min(v[i + 1], v[i]) and
            v[i - 1] - 1 <= max(v[i + 1], v[i])) {
            cout << 1 << '\n';
            return;
        }
    }
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