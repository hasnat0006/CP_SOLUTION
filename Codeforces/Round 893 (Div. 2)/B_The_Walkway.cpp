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

int find(int low, int high, int d) {
    return (high - low - 1) / d;
}

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> v(m), pre(m), suf(m);
    for (auto &i : v)
        cin >> i;

    pre[0] = 1 + (v[0] + d - 2) / d;
    for (int i = 1; i < m; i++)
        pre[i] = 1 + pre[i - 1] + find(v[i - 1], v[i], d);

    suf[m - 1] = 1 + find(v[m - 1], n + 1, d);
    for (int i = m - 2; i >= 0; i--)
        suf[i] = 1 + suf[i + 1] + find(v[i], v[i + 1], d);

    map<int, int> mp;
    int ans = ((v[1] + d - 2) / d) + suf[1];
    int removed = 0;
    mp[ans]++;
    int curr = pre[m - 2] + find(v[m - 2], n + 1, d);
    if (ans > curr)
        ans = curr;
    mp[curr]++;
    for (int i = 1; i < m - 1; i++) {
        curr = pre[i - 1] + suf[i + 1] + find(v[i - 1], v[i + 1], d);
        if (ans > curr)
            ans = curr;
        mp[curr]++;
    }
    cout << ans << " " << mp[ans] << endl;
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