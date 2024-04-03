//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|04|2024 15:46:41            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

string LPS = "";
int mark[1005][1005];


void print(int i, int j, string s){
    if(i == 0 or j == 0)
        return;
    if(mark[i][j] == 1)
        print(i - 1, j - 1, s), LPS.push_back(s[i - 1]);
    if(mark[i][j] == 2)
        print(i - 1, j, s);
    if(mark[i][j] == 3)
        print(i, j - 1, s);
}

string lcs(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1ll + dp[i - 1][j - 1], mark[i][j] = 1;
            else{
                int up = dp[i - 1][j], down = dp[i][j - 1];
                mark[i][j] = up > down ? 2 : 3;
                dp[i][j] = max(up, down);
            }
        }
    }
    print(n, m, s);
    return LPS;
}

void solve() {
    string a, b;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    cout << lcs(a, b) << endl;
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