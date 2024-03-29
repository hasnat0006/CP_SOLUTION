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
    int n;
    cin >> n;
    char a[n][n], b[n][n];
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int c = 0;
    for (int cholbe = 0; cholbe < n / 2; cholbe++) {
        for (int i = 0; i < n / 2; i++) {
            // these lines are written by copilot..
            int mx = max({s[cholbe][i], s[n - i - 1][cholbe], s[i][n - cholbe - 1],
                          s[n - cholbe - 1][n - i - 1]});
            c += mx - s[cholbe][i];
            c += mx - s[n - i - 1][cholbe];
            c += mx - s[i][n - cholbe - 1];
            c += mx - s[n - cholbe - 1][n - i - 1];
        }
    }
    cout << c << endl;
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