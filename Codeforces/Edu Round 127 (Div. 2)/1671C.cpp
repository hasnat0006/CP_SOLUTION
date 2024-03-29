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

void solve() {
    int n, coin;
    cin >> n >> coin;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(vf(v));
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + v[i];
    int cnt = 0, totalDay = 0;
    dbg(prefix);
    for (int i = n; i >= 1; i--) {
        prefix[i] += totalDay * i;
        int day = (coin >= prefix[i]) ? (coin - prefix[i]) / i + 1 : 0;
        cnt += (day * i);
        totalDay += day;
        dbg(i, day, cnt, totalDay);
    }
    cout << cnt << endl;
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