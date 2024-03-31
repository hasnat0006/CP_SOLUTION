//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|03|2024 22:24:48            !//
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(x);
    for (int i = 0; i < x; i++)
        cin >> v[i];
    sort(vf(v));
    int ans = x - 2;
    set<int> point(vf(v));
    for (auto i : point) {
        int left = i;
        int mid = ((i + 1) % n) == 0 ? n : (i + 1) % n;
        int right = ((i + 2) % n) == 0 ? n : (i + 2) % n;
        if(point.find(mid) == point.end() and point.find(right) != point.end()){
            ans++;
        }
    }
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