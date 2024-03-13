//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 22:32:50            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

int f(vector<int> &v, int k) {
    int n = v.size();
    vector<int> dp(n, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j < n) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(v[i] - v[i + j]));
            }
        }
    }
}

void solve() {
    // you are given an array of n integers and a value k;
    // you have to find the minimun cost to choose some elements from the array
    // to go to the end of the array. you can't skip more then k consecutive
    // elements. the cost of choosing an element is the value of the element + 1.
    // solve;
    // int n, k;
    // cin >> n >> k;
    // vector<int> v(n);
    // for (int &i : v)
    //     cin >> i;
    // vector<int> dp(n, inf);
    // dp[0] = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 1; j <= k; j++) {
    //         if (i + j < n) {
    //             dp[i + j] = min(dp[i + j], dp[i] + abs(v[i] - v[i + j]));
    //         }
    //     }
    // }
    // cout << dp[n - 1] << endl;
    // now there are n arrays of length m and a value k;
    // you have to find the minimun cost for all array ans store it in a vector.
    int n, m, k, d;
    cin >> n >> m >> d >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            v[i][j]++;
        }
    }
    vector<int> ans(n, inf);
    for (int i = 0; i < n; i++) {
        // the cost of choosing an element is the value of the element + 1.
        // now we have to find the minimun cost to choose some elements from the array
        // solve
        vector<int> dp(m, inf);
        dp[0] = 0;
        for (int j = 0; j < m; j++) {
            for (int l = 1; l <= k; l++) {
                if (j + l < m) {
                    dp[j + l] = min(dp[j + l], dp[j] + abs(v[i][j] - v[i][j + l]));
                }
            }
        }
        ans[i] = dp[m - 1];

    }
    for (int i : ans) {
        cout << i << " ";
    }
    // for (int i : ans) {
    //     cout << i << " ";
    // }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}