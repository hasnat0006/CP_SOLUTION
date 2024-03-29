//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|03|2024 02:16:29            !//
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

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1), ans(n + 1, 1);
    for(int i = 0; i < n; i++)
        cin >> v[i + 1];
    for(int i = 2; i <= n; i++){
        int j = i;
        set<int> s;
        for(int k = 1; k * k <= j; k++)
            if(j % k == 0)
                s.insert(k), s.insert(j / k);
        for(auto k: s)
            if(v[i] > v[k])
                ans[i] = max(ans[i], ans[k] + 1);
    }
    cout << *max_element(vf(ans)) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}