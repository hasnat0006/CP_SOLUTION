//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|03|2024 16:20:02            !//
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

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int cnt = 0, x = 0;
    while (s.size() > 1) {
        auto front = s.begin();
        auto back = s.rbegin();
        if (x + *front > *back) {
            int frontNeed = *back - x;
            x = *back;
            cnt += frontNeed;
            s.insert(*front - frontNeed);
            s.erase((front));
        }
        else {
            x += *front;
            cnt += *front;
            s.erase(front);
        }
        if (x >= *back) {
            s.erase(s.find(*back));
            cnt++;
            x = 0;
        }
        dbg(cnt, x);
        dbg(s);
    }
    if (s.size() == 1) {
        if (x >= *s.begin())
            cnt++;
        else {
            int mid = (*s.begin() + x + 1) / 2;
            cnt += min((mid - x) + 1, *s.begin());
        }
    }
    cout << cnt << endl;
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