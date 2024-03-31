//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 01:36:46            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;


int dp[55][5000];

int count(int i, int k, vector<int>& v) {
    if (i == 0) {
        if (k == 0 and v[i] == 0)
            return 2;
        if (k == 0)
            return 1;
        return k == v[i];
    }
    if (dp[i][k] != -1)
        return dp[i][k];
    int notTake = count(i - 1, k, v), take = 0;
    if (k - v[i] >= 0)
        take = count(i - 1, k - v[i], v);
    return dp[i][k] = take + notTake;
}

int countPartitions(int n, int d, vector<int>& arr) {
    memset(dp, -1, sizeof(dp));
    int total = accumulate(arr.begin(), arr.end(), 0ll);
    if(total - d < 0 or (total - d) % 2)
        return 0;
    int k = (total - d) / 2;
    return count(arr.size() - 1, k, arr);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << targetSum(n, k, v) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}