//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|10|2024 21:13:50            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> zero;
    zero.push_back(-1);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 0)
            zero.push_back(i);
    }
    ll ans = zero.size() - 1;
    zero.push_back(n);
    ll start = 0;

    auto findAns = [](vector<ll> &a) {
        ll N = a.size();
        vector<ll> pre(N);
        partial_sum(vf(a), pre.begin());
        ll cnt = 0;
        set<ll> s;
        ll last = -1;
        for (ll i = 0; i < N; i++) {
            if (s.count(pre[i])) {
                cnt++;
                s.clear();
                last = i;
            }
            else if (pre[i] == 0 and pre[i] - (last == -1 ? 0 : pre[last]) == 0) {
                cnt++;
                last = i;
                s.clear();
            }
            s.insert(pre[i]);
            dbg(i, pre[i], cnt);
            dbg(s);
        }
        dbg(a, pre, cnt);
        return cnt;
    };
dbg(zero);
    for (ll i = 0; i < zero.size() - 1; i++) {
        vector<ll> temp;
        dbg(zero[i], zero[i + 1]);
        for (ll val = zero[i] + 1; val < zero[i + 1]; val++) {
            temp.push_back(v[val]);
        }
        dbg(temp);
        ans += findAns(temp);
        start = zero[i] + 1;
        dbg(start);
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