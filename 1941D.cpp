//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 21:40:35            !//
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

int n, m, x;

void clockwiseUpdate(set<int> &s, int k) {
    dbg("clockwiseUpdate");
    set<int> temp;
    for (auto &it : s) {
        int x = it;
        x = (x + k) % n;
        temp.insert(x);
    }
    s.clear();
    s = temp;
}

void counterClockwiseUpdate(set<int> &s, int k) {
    dbg("counterClockwiseUpdate");
    set<int> temp;
    for (auto &it : s) {
        int x = it;
        x = (x - k + n) % n;
        temp.insert(x);
    }
    s.clear();
    s = temp;
}

void clockandcounterClockwiseUpdate(set<int> &s, int k) {
    dbg("clockandcounterClockwiseUpdate");
    set<int> temp;
    for (auto &it : s) {
        int x = it;
        x = (x + k) % n;
        temp.insert(x);
        x = it;
        x = (x - k + n) % n;
        temp.insert(x);
    }
    s.clear();
    s = temp;
}

void solve() {
    cin >> n >> m >> x;
    set<int> st;
    st.insert(x);
    int clock = 0, counterClock = 0, both = 0;
    for (int i = 0; i < m; i++) {
        int a;
        char c;
        cin >> a >> c;
        if (c == '?') {
            clockandcounterClockwiseUpdate(st, a);
        }
        else if (c == '1') {
            counterClockwiseUpdate(st, a);
        }
        else
            clockwiseUpdate(st, a);
        dbg(st);
    }
    // set<int> ans;
    vector<int> ans;
    cout << st.size() << endl;
    for (auto &it : st) {
        ans.push_back((it == 0 ? n : it));
    }
    sort(vf(ans));
    for (auto &it : ans)
        cout << (it) << " ";
    cout << endl;
    // cout << ans.size() << endl;
    // for (auto &it : ans)
    //     cout << (it) << " ";
    // cout << endl;
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