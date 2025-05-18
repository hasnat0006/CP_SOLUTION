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
    string s;
    cin >> s;
    ll _ = 0, minus = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') {
            _++;
        }
        else {
            minus++;
        }
    }
    if (minus < 2 or _ == 0) {
        cout << 0 << '\n';
        return;
    }
    ll half = minus / 2;
    ll ans = (half * (minus - half)) * _;
    cout << ans << '\n';
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