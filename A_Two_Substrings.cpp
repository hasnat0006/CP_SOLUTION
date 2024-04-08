//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 03:33:37            !//
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

vector<int> v;
int numberOfWays(int id, int k) {
    if (id == 0) {
        if (k == 0 and v[id] == 0)
            return 2;
        if (v[id] == k)
            return 1;
        if (k == 0)
            return 1;
        return 0;
    }
    int notTake = numberOfWays(id - 1, k), take = 0;
    if (v[id] <= k)
        take = numberOfWays(id - 1, k - v[id]);
    dbg(id, k, take, notTake);
    return take + notTake;
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int sum = accumulate(vf(v), 0ll);
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return;
    }
    dbg(sum);
    cout << numberOfWays(n - 1, sum / 3) << endl;
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