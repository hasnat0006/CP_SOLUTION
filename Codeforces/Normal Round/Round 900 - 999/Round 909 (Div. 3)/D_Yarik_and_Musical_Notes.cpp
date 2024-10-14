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
    vector<int> v(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
    int ans = 0, same = 0;
    sort(vf(v));
    for (int i = 0; i < n; i++) {
        same++;
        if (i == n - 1 || v[i] != v[i + 1]) {
            ans += (same * (same - 1)) / 2;
            same = 0;
        }
        for (int j = 1;; j++) {
            int rhs = v[i] * (1 << j);
            if (rhs > v.back())
                break;
            if (!freq.count(rhs))
                continue;
            if (rhs - v[i] == j)
                ans += freq[rhs];
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