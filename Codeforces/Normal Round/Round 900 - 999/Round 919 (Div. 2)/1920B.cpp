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
    int n, alice, bob;
    cin >> n >> alice >> bob;
    vector<int> v(n), prefix(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(vr(v));
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + v[i - 1];
    int ans = -1 * inf, sum = prefix.back();
    auto maxX = [&](int id) { return prefix[min(n, id + bob)] - prefix[id]; };
    for (int i = 0; i <= alice; i++)
        ans = max(ans, sum - 2 * maxX(i)), sum -= v[i];
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        dbg();
        solve();
    }
    return 0;
}