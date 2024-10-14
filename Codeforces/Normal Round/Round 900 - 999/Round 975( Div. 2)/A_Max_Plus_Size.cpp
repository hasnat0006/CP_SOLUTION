//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|09|2024 19:36:58            !//
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
    if(n == 1){
        int x;
        cin >> x;
        cout << x + 1 << endl;
        return;
    }
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(i % 2 == 0){
            a.push_back(x);
        }else{
            b.push_back(x);
        }
    }
    dbg(a);
    dbg(b);
    int ans1 = *max_element(vf(a)) + a.size();
    int ans2 = *max_element(vf(b)) + b.size();
    cout << max(ans1, ans2) << endl;
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