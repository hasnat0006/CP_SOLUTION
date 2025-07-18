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
    vector<ll> v(1000005);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v[a]++;
        v[b + 1]--;
    }
    vector<ll> pre(1000005);
    partial_sum(vf(v), pre.begin());
    cout << *max_element(vf(pre)) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}