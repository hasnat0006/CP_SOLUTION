//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|11|2024 21:48:41            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char x;
            cin >> x;
            arr[i][j] = x - '0';
        }
    }

    auto creatingAns = [&](int i) {
        vector<int> ans;
        int up = i, bam = i, down = n - 1 - i, dan = m - 1 - i;
        if (up > down || bam > dan)
            return ans;
        for (int j = bam; j <= dan; j++)
            ans.push_back(arr[up][j]);
        for (int i = up + 1; i <= down; i++)
            ans.push_back(arr[i][dan]);
        for (int j = dan - 1; j >= bam; j--)
            ans.push_back(arr[down][j]);
        for (int i = down - 1; i > up; i--)
            ans.push_back(arr[i][bam]);
        return ans;
    };

    auto findAns = [&](vector<int> ans) {
        if (ans.empty())
            return 0;
        vector<int> valid = {1, 5, 4, 3};
        int N = ans.size(), c = 0;
        vector<int> temp = ans;
        temp.insert(temp.end(), vf(ans));
        for (int i = 0; i < N; i++) {
            int f = 1;
            for (int j = 0; j < 4; j++) {
                if (temp[i + j] != valid[j]) {
                    f = 0;
                    break;
                }
            }
            if (f)
                c++;
        }
        return c;
    };

    ll sum = 0;
    ll N = min(n, m) / 2;
    for (ll i = 0; i < N; ++i) {
        vector<int> ans = creatingAns(i);
        sum += findAns(ans);
    }
    cout << sum << '\n';
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