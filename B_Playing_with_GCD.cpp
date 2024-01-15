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

int lcm(int a, int b) { return ((a * b) / __gcd(a, b)); }

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 2, 1), b(n + 2, 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n + 1; i++) {
        b[i] = lcm(v[i], v[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        if (__gcd(b[i], b[i + 1]) != v[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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