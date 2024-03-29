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

string a, b;
int dp[50][50], way[50][50];

void solve() {
    memset(dp, 0, sizeof dp);
    memset(way, 0, sizeof way);
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else {
                a[i - 1] == b[j - 1]
                    ? dp[i][j] = 1 + dp[i - 1][j - 1]
                    : dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 or j == 0)
                way[i][j] = 1;
            else if (a[i - 1] == b[j - 1])
                way[i][j] = way[i - 1][j - 1];
            else {
                if (dp[i - 1][j] == dp[i][j] - 1)
                    way[i][j] += way[i - 1][j];
                if (dp[i][j - 1] == dp[i][j] - 1)
                    way[i][j] += way[i][j - 1];
            }
        }
    }
    cout << dp[n][m] << " " << way[n][m] << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        case(i);
        solve();
    }
    return 0;
}