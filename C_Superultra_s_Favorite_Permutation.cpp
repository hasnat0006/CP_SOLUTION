//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|11|2024 20:51:40            !//
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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> ans;
    if(n < 5){
        cout << -1 << '\n';
        return;
    }
    for (int i = (n % 2 == 0 ? n - 1 : n); i > 0; i -= 2) {
        if (i != 5)
            ans.push_back(i);
    }
    ans.push_back(5);
    ans.push_back(4);
    for (int i = (n % 2 == 0 ? n : n - 1); i > 0; i -= 2) {
        if(i != 4 )
            ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ' ';
    }
    cout << '\n';
    dbgc(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}