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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

const int mod = 1000000007;
const int inf = 1e18;

void solve() {
    int n, x;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
        cin >> x, st.insert(x);
    vector<int> v;
    for (auto i : st)
        v.push_back(i);
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        int id = lower_bound(vf(v), v[i] + n) - v.begin() - i;
        ans = max(ans, id);
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}