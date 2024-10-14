//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, m, k, x;
    cin >> n >> m >> k;
    map<int, int> a, b;
    for (int i = 0; i < n; i++)
        cin >> x, a[x]++;
    for (int i = 0; i < m; i++)
        cin >> x, b[x]++;
    int AB = 0, A = 0, B = 0;
    for (int i = 1; i <= k; i++) {
        if (a[i] && b[i])
            AB++;
        else if (a[i])
            A++;
        else if (b[i])
            B++;
    }
    if (AB + A + B != k)
        cout << "NO" << endl;
    else {
        if (AB + min(A, B) >= k / 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}