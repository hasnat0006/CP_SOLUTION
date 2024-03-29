//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

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

int totalSum(int n) { return (n * (n + 1)) / 2; }
int LCM(int a, int b) { return (a * b) / __gcd(a, b); }

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    int x_dara = n / m;
    int y_dara = n / k;
    int xy_dara = n / LCM(m, k);
    x_dara -= xy_dara;
    y_dara -= xy_dara;
    ans = totalSum(n) - totalSum(n - x_dara);
    dbg(ans);
    ans -= totalSum(y_dara);
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}