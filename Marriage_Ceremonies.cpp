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

int arr[25][25];
int dp[25][25];
int n;

int finding_ans(int i, int j, unordered_map<int, int> woman) {
    if (i > n or j > n)
        return 0;
    int ans = -1;
    woman[j] = 1;
    for (int k = 1; k <= n; k++) {
        if (!woman[k]) {
            int x = finding_ans(i + 1, k, woman) + arr[i][k];
            ans = max(ans, x);
        }
    }
    return ans;
}

void solve() {
    memset(arr, 0, sizeof arr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        unordered_map<int, int> woman;
        int x = finding_ans(2, i, woman) + arr[1][i];
        ans = max(ans, x);
    }
    cout << ans << endl;
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