//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|11|2024 23:43:45            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    set<ll> st(vf(v));
    ll mex = 0;
    for (auto i : st) {
        if (i == mex)
            mex++;
        else
            break;
    }
    vector<ll> a;
    map<ll, ll> mp;
    for (auto i : v) {
        if (i < mex) {
            a.push_back(i);
            mp[i]++;
        }
    }
    sort(vf(a));
    ll ans = 0;
    while(mex != 0){
        vector<pair<float, ll>> temp;
        for(auto [i, cnt] : mp){
            ld tempCost = i + (cnt - 1) * mex;
            temp.push_back({tempCost / cnt, i});
        }
        sort(vf(temp));
        ll rem = temp.front().second;
        ans += (rem + (mp[rem] - 1) * mex);
        mp.erase(mp.find(rem));
        mex = rem;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}