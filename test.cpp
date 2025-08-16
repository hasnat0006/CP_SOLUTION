//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|08|2025 12:00:42            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> st[m + 5];
    vector<ll> ans(m + 1, 0);
    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        vector<ll> temp(x);
        for (int j = 0; j < x; j++) {
            cin >> temp[j];
        }
        ll next = 1, pre = 0;
        for (int j = 0; j < x; j++) {
            if(s.find(temp[j]) != s.end()) {
                dbg(j, pre);
                while(pre < j)
                    ans[temp[pre++]] = 1;
                pre = j + 1;
            }
            dbg(pre, j);
        }
        dbg(ans);
        dbg(temp);
        dbg(s);
        s.clear();
        s.insert(temp.begin(), temp.end());
        dbg("---------");
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}