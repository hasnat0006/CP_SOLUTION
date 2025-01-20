//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
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
const ll inf = mod;

void solve() {
    string s;
    cin >> s;
    map<ll, ll> mp;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        ll temp = s[i] - '0';
        sum += temp;
        if (temp < 4)
            mp[(temp * temp) - temp]++;
    }
    if (sum % 9 == 0) {
        cout << "YES" << '\n';
        return;
    }
    ll need = 9 - (sum % 9);
    dbg(need, sum);
    dbg(mp);
    if (need % 2)
        need += 9;
    while (mp[6] and need >= 6)
        mp[6]--, need -= 6;
    while (mp[2] and need >= 2)
        mp[2]--, need -= 2;
    cout << (need == 0 ? "YES" : "NO") << '\n';
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