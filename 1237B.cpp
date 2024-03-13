//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|03|2024 02:39:53            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), vis(n + 1, 0);
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[v[i]])
            continue;
        // cout << i << " " << v[i] << " " << dq.front() << endl;
        if (dq.front() != v[i]) {
            ans++;
            vis[dq.front()] = 1;
            i--;
        }
        dq.pop_front();
        if (dq.empty())
            break;
        // cout << i << " " << ans << endl;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}