#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {  
    ll n; cin >> n;
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v[i] = {x, i};
    }
    map<ll, ll> mp;
    sort(vr(v));
    mp[v[0].second] = 1;
    for(int i = 1; i < n; i++) {
        auto [val, id] = v[i];
        if(mp.count(id + 1) or mp.count(id - 1))
            mp[id] = 1;
        else {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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