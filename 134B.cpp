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

int minSteps(int n, int k) {
    if (k > n)
        swap(n, k);
    if (k == 1)
        return n - 1;
    if (n % k == 0)
        return inf;
    return minSteps(n % k, k) + n / k;
}

void solve() {
    int n;
    cin >> n;
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, minSteps(n, i));
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}