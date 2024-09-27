//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|09|2024 20:17:50            !//
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> id;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }
    map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        mp[a[i]] = n - i - 1;
        if (i != 0) {
            mp[a[i]] += mp[a[i - 1]] - cnt;
            cnt++;
        }
    }
    dbg(mp);
    map<int, int> point;
    for (auto i : mp) {
        point[i.second]++;
    }
    for(int i = 0; i < n - 1; i++){
        if(a[i + 1] - 1 != a[i]){
            int left = i + 1;
            int right = n - left;
            int pointCnt = left * right;
            int majePoint = a[i + 1] - a[i] - 1;
            point[pointCnt] += majePoint;
        }
    }

    dbg(point);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << point[x] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
        dbg("--------");
    }
    return 0;
}