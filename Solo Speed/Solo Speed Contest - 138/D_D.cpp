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
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

// it will be my first dp problem which i solved in a contest

int n, m;
vector<int> v;
int dp[70][7000][70];  // [i][sum][k]

int dp_diyei_korbo(int i, int sum, int k) {
    if (i == n) {
        if (sum == 0 and k == m)
            return 1;
        return 0;
    }
    if (sum == 0 and k == m)
        return 1;
    if (dp[i][sum][k] != -1)
        return dp[i][sum][k];
    // nibo na
    int ans = 0;
    ans += dp_diyei_korbo(i + 1, sum, k);
    // nibo
    if (sum - v[i] >= 0 and k + 1 <= m)
        ans += dp_diyei_korbo(i + 1, sum - v[i], k + 1);
    return dp[i][sum][k] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    if (m > n) {
        cout << 0 << endl;
        return;
    }
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(vf(v));
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += v[i];
    }
    cout << dp_diyei_korbo(0, sum, 0) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}