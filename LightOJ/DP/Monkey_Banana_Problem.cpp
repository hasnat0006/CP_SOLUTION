//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|04|2024 02:15:38            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int n, nn;
int dp[1005][1005];
int arr[1005][1005];

int monkeys_benefit(int i, int j, vector<int> v[]) {
    if (i > nn or j < 1 or j > n)
        return 0;
    if (i > n)
        j--;
    if (dp[i][j] != -1)
        return dp[i][j];
    int left = monkeys_benefit(i + 1, j, v) + arr[i][j];
    int right = monkeys_benefit(i + 1, j + 1, v) + arr[i][j];
    return dp[i][j] = max(left, right);
}

void solve() {
    vector<int> v[1005];
    memset(dp, -1, sizeof(dp));
    memset(arr, 0, sizeof(arr));
    cin >> n;
    nn = 2 * n - 1;
    for (int i = 1; i <= n; i++) {
        v[i].push_back(0);
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    int c = n - 1;
    for (int i = n + 1; i <= nn; i++) {
        v[i].push_back(0);
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
        }
        c--;
    }
    cout << monkeys_benefit(1, 1, v) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}