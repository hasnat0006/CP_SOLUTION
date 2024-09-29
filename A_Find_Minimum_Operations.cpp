//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|09|2024 21:38:23            !//
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

int binaryExp(int base, int power) {
    int res = 1;
    while (power) {
        if (power & 1)
            res = (res * base);
        base = ((base) * (base));
        power /= 2;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vlaue;
    int x = 0;
    if (k == 1) {
        cout << n << endl;
        return;
    }
    for (int i = 0; x < n; i++) {
        int temp = binaryExp(k, i);
        x = temp;
        vlaue.push_back(temp);
    }
    dbg(vlaue) int ans = 0;
    int pre = -1;
    while (n > 1) {
        int id = upper_bound(vf(vlaue), n) - vlaue.begin() - 1;
        if(pre == id and id == 0)
            break;  
        n -= vlaue[id];
        ans++;
        pre = id;
        dbg(id, vlaue[id], n, ans);
    }
    cout << ans + n << endl;
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