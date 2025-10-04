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
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(vf(v));
    ll cur_mex = 0;

    while (mp.count(cur_mex))
        cur_mex++;

    ll ans = 0;
    if (cur_mex == k)
        ans = 0;
    if (cur_mex > k)
        ans = mp[k];
    else {
        while (cur_mex != k) {
            if (mp[cur_mex] == 0)
                ans++;
            cur_mex++;
        }
        if (mp[k] - ans > 0)
            ans += (mp[k] - ans);
    }

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