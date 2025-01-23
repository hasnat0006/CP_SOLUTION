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
    ll even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        (x % 2 == 0 ? even++ : odd++);
    }
    if (odd == n) {
        cout << n - 1 << '\n';
    }
    else if (even == n)
        cout << 1 << '\n';
    else
        cout << 1 + odd << '\n';
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