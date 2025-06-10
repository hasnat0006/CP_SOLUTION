#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(m);
    for (ll i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(vf(v));
    ll l = 0, r = m - 1;
    while (n > 0) {
        auto print = [&](ll l, ll r) {
            for (int i = 0; i < 3; i++)
                cout << v[l] << " " << v[r] << " ";
            cout << '\n';
        };
        print(l, r);
        n--;
        if (n > 0)
            print(r, l);
        n--, l++, r--;
    }
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