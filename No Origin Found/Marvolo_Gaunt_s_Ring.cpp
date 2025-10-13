#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18, N = 1e5 + 5;

int n, p, q, r;
ll dp[N][4];
vector<int> v;
vector<ll> score;

ll findAns(int i, int pOn) {
    if ((pOn == 3))
        return 0;
    if (i == n)
        return LONG_LONG_MIN;
    if (dp[i][pOn] != -1)
        return dp[i][pOn];
    ll ans = findAns(i + 1, pOn);
    ans = max(ans, v[i] * score[pOn] +
                       max(findAns(i + 1, pOn + 1), findAns(i, pOn + 1)));
    return dp[i][pOn] = ans;
};

void solve() {
    cin >> n >> p >> q >> r;
    score = {p, q, r};
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < 4; ++i)
        dp[n][i] = LONG_LONG_MIN;
    dp[n][3] = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 2; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j];
            dp[i][j] = max(dp[i][j], dp[i][j + 1] + (v[i] * score[j]));
        }
    }
    cout << dp[0][0] << '\n';
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