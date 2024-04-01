//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|04|2024 23:39:38            !//
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

#define mod 1000000007;
#define inf 1000000000000000000;

vector<int> v;
vector<int> dp(100005, -1);

int findAns(int id, set<int> st) {
    if (id < 0)
        return 0;
    int notTake = findAns(id - 1, st), take = 0;
    if (st.find(v[id]) != st.end()) {
        st.erase(st.find(v[id] + 1));
        st.erase(st.find(v[id] - 1));
        dbg(id, v[id], take);
        take = v[id] + findAns(id - 1, st);
    }
    dbg(id, take, notTake);
    return max(take, notTake);
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(vf(v));
    set<int> st(vf(v));
    dbg(v);
    dbg(st);
    cout << findAns(n - 1, st) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}