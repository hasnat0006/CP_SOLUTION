//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|05|2024 21:22:27            !//
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> point(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> point[i];
    }
    map<int, int> time;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        time[point[i]] = x;
    }
    vector<int> ans;
    while (q--) {
        int x;
        cin >> x;
        int id = lower_bound(vf(point), x) - point.begin();
        if (point[id] == x) {
            ans.push_back(time[x]);
        }
        else {
            float leftVal = point[id - 1];
            float rightVal = point[id];
            float leftTime = time[leftVal];
            float rightTime = time[rightVal];
            float veg = ((rightTime - leftTime) / (rightVal - leftVal));
            int res = leftTime + ((x - leftVal) * ((rightTime - leftTime) /
                                                   (rightVal - leftVal)));
            // dbg(leftVal, rightVal, leftTime, rightTime, veg, res);
            ans.push_back(res);
        }
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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