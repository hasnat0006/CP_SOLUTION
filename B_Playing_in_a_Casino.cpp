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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            v[j].push_back(x);
        }
    }
    for (int i = 0; i < m; i++) {
        sort(vf(v[i]));
    }
    int suffix[m][n];
    for (int i = 0; i < m; i++) {
        suffix[i][n - 1] = v[i][n - 1];
        for (int j = n - 2; j >= 0; j--) {
            suffix[i][j] = suffix[i][j + 1] + v[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int temp = suffix[i][j] - ((n - j) * v[i][j - 1]);
            ans += temp;
            dbg(i, j, temp);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}