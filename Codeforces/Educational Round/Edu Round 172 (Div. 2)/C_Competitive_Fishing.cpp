//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|12|2024 20:15:39            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    priority_queue<ll> pq;
    ll cnt = 0;
    for (int i = n - 1; i > 0; i--) {
        cnt += (s[i] == '0' ? -1 : 1);
        pq.push(cnt);
    }
    cnt = 0;
    ll score = 0;
    while (pq.size()) {
        score += pq.top();
        cnt++;
        pq.pop();
        if (score >= k)
            break;
    }
    if (score < k)
        cnt = -2;
    cout << cnt + 1 << endl;
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