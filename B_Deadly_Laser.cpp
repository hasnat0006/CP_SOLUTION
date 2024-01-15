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

bool isvalid(int n, int m, int x, int y, int d) {
    if ((x + d) >= n and (y + d) >= m)
        return false;
    if ((x - d) <= 1 and (y - d) <= 1)
        return false;
    if ((x + d) >= n and (y + d) >= m)
        return false;
    if ((x - d) <= 1 and (y - d) <= 1)
        return false;
    int a = 0, b = 0;
    a += min(abs(n - x), d) + min(abs(1 - x), d) + 1;
    b += min(abs(m - y), d) + min(abs(1 - y), d) + 1;
    dbg(a, b);
    if (a >= n or b >= m)
        return false;
    return true;
}

void solve() {
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;
    if (d == 0) {
        cout << n + m - 2 << endl;
        return;
    }
    if (!isvalid(n, m, x, y, d)) {
        cout << -1 << endl;
        return;
    }
    cout << n + m - 2 << endl;
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