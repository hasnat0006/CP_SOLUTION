//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 00:53:24            !//
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

vector<int> v;

int dp[100005][2];

int findAns(int k, int player) {
    // base case
    if (k < v.front())
        return false;
    // memoization
    if (dp[k][player] != -1)
        return dp[k][player];
    bool ans = false;
    // try all possible moves.
    // if all moves findAns() returns true it means opposite player win and current player lose.
    for (int i = 0; i < v.size(); i++) {
        if (k >= v[i]) {
            ans = ans | !findAns(k - v[i], !player);
        }
    }
    return dp[k][player] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << (findAns(k, 0) ? "First" : "Second") << endl;
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