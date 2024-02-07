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

int mod = 1000000007;
int inf = 1e18;

vector<int> v;

int maximumTake(int i, int wt) {
    if (i == -1)
        return 0;
    int nibo = 0, niboNa = 0;
    if (wt >= v[i])
        nibo = v[i] + maximumTake(i - 1, wt - v[i]);
    niboNa = maximumTake(i - 1, wt);
    return max(nibo, niboNa);
}

void solve() {
    int n, m;
    cin >> n >> m;
    v.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(vf(v));
    cout << maximumTake(n - 1, m) << endl;
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