#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

class Node {
   public:
    int l, r, val;
    Node() {}
    Node(ll a, ll b, ll c) { l = a, r = b, val = c; }
};

void solve() {
    ll n, k;
    cin >> n >> k;
    map<ll, pair<ll, ll>> mp;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        mp[a] = {mp[a].first + 1, c};
        mp[c] = {mp[c].first - 1, c};
    }
    dbg(mp);
    ll cnt = 0, mx = -1, start = -1;
    set<pair<ll, ll>> st;
    // map<pair<ll, ll>, ll> ans;
    for (auto [i, v] : mp) {
        cnt += v.first;
        mx = max(mx, v.second);
        if (cnt > 0 && start == -1)
            start = i;
        if (cnt == 0 && start != -1) {
            st.insert({start, i - 1});
            dbg(start, i - 1);
            // ans[{start, i - 1}] = mx;
            if(k >= start and k <= i - 1) {
                cout << max(mx, k) <<'\n';
                return;
            }
            mx = -1;
            start = -1;
        }
    }
    dbg(st);
    cout << k << '\n';
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