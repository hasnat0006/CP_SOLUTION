//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|05|2024 20:41:57            !//
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

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n = 3;
    vector<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0)
            s.push_back(x);
    }
    if(s.size() == 0){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    while (s.size() > 1) {
        sort(vf(s));
        int first = s.front();
        s.erase(s.begin());
        int last = s.back();
        s.pop_back();
        ans++;
        if (first > 1)
            s.push_back(first - 1);
        if (last > 1)
            s.push_back(last - 1);
        dbg(s, ans);
    }
    if (s.size() and s[0] % 2)
        ans = -1;
    cout << ans << endl;
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