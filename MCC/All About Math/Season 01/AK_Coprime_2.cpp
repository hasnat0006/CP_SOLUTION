//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|10|2024 22:36:42            !//
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
    vector<int> pos(1005, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x] = i + 1;   
    }
    int ans = -1;
    for(int i = 1; i <= 1000; i++){
        for(int j = i; j <= 1000; j++){
            if(pos[i] and pos[j] and __gcd(i, j) == 1){
                ans = max(ans, pos[i] + pos[j]);
                // cout << ans << " " << pos[i] << " " << pos[j] << endl;
            }
        }
    }
    cout << ans << endl;
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