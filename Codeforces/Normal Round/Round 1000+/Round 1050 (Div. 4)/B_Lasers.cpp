#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll ans = 0;
    set<ll> A, B;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        A.insert(a);
    }
    for (int i = 0; i < m; i++) {
        ll a;
        cin >> a;
        B.insert(a);
    }
    cout << A.size() + B.size() << '\n';
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