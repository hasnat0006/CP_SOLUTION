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
#define dosomiP(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

string a, b;
string dp[105][105];
string LCS(int i, int j) {
    if (i <= 0 or j <= 0)
        return dp[i][j] = "";
    if (dp[i][j] != ".")
        return dp[i][j];
    if (a[i - 1] == b[j - 1])
        return dp[i][j] = LCS(i - 1, j - 1) + a[i - 1];
    else {
        string iP = LCS(i - 1, j);
        string jP = LCS(i, j - 1);
        if (iP.size() > jP.size())
            return dp[i][j] = iP;
        if (iP.size() < jP.size())
            return dp[i][j] = jP;
        if (iP < jP)
            return dp[i][j] = iP;
        return dp[i][j] = jP;
    }
}
void intial() {
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++)
            dp[i][j] = ".";
    }
}

void solve() {
    intial();
    cin >> a >> b;
    string ans = LCS(a.size(), b.size());
    ans.size() == 0 ? cout << ":(" << endl : cout << ans << endl;
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