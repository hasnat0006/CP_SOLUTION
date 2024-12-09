#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll one = 0;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            v[i][j] = x - '0';
            one += (v[i][j] == 1);
        }
    }
    if (one == 0) {
        cout << 0 << '\n';
        return;
    }

    auto isPossible = [&](ll x, ll y) {
        return (x >= 0 and x < n and y >= 0 and y < m and !v[x][y]);
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                if (isPossible(i - 1, j) or isPossible(i + 1, j) or
                    isPossible(i, j - 1) or isPossible(i, j + 1) or
                    isPossible(i - 1, j - 1) or isPossible(i - 1, j + 1) or
                    isPossible(i + 1, j - 1) or isPossible(i + 1, j + 1)) {
                    cout << one << '\n';
                    return;
                }
            }
        }
    }
    if (one == (n * m))
        cout << one - 2 << '\n';
    else
        cout << one - 1 << '\n';
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