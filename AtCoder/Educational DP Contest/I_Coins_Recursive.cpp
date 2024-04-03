//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|04|2024 01:18:38            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

vector<float> v;
int n;
vector<vector<float>> dp(3000, vector<float>(3000, -1.0));

float findAns(int id, int H) {
    if (id < 0)
        return (H >= (n - H)) ? 1.0 : 0.0;
    if (dp[id][H] != -1)
        return dp[id][H];
    float stillHead = v[id] * findAns(id - 1, H + 1);
    float takeTail = (1 - v[id]) * findAns(id - 1, H);
    return dp[id][H] = (stillHead + takeTail);
}

void solve() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << fixed << setprecision(10) << findAns(n - 1, 0) << endl;
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