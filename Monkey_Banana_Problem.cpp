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

const int N = 10005;
int dp[N][N], mark[N][N];

int LCS(int i, int j, string a, string b) {
    if (i == 0 or j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i - 1] == b[j - 1]) {
        mark[i][j] = 1;  //! 1 for diagonal
        return dp[i][j] = LCS(i - 1, j - 1, a, b) + 1;
    }
    else {
        int left = LCS(i - 1, j, a, b), right = LCS(i, j - 1, a, b);
        left > right ? mark[i][j] = 2 : mark[i][j] = 3;
        return dp[i][j] = max(left, right);
    }
}

void print_lcs(int i, int j, string a, string b) {
    if (i == 0 or j == 0)
        return;
    if (mark[i][j] == 1)
        print_lcs(i - 1, j - 1, a, b), cout << a[i - 1];
    if (mark[i][j] == 2)
        print_lcs(i - 1, j, a, b);
    if (mark[i][j] == 3)
        print_lcs(i, j - 1, a, b);
}

void solve() {
    memset(dp, -1, sizeof dp);
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    cout << LCS(n, m, a, b) << endl;
    print_lcs(n, m, a, b);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}