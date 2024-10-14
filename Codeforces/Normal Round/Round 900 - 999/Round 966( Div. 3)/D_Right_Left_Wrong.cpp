//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|08|2024 21:42:40            !//
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    while (s.size() and s.back() == 'L') {
        s.pop_back();
        v.pop_back();
    }
    reverse(vf(s));
    reverse(vf(v));
    while (s.size() and s.back() == 'R') {
        s.pop_back();
        v.pop_back();
    }
    if(s.empty()){
        cout << 0 << endl;
        return;
    }
    reverse(vf(s));
    reverse(vf(v));
    n = s.size();
    vector<int> pre(n, 0);
    pre[0] = v[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }
    vector<int> L;
    vector<int> R;
    for (int i = 0; i < n; i++) {
        s[i] == 'L' ? L.push_back(i) : R.push_back(i);
    }
    reverse(vf(R));
    dbg(v);
    dbg(s);
    dbg(pre);
    dbg(L);
    dbg(R);
    int ans = 0;
    for (int i = 0; i < min((int)L.size(), (int)R.size()); i++) {
        int lID = L[i];
        int rID = R[i];
        if (rID < lID) {
            break;
        }
        // sum between lID and rID
        dbg(lID, rID);
        int sum = pre[rID] - (lID != 0 ? pre[lID - 1] : 0);
        ans += sum;
        dbg(sum, ans);
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