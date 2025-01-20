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
    ll n = s.size();
    for (int i = 1; i < n; i++) {
        ll prev = i;
        while (prev > 0) {
            ll curVal = s[prev] - '0', preVal = s[prev - 1] - '0';
            if (curVal - 1 > preVal) {
                s[prev] = preVal + '0';
                s[prev - 1] = curVal - 1 + '0';
                prev--;
            }
            else
                break;
        }
    }
    cout << s << '\n';
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