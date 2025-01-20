#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> player(n), problem(m);
    for (int i = 0; i < n; i++)
        cin >> player[i];
    for (int i = 0; i < m; i++)
        cin >> problem[i];
    sort(vf(problem));
    sort(player.begin() + 1, player.end());
    vector<ll> rank(m + 1, 0);
    for (int i = 0; i < m; i++) {
        if (problem[i] <= player[0])
            rank[i + 1] = 1;
        else {
            ll id = lower_bound(player.begin() + 1, player.end(), problem[i]) -
                    player.begin();
            rank[i + 1] = n - id + 1;
        }
    }
    dbg(rank);
    sort(vf(rank));
    vector<ll> ans(m + 1, 0);
    ans[1] = accumulate(vf(rank), 0LL);
    for (int i = 2; i <= m; i++) {
        // cout << i << " : ";
        for (int j = i; j <= m; j += i) {
            // cout << rank[j] << " ";
            ans[i] += rank[j];
        }
        // cout << endl;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}