#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (k % 2) {
        for (auto &i : v)
            if (i % 2)
                i += k;
    }
    else {
        for (auto &i : v) {
            ll m = i % (k + 1);
            i += (m * k);
        }
    }
    for (auto i : v)
        cout << i << " ";
    cout << '\n';
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