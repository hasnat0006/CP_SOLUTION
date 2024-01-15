//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

void solve() {
    int n, x;
    cin >> n;
    vector<pair<int, int>> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = {x, i};
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        b[i] = {x, i};
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        c[i] = {x, i};
    }
    // sort(vr(a));
    // sort(vr(b));
    // sort(vr(c));
    // int ans = 0, idx = 0, idy = 0, idz = 0, i = 0;
    // while(i != 3){
    //     int xx, yy, zz;
    //     while(a[idx].first)
    //     id++;
    // }
    map<int, int> mp, done;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++) {
        int mx = max({a[i].first, b[i].first, c[i].first});
        if (mx == a[i].first)
            v.push_back({a[i].first, {i, 1}});  // 1 for a
        if (mx == b[i].first)
            v.push_back({b[i].first, {i, 2}});  // 2 for b
        if (mx == c[i].first)
            v.push_back({c[i].first, {i, 3}});  // 3 for c
    }
    sort(vr(v));
    int ans = 0;
    int cnt = 0;
    dbg(v);
    for (int i = 0; i < v.size(); i++) {
        if (cnt == 3)
            break;
        if (mp[v[i].second.first] == 0 && done[v[i].second.second] == 0) {
            ans += v[i].first;
            mp[v[i].second.first] = 1;
            done[v[i].second.second] = 1;
            cnt++;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}