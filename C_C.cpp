//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 12:32:10            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int   long long
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
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> pre(n), suf(n);
    auto MAX = [](int a, int b) { return max(a, b); };
    auto MIN = [](int a, int b) { return min(a, b); };
    partial_sum(vf(v), pre.begin(), MAX);
    partial_sum(vr(v), suf.rbegin(), MIN);
    dbg(pre);
    dbg(suf);
    int ans1 = 1, ans2 = 1, cur = 0;
    cur = pre[0];
    for(int i = 0; i < n; i++){
        if(pre[i] != cur){
            ans1++;
            cur = pre[i];
        }
    }
    cur = suf[n -1];
    for(int i = n - 1; i >= 0; i--){
        if(suf[i] != cur){
            ans2++;
            cur = suf[i];
        }
    }
    cout << min(ans1, ans2) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}