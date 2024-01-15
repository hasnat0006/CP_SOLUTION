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
    int s, m, p;
    cin >> s >> m >> p;
    float low = 0, high = 1e7;
    float ans = 0;
    while (low + 1e-8 <= high) {
        float mid = (low + high) / 2.0;
        float sub_total = 0;
        float sprime = s;
        for (int i = 0; i < m; i++) {
            float a = sprime * (p / 100.0);
            sub_total += (mid - a);
            sprime = sprime - (mid - a);
        }                      
        if (sub_total >= s) {
            high = mid;
            ans = mid;
        }
        else {
            low = mid + 1e-8;
        }
    }
    // cout << ans << endl;
    cout << dosomic(7) << ans << endl;
}

int32_t main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}