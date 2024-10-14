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
float pi = acos(0);
int inf = 1e18;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s, t;
    cin >> s >> t;
    vector<int> id;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i])
            id.pb(i);
    }
    if (id.size() % 2) {
        cout << -1 << endl;
        return;
    }
    if (id.size() == 2 and id[0] + 1 == id[1]) {
        cout << min(2ll * y, x) << endl;
    }
    else
        cout << ((int)(id.size() / 2)) * y << endl;
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