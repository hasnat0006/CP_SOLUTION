#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<vector<char>> v(n, vector<char>(n));

    ll cnt = k, f = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f == 1) {
                v[i][j] = (j == 0 ? 'R' : 'L');
                continue;
            }
            if (cnt > 0)
                v[i][j] = 'L', cnt--;
            else {
                f = 1;
                if (i == n - 1 and j == n - 1) {
                    cout << "NO\n";
                    return;
                }
                if (i != n - 1)
                    v[i][j] = 'D';
                else
                    v[i][j] = 'R';
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << v[i][j];
        cout << '\n';
    }
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